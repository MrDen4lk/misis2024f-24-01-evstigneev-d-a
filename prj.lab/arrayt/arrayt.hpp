#pragma once

#ifndef ARRAYT_HPP
#define ARRAYT_HPP

#include <cstddef>
#include <memory>
#include <stdexcept>

template<class T>
class ArrayT {
private:
    std::ptrdiff_t size_of_array_{0}; // количество элементов в массиве
    std::ptrdiff_t size_of_memory_{0}; // количество элементов в массиве под которые выделена память
    std::unique_ptr<T[]> data_pointer_; // указатель на выделенную память
public:
    // умолчательный конструктор
    ArrayT() = default;

    ArrayT(const ArrayT&);

    explicit ArrayT(std::ptrdiff_t size = 0);

    // деструктор
    ~ArrayT() = default;

    // присваивание
    ArrayT& operator=(const ArrayT&);

    // оператор обращения по индексу
    T& operator[](std::ptrdiff_t position);
    T operator[](std::ptrdiff_t position) const;

    // количество элементов
    std::ptrdiff_t Size() const noexcept;

    // проверка на пустоту
    bool Empty() const noexcept;

    // изменить размер на size и заполнить новые элементы value
    void Resize(std::ptrdiff_t size);

    // добавить в конец value
    void Push_back(const T& value) noexcept;

    // получить значение последнего элементы
    T Back() const noexcept;

    // получить значение первого элемента
    T Front() const noexcept;

    // получить максимальное количеств элементов, влезающих в текущую память
    std::ptrdiff_t Capacity() const noexcept;

    // вставить на место position значение value
    void Insert(std::ptrdiff_t position, T value);

    // удалить позицию position
    void Remove(std::ptrdiff_t position);

    // удалить последний элемент
    void Pop_back() noexcept;
};

template<class T>
ArrayT<T>::ArrayT(const ArrayT<T>& array)
    : size_of_array_(array.size_of_array_)
    , size_of_memory_(array.size_of_memory_) {
    data_pointer_.reset(new T[size_of_memory_]{T()});
    std::copy(array.data_pointer_.get(), array.data_pointer_.get() + size_of_array_, data_pointer_.get());
}

template<class T>
ArrayT<T>::ArrayT(std::ptrdiff_t size)
    : size_of_array_(size)
    , size_of_memory_(size) {
    data_pointer_.reset(new T[size]{T()});
}

template<class T>
std::ptrdiff_t ArrayT<T>::Size() const noexcept {
    return size_of_array_;
}

template<class T>
bool ArrayT<T>::Empty() const noexcept {
    return size_of_array_ == 0;
}

template<class T>
void ArrayT<T>::Resize(std::ptrdiff_t size) {
    if (size < 0) {
        throw std::invalid_argument("ArrayD::Resize - non positive size");
    }
    if (size_of_memory_ < size) {
        auto data = new T[size]{T()};
        if (0 < size) {
            std::memcpy(data, data_pointer_, size_of_array_ * sizeof(*data_pointer_));
        }
        std::swap(data_pointer_, data);
        delete[] data;
        size_of_memory_ = size;
    } else {
        if (size_of_array_ < size) {
            std::memset(data_pointer_ + size, 0, (size - size_of_array_) * sizeof(*data_pointer_));
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
        std::memmove(data_pointer_ + position, data_pointer_ + position + 1, (size_of_array_ - position) * sizeof(T));
    }
    Resize(size_of_array_ - 1);
}

template<class T>
void ArrayT<T>::Insert(std::ptrdiff_t position, T value) {
    if (position < 0 || position >= size_of_array_) {
        throw std::out_of_range("Index out of range");
    }
    Resize(size_of_array_ + 1);
    if (position != Size() - 1) {
        std::memmove(data_pointer_ + position + 1, data_pointer_ + position, (size_of_array_ - position - 1) * sizeof(T));
    }
    data_pointer_[position] = value;
}

template<class T>
void ArrayT<T>::Pop_back() noexcept {
    Resize(size_of_array_ - 1);
}

template<class T>
void ArrayT<T>::Push_back(const T &value) noexcept {
    Resize(size_of_array_ + 1);
    data_pointer_[size_of_array_ - 1] = value;
}

template<class T>
T ArrayT<T>::Back() const noexcept {
    return data_pointer_.get()[size_of_array_ - 1];
}

template<class T>
T ArrayT<T>::Front() const noexcept {
    return data_pointer_.get()[0];
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
        throw std::invalid_argument("ArrayD::operator[] - invalid argument");
    }
    return *(data_pointer_.get() + position);
}

template<class T>
T ArrayT<T>::operator[](const std::ptrdiff_t position) const {
    if (position < 0 || size_of_array_ <= position) {
        throw std::invalid_argument("ArrayD::operator[] - invalid argument");
    }
    return data_pointer_.get()[position];
}

#endif //ARRAYT_HPP