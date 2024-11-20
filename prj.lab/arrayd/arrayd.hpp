#ifndef ARRAYD_HPP
#define ARRAYD_HPP

#include <iosfwd>
#include <iterator>

template<class T>
class ArrayD {

private:
    ptrdiff_t size_of_array{0}; // количество элементов в массиве
    ptrdiff_t size_of_memory{0}; // количество элементов в массиве под которые выделена память
    T* data_pointer{nullptr}; // указатель на выделенную память

    ArrayD& Resize_memory() noexcept;
public:
    // умолчательный конструктор
    explicit ArrayD(ptrdiff_t size = 0, T value = 0);


    ArrayD(const ArrayD &vec);

    // деструктор
    ~ArrayD();

    // присваивание
    ArrayD& operator=(const ArrayD&) = default;
    ArrayD& operator=(ArrayD&&) = default;

    // оператор обращения по индексу
    T& operator[](ptrdiff_t position);

    // количество элементов
    ptrdiff_t Size() const noexcept;

    // проверка на пустоту
    bool Empty() const noexcept;

    // изменить размер на size и заполнить новые элементы value
    ArrayD& Resize(ptrdiff_t size, T value = 0);

    // добавить в конец value
    ArrayD& Push_back(const T& value) noexcept;

    // получить значение последнего элементы
    T& Back() const noexcept;

    // получить значение первого элемента
    T& Front() const noexcept;

    // получить максимальное количеств элементов, влезающих в текущую память
    ptrdiff_t Capacity() const noexcept;

    // очистить массив
    ArrayD& Clear() noexcept;

    // вставить на место position значение value
    ArrayD& Insert(ptrdiff_t position, T value);

    // удалить позицию position
    ArrayD& Erase(ptrdiff_t position);

    // удалить последний элемент
    ArrayD& Pop_back() noexcept;

    // получить указатель на начало
    T* begin() const noexcept;

    // получить перевернутый указатель на начало
    std::reverse_iterator<T*> rbegin() const noexcept;

    // получить указатель на конец
    T* end() const noexcept;

    // получить перевернутый указатель н конец
    std::reverse_iterator<T*> rend() const noexcept;

    // Форматированный вывод в поток outstream
    std::ostream& Write(std::ostream& outstream) const noexcept;

    // Форматированный ввод в поток instream
    std::istream& Read(std::istream& instream) noexcept;
};

// форматированный вывод в поток outstream динамического массива
template<class T>
std::ostream& operator<<(std::ostream& outstream, const ArrayD<T>& rhs) noexcept { return rhs.write(outstream); }

// Форматированный ввод из потока instream динамического массива
template<class T>
std::istream& operator>>(std::istream& instream, ArrayD<T>& rhs) noexcept { return rhs.read(instream); }

#include <arrayd/arrayd.cpp>

#endif //ARRAYD_HPP