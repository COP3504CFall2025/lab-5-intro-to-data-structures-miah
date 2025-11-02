#pragma once
#include <cstddef>

template <typename T>
class CircularBuffer {
public:
    explicit CircularBuffer(const std::size_t cap = 0) : data(new T[cap]), capacity(cap), size(0), frontIndex(0) {}

    CircularBuffer(const CircularBuffer& other) {
        capacity=other.capacity;
        data=new T[capacity];
        size=other.size;
        frontIndex=0;
        for (int i=0;i<capacity;i++) {
            if (i+other.frontIndex>=capacity)
                data[i]=other.data[i-capacity];
            else
                data[i]=other.data[i];
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
        deleteContents();
        delete[] data;
        capacity=other.capacity;
        data=new T[capacity];
        size=other.size;
        frontIndex=0;
        for (int i=0;i<capacity;i++) {
            if (i+other.frontIndex>=capacity)
                data[i]=other.data[i-capacity];
            else
                data[i]=other.data[i];
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
        if (newFront<0)
            newFront=size-1;

        data[newFront] = item;
        frontIndex=newFront;
    }
    void addBack(const T& item) {
        if (size==capacity)
            increaseSize();
        std::size_t newFront = frontIndex+size;
        if (newFront>capacity)
            newFront=0;

        data[newFront] = item;
        frontIndex=newFront;
    }


    void removeBack() {
        size--;
    }
    void removeFront() {
        frontIndex++;
        if (frontIndex>=capacity)
            frontIndex=0;
    }


    const T& front() const {
        return data[frontIndex];
    }
    const T& back() const {
        return data[frontIndex+size-1];
    }


    std::size_t getSize() const {
        return size;
    }
    std::size_t getCapacity() const {
        return capacity;
    }
    T* getData() {
        return data;
    }


    ~CircularBuffer() {
        deleteContents();
        delete data;
    }
private:
    T* data;
    std::size_t capacity;
    std::size_t size;
    std::size_t frontIndex;
    static constexpr size_t scale_factor_ = 2;

    void increaseSize() {
        T* temp=new T[capacity*scale_factor_];
        for (int i=0;i<capacity;i++) {
            if (i+frontIndex>=capacity)
                temp[i]=data[i-capacity];
            else
                temp[i]=data[i];
        }
        frontIndex=0;
        capacity*=2;
        deleteContents();
        delete[] data;
        data=temp;
    }
    void deleteContents() {
        for (int i=0; i < capacity; i++) {
            delete data[i];
        }
    }
};
