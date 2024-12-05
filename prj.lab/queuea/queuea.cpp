#include <queuea/queuea.hpp>

#include <cstdint>
#include <cstddef>
#include <iostream>
#include <memory>
#include <ostream>

void QueueA::Resize() {
    if (tail_ + 1 == head_ && capacity_ != 0) {
        return;
    }

    std::unique_ptr<std::uint8_t[]> temp(new std::uint8_t[(capacity_ == 0 ? 2 : capacity_ * 2)]{0});
    for (std::ptrdiff_t i = head_; i < capacity_; i++) {
        temp.get()[i - head_] = data_.get()[i];
    }
    for (std::ptrdiff_t i = 0; i < head_; i++) {
        temp.get()[i + head_] = data_.get()[i];
    }
    head_ = 0;
    tail_ = capacity_;
    capacity_ = (capacity_ == 0 ? 2 : capacity_ * 2);
    data_ = std::move(temp);
}


void QueueA::Push(const std::uint8_t value) {
    Resize();
    data_.get()[tail_] = value;
    tail_ = (tail_ + 1) % capacity_;
}

void QueueA::Pop() noexcept {
    head_ = (head_ + 1) % capacity_;
}

std::uint8_t& QueueA::Top() const {
    return data_.get()[head_];
}

void QueueA::Clear() noexcept {
    data_.reset(nullptr);
    head_ = 0;
    tail_ = 0;
}

bool QueueA::IsEmpty() const noexcept {
    return head_ == tail_;
}