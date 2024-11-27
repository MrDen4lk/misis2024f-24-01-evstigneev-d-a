#include <arrayd/arrayd.hpp>
#include <algorithm>
#include <stdexcept>
#include <iterator>
#include <iostream>

ArrayD::ArrayD(const ptrdiff_t size, const double value) {
    size_of_array_ = size;
    size_of_memory_ = size;
    data_pointer_ = ((size != 0) ? new double[size] : nullptr);

    for (int32_t i = 0; i < size; i++) {
        data_pointer_[i] = value;
    }
}

ArrayD::ArrayD(const ArrayD &vec) {
    size_of_array_ = vec.size_of_array_;
    size_of_memory_ = vec.size_of_memory_;
    data_pointer_ = ((size_of_memory_ != 0) ? new double[size_of_memory_] : nullptr);
    for (int32_t i = 0; i < size_of_memory_; i++) {
        data_pointer_[i] = vec.data_pointer_[i];
    }
}

ArrayD::~ArrayD() {
    delete [] data_pointer_;
}

ArrayD &ArrayD::Resize_memory() noexcept {
    if (size_of_array_ < size_of_memory_ / 4 && size_of_array_ <= size_of_memory_ / 2) {
        size_of_memory_ /= 2;
        double* new_data_pointer = new double[size_of_memory_];
        for (ptrdiff_t i = 0; i < size_of_array_; i++) {
            new_data_pointer[i] = data_pointer_[i];
        }

        delete [] data_pointer_;
        data_pointer_ = new_data_pointer;
    }
    return *this;
}

double& ArrayD::operator[](ptrdiff_t position) {
    if (position < 0 || position >= size_of_array_) {
        throw std::out_of_range("Index out of range");
    }
    return data_pointer_[position];
}

double ArrayD::operator[](ptrdiff_t position) const {
    if (position < 0 || position >= size_of_array_) {
        throw std::out_of_range("Index out of range");
    }
    return data_pointer_[position];
}


ptrdiff_t ArrayD::Size() const noexcept {
    return size_of_array_;
}

bool ArrayD::Empty() const noexcept {
    return (size_of_array_ == 0);
}

ArrayD& ArrayD::Push_back(const double &value) noexcept {
    Resize(size_of_array_ + 1);
    data_pointer_[size_of_array_ - 1] = value;

    return *this;
}

ArrayD &ArrayD::Resize(const ptrdiff_t size, const double value) {
    if (size_of_memory_ < size) {
        const int new_size_of_memory = std::max(size, size_of_memory_ * 2);
        double* new_data_pointer = new double[new_size_of_memory];

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

double& ArrayD::Back() const noexcept {
    return data_pointer_[size_of_array_ - 1];
}

double& ArrayD::Front() const noexcept {
    return data_pointer_[0];
}

ptrdiff_t ArrayD::Capacity() const noexcept {
    return size_of_memory_;
}

ArrayD& ArrayD::Clear() noexcept {
    delete [] data_pointer_;
    data_pointer_ = nullptr;
    size_of_array_ = 0;
    size_of_memory_ = 0;
    return *this;
}

ArrayD &ArrayD::Remove(ptrdiff_t position) {
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

ArrayD &ArrayD::Insert(ptrdiff_t position, double value) {
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

ArrayD &ArrayD::Pop_back() noexcept {
    if (size_of_array_ - 1 >= 0) {
        size_of_array_--;
    } else {
        size_of_array_ = 0;
    }
    Resize_memory();
    return *this;
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

std::ostream& ArrayD::Write(std::ostream& outstream) const noexcept {
    for (int32_t i = 0; i < size_of_array_ - 1; i++) {
        outstream << data_pointer_[i] << ' ';
    }
    outstream << data_pointer_[size_of_array_ - 1];
    return outstream;
}

std::istream &ArrayD::Read(std::istream& instream) noexcept {
    for (int32_t i = 0; i < size_of_array_; i++) {
        instream >> data_pointer_[i];
    }
    return instream;
}