#pragma once

#ifndef ARRAYT_HPP
#define ARRAYT_HPP

#include <memory>
#include <cstddef>
#include <stdexcept>
#include <algorithm>

template<class T>
class ArrayT {
public:
    // умолчательный конструктор
    ArrayT() = default;

    ArrayT(const ArrayT&);

    explicit ArrayT(std::ptrdiff_t size);

    // деструктор
    ~ArrayT() = default;

    // присваивание
    ArrayT& operator=(const ArrayT&);

    // оператор обращения по индексу
    T& operator[](std::ptrdiff_t position);
    const T& operator[](std::ptrdiff_t position) const;

    // количество элементов
    std::ptrdiff_t Size() const noexcept;

    // изменить размер на size и заполнить новые элементы value
    void Resize(std::ptrdiff_t size);

    // получить максимальное количеств элементов, влезающих в текущую память
    std::ptrdiff_t Capacity() const noexcept;

    // вставить на место position значение value
    void Insert(std::ptrdiff_t position, T value);

    // удалить позицию position
    void Remove(std::ptrdiff_t position);

private:
    std::ptrdiff_t size_of_array_{0}; // количество элементов в массиве
    std::ptrdiff_t size_of_memory_{0}; // количество элементов в массиве под которые выделена память
    std::unique_ptr<T[]> data_pointer_; // указатель на выделенную память
};

template<class T>
ArrayT<T>::ArrayT(const ArrayT<T>& array)
    : size_of_array_(array.size_of_array_)
    , size_of_memory_(array.size_of_memory_)
    , data_pointer_(std::make_unique<T[]>(array.size_of_array_)) {
    std::copy(array.data_pointer_.get(), array.data_pointer_.get() + size_of_array_, data_pointer_.get());
}

template<class T>
ArrayT<T>::ArrayT(const std::ptrdiff_t size)
    : size_of_array_(size)
    , size_of_memory_(size) {
    if (size <= 0) {
        throw std::invalid_argument("ArrayD::Resize - non positive size");
    }
    data_pointer_ = std::make_unique<T[]>(size);
}

template<class T>
std::ptrdiff_t ArrayT<T>::Size() const noexcept {
    return size_of_array_;
}

template<class T>
void ArrayT<T>::Resize(std::ptrdiff_t size) {
    if (size < 0) {
        throw std::invalid_argument("ArrayD::Resize - non positive size");
    }
    if (size_of_memory_ < size) {
        auto data = std::make_unique<T[]>(size);
        if (size > 0) {
            std::copy(data_pointer_.get(), data_pointer_.get() + size_of_array_, data.get());
        }
        std::swap(data_pointer_, data);
        size_of_memory_ = size;
    } else {
        if (size_of_array_ < size) {
            std::fill(data_pointer_.get() + size_of_array_, data_pointer_.get() + size, T());
        }
    }
    size_of_array_ = size;
}

template<class T>
void ArrayT<T>::Remove(std::ptrdiff_t position) {
    if (position < 0 || position >= size_of_array_) {
        throw std::out_of_range("Index out of range");
    }
    if (position != size_of_array_ - 1) {
        std::copy(data_pointer_.get() + position + 1,
      data_pointer_.get() + size_of_array_, data_pointer_.get() + position);
    }
    Resize(size_of_array_ - 1);
}

template<class T>
void ArrayT<T>::Insert(std::ptrdiff_t position, T value) {
    if (position < 0 || position > size_of_array_) {
        throw std::out_of_range("Index out of range");
    }
    Resize(size_of_array_ + 1);
    if (position != Size() - 1) {
        std::copy_backward(data_pointer_.get() + position,
      data_pointer_.get() + size_of_array_ - 1, data_pointer_.get() + size_of_array_);
    }
    data_pointer_[position] = value;
}

template<class T>
std::ptrdiff_t ArrayT<T>::Capacity() const noexcept {
    return size_of_memory_;
}

template<class T>
ArrayT<T>& ArrayT<T>::operator=(const ArrayT<T>& rhs) {
    if (this != &rhs) {
        Resize(rhs.size_of_array_);
        std::copy(rhs.data_pointer_.get(), rhs.data_pointer_.get() + size_of_array_, data_pointer_.get());
    }
    return *this;
}

template<class T>
T& ArrayT<T>::operator[](const std::ptrdiff_t position) {
    if (position < 0 || size_of_array_ <= position) {
        throw std::out_of_range("ArrayD::operator[] - invalid argument");
    }
    return *(data_pointer_.get() + position);
}

template<class T>
const T& ArrayT<T>::operator[](const std::ptrdiff_t position) const {
    if (position < 0 || size_of_array_ <= position) {
        throw std::out_of_range("ArrayD::operator[] - invalid argument");
    }
    return *(data_pointer_.get() + position);
}

#endif //ARRAYT_HPP