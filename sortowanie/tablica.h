#ifndef TABLICA_H
#define TABLICA_H

#include <iostream>
#include <chrono>
using namespace std;

template <typename Typ, unsigned int rozmiar>
class Tablica {
public:
	Typ *tab;
public:
	Tablica() {
		tab = new Typ[rozmiar];
		for (int i = 0; i < rozmiar; ++i) {
			(*this)[i] = 0;
		}
	}
	Tablica(const Tablica<Typ, rozmiar>  & tab_kop) {
		tab = new Typ[rozmiar];
		for (int i = 0; i < rozmiar; ++i) {
			(*this)[i] = tab_kop[i];
		}
	}
	~Tablica() { delete[] tab; }

	Typ & operator [] (unsigned int indeks) { return tab[indeks]; }
	Typ   operator [] (unsigned int indeks) const { return tab[indeks]; }

	void wypelnij_losowo();
	void wypelnij_25posortowane();
	void wypelnij_50posortowane();
	void wypelnij_75posortowane();
	void wypelnij_95posortowane();
	void wypelnij_99posortowane();
	void wypelnij_997posortowane();
	void wypelnij_posortowane_odwrotnie();

	void odwroc();
	bool czy_posortowane();
	void swap(unsigned int first, unsigned int second);
	int mediana_z_trzech(int first, int second, int third);

	void mergesort(unsigned int min, unsigned int max);
	void merge(unsigned int min, unsigned int max);

	void quicksort_old(unsigned int min, unsigned int max);
	void cut_off_quicksort_old(unsigned int min, unsigned int max, int M);

	void quicksort(int min, int max);
	void cut_off_quicksort(int min, int max, int M);

	void heapsort_old(unsigned int min, unsigned int max);
	void maxheap_old(unsigned int parent, unsigned int min, unsigned int size);

	void heapsort(int min, int max);
	void heap(int min, int max);
	void deheap(int min, int max);

	void introsort(unsigned int min, unsigned int max);
};

template<typename Typ, unsigned int rozmiar>
void Tablica<Typ, rozmiar>::wypelnij_losowo()
{
	for (int i = 0; i < rozmiar; i++) {
		(*this)[i] = double(rand() % 1000);
	}
}

template<typename Typ, unsigned int rozmiar>
void Tablica<Typ, rozmiar>::wypelnij_25posortowane()
{
	(*this).wypelnij_losowo();
	(*this).heapsort(0, rozmiar * 0.25 - 1);
}

template<typename Typ, unsigned int rozmiar>
void Tablica<Typ, rozmiar>::wypelnij_50posortowane()
{
	(*this).wypelnij_losowo();
	(*this).heapsort(0, rozmiar * 0.5 - 1);
}

template<typename Typ, unsigned int rozmiar>
void Tablica<Typ, rozmiar>::wypelnij_75posortowane()
{
	(*this).wypelnij_losowo();
	(*this).heapsort(0, rozmiar * 0.75 - 1);
}

template<typename Typ, unsigned int rozmiar>
void Tablica<Typ, rozmiar>::wypelnij_95posortowane()
{
	(*this).wypelnij_losowo();
	(*this).heapsort(0, rozmiar * 0.95 - 1);
}

template<typename Typ, unsigned int rozmiar>
void Tablica<Typ, rozmiar>::wypelnij_99posortowane()
{
	(*this).wypelnij_losowo();
	(*this).heapsort(0, rozmiar * 0.99 - 1);
}

template<typename Typ, unsigned int rozmiar>
void Tablica<Typ, rozmiar>::wypelnij_997posortowane()
{
	(*this).wypelnij_losowo();
	(*this).heapsort(0, rozmiar * 0.997 - 1);
}

template<typename Typ, unsigned int rozmiar>
void Tablica<Typ, rozmiar>::wypelnij_posortowane_odwrotnie()
{
	(*this).wypelnij_losowo();
	(*this).heapsort(0,rozmiar-1);
	(*this).odwroc();
}

template<typename Typ, unsigned int rozmiar>
void Tablica<Typ, rozmiar>::odwroc() {
	Typ temp = 0;
	for (int i = 0; i < rozmiar / 2 ; i++) {
		temp = (*this)[i];
		(*this)[i] = (*this)[rozmiar - 1 - i];
		(*this)[rozmiar - 1 - i] = temp;
	}
}

template<typename Typ, unsigned int rozmiar>
bool Tablica<Typ, rozmiar>::czy_posortowane()
{
	unsigned int i = 0;
	while (i < rozmiar - 1) {
		if ((*this)[i] <= (*this)[i + 1]) {
			i++;
		}
		else {
			cout << "liczby nie sa posortowane \n";
			return false;
		}
	}
	return true;
}

