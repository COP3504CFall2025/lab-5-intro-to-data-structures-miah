#pragma once

#include <cstddef>
#include <stdexcept>

#include "CircularBuffer.hpp"
#include "Interfaces.hpp"

// Technically bad, but size_t isn't likely to conflict with any client code.
using std::size_t;

template<typename T>
class ABQ : public QueueInterface<T> {
    CircularBuffer<T> data;

public:
    // Constructor
    explicit ABQ(const size_t capacity=1) : data(capacity) {}

    // Getters
    [[nodiscard]] size_t getSize() const noexcept override {
        return data.getSize();
    }
    [[nodiscard]] size_t getMaxCapacity() const noexcept {
        return data.getCapacity();
    }
    [[nodiscard]] T* getData() const noexcept {
        return data.getData();
    }

    // Insertion
    void enqueue(const T& item) override {
        data.addBack(item);
    }

    // Access
    T peek() const override {
        return data.front();
    }

    // Deletion
    T dequeue() override {
        T temp = data.front();
        data.removeFront();
        return temp;
    }

};