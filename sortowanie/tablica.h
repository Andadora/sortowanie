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

	void wypelnij_losowo();
	void wypelnij_25posortowane();
	void wypelnij_50posortowane();
	void wypelnij_75posortowane();
	void wypelnij_95posortowane();
	void wypelnij_99posortowane();
	void wypelnij_997posortowane();
	void wypelnij_posortowane_odwrotnie();

	void odwroc();

	void mergesort(unsigned int min, unsigned int max);
	void merge(unsigned int min, unsigned int max);

	void quicksort(unsigned int min, unsigned int max);
	void sort(unsigned int min, unsigned int max);
};

template<typename Typ, unsigned int rozmiar>
void Tablica<Typ, rozmiar>::wypelnij_losowo()
{
	for (int i = 0; i < rozmiar; i++) {
		(*this)[i] = double(rand() % 1000); // (rand() % 10 + 1);
	}
}

template<typename Typ, unsigned int rozmiar>
void Tablica<Typ, rozmiar>::wypelnij_25posortowane()
{
	for (int i = 0 ; i < rozmiar * 0.25 ; i++) {
		(*this)[i] = double(rand() % 250); // (rand() % 10 + 1);
	}
	(*this).mergesort(0, rozmiar * 0.25 - 1);
	for (int i = rozmiar * 0.25; i < rozmiar ; i++) {
		(*this)[i] = double(rand() % 750)+250; // (rand() % 10 + 1) + 25;
	}
}

template<typename Typ, unsigned int rozmiar>
void Tablica<Typ, rozmiar>::wypelnij_50posortowane()
{
	for (int i = 0; i < rozmiar * 0.5; i++) {
		(*this)[i] = double(rand() % 500); // (rand() % 10 + 1);
	}
	(*this).mergesort(0, rozmiar * 0.5 - 1);
	for (int i = rozmiar * 0.5; i < rozmiar; i++) {
		(*this)[i] = double(rand() % 500) + 500; // (rand() % 10 + 1) + 25;
	}
}

template<typename Typ, unsigned int rozmiar>
void Tablica<Typ, rozmiar>::wypelnij_75posortowane()
{
	for (int i = 0; i < rozmiar * 0.75; i++) {
		(*this)[i] = double(rand() % 750); // (rand() % 10 + 1);
	}
	(*this).mergesort(0, rozmiar * 0.75 - 1);
	for (int i = rozmiar * 0.75; i < rozmiar; i++) {
		(*this)[i] = double(rand() % 250) + 750; // (rand() % 10 + 1) + 25;
	}
}

template<typename Typ, unsigned int rozmiar>
void Tablica<Typ, rozmiar>::wypelnij_95posortowane()
{
	for (int i = 0; i < rozmiar * 0.95; i++) {
		(*this)[i] = double(rand() % 950); // (rand() % 10 + 1);
	}
	(*this).mergesort(0, rozmiar * 0.95 - 1);
	for (int i = rozmiar * 0.95; i < rozmiar; i++) {
		(*this)[i] = double(rand() % 50) + 950; // (rand() % 10 + 1) + 25;
	}
}

template<typename Typ, unsigned int rozmiar>
void Tablica<Typ, rozmiar>::wypelnij_99posortowane()
{
	for (int i = 0; i < rozmiar * 0.99; i++) {
		(*this)[i] = double(rand() % 990); // (rand() % 10 + 1);
	}
	(*this).mergesort(0, rozmiar * 0.99 - 1);
	for (int i = rozmiar * 0.99; i < rozmiar; i++) {
		(*this)[i] = double(rand() % 10) + 990; // (rand() % 10 + 1) + 25;
	}
}

template<typename Typ, unsigned int rozmiar>
void Tablica<Typ, rozmiar>::wypelnij_997posortowane()
{
	for (int i = 0; i < rozmiar * 0.997; i++) {
		(*this)[i] = double(rand() % 997); // (rand() % 10 + 1);
	}
	(*this).mergesort(0, rozmiar * 0.997 - 1);
	for (int i = rozmiar * 0.997; i < rozmiar; i++) {
		(*this)[i] = double(rand() % 3) + 997; // (rand() % 10 + 1) + 25;
	}
}

template<typename Typ, unsigned int rozmiar>
void Tablica<Typ, rozmiar>::wypelnij_posortowane_odwrotnie()
{
	(*this).wypelnij_losowo();
	(*this).mergesort(0,rozmiar-1);
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
		unsigned int i = min;								//pocz�tkowy indeks pierwszej czesci liczb
		unsigned int j = (min + max) / 2 + 1;				//pocz�tkowy indeks drugiej czesci liczb
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