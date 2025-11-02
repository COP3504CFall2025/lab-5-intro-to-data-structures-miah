#pragma once

#include <cstddef>
#include <stdexcept>
#include "Interfaces.hpp"
#include <utility>

#include "CircularBuffer.hpp"

template <typename T>
class ABDQ : public DequeInterface<T> {
private:
    CircularBuffer<T> data;

public:
    // Big 5
    ABDQ() : data() {}
    explicit ABDQ(std::size_t capacity) : data(capacity) {}
    ABDQ(const ABDQ& other) : data(other.data) {}
    ABDQ(ABDQ&& other) noexcept : data(other.data) {}
    ABDQ& operator=(const ABDQ& other) {
        if (this==&other)
            return *this;
        data=other.data;
        return *this;
    }
    ABDQ& operator=(ABDQ&& other) noexcept {
        if (this==&other)
            return *this;
        data=other.data;
        return *this;
    }
    ~ABDQ() override = default;

    // Insertion
    void pushFront(const T& item) override {
        data.addFront(item);
    }
    void pushBack(const T& item) override {
        data.addBack(item);
    }

    // Deletion
    T popFront() override {
        T temp = data.front();
        data.removeFront();
        return temp;
    }
    T popBack() override {
        T temp = data.back();
        data.removeBack();
        return temp;
    }

    // Access
    const T& front() const override {
        return data.front();
    }
    const T& back() const override {
        return data.back();
    }

    // Getters
    [[nodiscard]] std::size_t getSize() const noexcept override {
        return data.getSize();
    }

};
