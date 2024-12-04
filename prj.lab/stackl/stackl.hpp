#ifndef STACKL_HPP
#define STACKL_HPP

#include <cstdint>
#include <memory>

class StackL {
private:
    // Узел для хранения одного элемента стека
    struct Node {
        std::unique_ptr<Node> next_{nullptr}; // Указатель на следующий узел
        std::uint8_t value_{0}; // Значение элемента

        explicit Node(const std::uint8_t val) : next_(nullptr), value_(val) {}
    };
    // Указание на top
    std::unique_ptr<Node> head_{nullptr};

public:
    // Умолчательный конструктор
    StackL() = default;

    // Деструктор
    ~StackL() = default;

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

#endif //STACKL_HPP
