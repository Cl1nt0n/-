/**************************************************************************************************/
/*                             МАССИВЫ И ВРЕМЯ                                                    */
/**************************************************************************************************/
/*	Project Type	: Win64 Console Applicatoin                                                   */
/*	Progect Name	: Лаб.р. №1 массивы время													  */
/*	File Name		: Лаб.р. №1 массивы время.cpp                                                 */
//*	Language		: CPP, MSVS ver 2019                                                          */
//*	Programmers		: Романова Полина Николаевна, Великанова Анна Алексеевна, М3О-210Б-21         */
/*	Modified by		:                                                                             */
/*	Created			:                                                                             */
/*	Last Revision	:                                                                             */
/*                                                                                                */
/*________________________________________________________________________________________________*/
/*	Comment			: Лабораторная работа №1, 3 семестр                                           */
/**************************************************************************************************/

#include <iostream>
#include <fstream>
#include <ctime>
#include <cmath>
#include <cstdlib>
#include <chrono>  //библиотека для вычисления времени работы алгоритмов

#define N 6 //Количество элементов массива указателей на функцию
#define PI 3.14159265	//Число ПИ
//const char* FName1 = "file_int.txt"; //Имя файля для записи последовательности из целочисленных значений
//char FName2[] = "file_double.txt"; //Имя файля для записи последовательности из вещественных значений


//**********************************************************************************************************************
//*                                             ПРОТОТИПЫ ФУНКЦИЙ                                                      *
//**********************************************************************************************************************

/**********************************************С целыми числами*******************************************************/

//Функция записи последлвательностей в файл
void fill_file(int* arr1, double* arr2, int cnt); 

//Функция создания случайной целочисленной последовательности
void random_seq(int* arr, //массив
	int cnt,              //количество элементов
	int limit,			  //ограничение на рандомное число
	int interval);		  //интервал

//Функция создания возрастающей целочисленной последовательности
void increase_seq(int* arr, //массив
	int cnt,				//количество элементов
	int limit,				//ограничение на рандомное число
	int interval);			//интервал

//Функция создания убывающей целочисленной последовательности
void decrease_seq(int* arr, //массив
	int cnt,				//количество элементов
	int limit,				//ограничение на рандомное число
	int interval);			//интервал

//Функция создания пилообразной целочисленной последовательности
void pila_seq(int* arr, //массив
	int cnt,			//количество элементов
	int limit,			//ограничение на рандомное число
	int interval);		//интервал

//Функция создания синусоидальной целочисленной последовательности
void sin_sorted_int(int* arr, //массив
	int cnt,		   //количество элементов					
	int limit,		   //ограничение на рандомное число
	int interval);	   //интервал

//Функция создания ступенчатой целочисленной последовательности
void step_sorted_int(int* arr, //массив
	int cnt,			//количество элементов
	int limit,			//ограничение на рандомное число
	int interval);		//интервал


/******************************************С плавающей запятой***********************************************************/


//Функция создания случайной вещественной последовательности
void random_sorted(double* arr, //массив
	int cnt,				 //количество элементов
	int limit,				 //ограничение на рандомное число
	int interval);			 //интервал

//Функция создания возрастающей вещественной последовательности
void increase_seq(double* arr, //массив
	int cnt,				   //количество элементов
	int limit,				   //ограничение на рандомное число
	int interval);             //интервал

//Функция создания убывающей вещественной последовательности
void decrease_seq(double* arr,	//массив
	int cnt,					//количество элементов
	int limit,					//ограничение на рандомное число
	int interval);				//интервал

//Функция создания пилообразной вещественной последовательности
void pila_seq(double* arr,	//массив
	int cnt,				//количество элементов
	int limit,				//ограничение на рандомное число
	int interval);			//интервал

//Функция создания синусоидальной вещественной последовательности
void sin_sorted(double* arr,	//массив
	int cnt,				//количество элементов
	int limit,				//ограничение на рандомное число
	int interval);			//интервал

//Функция создания ступенчатой вещественной последовательности
void step_sorted_int(double* arr,	//массив
	int cnt,				//количество элементов
	int limit,				//ограничение на рандомное число
	int interval);			//интервал


/**************************************************МАССИВ УКАЗАТЕЛЕЙ*******************************************************/

//Введение типа указателя на функцию для значений целочисленного типа
typedef void (*ptr_func_int)(int*, int, int, int); 

