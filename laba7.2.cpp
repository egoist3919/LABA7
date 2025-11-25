#include <iostream>
#include <array>
#include <ctime>
using namespace std;

array <int, 10> Sort1(array<int, 10> arr) {
	cout << "Функция передачи по значению" << endl;
	short k = 1;
	cout << "Выберети какую сортировку хотите сделать :" << endl;
	cout << "1 - Сортировка по убыванию" << endl;
	cout << "2 - Сортиоровка по возростанию" << endl;
	while (true) {
		cout << "Введите номер пункт: " << endl;
		cin >> k;
		if (k == 1) {
			for (int i = 0; i < arr.size(); ++i) {
				for (int j = i + 1; j != arr.size(); ++j) {
					if (arr[i] < arr[j]) {
						swap(arr[i], arr[j]);
					}
				}
			}
			return arr;
		}
		else if (k == 2) {
			for (int i = 0; i << arr.size(); ++i) {
				for (int j = i + 1; j != arr.size() - 1; ++j) {
					if (arr[i] > arr[j]) {
						swap(arr[i], arr[j]);
					}
				}
			}
			return arr;
		} 
		else {
			cout << "Выберите коретный пункт (1 или 2)" << endl;
		}
	}
}
array <int, 10> Sort2(array<int, 10> arr) {
	cout << "Функция передачи по значению" << endl;
	short k = 1;
	cout << "Выберети какую сортировку хотите сделать :" << endl;
	cout << "1 - Сортировка по убыванию" << endl;
	cout << "2 - Сортиоровка по возростанию" << endl;
	while (true) {
		if (k == 1) {
			for (int i = 0; i != arr.size(); ++i) {
				for (int j = i + 1; j != arr.size(); ++j) {
					if (arr[i] > arr[j]) {
						swap(arr[i], arr[j]);
					}
				}
			}
			return arr;
		}
		else if (k == 2) {
			for (int i = 0; i != arr.size(); ++i) {
				for (int j = i + 1; j != arr.size() - 1; ++j) {
					if (arr[i] < arr[j]) {
						swap(arr[i], arr[j]);
					}
				}
			}
			return arr;
		}
		else {
			cout << "Выберите коретный пункт (1 или 2)" << endl;
		}
	}
}

int main() {
	setlocale(LC_ALL, "RUS");
	array <int, 10> arr;
	srand(time(NULL));
	for (int i = 0; i != arr.size(); ++i) {
		arr[i] = rand() % 20 - 10;
		cout << arr[i] << " ";
	}
	array <int, 10> res = Sort1(arr);

}