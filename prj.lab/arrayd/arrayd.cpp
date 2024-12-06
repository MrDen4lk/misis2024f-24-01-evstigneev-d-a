#include <arrayd/arrayd.hpp>
#include <stdexcept>
#include <cstddef>
#include <iterator>

ArrayD::ArrayD(const std::ptrdiff_t size, const double value)
    : size_of_array_(size)
    , size_of_memory_(size) {
    if (size <= 0) {
        throw std::invalid_argument("ArrayD::ArrayD - non positive size");
    }
    data_pointer_ = new double[size]{value};
    for (std::ptrdiff_t i = 0; i < size; i++) { data_pointer_[i] = value; }
}

ArrayD::ArrayD(const ArrayD& array)
    : size_of_array_(array.size_of_array_)
    , size_of_memory_(array.size_of_memory_)
    , data_pointer_(new double[size_of_memory_]) {
    std::memcpy(data_pointer_, array.data_pointer_, size_of_array_ * sizeof(*data_pointer_));
}

ArrayD::~ArrayD() {
    delete[] data_pointer_;
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

bool ArrayD::Empty() const noexcept {
    return (size_of_array_ == 0);
}

void ArrayD::Push_back(const double &value) {
    Resize(size_of_array_ + 1);
    data_pointer_[size_of_array_ - 1] = value;
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
            std::memset(data_pointer_ + size, 0, (size - size_of_array_) * sizeof(*data_pointer_));
        }
    }
    size_of_array_ = size;
}

double ArrayD::Back() const {
    if (size_of_memory_ == 0) {
        throw std::out_of_range("No one element in array");
    }
    return data_pointer_[size_of_array_ - 1];
}

double ArrayD::Front() const {
    if (size_of_memory_ == 0) {
        throw std::out_of_range("No one element in array");
    }
    return data_pointer_[0];
}

std::ptrdiff_t ArrayD::Capacity() const noexcept {
    return size_of_memory_;
}

void ArrayD::Clear() noexcept {
    delete[] data_pointer_;
    data_pointer_ = nullptr;
    size_of_array_ = 0;
    size_of_memory_ = 0;
}

void ArrayD::Remove(std::ptrdiff_t position) {
    if (position < 0 || position >= size_of_array_) {
        throw std::out_of_range("Index out of range");
    }
    if (position != size_of_array_ - 1) {
        std::memmove(data_pointer_ + position, data_pointer_ + position + 1, (size_of_array_ - position) * sizeof(double));
    }
    Resize(size_of_array_ - 1);
}

void ArrayD::Insert(std::ptrdiff_t position, double value) {
    if (position < 0 || position >= size_of_array_) {
        throw std::out_of_range("Index out of range");
    }
    Resize(size_of_array_ + 1);
    if (position != Size() - 1) {
        std::memmove(data_pointer_ + position + 1, data_pointer_ + position, (size_of_array_ - position - 1) * sizeof(double));
    }
    data_pointer_[position] = value;
}

void ArrayD::Pop_back() noexcept {
    if (size_of_array_ != 0) {
        Resize(size_of_array_ - 1);
    }
}

double* ArrayD::begin() const noexcept {
    return data_pointer_;
}

std::reverse_iterator<double*> ArrayD::rbegin() const noexcept {
    return std::reverse_iterator<double*>(end());
}

double *ArrayD::end() const noexcept {
    return data_pointer_ + size_of_array_;
}

std::reverse_iterator<double*> ArrayD::rend() const noexcept {
    return std::reverse_iterator<double*>(begin());
}