#include <arrayd/arrayd.hpp>
#include <algorithm>
#include <stdexcept>
#include <iterator>
#include <iostream>

template<class T>
ArrayD<T>::ArrayD(const ptrdiff_t size, const T value) {
    size_of_array_ = size;
    size_of_memory_ = size;
    data_pointer_ = ((size != 0) ? new T[size] : nullptr);

    for (int32_t i = 0; i < size; i++) {
        data_pointer_[i] = value;
    }
}

template<class T>
ArrayD<T>::ArrayD(const ArrayD<T> &vec) {
    size_of_array_ = vec.size_of_array_;
    size_of_memory_ = vec.size_of_memory_;
    data_pointer_ = ((size_of_memory_ != 0) ? new T[size_of_memory_] : nullptr);
    for (int32_t i = 0; i < size_of_memory_; i++) {
        data_pointer_[i] = vec.data_pointer_[i];
    }
}

template<class T>
ArrayD<T>::~ArrayD() {
    delete [] data_pointer_;
}

template<class T>
ArrayD<T> &ArrayD<T>::Resize_memory() noexcept {
    if (size_of_array_ < size_of_memory_ / 4 && size_of_array_ <= size_of_memory_ / 2) {
        size_of_memory_ /= 2;
        T* new_data_pointer = new T[size_of_memory_];
        for (ptrdiff_t i = 0; i < size_of_array_; i++) {
            new_data_pointer[i] = data_pointer_[i];
        }

        delete [] data_pointer_;
        data_pointer_ = new_data_pointer;
    }
    return *this;
}


template<class T>
T& ArrayD<T>::operator[](ptrdiff_t position) {
    if (position < 0 || position >= size_of_array_) {
        throw std::out_of_range("Index out of range");
    }
    return data_pointer_[position];
}

template<class T>
T ArrayD<T>::operator[](ptrdiff_t position) const {
    if (position < 0 || position >= size_of_array_) {
        throw std::out_of_range("Index out of range");
    }
    return *data_pointer_[position];
}


template<class T>
ptrdiff_t ArrayD<T>::Size() const noexcept {
    return size_of_array_;
}

template<class T>
bool ArrayD<T>::Empty() const noexcept {
    return (size_of_array_ == 0);
}


template<class T>
ArrayD<T>& ArrayD<T>::Push_back(const T &value) noexcept {
    Resize(size_of_array_ + 1);
    data_pointer_[size_of_array_ - 1] = value;

    return *this;
}

template<class T>
ArrayD<T> &ArrayD<T>::Resize(const ptrdiff_t size, const T value) {
    if (size_of_memory_ < size) {
        const int new_size_of_memory = std::max(size, size_of_memory_ * 2);
        T* new_data_pointer = new T[new_size_of_memory];

        for (ptrdiff_t i = 0; i < size_of_array_; i++) {
            new_data_pointer[i] = data_pointer_[i];
        }
        for (ptrdiff_t i = size_of_array_; i < new_size_of_memory; i++) {
            new_data_pointer[i] = value;
        }

        delete [] data_pointer_;
        data_pointer_ = new_data_pointer;
        size_of_memory_ = new_size_of_memory;
    }
    size_of_array_ = size;
    return *this;
}

template<class T>
T& ArrayD<T>::Back() const noexcept {
    return data_pointer_[size_of_array_ - 1];
}

template<class T>
T& ArrayD<T>::Front() const noexcept {
    return data_pointer_[0];
}

template<class T>
ptrdiff_t ArrayD<T>::Capacity() const noexcept {
    return size_of_memory_;
}

template<class T>
ArrayD<T>& ArrayD<T>::Clear() noexcept {
    delete [] data_pointer_;
    data_pointer_ = nullptr;
    size_of_array_ = 0;
    size_of_memory_ = 0;
    return *this;
}

template<class T>
ArrayD<T> &ArrayD<T>::Erase(ptrdiff_t position) {
    if (position < 0 || position >= size_of_array_) {
        throw std::out_of_range("Index out of range");
    }

    for (ptrdiff_t i = position; i < size_of_array_ - 1; i++) {
        data_pointer_[i] = data_pointer_[i + 1];
    }
    if (size_of_array_ - 1 >= 0) {
        size_of_array_--;
    } else {
        size_of_array_ = 0;
    }
    Resize_memory();

    return *this;
}

template<class T>
ArrayD<T> &ArrayD<T>::Insert(ptrdiff_t position, T value) {
    if (position < 0 || position >= size_of_array_) {
        throw std::out_of_range("Index out of range");
    }
    Resize(size_of_array_ + 1);
    for (ptrdiff_t i = size_of_array_ - 1; i > position; i--) {
        data_pointer_[i] = data_pointer_[i - 1];
    }
    data_pointer_[position] = value;

    return *this;
}

template<class T>
ArrayD<T> &ArrayD<T>::Pop_back() noexcept {
    if (size_of_array_ - 1 >= 0) {
        size_of_array_--;
    } else {
        size_of_array_ = 0;
    }
    Resize_memory();
    return *this;
}


template<class T>
T* ArrayD<T>::begin() const noexcept {
    return data_pointer_;
}

template<class T>
std::reverse_iterator<T *> ArrayD<T>::rbegin() const noexcept {
    return std::reverse_iterator<T*>(end());
}

template<class T>
T *ArrayD<T>::end() const noexcept {
    return data_pointer_ + size_of_array_;
}

template<class T>
std::reverse_iterator<T *> ArrayD<T>::rend() const noexcept {
    return std::reverse_iterator<T*>(begin());
}

template<class T>
std::ostream& ArrayD<T>::Write(std::ostream& outstream) const noexcept {
    for (int32_t i = 0; i < size_of_array_ - 1; i++) {
        outstream << data_pointer_[i] << ' ';
    }
    outstream << data_pointer_[size_of_array_ - 1];
    return outstream;
}

template<class T>
std::istream &ArrayD<T>::Read(std::istream& instream) noexcept {
    for (int32_t i = 0; i < size_of_array_; i++) {
        instream >> data_pointer_[i];
    }
    return instream;
}