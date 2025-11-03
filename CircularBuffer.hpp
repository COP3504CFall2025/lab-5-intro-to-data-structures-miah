#pragma once
#include <cstddef>
#include <iostream>

template <typename T>
class CircularBuffer {
public:
    explicit CircularBuffer(const std::size_t cap = 1) : data(new T[cap]), capacity(cap), size(0), frontIndex(0) {}

    CircularBuffer(const CircularBuffer& other) {
        capacity=other.capacity;
        data=new T[capacity];
        size=other.size;
        frontIndex=0;
        for (std::size_t i=0;i<size;i++) {
            if (i+other.frontIndex>=capacity)
                data[i]=other.data[i+other.frontIndex-capacity];
            else
                data[i]=other.data[i+other.frontIndex];
        }
    }

    CircularBuffer(CircularBuffer&& other) noexcept {
        capacity=other.capacity;
        size=other.size;
        frontIndex=other.frontIndex;
        data=other.data;
        other.capacity=0;
        other.size=0;
        other.frontIndex=0;
        other.data=nullptr;
    }

    CircularBuffer& operator=(const CircularBuffer& other) {
        if (this==&other)
            return *this;
        delete[] data;
        capacity=other.capacity;
        data=new T[capacity];
        size=other.size;
        frontIndex=0;
        for (std::size_t i=0;i<size;i++) {
            if (i+other.frontIndex>=capacity)
                data[i]=other.data[i+other.frontIndex-capacity];
            else
                data[i]=other.data[i+other.frontIndex];
        }
        return *this;
    }

    CircularBuffer& operator=(CircularBuffer&& other)  noexcept {
        if (this==&other)
            return *this;
        capacity=other.capacity;
        size=other.size;
        frontIndex=other.frontIndex;
        data=other.data;
        other.capacity=0;
        other.size=0;
        other.frontIndex=0;
        other.data=nullptr;
        return *this;
    }

    void addFront(const T& item) {
        if (size==capacity)
            increaseSize();
        long newFront = frontIndex-1;
        if (newFront==-1)
            newFront=capacity-1;

        data[newFront] = item;
        frontIndex=newFront;
        size++;
    }
    void addBack(const T& item) {
        if (size==capacity)
            increaseSize();
        std::size_t newBack = frontIndex+size;
        if (newBack>capacity)
            newBack=0;

        data[newBack] = item;
        size++;
    }


    void removeBack() {
        if (size==0)
            throw std::runtime_error("tried to remove from an empty buffer");
        size--;
    }
    void removeFront() {
        if (size==0)
            throw std::runtime_error("tried to remove from an empty buffer");
        frontIndex++;
        if (frontIndex>=capacity)
            frontIndex=0;
        size--;
    }


    const T& front() const {
        if (size==0)
            throw std::runtime_error("tried to access an empty buffer");
        return data[frontIndex];
    }
    const T& back() const {
        if (size==0)
            throw std::runtime_error("tried to access an empty buffer");
        if (frontIndex+size>=capacity)
            return data[frontIndex+size-capacity-1];
        return data[frontIndex+size-1];
    }


    [[nodiscard]] std::size_t getSize() const {
        return size;
    }
    [[nodiscard]] std::size_t getCapacity() const {
        return capacity;
    }
    T* getData() {
        return data;
    }

    void printData() {
        std::cout<<"{ ";
        for (std::size_t i=0; i<size;i++) {
            if (i+frontIndex>=capacity)
                std::cout<<data[i+frontIndex-capacity]<<" ";
            else
                std::cout<<data[i+frontIndex]<< " ";
        }
        std::cout<< "}"<<std::endl;
    }


    ~CircularBuffer() {
        delete[] data;
    }
private:
    T* data;
    std::size_t capacity;
    std::size_t size;
    std::size_t frontIndex;
    static constexpr size_t scale_factor_ = 2;

    void increaseSize() {
        T* temp=new T[capacity*scale_factor_];
        for (std::size_t i=0;i<capacity;i++) {
            if (i+frontIndex>=capacity)
                temp[i]=data[i+frontIndex-capacity];
            else
                temp[i]=data[i+frontIndex];
        }
        frontIndex=0;
        capacity = capacity*scale_factor_;
        delete[] data;
        data=temp;
    }
};
