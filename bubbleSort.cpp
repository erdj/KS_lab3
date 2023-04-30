#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main() {
    srand(time(NULL)); // Инициализируем генератор случайных чисел

    for (int i = 0; i < 1000000; i++) {
        int arr[100];

        // Заполняем массив случайными числами от 1 до 10
        for (int j = 0; j < 100; j++) {
            arr[j] = rand() % 10 + 1;
        }

        // Сортируем массив с помощью сортировки пузырьком
        bubbleSort(arr, 100);
    }

    cout << "OK";

    return 0;
}