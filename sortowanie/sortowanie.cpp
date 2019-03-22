#include "pch.h"
#include "tablica.h"
#include <iostream>
#include <cstdlib>
#include <cstddef>
#include <ctime>
#include <chrono>

using namespace std;


int main()
{
	srand(time(NULL));
	auto start = chrono::high_resolution_clock::now(), stop = start;
	const int rozmiar = 10000;
	Tablica<int, rozmiar> liczby;

	int min = 0;
	int max = rozmiar - 1;

	cout << "10 000 \nodwrotnie:\t losowo:\t 25posortowane:\t 50posortowane:\t 75posortowane:\t 95posortowane:\t 99posortowane:\t 997posortowane:\n";
	for (int i = 0; i < 80; i++) {
		if (i % 8 == 0) {
			liczby.wypelnij_posortowane_odwrotnie();
		}
		if (i % 8 == 1) {
			liczby.wypelnij_losowo();
		}
		if (i % 8 == 2) {
			liczby.wypelnij_25posortowane();
		}
		if (i % 8 == 3) {
			liczby.wypelnij_50posortowane();
		}
		if (i % 8 == 4) {
			liczby.wypelnij_75posortowane();
		}
		if (i % 8 == 5) {
			liczby.wypelnij_95posortowane();
		}
		if (i % 8 == 6) {
			liczby.wypelnij_99posortowane();
		}
		if (i % 8 == 7) {
			liczby.wypelnij_997posortowane();
		}
		start = chrono::high_resolution_clock::now();
		liczby.quicksort(min, max);
		stop = chrono::high_resolution_clock::now();
		cout << chrono::duration_cast<chrono::milliseconds>(stop - start).count() << "\t\t ";
		liczby.czy_posortowane();
		if (i % 8 == 7) cout << "\n";
	}

	return 0;
}
