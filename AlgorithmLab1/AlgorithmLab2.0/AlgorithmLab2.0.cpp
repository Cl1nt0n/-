/*Лабораторная работа №1, 3 семестр*/

#include <iostream>
#include <fstream>
#include <ctime>
#include <cmath>
#include <cstdlib>
#include <chrono>  //библиотека для вычисления времени работы алгоритмов

#define N 6 //Количество элементов массива указателей на функцию
#define PI 3.14159265	//Число ПИ

#pragma region Функции для целых чисел
//Функция создания случайной целочисленной последовательности
void random_sorted_int(int* arr, int n, int divider, int interval)
{
	srand(time(NULL));
	for (int i = 0; i < n; ++i) {
		*(arr + i) = rand() % divider;
	}
}

//Функция создания возрастающей целочисленной последовательности
void increase_sorted_int(int* arr, int n, int divider, int interval)
{
	srand(time(NULL));
	*(arr) = rand() % divider;
	for (int i = 1; i < n; ++i) {
		*(arr + i) = *(arr + i - 1) + rand() % divider;
	}
}

//Функция создания убывающей целочисленной последовательности
void decrease_sorted_int(int* arr, int n, int divider, int interval)
{
	srand(time(NULL));
	*arr = rand() % divider;
	for (int i = 1; i < n; ++i) {
		*(arr + i) = *(arr + i - 1) - rand() % divider;
	}
}

//Функция создания пилообразной целочисленной последовательности
void sawtooth_sorted_int(int* arr, int n, int divider, int interval)
{
	srand(time(NULL));
	*arr = rand() % divider;

	for (int i = 1; i < n; ++i) {
		if (i % interval != 0) {
			*(arr + i) = *(arr + i - 1) + rand() % divider;
		}
		if (i % interval == 0) {
			*(arr + i) = *(arr);
		}
	}
}

//Функция создания синусоидальной целочисленной последовательности
void sin_sorted_int(int* arr, int n, int divider, int interval)
{
	srand(time(NULL));
	double A = divider / 2;
	double corner = rand() % divider;
	for (int i = 0; i < n; ++i) {
		*(arr + i) = (int)(A * sin(i * PI / interval));
	}
}

//Функция создания ступенчатой целочисленной последовательности
void step_sorted_int(int* arr, int n, int divider, int interval)
{
	srand(time(NULL));
	int level = rand() % divider;

	for (int i = 0; i < n; ++i) {
		if (i % interval != 0) {
			*(arr + i) = level;
		}
		if (i % interval == 0) {
			level += interval / 2;
			*(arr + i) = level;
		}
	}
}
#pragma endregion

#pragma region Функции для чисел с плавающей запятой
//Функция создания случайной вещественной последовательности
void random_sorted_double(double* arr, int n, int divider, int interval)
{
	srand(time(NULL));
	double noise = 0;
	for (int i = 0; i < n; ++i) {
		noise = 0.01 * ((rand() % divider) + 1); //Генерация "шума"
		*(arr + i) = rand() % divider + noise;
	}
}

//Функция создания возрастающей вещественной последовательности
void increase_sorted_double(double* arr, int n, int divider, int interval)
{
	srand(time(NULL));
	double noise = 0;
	*arr = rand() % divider;
	for (int i = 1; i < n; ++i) {
		noise = 0.01 * ((rand() % divider) + 1); //Генерация "шума"
		*(arr + i) = *(arr + i - 1) + rand() % divider + noise;
	}
}

//Функция создания убывающей целочисленной последовательности
void decrease_sorted_double(double* arr, int n, int divider, int interval)
{
	srand(time(NULL));
	double noise = 0;
	*arr = rand() % divider;
	for (int i = 1; i < n; ++i) {
		noise = 0.01 * ((rand() % divider) + 1); //Генерация "шума"
		*(arr + i) = *(arr + i - 1) - rand() % divider + noise;
	}
}

//Функция создания пилообразной вещественной последовательности
void sawtooth_sorted_double(double* arr, int n, int divider, int interval)
{
	srand(time(NULL));
	*arr = rand() % divider;
	double noise = 0;
	for (int i = 1; i < n; ++i) {
		if (i % interval != 0) {
			noise = 0.01 * ((rand() % divider) + 1); //Генерация "шума"
			*(arr + i) = *(arr + i - 1) + rand() % divider + noise;
		}
		if (i % interval == 0) {
			noise = 0.01 * ((rand() % divider) + 1); //Генерация "шума"
			*(arr + i) = *arr + noise;
		}
	}
}

//Функция создания синусоидальной вещественной последовательности
void sin_sorted_double(double* arr, int n, int divider, int interval)
{
	srand(time(NULL));
	double noise = 0;
	double A = divider / 2;
	double corner = rand() % divider;
	for (int i = 0; i < n; ++i) {
		noise = 0.01 * ((rand() % divider) + 1); //Генерация "шума"
		*(arr + i) = A * sin(i * PI / interval) + noise;
	}
}

//Функция создания ступенчатой вещественной последовательности
void step_sorted_double(double* arr, int n, int divider, int interval)
{
	srand(time(NULL));
	double level = double(rand() % divider);
	double noise = 0;
	for (int i = 0; i < n; ++i) {
		if (i % interval != 0) {
			noise = 0.01 * ((rand() % divider) + 1); //Генерация "шума"
			*(arr + i) = level + noise;
		}
		if (i % interval == 0) {
			level += interval / 2;
			noise = 0.01 * ((rand() % divider) + 1); //Генерация "шума"
			*(arr + i) = level + noise;
		}
	}
}
#pragma endregion

