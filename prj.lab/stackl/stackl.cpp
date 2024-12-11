#include <stackl/stackl.hpp>
#include <cstdint>
#include <memory>
#include <stdexcept>

void StackL::Push(const T value) {
    auto tmp = std::unique_ptr<Node>(new Node(value));
    tmp->next_ = std::move(head_);
    head_ = std::move(tmp);
}

void StackL::Pop() noexcept {
    if (head_ != nullptr) {
        head_ = std::move(head_->next_);
    }
}

StackL::T& StackL::Top() & {
    if (IsEmpty()) {
        throw std::logic_error("StackL - try get top form empty stack.");
    }
    return head_->value_;
}

const StackL::T& StackL::Top() const & {
    if (IsEmpty()) {
        throw std::logic_error("StackL - try get top form empty stack.");
    }
    return head_->value_;
}

void StackL::Clear() noexcept {
    while (!IsEmpty()) {
        Pop();
    }
}

bool StackL::IsEmpty() const noexcept {
    return head_ == nullptr;
}

StackL& StackL::operator=(const StackL& src) {

}

StackL& StackL::operator=(StackL&& src) noexcept {
    std::swap(head_, src.head_);
    return *this;
}

StackL::StackL(const StackL& src) {

}

StackL::StackL(const StackL& src) {

}