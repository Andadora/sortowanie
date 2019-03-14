#ifndef TABLICA_H
#define TABLICA_H

#include <iostream>
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
	void mergesort(unsigned int min, unsigned int max);
	void merge(unsigned int min, unsigned int max);
	void quicksort(unsigned int min, unsigned int max);
	void sort(unsigned int min, unsigned int max);
};

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
void Tablica<Typ, rozmiar>::quicksort(unsigned int min, unsigned int max)
{
	unsigned int pivot = rand() % (max - min) + min;
	Typ temp = (*this)[pivot];
	(*this)[pivot] = (*this)[max];
	(*this)[max] = temp;
	(*this).sort(min, max);
}

template<typename Typ, unsigned int rozmiar>
void Tablica<Typ, rozmiar>::sort(unsigned int min, unsigned int max)
{
	Typ temp = 0;
	int border = min;
	unsigned int k = min;

	while (k < max) {
		if ((*this)[k] < (*this)[max]) {
			temp = (*this)[border];
			(*this)[border] = (*this)[k];
			(*this)[k] = temp;
			k++;
			border++;
		}
		else {
			k++;
		}
	}
	temp = (*this)[border];
	(*this)[border] = (*this)[max];
	(*this)[max] = temp;

	if (min + 1 < border) {
		(*this).quicksort(min, border - 1);
	}
	if (border + 1 < max) {
		(*this).quicksort(border + 1, max);
	}
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