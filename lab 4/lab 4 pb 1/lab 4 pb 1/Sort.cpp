#include "Sort.h"
#include <random>
#include <iostream>
#include <sstream>
using namespace std;

Sort::Sort(int n, int mini, int maxi)
{
	this->lista = new int[n];
	this->nr_elem = n;

	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dis(mini, maxi);

	for (int i = 0; i < this->nr_elem; i++)
	{
		this->lista[i] = dis(gen);
	}
}

Sort::Sort(std::initializer_list<int> initList) {
	this->nr_elem = initList.size();
	this->lista = new int[nr_elem];
	int index = 0;
	for (int elem : initList) {
		this->lista[index++] = elem;
	}
}

Sort::Sort(int* lista, int n)
{
	this->nr_elem = n;
	this->lista = new int[n];
	for (int i = 0; i < this->nr_elem; i++)
	{
		this->lista[i] = lista[i];
	}
}

Sort::Sort(int n, ...)
{
	this->nr_elem = n;
	this->lista = new int[n];
	va_list args;
	va_start(args, n);
	for (int i = 0; i < n; i++)
		this->lista[i] = va_arg(args, int);
	va_end(args);
}

Sort::Sort(const string& sir)
{
	this->nr_elem = 1;
	for (char c : sir)
		if (c == ',') this->nr_elem++;
	this->lista = new int[this->nr_elem];
	stringstream ss(sir);
	string item;
	int index = 0;
	while (getline(ss, item, ',')) {
		this->lista[index++] = stoi(item);
	}
}

Sort::~Sort()
{
	delete[] this->lista;
}

void Sort::InsertSort(bool ascendent)
{
	for (int i = 1; i < nr_elem; i++)
	{
		int a = lista[i];
		int j = i - 1;
		while (j >= 0 && ((ascendent && lista[j] > a) || (!ascendent && lista[j] < a)))
		{
			lista[j + 1] = lista[j];
			j--;
		}
		lista[j + 1] = a;
	}
}

void  Sort::QuickSortR(int low, int high, bool ascendent)
{
	if (low < high)
	{
		int pivot = Partition(low, high, ascendent);
		QuickSortR(low, pivot - 1, ascendent);
		QuickSortR(pivot + 1, high, ascendent);
	}
}

void Sort::QuickSort(bool ascendent)
{
	QuickSortR(0, nr_elem - 1, ascendent);
}

void Sort::BubbleSort(bool ascendent)
{
	for(int i=0; i<nr_elem; i++)
		for(int j=0; j<nr_elem-i-1; j++)
			if ((ascendent && lista[j] > lista[j + 1]) || (!ascendent && lista[j] < lista[j + 1])) {
				swap(lista[j], lista[j + 1]);
			}
}

int Sort::Partition(int low, int high, bool ascendent) {
	int pivot = lista[high];
	int i = (low - 1);

	for (int j = low; j <= high - 1; j++) {
		if (ascendent ? (lista[j] < pivot) : (lista[j] > pivot)) {
			i++;
			swap(lista[i], lista[j]);
		}
	}
	swap(lista[i + 1], lista[high]);
	return (i + 1);
}

void Sort::Print() {
	for (int i = 0; i < nr_elem; i++) {
		cout << lista[i] << (i < nr_elem - 1 ? ", " : "");
	}
	cout << endl;
}

int Sort::GetElementsCount()
{
	return nr_elem;
}

int Sort::GetElementFromIndex(int index)
{
	if (index >= 0 && index < nr_elem)
		return lista[index];
	return -1;
}