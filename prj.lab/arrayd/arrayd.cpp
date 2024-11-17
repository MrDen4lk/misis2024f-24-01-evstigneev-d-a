#include <arrayd/arrayd.hpp>
#include <algorithm>
#include <stdexcept>
#include <iterator>
#include <iostream>

template<class T>
ArrayD<T>::ArrayD(const int32_t size, const T value) {
    size_of_array = size;
    size_of_memory = size;
    data_pointer = ((size != 0) ? new T[size] : nullptr);

    for (int32_t i = 0; i < size; i++) {
        data_pointer[i] = value;
    }
}

template<class T>
ArrayD<T>::ArrayD(const ArrayD<T> &vec) {
    size_of_array = vec.size_of_array;
    size_of_memory = vec.size_of_memory;
    data_pointer = ((size_of_memory != 0) ? new T[size_of_memory] : nullptr);
    for (int32_t i = 0; i < size_of_memory; i++) {
        data_pointer[i] = vec.data_pointer[i];
    }
}

template<class T>
ArrayD<T>::~ArrayD() {
    delete [] data_pointer;
}

template<class T>
ArrayD<T> &ArrayD<T>::resize_memory() noexcept {
    if (size_of_array < size_of_memory / 4 && size_of_array <= size_of_memory / 2) {
        size_of_memory /= 2;
        T* new_data_pointer = new T[size_of_memory];
        for (int32_t i = 0; i < size_of_array; i++) {
            new_data_pointer[i] = data_pointer[i];
        }

        delete [] data_pointer;
        data_pointer = new_data_pointer;
    }
    return *this;
}


template<class T>
T& ArrayD<T>::operator[](int32_t position) {
    if (position < 0 || position >= size_of_array) {
        throw std::out_of_range("Index out of range");
    }
    return data_pointer[position];
}

template<class T>
int32_t ArrayD<T>::size() const noexcept {
    return size_of_array;
}

template<class T>
bool ArrayD<T>::empty() const noexcept {
    return (size_of_array == 0);
}


template<class T>
ArrayD<T>& ArrayD<T>::push_back(const T &value) noexcept {
    resize(size_of_array + 1);
    data_pointer[size_of_array - 1] = value;

    return *this;
}

template<class T>
ArrayD<T> &ArrayD<T>::resize(const int32_t size, const T value) {
    if (size_of_memory < size) {
        const int new_size_of_memory = std::max(size, size_of_memory * 2);
        T* new_data_pointer = new T[new_size_of_memory];

        for (int32_t i = 0; i < size_of_array; i++) {
            new_data_pointer[i] = data_pointer[i];
        }
        for (int32_t i = size_of_array; i < new_size_of_memory; i++) {
            new_data_pointer[i] = value;
        }

        delete [] data_pointer;
        data_pointer = new_data_pointer;
        size_of_memory = new_size_of_memory;
    }
    size_of_array = size;
    return *this;
}

template<class T>
T& ArrayD<T>::back() const noexcept {
    return data_pointer[size_of_array - 1];
}

template<class T>
T& ArrayD<T>::front() const noexcept {
    return data_pointer[0];
}

template<class T>
int32_t ArrayD<T>::capacity() const noexcept {
    return size_of_memory;
}

template<class T>
ArrayD<T>& ArrayD<T>::clear() noexcept {
    delete [] data_pointer;
    data_pointer = nullptr;
    size_of_array = 0;
    size_of_memory = 0;
    return *this;
}

template<class T>
ArrayD<T> &ArrayD<T>::erase(int32_t position) {
    if (position < 0 || position >= size_of_array) {
        throw std::out_of_range("Index out of range");
    }

    for (int32_t i = position; i < size_of_array - 1; i++) {
        data_pointer[i] = data_pointer[i + 1];
    }
    size_of_array = std::max(0, size_of_array - 1);
    resize_memory();

    return *this;
}

template<class T>
ArrayD<T> &ArrayD<T>::insert(int32_t position, T value) {
    if (position < 0 || position >= size_of_array) {
        throw std::out_of_range("Index out of range");
    }
    resize(size_of_array + 1);
    for (int32_t i = size_of_array - 1; i > position; i--) {
        data_pointer[i] = data_pointer[i - 1];
    }
    data_pointer[position] = value;

    return *this;
}

template<class T>
ArrayD<T> &ArrayD<T>::pop_back() noexcept {
    size_of_array = std::max(0, size_of_array - 1);
    resize_memory();
    return *this;
}


template<class T>
T* ArrayD<T>::begin() const noexcept {
    return data_pointer;
}

template<class T>
std::reverse_iterator<T *> ArrayD<T>::rbegin() const noexcept {
    return std::reverse_iterator<T*>(end());
}

template<class T>
T *ArrayD<T>::end() const noexcept {
    return data_pointer + size_of_array;
}

template<class T>
std::reverse_iterator<T *> ArrayD<T>::rend() const noexcept {
    return std::reverse_iterator<T*>(begin());
}

template<class T>
std::ostream& ArrayD<T>::write(std::ostream& outstream) const noexcept {
    for (int32_t i = 0; i < size_of_array - 1; i++) {
        outstream << data_pointer[i] << ' ';
    }
    outstream << data_pointer[size_of_array - 1];
    return outstream;
}

template<class T>
std::istream &ArrayD<T>::read(std::istream& instream) noexcept {
    for (int32_t i = 0; i < size_of_array; i++) {
        instream >> data_pointer[i];
    }
    return instream;
}