//Введение типа указателя на функцию для значений целочисленного типа
typedef void (*ptr_func_int)(int*, int, int, int);

//Создание массива типа указатель на функцию
ptr_func_int int_functions[N] = { random_sorted_int, increase_sorted_int, decrease_sorted_int, sawtooth_sorted_int, sin_sorted_int, step_sorted_int };

//Введение типа указателя на функцию для значений целочисленного типа
typedef void (*ptr_func_double)(double*, int, int, int);

//Создание массива типа указатель на функцию
ptr_func_double double_functions[N] = { random_sorted_double, increase_sorted_double, decrease_sorted_double, sawtooth_sorted_double, sin_sorted_double, step_sorted_double };

using namespace std;
//Функция для записи последовательности в файл при количестве элементов менее 200
void fill_file(/*const char* FName1, const char* FName2,*/ int* arr1, double* arr2, int cnt)
{
	ofstream out;
	out.open("file_int.txt");
	if (!out.is_open()) {
		cout << "Файл не открыт\n";
		exit(0);
	}
	for (int i = 0; i < cnt; ++i) {
		out << *(arr1 + i) << "\n";
	}
	out.close();

	out.open("file_double.txt");
	if (!out.is_open()) {
		cout << "Файл не открыт\n";
		exit(0);
	}
	for (int i = 0; i < cnt; ++i) {
		out << *(arr2 + i) << "\n";
	}
	out.close();
}

#pragma region Основная программа
int main() {
	setlocale(LC_ALL, "rus");

	int count;  //количество элментов в массиве
	int limit_int; //ограничение на целочисленную последовательность
	int limit_double; //ограничение на float последовательность
	int interval; //интервал

	cout << "Введите количество элементов последовательности: ";
	cin >> count;
	while (count <= 0) {
		cout << "Количество элементов должно быть больше 0. Введите ещё раз: ";
		cin >> count;
	}

	cout << "Введите ограничение для целых чисел: ";
	cin >> limit_int;
	while (limit_int <= 0) {
		cout << "Ограничение должно быть больше 0. Введите ещё раз: ";
		cin >> limit_int;
	}

	cout << "Введите ограничение для вещественных чисел: ";
	cin >> limit_double;
	while (limit_double <= 0) {
		cout << "Ограничение должно быть больше 0. Введите ещё раз: ";
		cin >> limit_double;
	}

	cout << "Введите значение интервала: ";
	cin >> interval;
	while (interval <= 0) {
		cout << "Интервал должен быть больше 0. Введите ещё раз: ";
		cin >> interval;
	}

	int** arr1; //Целочисленная последовательность
	arr1 = new int* [N];

	double** arr2; //Вещественная последовательность
	arr2 = new double* [N];

	for (int i = 0; i < N; ++i) {
		switch (i) {
		case 0: cout << "\nВремя создания случайной последовательности" << endl;
			break;
		case 1: cout << "\nВремя создания возрастающей последовательности" << endl;
			break;
		case 2: cout << "\nВремя создания убывающей последовательности" << endl;
			break;
		case 3: cout << "\nВремя создания пилообразной последовательности" << endl;
			break;
		case 4: cout << "\nВремя создания синусоидальной последовательности" << endl;
			break;
		case 5: cout << "\nВремя создания ступенчатой последовательности" << endl;
			break;
		}

		*(arr1 + i) = new int[count];
		auto begin1 = std::chrono::steady_clock::now();

		//Вызов выбранной функции для целочисленных значений
		int_functions[i](*(arr1 + i), count, limit_int, interval);
		auto end1 = std::chrono::steady_clock::now();
		auto res_time1 = std::chrono::duration_cast<std::chrono::microseconds>(end1 - begin1);
		cout << "Целочисленной последовательности: " << res_time1.count() << " мкС \n";

		*(arr2 + i) = new double[count];
		auto begin2 = std::chrono::steady_clock::now();

		//Вызов выбранной функции для вещественный значений
		double_functions[i](*(arr2 + i), count, limit_double, interval);
		auto end2 = std::chrono::steady_clock::now();
		auto res_time2 = std::chrono::duration_cast<std::chrono::microseconds>(end2 - begin2);
		cout << "Вещественной последовательности: " << res_time2.count() << " мкС \n";
	}

	int num = 0; //Номер функции
	while (true)
	{
		cout << "\nВыберите вариант последовательности и введите соответствующее число:\n" //Приглашение на ввод
			<< "1). Случайная последовательность\n"
			<< "2). Возрастающая последовательность\n"
			<< "3). Убывающая последовательность\n"
			<< "4). Пилообразная последовательность\n"
			<< "5). Синусоидальная последовательность\n"
			<< "6). Ступенчатая последовательность\n"
			<< "Введите 0 для завершения.\n";
		cin >> num; //Ввод номера функции
		if (num == 0) {
			cout << "Программа завершена.\n";
			break;
		}

		cout << "Целочисленная последовательность:\n";
		for (int i = 0; i < count; ++i) {
			cout << *(*(arr1 + num - 1) + i) << "\t";
		}
		cout << "\n\n";
		cout << "Вещественная последовательность:\n";
		for (int i = 0; i < count; ++i) {
			cout << *(*(arr2 + num - 1) + i) << "\t";
		}
		cout << "\n\n";
		if (count <= 200 && count >= 150) { //Вызов функций записи последовательности в файл, если количество элементов в диапозоне от 150 до 200;
			fill_file(*(arr1 + num - 1), *(arr2 + num - 1), count);
		}
	}

	delete[] arr1;
	delete[] arr2;
	return 0;
}
#pragma endregion




