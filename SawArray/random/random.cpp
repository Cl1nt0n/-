﻿#include <iostream>
using namespace std;

#define PI 3.14159265

int main()
{
	setlocale(0, "rus");

	int n = 0;
	cout << "Введите размер массива: ";
	cin >> n;

	int* arr = new int[n];

	srand(time(NULL));
	for (int i = 0; i < n; ++i) {
		int random = rand();
		arr[i] = random % 100;
	}

	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << endl;
	}

	return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.