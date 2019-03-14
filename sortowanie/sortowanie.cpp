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
	const int rozmiar = 12;
	Tablica<int, rozmiar> liczby;

	liczby.wypelnij_75posortowane();

	int ind_min = 0;
	int ind_max = rozmiar - 1;

	cout << liczby << "\n";

	liczby.mergesort(ind_min, ind_max);

	cout << "\n Posortowane liczby (quicksort): \n" << liczby << "\n";

	return 0;
}
