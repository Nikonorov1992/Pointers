#include<iostream>
using namespace std;
//#define START
//#define POINTER_ARITHMETICS
void main()
{
	setlocale(LC_ALL, "Russian");
#ifdef START
		int a = 2;	//���������� ����������
	int* pa = &a;	//Pointer to 'a'
	//& - �������� ������ ������
	cout << a << endl;	// ����� ���������� 'a' �� �����
	cout << &a << endl;	// ��������� ������ ���������� 'a' ��� ������
	cout << pa << endl;	// ����� ������ ���������� 'a', ����������� � ��������� '��'
	cout << *pa << endl;// ������������� ��������� '��' � ��������� �������� �� ������ � ���� ���������
	// * - �������� ������������� (Dereference operator)



	int* pointer;
	int b = 3;
	pointer = &b;
	/*
	int - int;
	int* - ��������� �� int
	double - double;
	double* - ��������� �� double
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


	//Reference - ��� ����������, ������� �������� ����� ������ ����������.

	int a = 2;
	int& ra = a;
	ra += 3;
	cout << &a << endl;
	cout << &ra << endl;
}