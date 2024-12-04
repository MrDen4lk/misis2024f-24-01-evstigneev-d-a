#include <stackl/stackl.hpp>

#include <cstdint>
#include <memory>
#include <stdexcept>

void StackL::Push(const std::uint8_t value) {
    auto tmp = std::unique_ptr<Node>(new Node(value));
    tmp->next_ = std::move(head_);
    head_ = std::move(tmp);
}

void StackL::Pop() noexcept {
    if (head_ != nullptr) {
        head_ = std::move(head_->next_);
    }
}

std::uint8_t& StackL::Top() const {
    if (head_ == nullptr) {
        throw std::invalid_argument("No one element in stack");
    }
    return head_->value_;
}

void StackL::Clear() noexcept {
    head_.reset(nullptr);
}

bool StackL::IsEmpty() const noexcept {
    return head_ == nullptr;
}
