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
				for (int j = i + 1; j != arr.size(); ++j) {
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
void Sort2(array<int, 10>& arr) {
	cout << "Функция передачи по ссылке" << endl;
	short k = 1;
	cout << "Выберети какую сортировку хотите сделать :" << endl;
	cout << "1 - Сортировка по убыванию" << endl;
	cout << "2 - Сортиоровка по возростанию" << endl;
	while (true) {
		if (k == 1) {
			cin >> k;
			for (int i = 0; i != arr.size(); ++i) {
				for (int j = i + 1; j != arr.size(); ++j) {
					if (arr[i] > arr[j]) {
						swap(arr[i], arr[j]);
					}
				}
			}
			break;
		}
		else if (k == 2) {
			for (int i = 0; i != arr.size(); ++i) {
				for (int j = i + 1; j != arr.size(); ++j) {
					if (arr[i] < arr[j]) {
						swap(arr[i], arr[j]);
					}
				}
			}
			break;
		}
		else {
			cout << "Выберите коректный пункт (1 или 2)" << endl;
		}
	}
}
void Sort2(array<int, 10> *arr_ptr, int n) {
	cout << "Функция передачи по указателю" << endl;
	short k = 1;
	cout << "Выберети какую сортировку хотите сделать :" << endl;
	cout << "1 - Сортировка по убыванию" << endl;
	cout << "2 - Сортиоровка по возростанию" << endl;
	while (true) {
		if (k == 1) {
			cin >> k;
			for (int i = 0; i != n; ++i) {
				for (int j = i + 1; j != n; ++j) {
					if ((*arr_ptr)[i] > (*arr_ptr)[j]) {
						swap((*arr_ptr)[i], (*arr_ptr)[j]);
					}
				}
			}
			break;
		}
		else if (k == 2) {
			for (int i = 0; i != n; ++i) {
				for (int j = i + 1; j != n; ++j) {
					if ((*arr_ptr)[i] < (*arr_ptr)[j]) {
						swap((*arr_ptr)[i], (*arr_ptr)[j]);
					}
				}
			}
			break;
		}

		else {
			cout << "Выберите коректный пункт (1 или 2)" << endl;
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
	array <int, 10> res = Sort1(arr); // когда передаем значение, у нас в функции создается копия(новая переменная) нашей переменной, из-за этого действия происходящие с массивом в функции не влияют на основной список 
	Sort2(arr);// когда передаем по ссылке, в функции не создается копия и не выделяется под нее память, благодоря этому, тратиться меньше памяти
	Sort2(&arr, arr.size()); //когда передаем по ссылке, нам надо передовать в функцию еще один аргумент - размерность массива
	for (int i = 0; i != 10; ++i) {
		cout << arr[i] << " ";
	}





}
