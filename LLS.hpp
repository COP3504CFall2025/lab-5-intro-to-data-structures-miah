#pragma once

#include "Interfaces.hpp"
#include "LinkedList.hpp"
#include <stdlib.h>
#include <stdexcept>

template <typename T>
class LLS : public StackInterface<T> {
private:
    LinkedList<T> list;
public:
    // Constructor
    LLS() : list() {}

    // Insertion
    void push(const T& item) override {
        list.addHead(item);
    }

    // Deletion
    T pop() override {
        T out = list.getTail()->data;
        list.removeHead()->data;
        return out;
    }

    // Access
    T peek() const override {
        return list.getTail()->data;
    }

    //Getters
    [[nodiscard]] std::size_t getSize() const noexcept override {
        return list.getCount();
    }
};