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
	const int rozmiar = 11;
	Tablica<int, rozmiar> liczby;

	liczby.wypelnij_posortowane_odwrotnie();

	int min = 0;
	int max = rozmiar - 1;

	cout << liczby << "\n";

	liczby.quicksort(min, max);

	cout << "\n Posortowane liczby: \n" << liczby << "\n";

	return 0;
}
