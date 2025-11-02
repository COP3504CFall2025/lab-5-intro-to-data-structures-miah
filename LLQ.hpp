#pragma once

#include "Interfaces.hpp"
#include "LinkedList.hpp"
#include <stdlib.h>
#include <stdexcept>

template <typename T>
class LLQ : public QueueInterface<T> {
private:
    LinkedList<T> list;
public:
    // Constructor
    LLQ() : list() {}

    // Insertion
    void enqueue(const T& item) override {
        list.addHead(item);
    }

    // Deletion
    T dequeue() override {
        if (list.getCount()==0)
            throw std::runtime_error("Tried to dequeue on an empty queue.");
        T out = list.getTail()->data;
        list.removeTail();
        return out;
    }

    // Access
    T peek() const override {
        if (list.getCount()==0)
            throw std::runtime_error("Tried to peek on an empty queue.");
        return list.getTail()->data;
    }

    // Getter
    [[nodiscard]] std::size_t getSize() const noexcept override {
        return list.getCount();
    }

};