//Создание массива типа указатель на функцию
ptr_func_int mas1[N] = { random_seq, increase_seq, decrease_seq, pila_seq, sin_sorted_int, step_sorted_int }; 

//Введение типа указателя на функцию для значений целочисленного типа
typedef void (*ptr_func_double)(double*, int, int, int); 

//Создание массива типа указатель на функцию
ptr_func_double mas2[N] = { random_sorted, increase_seq, decrease_seq, pila_seq, sin_sorted,  step_sorted_int }; 

using namespace std;

/*****************************************************************************************************************************/
/*								              ОСНОВНАЯ ПРОГРАММА                                                             */
/*****************************************************************************************************************************/

int main() {
	setlocale(LC_ALL, "rus");

	int count;  //количество элментов в массиве
	int limit_int; //ограничение на целочисленную последовательность
	int limit_double; //ограничение на float последовательность
	int interval; //интервал

	/**************************************Проверка корректности введенных данных******************************************/

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

	/************************************************************************************************************************/

	int** arr1; //Целочисленная последовательность
	arr1 = new int* [N];

	double** arr2; //Вещественная последовательность
	arr2 = new double* [N];

	for (int i = 0; i < N; ++i) {
		switch (i) {
		case 0: cout << "\nВремя создания случайной последовательности\n"; break;
		case 1: cout << "\nВремя создания возрастающей последовательности\n"; break;
		case 2: cout << "\nВремя создания убывающей последовательности\n"; break;
		case 3: cout << "\nВремя создания пилообразной последовательности\n"; break;
		case 4: cout << "\nВремя создания синусоидальной последовательности\n"; break;
		case 5: cout << "\nВремя создания ступенчатой последовательности\n"; break;
		}

		*(arr1 + i) = new int[count];
		auto begin1 = std::chrono::steady_clock::now();

		//Вызов выбранной функции для целочисленных значений
		mas1[i](*(arr1 + i), count, limit_int, interval); 
		auto end1 = std::chrono::steady_clock::now();
		auto res_time1 = std::chrono::duration_cast<std::chrono::microseconds>(end1 - begin1);
		cout << "Целочисленной последовательности: " << res_time1.count() << " мкС \n";

		*(arr2 + i) = new double[count];
		auto begin2 = std::chrono::steady_clock::now();

		//Вызов выбранной функции для вещественный значений
		mas2[i](*(arr2 + i), count, limit_double, interval); 
		auto end2 = std::chrono::steady_clock::now();
		auto res_time2 = std::chrono::duration_cast<std::chrono::microseconds>(end2 - begin2);
		cout << "Вещественной последовательности: " << res_time2.count() << " мкС \n";
	}

	int num = 0; //Номер функции
	while (1) {
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

		cout << "Int seq:\n";
		for (int i = 0; i < count; ++i) {
			cout << *(*(arr1 + num - 1) + i) << " ";
		}
		cout << "\n\n";
		cout << "Double seq:\n";
		for (int i = 0; i < count; ++i) {
			cout << *(*(arr2 + num - 1) + i) << " ";
		}
		cout << "\n\n";
		if (count <= 200) { //Вызов функций записи последовательности в файл, если количество элементов не превышает 200
			fill_file(*(arr1 + num - 1), *(arr2 + num - 1), count);
		}
	}

	delete[] arr1;
	delete[] arr2;
	return 0;
}//main
/***************************************КОНЕЦ ОСНОВНОЙ ПРОГРАММЫ*********************************************************/


/***********************************************************************************************************************/
/*								          РЕАЛИЗАЦИЯ ФУНКЦИЙ                                                                     */
/***********************************************************************************************************************/

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

/******************************************С целыми числами******************************************************************/
//Функция создания случайной целочисленной последовательности
void random_sorted(int* arr, int cnt, int limit)
{
	srand(time(NULL));
	for (int i = 0; i < cnt; ++i) {
		*(arr + i) = rand() % limit;
	}
}

//Функция создания возрастающей целочисленной последовательности
void increase_seq(int* arr, int cnt, int limit)
{
	srand(time(NULL));
	*arr = rand() % limit;
	for (int i = 1; i < cnt; ++i) {
		*(arr + i) = *(arr + i - 1) + rand() % limit;
	}
}

//Функция создания убывающей целочисленной последовательности
void decrease_seq(int* arr, int cnt, int limit)
{
	srand(time(NULL));
	*arr = rand() % limit;
	for (int i = 1; i < cnt; ++i) {
		*(arr + i) = *(arr + i - 1) - rand() % limit;
	}
}

