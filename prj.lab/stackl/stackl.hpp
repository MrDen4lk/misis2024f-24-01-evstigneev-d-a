#ifndef STACKL_HPP
#define STACKL_HPP

#include <cstdint>
#include <memory>

class StackL {
public:
    using T = std::uint8_t;
public:
    // Умолчательный конструктор
    StackL() = default;

    // Деструктор
    ~StackL() = default;

    // конструктор
    StackL(const StackL& src);

    StackL(StackL&& src) noexcept;

    // оператор копирования
    StackL& operator=(const StackL& src);

    StackL& operator=(StackL&& src) noexcept;

    // Добавление элемента в стек
    void Push(T value);

    // Удаление элемента из top
    void Pop() noexcept;

    // Проверка на пустоту
    bool IsEmpty() const noexcept;

    // Очистка всех элементов
    void Clear() noexcept;

    // Получение значения элемента в top
    T& Top() &;

    const T& Top() const &;

private:
    // Узел для хранения одного элемента стека
    struct Node {
        std::unique_ptr<Node> next_{nullptr}; // Указатель на следующий узел
        T value_{T()}; // Значение элемента

        explicit Node(const T val) : next_(nullptr), value_(val) {}
    };
    // Указание на top
    std::unique_ptr<Node> head_{nullptr};
};

#endif //STACKL_HPP
