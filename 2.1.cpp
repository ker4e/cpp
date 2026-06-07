#include <iostream>
#include <stdexcept>

class smart_array {
private:
    int* data;
    int capacity;
    int size;

public:
    smart_array(int capacity) {
        if (capacity <= 0) {
            throw std::invalid_argument("Размер массива должен быть больше нуля");
        }

        this->capacity = capacity;
        this->size = 0;
        this->data = new int[capacity];
    }

    void add_element(int value) {
        if (size >= capacity) {
            throw std::out_of_range("Массив заполнен, добавить элемент нельзя");
        }

        data[size] = value;
        size++;
    }

    int get_element(int index) const {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Некорректный индекс элемента");
        }

        return data[index];
    }

    ~smart_array() {
        delete[] data;
    }
};

int main() {
    try {
        smart_array arr(5);

        arr.add_element(1);
        arr.add_element(4);
        arr.add_element(155);
        arr.add_element(14);
        arr.add_element(15);

        std::cout << arr.get_element(1) << std::endl;
    }
    catch (const std::exception& ex) {
        std::cout << ex.what() << std::endl;
    }
    return 0;
}
