#include <stackl/stackl.hpp>
#include <stdexcept>
#include <memory>
#include <algorithm>

void StackL::Push(const T value) {
    auto tmp = std::make_unique<Node>(value);
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
	    Clear();
	    if (!src.IsEmpty()) {
	        head_ = std::make_unique<Node>(src.head_->value_);
	        Node* prev_src = src.head_.get();
	        Node* prev_new = head_.get();
	        while (prev_src->next_) {
	            prev_new->next_ = std::make_unique<Node>(prev_src->next_->value_);
	            prev_new = prev_new->next_.get();
	            prev_src = prev_src->next_.get();
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
    if (!src.IsEmpty()) {
        head_ = std::make_unique<Node>(src.head_->value_);
        Node* prev_src = src.head_.get();
        Node* prev_new = head_.get();
        while (prev_src->next_) {
        	prev_new->next_ = std::make_unique<Node>(prev_src->next_->value_);
            prev_new = prev_new->next_.get();
            prev_src = prev_src->next_.get();
        }
    }
}

StackL::StackL(StackL&& src) noexcept {
    std::swap(head_, src.head_);
}