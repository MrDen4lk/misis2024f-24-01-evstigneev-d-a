#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <cstdint>
#include <cstddef>
#include <memory>

class QueueA {
public:
    using T = std::uint8_t;
public:
    // Умолчательный конструктор
    QueueA() = default;

    // конструктор оот ссылки на queuea
    QueueA(QueueA&& src) noexcept;

    // деструктор
    ~QueueA() = default;

    // оператор копирование
    QueueA& operator=(const QueueA& src);

    QueueA& operator=(QueueA&& src);

    // Добавление элемента в стек
    void Push(std::uint8_t value);

    // Удаление элемента из top
    void Pop() noexcept;

    // Проверка на пустоту
    bool IsEmpty() const noexcept;

    // Очистка всех элементов
    void Clear() noexcept;

    // Получение значения элемента в top
    T& Top();

    const T& Top() const;

private:
    std::ptrdiff_t capacity_{0};
    std::ptrdiff_t size_{0};
    std::ptrdiff_t head_{0};
    std::ptrdiff_t tail_{0};
    std::unique_ptr<std::uint8_t[]> data_;

    void Resize();
};

#endif //QUEUE_HPP
