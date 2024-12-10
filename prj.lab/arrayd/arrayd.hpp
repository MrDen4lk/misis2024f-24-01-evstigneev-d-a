#pragma once

#ifndef ARRAYD_HPP
#define ARRAYD_HPP

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

    ArrayD(const std::ptrdiff_t size);

    // деструктор
    ~ArrayD();

    // присваивание
    ArrayD& operator=(const ArrayD&);

    // оператор обращения по индексу
    double& operator[](std::ptrdiff_t position);
    double operator[](std::ptrdiff_t position) const;

    // количество элементов
    std::ptrdiff_t Size() const noexcept;

    // изменить размер на size и заполнить новые элементы value
    void Resize(std::ptrdiff_t size);

    // вставить на место position значение value
    void Insert(std::ptrdiff_t position, double value);

    // удалить позицию position
    void Remove(std::ptrdiff_t position);
};

#endif //ARRAYD_HPP