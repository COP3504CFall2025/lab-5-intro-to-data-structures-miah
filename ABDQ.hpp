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
    // Constructor
    explicit ABDQ(std::size_t capacity=0) : data(capacity) {}

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
