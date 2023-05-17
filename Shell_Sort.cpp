#include <iostream>
#include <vector>

// Функция для сортировки массива методом Шелла
void ShellSort(std::vector<int>& array) {
    int n = array.size();

    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; ++i) {
            int temp = array[i];
            int j;

            for (j = i; j >= gap && array[j - gap] > temp; j -= gap) {
                array[j] = array[j - gap];
            }

            array[j] = temp;
        }
    }
}

int main() {
    std::vector<int> array;

    int size;
    std::cout << "Введите размер массива: ";
    std::cin >> size;

    std::cout << "Введите элементы массива: ";
    for (int i = 0; i < size; ++i) {
        int element;
        std::cin >> element;
        array.push_back(element);
    }

    ShellSort(array);

    std::cout << "Отсортированный массив: ";
    for (const auto& element : array) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    return 0;
}
