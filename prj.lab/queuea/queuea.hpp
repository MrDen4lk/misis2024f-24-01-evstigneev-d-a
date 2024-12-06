#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <cstdint>
#include <cstddef>
#include <memory>

class QueueA {
private:
    std::ptrdiff_t capacity_{0};
    std::ptrdiff_t size_{0};
    std::ptrdiff_t head_{0};
    std::ptrdiff_t tail_{0};
    std::unique_ptr<std::uint8_t[]> data_;

    void Resize();

public:
    // Умолчательный конструктор
    QueueA() = default;

    // Деструктор
    ~QueueA() = default;

    // Добавление элемента в стек
    void Push(std::uint8_t value);

    // Удаление элемента из top
    void Pop() noexcept;

    // Проверка на пустоту
    bool IsEmpty() const noexcept;

    // Очистка всех элементов
    void Clear() noexcept;

    // Получение значения элемента в top
    std::uint8_t& Top() const;
};

#endif //QUEUE_HPP
