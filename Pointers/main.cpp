#include<iostream>
using namespace std;
//#define START
//#define POINTER_ARITHMETICS
void main()
{
	setlocale(LC_ALL, "Russian");
#ifdef START
		int a = 2;	//Объявление переменной
	int* pa = &a;	//Pointer to 'a'
	//& - Оператор взятия адреса
	cout << a << endl;	// Вывод переменной 'a' на экран
	cout << &a << endl;	// Получение адреса переменной 'a' при выводе
	cout << pa << endl;	// Вывод адреса переменной 'a', хранящегося в указателе 'ра'
	cout << *pa << endl;// Разыменование указателя 'ра' и получение значения по адресу в этом указателе
	// * - Оператор разыменования (Dereference operator)



	int* pointer;
	int b = 3;
	pointer = &b;
	/*
	int - int;
	int* - Указатель на int
	double - double;
	double* - Указатель на double
	*/


	double price = 2.5;
	double* p_price;
#endif START
#ifdef POINTER_ARITHMETICS
	const int n = 5;
	int arr[n] = { 3,5,8,13,21 };
	cout << *arr << endl;
	for (int i = 0; i < n; i++)
	{
		cout << *(arr + i) << "\t";
	}
	cout << endl;
#endif POINTER_ARITHMETICS


	//Reference - это переменная, которая содержит адрес другой переменной.

	int a = 2;
	int& ra = a;
	ra += 3;
	cout << &a << endl;
	cout << &ra << endl;
}