#ifndef QUEUEA_HPP
#define QUEUEA_HPP

#include <cstdint>
#include <cstddef>
#include <memory>

class QueueA {
public:
    using T = std::uint8_t;

    // Умолчательный конструктор
    QueueA() = default;

    // конструкторы
    QueueA(QueueA&& src) noexcept;

    QueueA(const QueueA& src);

    // деструктор
    ~QueueA() = default;

    // оператор копирование
    QueueA& operator=(const QueueA& src);

    QueueA& operator=(QueueA&& src);

    // удаление элемента в Top
    void Pop() noexcept;

    // добавление элемента
    void Push(const T value);

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
    std::unique_ptr<T[]> data_;

    void Resize();
};

#endif //QUEUEA_HPP
