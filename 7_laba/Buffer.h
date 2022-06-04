#pragma once
#include <iostream>

template<typename T>
class RingBuffer {
private:
    unsigned int size_ = 0, capacity_ = 0, insert_next = 0;
    T* buffer;

public:

    class MyIterator : public std::iterator<std::random_access_iterator_tag, T> {
    private:
        T* iterator_;
    public:
        explicit MyIterator(T* iterat_) : iterator_(iterat_) {}

        T& operator*() {
            return *iterator_;
        }

        T* operator->() {
            return iterator_;
        }


        MyIterator& operator++() {
            iterator_++;
            return *this;
        }

        MyIterator& operator--() {
            iterator_--;
            return *this;
        }

        MyIterator operator++(T) {
            ++iterator_;
            return *this;
        }

        MyIterator operator--(T) {
            --iterator_;
            return *this;
        }

        bool operator==(const MyIterator& iterat_) {
            return iterator_ == iterat_.iterator_;
        }
        bool operator!=(const MyIterator& iterat_) {
            return iterator_ != iterat_.iterator_;
        }
        bool operator>(const MyIterator& iterat_) {
            return iterator_ > iterat_.iterator_;
        }
        bool operator<(const MyIterator& iterat_) {
            return iterator_ < iterat_.iterator_;
        }

        using iterat_type = typename std::iterator<std::random_access_iterator_tag, T>::value_type;
        iterat_type operator-(const MyIterator& itr) {
            return iterator_ - itr.iterator_;
        }
        MyIterator operator+(iterat_type iterat_) {
            MyIterator itr(iterator_ + iterat_);
            return itr;
        }
        MyIterator operator-(iterat_type iterat_) {
            MyIterator itr(iterator_ - iterat_);
            return itr;
        }

    };

    RingBuffer() = default;

    explicit RingBuffer(unsigned int size) : capacity_(size) {
        buffer = new T[capacity_];
    }

    ~RingBuffer() {
        delete[] buffer;
    }

    void resize(unsigned size_) {
        if (this->capacity_ < size_) {
            T* buffer_new = new T[size_];
            for (unsigned int i = 0; i < this->size_; i++) {
                buffer_new[i] = buffer[i];
            }
            *buffer = *buffer_new;
            capacity_ = size_;

        }

    }

    void reserve(unsigned size) {
        if (!capacity_) {
            buffer = new T[size];
            capacity_ = size;
        }
    }


    unsigned size() {
        return size_;
    }

    unsigned capacity() {
        return capacity_;
    }

    void add(T value_) {
        if (insert_next >= capacity_) {
            insert_next = 0;
        }

        buffer[insert_next] = value_;
        insert_next++;
        if (size_ != capacity_) size_++;


    }

    void add_begin(T value_) {

        if (size_ != capacity_) {
            size_++;
            insert_next = size_;
        }

        for (MyIterator itr = end(); itr != begin(); itr--) {
            *itr = *(itr - 1);
        }
        *begin() = value_;

    }

    void add_end(T value_) {
        if (size_ == capacity_) {
            for (size_t i = 0; i < size_ - 1; i++) {
                buffer[i] = buffer[i + 1];
            }
        }

        else {
            insert_next++;
            size_++;

        }
        buffer[size_ - 1] = value_;

    };

    void add_element(unsigned int n, T value_) {
        if (n > capacity_ - 1)
            throw MyException("this index cannot be used");

        if (size_ != capacity_) {
            size_++;
            insert_next = size_;
        }

        for (unsigned int i = size_ - 1; i > n - 1; i--) {
            buffer[i] = buffer[i - 1];
        }
        buffer[n - 1] = value_;


    }

    void delete_start() {
        if (size_) {
            for (MyIterator itr = begin(); itr != end() - 1; itr++) {
                *itr = *(itr + 1);
            }
            insert_next = --size_;
        }
    }

    void delete_end() {
        if (size_) {
            insert_next = --size_;
        }
    }
    T start() {
        if (size_ != 0) return buffer[0];
    }

    T stop() {
        if (size_ != 0) return buffer[size_ - 1];
    }


    T operator[](unsigned n) {
        if (n > size_ - 1)
            throw MyException("this index cannot be used");
        return buffer[n];
    }


    MyIterator begin() {
        return MyIterator(buffer);
    }

    MyIterator end() {
        return MyIterator(buffer + size_);
    }
};
