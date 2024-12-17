#include <queuea/queuea.hpp>
#include <cstdint>
#include <cstddef>
#include <memory>
#include <algorithm>

void QueueA::Resize() {
    if (data_ == nullptr) {
        capacity_ = 2;
        data_ = std::make_unique<T[]>(capacity_);
        return;
    }
    if (head_ == (tail_ + 1) % capacity_) {
        auto tmp = std::make_unique<T[]>(capacity_ * 2);
        std::swap(tmp, data_);
        if (head_ < tail_) {
            std::copy(tmp.get() + head_, tmp.get() + tail_ + 1, data_.get());
        } else {
            std::copy(tmp.get() + head_, tmp.get() + capacity_, data_.get());
            std::copy(tmp.get(), tmp.get() + tail_ + 1, data_.get() + tail_ - head_);
        }
        capacity_ *= 2;
    }
}

void QueueA::Resize_up(const std::ptrdiff_t count) {
    capacity_ = (count + 4) / 4 * 4;
    data_ = std::make_unique<T[]>(capacity_);
}

void QueueA::Swap(QueueA&& src) noexcept {
    std::swap(capacity_, src.capacity_);
    std::swap(data_, src.data_);
    std::swap(head_, src.head_);
    std::swap(tail_, src.tail_);
}

void QueueA::Push(const T value) {
    Resize();
    if (IsEmpty()) {
        head_ = 0;
        tail_ = 0;
        data_[tail_] = value;
        return;
    }
    if (head_ == (tail_ + 1) % capacity_) {
        tail_ = (tail_ + capacity_ - head_) % capacity_ + 1;
    } else {
        tail_ = (tail_ + 1) % capacity_;
    }
    data_[tail_] = value;
}

void QueueA::Pop() noexcept {
    if (!IsEmpty()) {
        if (head_ == tail_) {
            head_ = -1;
        } else {
            head_ = (head_ + 1) % capacity_;
        }
    }
}

const QueueA::T& QueueA::Top() const {
    if (IsEmpty()) {
        throw std::logic_error("Queue is empty");
    }
    return data_.get()[head_];
}

QueueA::T& QueueA::Top() {
    if (IsEmpty()) {
        throw std::logic_error("Queue is empty");
    }
    return data_.get()[head_];
}

void QueueA::Clear() noexcept {
    head_ = -1;
    tail_ = -1;
    capacity_ = 0;
    data_.reset(nullptr);
}

bool QueueA::IsEmpty() const noexcept {
    return head_ < 0;
}

QueueA::QueueA(const QueueA& src) {
    if (!src.IsEmpty()) {
        const std::ptrdiff_t count = src.IsEmpty() ? 0 : (src.tail_ + src.capacity_ - src.head_) % src.capacity_ + 1;
        head_ = 0;
        tail_ = count - 1;
        Resize_up(count);
        if (src.head_ < src.tail_) {
            std::copy(src.data_.get() + src.head_, src.data_.get() + src.tail_ + 1, data_.get());
        } else {
            std::copy(src.data_.get() + src.head_, src.data_.get() + src.capacity_, data_.get());
            std::copy(src.data_.get(), src.data_.get() + src.tail_ + 1, data_.get() + src.capacity_ - src.head_);
        }
    }
}

QueueA::QueueA(QueueA&& src) noexcept {
    Swap(std::move(src));
}

QueueA& QueueA::operator=(const QueueA& src) {
    if (this != &src) {
        Clear();
        Resize();
        if (!src.IsEmpty()) {
            const std::ptrdiff_t count = src.IsEmpty() ? 0 : (src.tail_ + src.capacity_ - src.head_) % src.capacity_ + 1;
            head_ = 0;
            tail_ = count - 1;
            Resize_up(count);
            if (src.head_ < src.tail_) {
                std::copy(src.data_.get() + src.head_, src.data_.get() + src.tail_ + 1, data_.get());
            } else {
                std::copy(src.data_.get() + src.head_, src.data_.get() + src.capacity_, data_.get());
                std::copy(src.data_.get(), src.data_.get() + src.tail_ + 1, data_.get() + src.capacity_ - src.head_);
            }
        }
    }
    return *this;
}

QueueA& QueueA::operator=(QueueA&& src) {
    if (this != &src) {
        Swap(std::move(src));
    }
    return *this;
}