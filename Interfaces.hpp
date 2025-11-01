#pragma once

#include <cstddef>
#include <stdexcept>


template <typename T>
class StackInterface {
public:
    virtual ~StackInterface() = default;

private:
    virtual void push(const T& item) = 0;
    virtual T pop() = 0;
    virtual T peek() const = 0;
    [[nodiscard]] virtual std::size_t getSize() const noexcept = 0;
};


template <typename T>
class QueueInterface {
public:
    virtual ~QueueInterface() = default;

private:
    virtual void enqueue(const T& item) = 0;
    virtual T dequeue() = 0;
    virtual T peek() const = 0;
    [[nodiscard]] virtual std::size_t getSize() const noexcept = 0;
};


template <typename T>
class DequeInterface {
public:
    virtual ~DequeInterface() = default;

private:
    virtual void pushFront(const T& item) = 0;
    virtual void pushBack(const T& item) = 0;
    virtual T popFront() = 0;
    virtual T popBack() = 0;
    virtual const T& front() const = 0;
    virtual const T& back() const = 0;
    [[nodiscard]] virtual std::size_t getSize() const noexcept = 0;
};

