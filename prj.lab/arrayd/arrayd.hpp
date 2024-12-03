#pragma once

#ifndef ARRAYD_HPP
#define ARRAYD_HPP

#include <iterator>
#include <cstddef>

class ArrayD {
private:
    std::ptrdiff_t size_of_array_{0}; // количество элементов в массиве
    std::ptrdiff_t size_of_memory_{0}; // количество элементов в массиве под которые выделена память
    double* data_pointer_{nullptr}; // указатель на выделенную память

public:
    // умолчательный конструктор
    ArrayD() = default;

    ArrayD(const ArrayD&);

    explicit ArrayD(std::ptrdiff_t size = 0);

    // деструктор
    ~ArrayD();

    // присваивание
    ArrayD& operator=(const ArrayD&) = default;
    ArrayD& operator=(ArrayD&&) = default;

    // оператор обращения по индексу
    double& operator[](std::ptrdiff_t position);
    double operator[](std::ptrdiff_t position) const;

    // количество элементов
    std::ptrdiff_t Size() const noexcept;

    // проверка на пустоту
    bool Empty() const noexcept;

    // изменить размер на size и заполнить новые элементы value
    void Resize(std::ptrdiff_t size);

    // добавить в конец value
    void Push_back(const double& value) noexcept;

    // получить значение последнего элементы
    double Back() const noexcept;

    // получить значение первого элемента
    double Front() const noexcept;

    // получить максимальное количеств элементов, влезающих в текущую память
    std::ptrdiff_t Capacity() const noexcept;

    // очистить массив
    void Clear() noexcept;

    // вставить на место position значение value
    void Insert(std::ptrdiff_t position, double value);

    // удалить позицию position
    void Remove(std::ptrdiff_t position);

    // удалить последний элемент
    void Pop_back() noexcept;

    // получить указатель на начало
    double* begin() const noexcept;

    // получить перевернутый указатель на начало
    std::reverse_iterator<double*> rbegin() const noexcept;

    // получить указатель на конец
    double* end() const noexcept;

    // получить перевернутый указатель н конец
    std::reverse_iterator<double*> rend() const noexcept;
};

#endif //ARRAYD_HPP