template<typename Typ, unsigned int rozmiar>
void Tablica<Typ, rozmiar>::swap(unsigned int first, unsigned int second)
{
	Typ temp = 0;
	temp = (*this)[first];
	(*this)[first] = (*this)[second];
	(*this)[second] = temp;
}

template<typename Typ, unsigned int rozmiar>
int Tablica<Typ, rozmiar>::mediana_z_trzech(int first, int second, int third)
{
	if ((*this)[first] >= (*this)[second] && (*this)[first] >= (*this)[third]) {
		if ((*this)[second] >= (*this)[third]) {
			return second;
		}
		else { return third; }
	}
	else if ((*this)[first] <= (*this)[second] && (*this)[first] <= (*this)[third]) {
		if ((*this)[second] <= (*this)[third]) {
			return second;
		}
		else { return third; }
	}
	else {
		return first;
	}
}

template<typename Typ, unsigned int rozmiar>
void Tablica<Typ, rozmiar>::mergesort(unsigned int min, unsigned int max)
{
	if (min < max) {
		(*this).mergesort(min, (min + max) / 2);
		(*this).mergesort((min + max) / 2 + 1, max);
	}
	(*this).merge(min, max);
}

template<typename Typ, unsigned int rozmiar>
void Tablica<Typ, rozmiar>::merge(unsigned int min, unsigned int max)
{
	if (min < max) {
		Typ * temp = new Typ[max - min + 1];
		unsigned int t = 0;									//indeks tablicy tymczasowej
		unsigned int i = min;								//pocz¹tkowy indeks pierwszej czesci liczb
		unsigned int j = (min + max) / 2 + 1;				//pocz¹tkowy indeks drugiej czesci liczb
		while (i < (min + max) / 2 + 1 && j < max + 1) {
			if ((*this)[i] > (*this)[j]) {
				temp[t] = (*this)[j];
				t++;
				j++;
			}
			else {
				temp[t] = (*this)[i];
				t++;
				i++;
			}
		}
		while (i < (min + max) / 2 + 1) {
			temp[t] = (*this)[i];
			t++;
			i++;
		}
		while (j < max + 1) {
			temp[t] = (*this)[j];
			t++;
			j++;
		}
		for (t = 0; t < max - min + 1; t++) {
			(*this)[min + t] = temp[t];
		}
		delete[] temp;
	}
}

template<typename Typ, unsigned int rozmiar>
void Tablica<Typ, rozmiar>::quicksort_old(unsigned int min, unsigned int max)
{
	unsigned int pivot = (*this).mediana_z_trzech(rand() % (max - min) + min, rand() % (max - min) + min, rand() % (max - min) + min);
	(*this).swap(max, pivot);

	int border = min;
	unsigned int k = min;

	while (k < max) {
		if ((*this)[k] < (*this)[max]) {
			(*this).swap(k, border);
			k++;
			border++;
		}
		else {
			k++;
		}
	}
	(*this).swap(max, border);

	if (min + 1 < border) {
		(*this).quicksort_old(min, border - 1);
	}
	if (border + 1 < max) {
		(*this).quicksort_old(border + 1, max);
	}
}

template<typename Typ, unsigned int rozmiar>
void Tablica<Typ, rozmiar>::cut_off_quicksort_old(unsigned int min, unsigned int max, int M)
{
	if (M>0) {
		unsigned int pivot = (*this).mediana_z_trzech(rand() % (max - min) + min, rand() % (max - min) + min, rand() % (max - min) + min);
		(*this).swap(max, pivot); 
		
		int border = min;
		unsigned int k = min;

		while (k < max) {
			if ((*this)[k] < (*this)[max]) {
				(*this).swap(k, border);
				k++;
				border++;
			}
			else {
				k++;
			}
		}
		(*this).swap(max, border);
		if (min + 1 < border) {
			(*this).cut_off_quicksort_old(min, border - 1, M - 1);
		}
		if (border + 1 < max) {
			(*this).cut_off_quicksort_old(border + 1, max, M - 1);
		}
	}
	else {
		(*this).heapsort(min, max);
	}
}

template<typename Typ, unsigned int rozmiar>
void Tablica<Typ, rozmiar>::quicksort(int min, int max)
{
	if (min < max) {
		unsigned int pivot = rand() % (max - min) + min;
		Typ vpivot = (*this)[pivot];
		int i = min-1, j = max+1;

		while (1) {
			while (vpivot > (*this)[++i]);
			while (vpivot < (*this)[--j]);
			if (i <= j) {
				(*this).swap(i, j);
			}
			else break;
		}
		if (j > min)
			(*this).quicksort(min, j);
		if (i < max)
			(*this).quicksort(i, max);
	}
}

