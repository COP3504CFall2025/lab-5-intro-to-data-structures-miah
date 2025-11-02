#pragma once

#include <cstddef>
#include <stdexcept>
#include "Interfaces.hpp"
#include "LinkedList.hpp"
#include <utility>



template <typename T>
class LLDQ : public DequeInterface<T> {
private:
    LinkedList<T> list;

public:
    // Constructor
    LLDQ() : list() {}

    // Core Insertion Operations
    void pushFront(const T& item) override {
        list.addHead(item);
    }
    void pushBack(const T& item) override {
        list.addTail(item);
    }

    // Core Removal Operations
    T popFront() override {
        if (list.getCount()==0)
            throw std::out_of_range("Tried to access anb empty deque");
        T out = list.getHead()->data;
        list.removeHead();
        return out;
    }
    T popBack() override {
        if (list.getCount()==0)
            throw std::out_of_range("Tried to access anb empty deque");
        T out = list.getTail()->data;
        list.removeTail();
        return out;
    }

    // Element Accessors
    const T& front() const override {
        if (list.getCount()==0)
            throw std::out_of_range("Tried to access anb empty deque");
        return list.getHead()->data;
    }
    const T& back() const override {
        if (list.getCount()==0)
            throw std::out_of_range("Tried to access anb empty deque");
        return list.getTail()->data;
    }

    // Getter
    [[nodiscard]] std::size_t getSize() const noexcept override {
        return list.getCount();
    }
};






