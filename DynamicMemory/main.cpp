#include <iostream>
using namespace std;
//#define NUM_1
//#define DEBUG_ASSERTION_FAILED_1
//#define DEBUG_ASSERTION_FAILED_2

void Print(int arr[], const int n);
void FillRand(int arr[], const int n);

int* push_back(int arr[], int& n, int value);
int* push_front(int arr[], int& n, int value);
int* insert(int arr[], int& n, int value,int index);

void main()
{
	setlocale(LC_ALL, "");
#ifdef NUM_1
	int n;	//������ �������
	cout << "������� ������ �������: "; cin >> n;
	int* arr = new int[n] {3, 5, 8};	//Heap - ����; �������� ������ ��� ������



	FillRand(arr, n);
	Print(arr, n);
	int value;
	cout << "������� ����������� ��������: "; cin >> value;
	//1) ������ �������� ������ ������� �������:
	int*buffer = new int[n + 1];
	//2) �������� �������� ������ � ��������:
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	//3) ������� �������� ������: 
	delete[] arr;
	//arr[n]=value;

	//4) ��������� �������� ������:
	arr = buffer;
	//5) ��������� ��������:
	arr[n] = value;
	//6 ����������� ������ �������: 
	n++;
	Print(arr, n);
	delete[] arr;		//����������� ������,���������� ��������  
#endif // DEBUG
	int n;
#ifdef DEBUG_ASSERTION_FAILED_1
	int*pn = &n;
	delete[] pn;
#endif // DEBUG_ASSERTION_FAILED_1

	cout << "������� ������ �������: "; cin >> n;
	int* arr = new int[n] {3, 5, 8};
	FillRand(arr, n);
	Print(arr, n);

	int value;
	cout << "������� ����������� ��������: "; cin >> value;
	arr = push_back(arr,n,value);
	Print(arr, n);
	cout << "������� ����������� ��������: "; cin >> value;
	arr = push_front(arr, n, value);
	Print(arr, n);

	int index;
		cout << "������� ����������� ��������: "; cin >> value;
		cout << "������� �����: "; cin >> index;
		arr = insert(arr, n, value, index);
		Print(arr, n);

#ifdef DEBUG_ASSERTION_FAILED_2
	delete[] buffer;
#endif // DEBUG_ASSERTION_FAILED_2

	delete[] arr;
}

void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 100;
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

int* push_back(int arr[], int& n, int value)
{
	//������ �������� ������ ������� ������� (�� 1 ������� ������): 
	int*buffer = new int[n + 1]{};

	//�������� ��� �������� � ����� ������:
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}

	//������� �������� ������:
	delete[] arr;

	//��������� �������� ������ ���������: 
	arr = buffer;


	//��������� �������� � ����� �������
	arr[n] = value;

	//����� ����,��� � ������� ��������� �������, ���������� ��� ��������� ������������� �� 1:
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
	//����� ������� �������� ��������������:
	for (int i = 0; i < index; i++)
	{
		buffer[i] = arr[i];
	}
	//���������� ����� ������� �������� �� ���������:
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