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
    if (this != &src) {
        if (src.IsEmpty()) {
            Clear();
        } else {
            std::unique_ptr<Node> p_src = std::move(head_);
            if (IsEmpty()) {
                head_.reset(new Node(src.head_->value_));
            } else {
                head_->value_ = src.head_->value_;
            }
            std::unique_ptr<Node> p_dst = std::move(head_);
            while (p_src->next_) {
                if (p_dst->next_) {
                    p_dst->next_->value_ = p_src->next_->value_;
                } else {
                    p_dst->next_.reset(new Node(p_src->next_->value_));
                }
                p_src = std::move(p_src->next_);
                p_dst = std::move(p_dst->next_);
            }
            if (p_dst->next_) {
                std::unique_ptr<Node> tail = std::move(p_dst->next_->next_);
                while (p_dst->next_) {
                    delete p_dst->next_;
                    p_dst->next_ = nullptr;
                    p_dst = std::move(tail);
                }
            }
        }
    }

    return *this;
}

StackL& StackL::operator=(StackL&& src) noexcept {
    std::swap(head_, src.head_);
    return *this;
}

StackL::StackL(const StackL& src) {

}

StackL::StackL(const StackL& src) {

}