//Функция создания пилообразной целочисленной последовательности
void pila_seq(int* arr, int cnt, int limit, int interval)
{
	srand(time(NULL));
	*arr = rand() % limit;

	for (int i = 1; i < cnt; ++i) {
		if (i % interval != 0) {
			*(arr + i) = *(arr + i - 1) + rand() % limit;
		}
		if (i % interval == 0) {
			*(arr + i) = *arr;
		}
	}
}

//Функция создания синусоидальной целочисленной последовательности
void sin_sorted_int(int* arr, int cnt, int limit, int interval)
{
	srand(time(NULL));
	double A = limit / 2;
	double corner = rand() % limit;
	for (int i = 0; i < cnt; ++i) {
		*(arr + i) = (int)(A * sin(corner * i * PI / interval));
	}
}

//Функция создания ступенчатой целочисленной последовательности
void step_sorted_int(int* arr, int cnt, int limit, int interval)
{
	srand(time(NULL));
	int level = rand() % limit;

	for (int i = 0; i < cnt; ++i) {
		if (i % interval != 0) {
			*(arr + i) = level;
		}
		if (i % interval == 0) {
			level += interval / 2;
			*(arr + i) = level;
		}
	}
}

/******************************С плавающей запятой***********************************************************************/


//Функция создания случайной вещественной последовательности
void random_sorted(double* arr, int cnt, int limit, int interval)
{
	srand(time(NULL));
	double noise = 0;
	for (int i = 0; i < cnt; ++i) {
		noise = 0.01 * ((rand() % limit) % 100001 + 1); //Генерация "шума"
		*(arr + i) = rand() % limit + noise;
	}
}

//Функция создания возрастающей вещественной последовательности
void increase_seq(double* arr, int cnt, int limit, int interval)
{
	srand(time(NULL));
	double noise = 0;
	*arr = rand() % limit;
	for (int i = 1; i < cnt; ++i) {
		noise = 0.01 * ((rand() % limit) % 100001 + 1); //Генерация "шума"
		*(arr + i) = *(arr + i - 1) + rand() % limit + noise;
	}
}

//Функция создания убывающей целочисленной последовательности
void decrease_seq(double* arr, int cnt, int limit, int interval)
{
	srand(time(NULL));
	double noise = 0;
	*arr = rand() % limit;
	for (int i = 1; i < cnt; ++i) {
		noise = 0.01 * ((rand() % limit) % 100001 + 1); //Генерация "шума"
		*(arr + i) = *(arr + i - 1) - rand() % limit + noise;
	}
}

//Функция создания пилообразной вещественной последовательности
void pila_seq(double* arr, int cnt, int limit, int interval)
{
	srand(time(NULL));
	*arr = rand() % limit;
	double noise = 0;
	for (int i = 1; i < cnt; ++i) {
		if (i % interval != 0) {
			noise = 0.01 * ((rand() % limit) % 100001 + 1); //Генерация "шума"
			*(arr + i) = *(arr + i - 1) + rand() % limit + noise;
		}
		if (i % interval == 0) {
			noise = 0.01 * ((rand() % limit) % 100001 + 1); //Генерация "шума"
			*(arr + i) = *arr + noise;
		}
	}
}

//Функция создания синусоидальной вещественной последовательности
void sin_sorted(double* arr, int cnt, int limit, int interval)
{
	srand(time(NULL));
	double noise = 0;
	double A = limit / 2;
	double corner = rand() % limit;
	for (int i = 0; i < cnt; ++i) {
		noise = 0.01 * ((rand() % limit) % 100001 + 1); //Генерация "шума"
		*(arr + i) = A * sin(corner * i * PI / interval) + noise;
	}
}

//Функция создания ступенчатой вещественной последовательности
void step_sorted_int(double* arr, int cnt, int limit, int interval)
{
	srand(time(NULL));
	double level = double(rand() % limit);
	double noise = 0;
	for (int i = 0; i < cnt; ++i) {
		if (i % interval != 0) {
			noise = 0.01 * ((rand() % limit) % 100001 + 1); //Генерация "шума"
			*(arr + i) = level + noise;
		}
		if (i % interval == 0) {
			level += interval / 2;
			noise = 0.01 * ((rand() % limit) % 100001 + 1); //Генерация "шума"
			*(arr + i) = level + noise;
		}
	}
}