template<typename Typ, unsigned int rozmiar>
void Tablica<Typ, rozmiar>::cut_off_quicksort(int min, int max, int M)
{
	if (min < max) {
		if (M > 0) {
			unsigned int pivot = rand() % (max - min) + min;
			Typ vpivot = (*this)[pivot];
			int i = min - 1, j = max + 1;

			while (1) {
				while (vpivot > (*this)[++i]);
				while (vpivot < (*this)[--j]);
				if (i <= j) {
					(*this).swap(i, j);
				}
				else break;
			}
			if (j > min)
				(*this).cut_off_quicksort(min, j, M - 1);
			if (i < max)
				(*this).cut_off_quicksort(i, max, M - 1);
		}
		else {
			(*this).heapsort(min, max);
		}
	}
}

template<typename Typ, unsigned int rozmiar>
void Tablica<Typ, rozmiar>::heapsort_old(unsigned int min, unsigned int max)
{
	unsigned int size = max - min + 1;
	while (size > 1) {
		for (int i = size / 2 - 1; i >= 0; i--) {
			(*this).maxheap_old(i, min, size);
		}
		(*this).swap(min, size - 1 + min);
		size--;
	}
}

template<typename Typ, unsigned int rozmiar>
void Tablica<Typ, rozmiar>::maxheap_old(unsigned int parent, unsigned int min, unsigned int size)
{
	if (2 * parent + 2 < size) {
		if ((*this)[2 * parent + 2 + min] > (*this)[2 * parent + 1 + min]) {
			if ((*this)[2 * parent + 2 + min] > (*this)[parent + min]) {
				(*this).swap(2 * parent + 2 + min, parent + min);
				maxheap_old(2 * parent + 2, min, size);
			}
		}
		else if ((*this)[2 * parent + 1 + min] > (*this)[parent + min]) {
			(*this).swap(2 * parent + 1 + min, parent + min);
			maxheap_old(2 * parent + 1, min, size);
		}
	}
	else if (2 * parent + 1 < size) {
		if ((*this)[2 * parent + 1 + min] > (*this)[parent + min]) {
			(*this).swap(2 * parent + 1 + min, parent + min);
		}
	}
}

template<typename Typ, unsigned int rozmiar>
void Tablica<Typ, rozmiar>::heap(int min, int max)
{
	for (int i = min; i <= max; i++)
	{
		int child = i;
		int parent = (child + min - 1) / 2;
		Typ inserted = (*this)[i];

		while (child > min && (*this)[parent] < inserted)
		{
			(*this)[child] = (*this)[parent];

			child = parent;
			parent = (child + min - 1) / 2;
		}
		(*this)[child] = inserted;
	}
}

template<typename Typ, unsigned int rozmiar>
void Tablica<Typ, rozmiar>::deheap(int min, int max)
{
	for (int i = max; i > min; i--)
	{
		(*this).swap(min, i);

		int j = min, k = min + 1, m;

		while (k < i)
		{
			if (k + 1 < i && (*this)[k + 1] > (*this)[k])
				m = k + 1;
			else
				m = k;

			if ((*this)[m] > (*this)[j])
			{
				(*this).swap(j, m);
				j = m;
				k = 2 * j - min + 1;
			}
			else
				break;
		}
	}
}

template<typename Typ, unsigned int rozmiar>
void Tablica<Typ, rozmiar>::heapsort(int min, int max)
{
	(*this).heap(min, max);
	(*this).deheap(min, max);
}

template<typename Typ, unsigned int rozmiar>
void Tablica<Typ, rozmiar>::introsort(unsigned int min, unsigned int max)
{
	int M = log2(max - min + 1);
	(*this).cut_off_quicksort(min, max, M);
}

template <typename Typ, unsigned int rozmiar>
ostream& operator << (ostream &Strm, const Tablica<Typ, rozmiar>& Tab)
{
	for (int i = 0; i < rozmiar; ++i) {
		Strm << "  " << Tab[i];
	}
	return Strm;
}

template <typename Typ, unsigned int rozmiar>
istream& operator >> (istream &Strm, Tablica<Typ, rozmiar>& Tab)
{
	for (int i = 0; i < rozmiar; ++i) {
		Strm >> Tab[i];
	}
	return Strm;
}

#endif