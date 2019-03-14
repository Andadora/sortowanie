#include "pch.h"
#include "tablica.h"
#include <iostream>
#include <cstdlib>
#include <cstddef>
#include <ctime>

using namespace std;

int main()
{
	srand(time(NULL));
	const int rozmiar = 10;
	Tablica<int, rozmiar> liczby;

	for (int i = 0; i < rozmiar; i++) {
		liczby[i] = double(rand() % 100); // (rand() % 10 + 1);
	}

	int ind_min = 0;
	int ind_max = rozmiar - 1;

	cout << liczby << "\n";

	liczby.mergesort(ind_min, ind_max);

	cout << "\n Posortowane liczby (quicksort): \n" << liczby << "\n";

	return 0;
}
