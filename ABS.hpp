#pragma once

#include <cstddef>
#include <stdexcept>

#include "CircularBuffer.hpp"
#include "Interfaces.hpp"

// Technically bad, but size_t isn't likely to conflict with any client code.
using std::size_t;

template<typename T>
class ABS : public StackInterface<T> {
public:
    // Big 5 + Parameterized Constructor
    ABS() : data() {}
    explicit ABS(const size_t capacity) : data(capacity) {}
    ABS(const ABS& other) : data(other.data) {}
    ABS& operator=(const ABS& rhs) {
        if (this==&rhs)
            return *this;
        data = rhs.data;
        return *this;
    }
    ABS(ABS&& other) noexcept : data(other.data) {}
    ABS& operator=(ABS&& rhs) noexcept {
        if (this==&rhs)
            return *this;
        data = rhs.data;
        return *this;
    }
    ~ABS() noexcept override = default;

    // Get the number of items in the ABS
    [[nodiscard]] size_t getSize() const noexcept override {
        return data.getSize();
    }

    // Get the max size of the ABS
    [[nodiscard]] size_t getMaxCapacity() const noexcept {
        return data.getCapacity();
    }

    // Return underlying data for the stack
    [[nodiscard]] T* getData() const noexcept {
        return data.getData();
    }

    // Push item onto the stack
    void push(const T& data) override {
        this->data.addFront(data);
    }

    T peek() const override {
        return data.front();
    }

    T pop() override {
        T temp = data.front();
        data.removeFront();
        return temp;
    }

private:
    CircularBuffer<T> data;
};
