#include <arrayd/arrayd.hpp>
#include <stdexcept>
#include <cstddef>
#include <cstring>
#include <algorithm>

ArrayD::ArrayD(const std::ptrdiff_t size)
    : size_of_array_(size)
    , size_of_memory_(size) {
    if (size <= 0) {
        throw std::invalid_argument("ArrayD::ArrayD - non positive size");
    }
    data_pointer_ = new double[size_of_memory_]{0.0};
}

ArrayD::ArrayD(const ArrayD& array)
    : size_of_array_(array.size_of_array_)
    , size_of_memory_(array.size_of_array_)
    , data_pointer_(new double[size_of_array_]) {
    std::memcpy(data_pointer_, array.data_pointer_, size_of_array_ * sizeof(*data_pointer_));
}

ArrayD::~ArrayD() {
    delete[] data_pointer_;
}

ArrayD& ArrayD::operator=(const ArrayD& array) {
    if (this != &array) {
        Resize(array.size_of_array_);
        std::memcpy(data_pointer_, array.data_pointer_, size_of_array_ * sizeof(*data_pointer_));
    }
    return *this;
}

double& ArrayD::operator[](const std::ptrdiff_t position) {
    if (position < 0 || position >= size_of_array_) {
        throw std::out_of_range("Index out of range");
    }
    return *(data_pointer_ + position);
}

double ArrayD::operator[](const std::ptrdiff_t position) const {
    if (position < 0 || position >= size_of_array_) {
        throw std::out_of_range("Index out of range");
    }
    return data_pointer_[position];
}

std::ptrdiff_t ArrayD::Size() const noexcept {
    return size_of_array_;
}

void ArrayD::Resize(const std::ptrdiff_t size) {
    if (size < 0) {
        throw std::invalid_argument("ArrayD::Resize - non positive size");
    }
    if (size_of_memory_ < size) {
        auto data = new double[size]{0.0};
        if (0 < size) {
            std::memcpy(data, data_pointer_, size_of_array_ * sizeof(*data_pointer_));
        }
        std::swap(data_pointer_, data);
        delete[] data;
        size_of_memory_ = size;
    } else {
        if (size_of_array_ < size) {
            std::memset(data_pointer_ + size_of_array_, 0, (size - size_of_array_) * sizeof(*data_pointer_));
        }
    }
    size_of_array_ = size;
}

void ArrayD::Remove(const std::ptrdiff_t position) {
    if (position < 0 || position >= size_of_array_) {
        throw std::out_of_range("Index out of range");
    }
    if (position != size_of_array_ - 1) {
        std::memmove(data_pointer_ + position, data_pointer_ + position + 1, (size_of_array_ - position) * sizeof(double));
    }
    Resize(size_of_array_ - 1);
}

void ArrayD::Insert(const std::ptrdiff_t position, const double value) {
    if (position < 0 || position > size_of_array_) {
        throw std::out_of_range("Index out of range");
    }
    Resize(size_of_array_ + 1);
    if (position != Size() - 1) {
        std::memmove(data_pointer_ + position + 1, data_pointer_ + position, (size_of_array_ - position - 1) * sizeof(double));
    }
    data_pointer_[position] = value;
}
