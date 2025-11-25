
#include <vector>
#include <iostream>
using namespace std;
void prosmotr(vector <double> arr) {
	short k = 0;
	cout << "[ ";
	for (size_t i = 0; i != arr.size(); ++i) {
		cout << arr[i];
		++k;
		if (k < arr.size()) {
			cout << ", ";
		}
	}
	cout << "]" << endl;
	
}
void element(vector <double>& arr) {
	double qun;
	cout << "Введите число" << endl;
	cin >> qun;
	arr.insert(arr.begin(), qun);
}
void element2(vector <double>& arr) {
	double qun;
	cout << "Введите число" << endl;
	cin >> qun;
	arr.push_back(qun);
}
void clear(vector <double>& arr) {
	arr.clear();
}
void search(vector <double> arr) { // 5 
	short k = 0;
	int a;
	cout << "Введите число" << endl;
	cin >> a;
	cout << "[";
	for (int i = 0; i != arr.size(); ++i) {
		if (arr[i] == a) {
			++k;
			if (k > 1) {
				cout << ", ";
			}
			cout << i;
		}
	}
	cout << "]" << endl;
}
void reverse(vector <double>& arr) { 
	vector <double> res;
	bool flag = false;
	cout << "Исходный: ";
	prosmotr(arr);
	for (size_t i = arr.size() - 1; i != -1; --i) {
		if (int(arr[i]) % 7 == 0) {
			if (arr[i] == 777.0) {
				res.push_back(arr[i]);
			}
			else {
				flag = true;
			}
		}
		else {
			res.push_back(arr[i]);
		}
	}
	if (flag == false) { 
		res.push_back(0);
		res.push_back(0);
		res.push_back(0);
		cout << "Чисел кратных 7 не найдено. Добавлены три нуля." << endl;
	}
	arr = res;
	cout << "Результат: ";
	prosmotr(res);
}


int main()
{
	vector <double> arr{1, 32 , 4};
	arr.reserve(100);
	short number;
	setlocale(LC_ALL, "RUS");
	while (true){
		cout << "1. Просмотр массива." << endl;
		cout << "2. Добавить элемент в начало." << endl;
		cout << "3. Добавить элемент в конец." << endl;
		cout << "4. Очистка всего массива." << endl;
		cout << "5.Поиск элемента в массиве." << endl;
		cout << "6.Перезаписать массив в обратном порядке, пропустив все числа кратные 7, кроме 777. Если таких чисел нет – добавить в конец три нуля." << endl;
		cout << "0.Выйти" << endl;
		cout << "Введите номер пункта" << endl;
		cin >> number;
		if (number == 0) {
			break;
		}
		if (number == 1) {
			prosmotr(arr);
		}
		if (number == 2) {
			element(arr);
		}
		if (number == 3) {
			element2(arr);
		}
		if (number == 4) {
			clear(arr);
		}
		if (number == 5) {
			search(arr);
		}
		if (number == 6) {
			reverse(arr);
		}
	}
}

