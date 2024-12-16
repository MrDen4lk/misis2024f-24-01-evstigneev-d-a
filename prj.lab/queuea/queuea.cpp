#include <queuea/queuea.hpp>
#include <cstdint>
#include <cstddef>
#include <memory>

void QueueA::Resize() {
    if (head_ % capacity_ != tail_ % capacity_) {
        return;
    }

    std::unique_ptr<std::uint8_t[]> temp(new T[capacity_ == 0 ? 1 : capacity_ * 2]{T()});
    for (std::ptrdiff_t i = head_; i < capacity_; i++) {
        temp.get()[i - head_] = data_.get()[i];
    }
    for (std::ptrdiff_t i = 0; i < head_; i++) {
        temp.get()[i + head_] = data_.get()[i];
    }
    head_ = 0;
    tail_ = capacity_;
    capacity_ = (capacity_ == 0 ? 1 : capacity_ * 2);
    data_ = std::move(temp);
}


void QueueA::Push(const T value) {
    size_++;
    Resize();
    data_.get()[tail_] = value;
    tail_ = (tail_ + 1) % capacity_;
}

void QueueA::Pop() noexcept {
    if (!IsEmpty()) {
        size_--;
        head_ = (head_ + 1) % capacity_;
    }
}

const QueueA::T& QueueA::Top() const {
    if (IsEmpty()) {
        throw std::logic_error("QueueA - try get top form empty queue.");
    }
    return data_.get()[head_];
}

QueueA::T& QueueA::Top() {
    if (IsEmpty()) {
        throw std::logic_error("QueueA - try get top form empty queue.");
    }
    return data_.get()[head_];
}

void QueueA::Clear() noexcept {
    data_.reset(nullptr);
    std::unique_ptr<T[]> temp(new T[]{T()});
    data_ = std::move(temp);
    capacity_ = 0;
    head_ = 0;
    tail_ = 0;
    size_ = 0;
}

bool QueueA::IsEmpty() const noexcept {
    return size_ == 0;
}

QueueA::QueueA(const QueueA& src) {

}

QueueA::QueueA(QueueA&& src) noexcept {

}

QueueA& QueueA::operator=(const QueueA& src) {

}

QueueA& QueueA::operator=(QueueA&& src) {

}

