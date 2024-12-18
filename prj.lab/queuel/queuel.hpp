#ifndef QUEUEL_HPP
#define QUEUEL_HPP

#include <memory>

class QueueL {
public:
    using T = float;

    // Умолчательный конструктор
    QueueL() = default;

    // конструкторы
    QueueL(QueueL&& src) noexcept;

    QueueL(const QueueL& src);

    // деструктор
    ~QueueL();

    // оператор копирование
    QueueL& operator=(const QueueL& src);

    QueueL& operator=(QueueL&& src);

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
    // структура узла
    struct Node {
      T value_{0};
      Node* next_{nullptr};
      Node (const T& value) : value_(value) {}
    };
    // указатели на голову и хвост очереди
    Node* head_{nullptr};
    Node* tail_{nullptr};
};

#endif //QUEUEL_HPP
