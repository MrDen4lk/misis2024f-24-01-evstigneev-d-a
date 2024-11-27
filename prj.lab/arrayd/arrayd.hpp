#ifndef ARRAYD_HPP
#define ARRAYD_HPP

#include <iosfwd>
#include <iterator>

class ArrayD {
private:
    ptrdiff_t size_of_array_{0}; // количество элементов в массиве
    ptrdiff_t size_of_memory_{0}; // количество элементов в массиве под которые выделена память
    double* data_pointer_{nullptr}; // указатель на выделенную память

    ArrayD& Resize_memory() noexcept;
public:
    // умолчательный конструктор
    explicit ArrayD(ptrdiff_t size = 0, double value = 0);


    ArrayD(const ArrayD &vec);

    // деструктор
    ~ArrayD();

    // присваивание
    ArrayD& operator=(const ArrayD&) = default;
    ArrayD& operator=(ArrayD&&) = default;

    // оператор обращения по индексу
    double& operator[](ptrdiff_t position);
    double operator[](ptrdiff_t position) const;

    // количество элементов
    ptrdiff_t Size() const noexcept;

    // проверка на пустоту
    bool Empty() const noexcept;

    // изменить размер на size и заполнить новые элементы value
    ArrayD& Resize(ptrdiff_t size, double value = 0);

    // добавить в конец value
    ArrayD& Push_back(const double& value) noexcept;

    // получить значение последнего элементы
    double& Back() const noexcept;

    // получить значение первого элемента
    double& Front() const noexcept;

    // получить максимальное количеств элементов, влезающих в текущую память
    ptrdiff_t Capacity() const noexcept;

    // очистить массив
    ArrayD& Clear() noexcept;

    // вставить на место position значение value
    ArrayD& Insert(ptrdiff_t position, double value);

    // удалить позицию position
    ArrayD& Remove(ptrdiff_t position);

    // удалить последний элемент
    ArrayD& Pop_back() noexcept;

    // получить указатель на начало
    double* begin() const noexcept;

    // получить перевернутый указатель на начало
    std::reverse_iterator<double*> rbegin() const noexcept;

    // получить указатель на конец
    double* end() const noexcept;

    // получить перевернутый указатель н конец
    std::reverse_iterator<double*> rend() const noexcept;

    // Форматированный вывод в поток outstream
    std::ostream& Write(std::ostream& outstream) const noexcept;

    // Форматированный ввод в поток instream
    std::istream& Read(std::istream& instream) noexcept;
};

// форматированный вывод в поток outstream динамического массива
inline std::ostream& operator<<(std::ostream& outstream, const ArrayD& rhs) noexcept { return rhs.Write(outstream); }

// Форматированный ввод из потока instream динамического массива
inline std::istream& operator>>(std::istream& instream, ArrayD& rhs) noexcept { return rhs.Read(instream); }

#endif //ARRAYD_HPP