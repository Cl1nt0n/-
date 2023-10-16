#include <iostream>
#include <fstream>
#include <ctime>
#include <cmath>
#include <cstdlib>
#include <chrono> 
using namespace std;

#define PI 3.14159265

int main() 
{
    setlocale(0, "rus");

    int n = 0;
    cout << "Введите размер массива: ";
    cin >> n;

	double* arr = new double[n];

	srand(time(NULL));
	double noise = 0;
	for (int i = 0; i < n; ++i) {
		noise = 0.01 * ((rand() % 100)); //Генерация "шума"
		arr[i] = rand() % 100 + noise;
	}

	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << endl;
	}

    return 0;
}
