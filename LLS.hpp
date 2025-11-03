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
        if (list.getCount()==0)
            throw std::runtime_error("Tried to pop an empty stack");
        T out = list.getHead()->data;
        list.removeHead();
        return out;
    }

    // Access
    T peek() const override {
        if (list.getCount()==0)
            throw std::runtime_error("Tried to peak an empty stack");
        return list.getHead()->data;
    }

    //Getters
    [[nodiscard]] std::size_t getSize() const noexcept override {
        return list.getCount();
    }
};