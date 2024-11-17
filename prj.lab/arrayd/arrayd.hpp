#ifndef ARRAYD_HPP
#define ARRAYD_HPP

#include <iosfwd>
#include <iterator>

template<class T>
class ArrayD {

private:
    int32_t size_of_array{0}; // количество элементов в массиве
    int32_t size_of_memory{0}; // количество элементов в массиве под которые выделена память
    T* data_pointer{nullptr}; // указатель на выделенную память

    ArrayD& resize_memory() noexcept;
public:
    // умолчательный конструктор
    explicit ArrayD(int32_t size = 0, T value = 0);


    ArrayD(const ArrayD<T> &vec);

    // деструктор
    ~ArrayD();

    // присваивание
    ArrayD& operator=(const ArrayD&) = default;
    ArrayD& operator=(ArrayD&&) = default;

    // оператор обращения по индексу
    T& operator[](int32_t index);

    // количество элементов
    int32_t size() const noexcept;

    // проверка на пустоту
    bool empty() const noexcept;

    // изменить размер на size и заполнить новые элементы value
    ArrayD& resize(int32_t size, T value = 0);

    // добавить в конец value
    ArrayD& push_back(const T& value) noexcept;

    // получить значение последнего элементы
    T& back() const noexcept;

    // получить значение первого элемента
    T& front() const noexcept;

    // получить максимальное количеств элементов, влезающих в текущую память
    int32_t capacity() const noexcept;

    // очистить массив
    ArrayD& clear() noexcept;

    // вставить на место position значение value
    ArrayD& insert(int32_t position, T value);

    // удалить позицию position
    ArrayD& erase(int32_t position);

    // удалить последний элемент
    ArrayD& pop_back() noexcept;

    // получить указатель на начало
    T* begin() const noexcept;

    // получить перевернутый указатель на начало
    std::reverse_iterator<T*> rbegin() const noexcept;

    // получить указатель на конец
    T* end() const noexcept;

    // получить перевернутый указатель н конец
    std::reverse_iterator<T*> rend() const noexcept;

    // Форматированный вывод в поток outstream
    std::ostream& write(std::ostream& outstream) const noexcept;

    // Форматированный ввод в поток instream
    std::istream& read(std::istream& instream) noexcept;
};

// форматированный вывод в поток outstream рационального числа
template<class T>
std::ostream& operator<<(std::ostream& outstream, const ArrayD<T>& rhs) noexcept { return rhs.write(outstream); }

// Форматированный ввод из потока instream рационального числа
template<class T>
std::istream& operator>>(std::istream& instream, ArrayD<T>& rhs) noexcept { return rhs.read(instream); }

#include <arrayd/arrayd.cpp>

#endif //ARRAYD_HPP