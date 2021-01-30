#include <iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

//#define NUM_1
//#define DEBUG_ASSERTION_FAILED_1
//#define DEBUG_ASSERTION_FAILED_2

void FillRand(int arr[], const int n);
void FillRand(int** arr, const int m, const int n);
void Print(int arr[], const int n);
void Print(int** arr, const int m, const int n);


int* push_back(int arr[], int& n, int value);
int* push_front(int arr[], int& n, int value);
int* insert(int arr[], int& n, int value, int index);

//#define DYNAMIC_1
#define DYNAMIC_2


void main()
{
	setlocale(LC_ALL, "");
#ifdef DYNAMIC_1
#ifdef NUM_1
	int n;	//Размер массива
	cout << "Введите размер массива: "; cin >> n;
	int* arr = new int[n] {3, 5, 8};	//Heap - куча; выделяем память под массив



	FillRand(arr, n);
	Print(arr, n);
	int value;
	cout << "Введите добавляемое значение: "; cin >> value;
	//1) Создаём буферный массив нужного размера:
	int*buffer = new int[n + 1];
	//2) Копируем исходный массив в буферный:
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	//3) Удаляем исходный массив: 
	delete[] arr;
	//arr[n]=value;

	//4) Подменяем исходный массив:
	arr = buffer;
	//5) Добавляем значение:
	arr[n] = value;
	//6 Увеличиваем размер массива: 
	n++;
	Print(arr, n);
	delete[] arr;		//Освобождаем память,занимаемую массивом  
#endif // DEBUG
	int n;
#ifdef DEBUG_ASSERTION_FAILED_1
	int*pn = &n;
	delete[] pn;
#endif // DEBUG_ASSERTION_FAILED_1

	cout << "Введите размер массива: "; cin >> n;
	int* arr = new int[n] {3, 5, 8};
	FillRand(arr, n);
	Print(arr, n);

	int value;
	cout << "Введите добавляемое значение: "; cin >> value;
	arr = push_back(arr, n, value);
	Print(arr, n);
	cout << "Введите добавляемое значение: "; cin >> value;
	arr = push_front(arr, n, value);
	Print(arr, n);

	int index;
	cout << "Введите добавляемое значение: "; cin >> value;
	cout << "Введите индес: "; cin >> index;
	arr = insert(arr, n, value, index);
	Print(arr, n);

#ifdef DEBUG_ASSERTION_FAILED_2
	delete[] buffer;
#endif // DEBUG_ASSERTION_FAILED_2

	delete[] arr;
#endif // DYNAMIC_1
#ifdef DYNAMIC_2
	int m;	//Количество строк
	int n;	//Количество элемендтов строки (количество столбцов)
	cout << "Введите количество строк: "; cin >> m;
	cout << "Введите количество элементов строки: "; cin >> n;
	//////////////////////////////////////////////////////////////////////////////////////////////
	//////////////////////// объявление двумерного динамического массива ////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////////////
	// 1.	Создаем массив указателей:
	int**arr = new int*[m];
	// 2.	Создаем строки двумерного массива:
	for (int i = 0; i < m; i++)
	{
		arr[i] = new int [n] {};
	}
	FillRand(arr, m, n);
	Print(arr, m, n);
	


	///////////////////////////////////////////////////////////////////////////////////////////////
	////////////////////////////УДАЛЕНИЕ ДВУМЕРНОГО ДИНАМИЧЕСКОГО МАССИВА://///////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////
	// 1.	Удаляем строки двумерного массива:
	for (int i = 0; i < m; i++)
	{
		delete[] arr[i];
	}
	// 2. Удаляем массив указателей:
	delete[]arr;
	////////////////////////////////////////////////////////////////////////////////////////////
#endif // DYNAMIC_2

}

void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 100;
	}
}
void FillRand(int** arr, const int m, const int n)
{
	for (int i = 0; i < m; i++)
	{
		arr[i] = new int[n] {};
	}

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			arr[i][j] = rand() % 100;
		}
	}
}
void Print(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << *(arr + i) << "\t";
	}
	cout << endl;
}
void Print(int** arr, const int m, const int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
}
int* push_back(int arr[], int& n, int value)
{
	//Создаём буферный массив нужного размера (на 1 элемент больше): 
	int*buffer = new int[n + 1]{};

	//Копируем все значения в новый массив:
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}

	//Удаляем исходный массив:
	delete[] arr;

	//Подменяем исходный массив буфферным: 
	arr = buffer;


	//Добавляем значение в конец массива
	arr[n] = value;

	//После того,как в массиве добавился элемент, количество его элементов увеличивается на 1:
	n++;
	return arr;
}
int* push_front(int arr[], int& n, int value)
{
	int*buffer = new int[n + 1]{};
	for (int i = 0; i < n; i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[0] = value;
	n++;
	return arr;
}
int* insert(int arr[], int& n, int value, int index)

{
	if (index >= n)return arr;
	int* buffer = new int[n + 1];
	//Часть массива копируем соответственно:
	for (int i = 0; i < index; i++)
	{
		buffer[i] = arr[i];
	}
	//Оставшуюся часть массива копируем со смещением:
	for (int i = index; i < n; i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[index] = value;
	n++;
	return arr;
}