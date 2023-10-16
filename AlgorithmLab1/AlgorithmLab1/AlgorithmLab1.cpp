#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
//Целые числа
//отсортировано по возрастанию целых чисел
void sorted_in_ascending_order(int* arr, int size)
{
	for (int i = 0; i < size; ++i)
	{
		arr[i] = i;
	}
}

//отсортировано по убыванию целых чисел
void sorted_descending(int* arr, int size)
{
	for (int i = size - 1; i >= 0; --i)
	{
		arr[size - 1 - i] = i;
	}
}

//случайные последовательности целых чисел
void sorted_random(int* arr, int size)
{
	for (int i = 0; i < size; ++i)
		arr[i] = (rand()) / (RAND_MAX / 100);
}

//пилообразные последовательности
void sorted_sawtooth(int* arr, int size)
{
	for (int i = 0; i < size; i++) 
	{
		int coef = 2;
		if (i % 2 == 0) 
			arr[i] = i / coef;
		else 
			arr[i] = size - (i / coef) - 1;
	}
}

//Дробные
// //отсортировано по возрастанию дробных чисел
void sorted_in_ascending_order(float* arr, int size)
{
	for (int i = 0; i < size; ++i)
	{
		arr[i] = i;
	}
}

//отсортировано по убыванию дробных чисел
void sorted_descending(float* arr, int size)
{
	for (int i = size - 1; i >= 0; --i)
	{
		arr[size - 1 - i] = i;
	}
}

//случайные последовательности дробных чисел
void sorted_random(float* arr, int size)
{
	for (int i = 0; i < size; ++i)
		arr[i] = (float)(rand()) / (float)(RAND_MAX / (100));
}

//пилообразные последовательности
void sorted_sawtooth(float* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int i = 0; i < size; i++) 
		{
			float coef = 2.718;
			if (i % 2 == 0) 
				arr[i] = i / coef;
			else 
				arr[i] = size - (i / coef) - 1;
		}
	}
}

//функция для измерения времени для целых чисел
void time_checking(void(*function)(int*, int), int size)
{
	//выделяем память
	int* arr = new int[size];
	auto begin = std::chrono::steady_clock::now();
	// получаем время перед началом формирования последовательности

	//вызов функции
	function(arr, size);

	auto end = std::chrono::steady_clock::now();// получаем время по окончанию формирования последовательности
	auto elapsed_ms = std::chrono::duration_cast<std::chrono::microseconds>(end - begin); //получаем время в микросекундах 
	std::cout << "Время работы алгоритма по формированию последовательности: " << elapsed_ms.count() << " (мкС)" << std::endl; // вывод
	//чистим пямять
	delete[] arr;
}


//функция для измерения времени для дробных чисел
void time_checking(void(*function)(float*, int)//указатель на функцию
	, int size)//размер массива
{
	//выделяем память
	float* arr = new float[size];
	auto begin = std::chrono::steady_clock::now();
	// получаем время перед началом формирования последовательности

	//вызов функции
	function(arr, size);

	auto end = std::chrono::steady_clock::now();// получаем время по окончанию формирования последовательности
	auto elapsed_ms = std::chrono::duration_cast<std::chrono::microseconds>(end - begin); //получаем время в микросекундах 
	std::cout << "Время работы алгоритма по формированию последовательности: " << elapsed_ms.count() << " (мкС)" << std::endl; // вывод
	//чистим пямять
	delete[] arr;
}

int main()
{
	setlocale(0, "rus");
	srand(time(NULL));

	float* arr = new float[100];
	sorted_random(arr, 100);

	for (int i = 0; i < 100; ++i)
	{
		cout << arr[i] << '\n';
	}

	system("pause");
	return 0;
}

