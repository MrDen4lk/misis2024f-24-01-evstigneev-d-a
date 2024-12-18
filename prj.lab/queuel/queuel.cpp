#include <queuel/queuel.hpp>

//QueueL::QueueL(const QueueL &src) {}

//QueueL::QueueL(QueueL &&src) noexcept {}

//QueueL& QueueL::operator=(const QueueL &src) {}

//QueueL& QueueL::operator=(QueueL &&src) noexcept {}

QueueL::~QueueL() {
    delete head_;
}

bool QueueL::IsEmpty() const noexcept {
    return (head_ == nullptr);
}

void QueueL::Push(const T value) {
    const auto tmp = new Node(value);
    if (IsEmpty()) {
        head_ = tmp;
        tail_ = tmp;
    } else {
        tail_->next_ = tmp;
        tail_ = tmp;
    }
}

void QueueL::Pop() noexcept {
    if (head_ != nullptr) {
        head_ = head_->next_;
    }
}

void QueueL::Clear() noexcept {
    while (!IsEmpty()) {
        Pop();
    }
}

QueueL::T &QueueL::Top() {
    if (IsEmpty()) {
        throw std::logic_error("QueueL is empty");
    }
    return head_->value_;
}

const QueueL::T &QueueL::Top() const {
    if (IsEmpty()) {
        throw std::logic_error("QueueL is empty");
    }
    return head_->value_;
}
