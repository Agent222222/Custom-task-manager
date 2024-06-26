#include <math.h>
#include <string>
#include <cstring>
#include <random>
#include <chrono>
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
// Функція для обчислення n-го числа Фібоначчі
int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    int a = 0, b = 1;
    int result = 0;
    for (int i = 2; i <= n; ++i) {
        result = a + b;
        a = b;
        b = result;
    }
    return result;
}

int main() {
    int size = 1000000;
    int* arr;
    arr = new int[size];
    std::random_device rd;
    std::mt19937 generator(rd());

    for (int i = 0; i < size; i++) {
        int random_number = std::uniform_int_distribution<int>(0, 100000)(generator);// для виконання з цілими числами (int random_number = uniform_int_distribution<int> . . .)
        arr[i] = random_number;
    }
    //cout << sizeof(arr);
    for (int i = 0; i < size; i++) {
        cout << arr[i] << endl;
    }
    // Заповнюємо масив числами Фібоначчі
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] == arr[i - 1] + arr[i - 2]) {
            count++;
        }
    }
    

    std::cout << "Amount of digits Fibonachi: " << count << std::endl;
    getchar();
    return 0;
}