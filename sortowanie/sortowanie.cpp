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
	
	const int rozmiar1 = 10000, rozmiar2 = 50000, rozmiar3 = 100000, rozmiar4 = 500000, rozmiar5 = 1000000;
	Tablica<int, rozmiar1> liczby1;
	Tablica<int, rozmiar2> liczby2;
	Tablica<int, rozmiar3> liczby3;
	Tablica<int, rozmiar4> liczby4;
	Tablica<int, rozmiar5> liczby5;

	int min = 0, max = 0, i = 0;
	
	max = rozmiar1 - 1;
	cout << "10000;\nodwrotnie:;losowo:;25posortowane:;50posortowane:;75posortowane:;95posortowane:;99posortowane:;997posortowane:;\n";
	for (i = 0; i < 800; i++) {
		if (i % 8 == 0) {
			liczby1.wypelnij_posortowane_odwrotnie();
		}
		if (i % 8 == 1) {
			liczby1.wypelnij_losowo();
		}
		if (i % 8 == 2) {
			liczby1.wypelnij_25posortowane();
		}
		if (i % 8 == 3) {
			liczby1.wypelnij_50posortowane();
		}
		if (i % 8 == 4) {
			liczby1.wypelnij_75posortowane();
		}
		if (i % 8 == 5) {
			liczby1.wypelnij_95posortowane();
		}
		if (i % 8 == 6) {
			liczby1.wypelnij_99posortowane();
		}
		if (i % 8 == 7) {
			liczby1.wypelnij_997posortowane();
		}
		start = chrono::high_resolution_clock::now();
		liczby1.introsort(min, max);
		stop = chrono::high_resolution_clock::now();
		cout << chrono::duration_cast<chrono::milliseconds>(stop - start).count() << ";";
		liczby1.czy_posortowane();
		if (i % 8 == 7) cout << "\n";
	}

	max = rozmiar2 - 1;
	cout << "50000;\nodwrotnie:;losowo:;25posortowane:;50posortowane:;75posortowane:;95posortowane:;99posortowane:;997posortowane:;\n";
	for (i = 0; i < 800; i++) {
		if (i % 8 == 0) {
			liczby2.wypelnij_posortowane_odwrotnie();
		}
		if (i % 8 == 1) {
			liczby2.wypelnij_losowo();
		}
		if (i % 8 == 2) {
			liczby2.wypelnij_25posortowane();
		}
		if (i % 8 == 3) {
			liczby2.wypelnij_50posortowane();
		}
		if (i % 8 == 4) {
			liczby2.wypelnij_75posortowane();
		}
		if (i % 8 == 5) {
			liczby2.wypelnij_95posortowane();
		}
		if (i % 8 == 6) {
			liczby2.wypelnij_99posortowane();
		}
		if (i % 8 == 7) {
			liczby2.wypelnij_997posortowane();
		}
		start = chrono::high_resolution_clock::now();
		liczby2.introsort(min, max);
		stop = chrono::high_resolution_clock::now();
		cout << chrono::duration_cast<chrono::milliseconds>(stop - start).count() << ";";
		liczby2.czy_posortowane();
		if (i % 8 == 7) cout << "\n";
	}

	max = rozmiar3 - 1;
	cout << "100000;\nodwrotnie:;losowo:;25posortowane:;50posortowane:;75posortowane:;95posortowane:;99posortowane:;997posortowane:;\n";
	for (i = 0; i < 800; i++) {
		if (i % 8 == 0) {
			liczby3.wypelnij_posortowane_odwrotnie();
		}
		if (i % 8 == 1) {
			liczby3.wypelnij_losowo();
		}
		if (i % 8 == 2) {
			liczby3.wypelnij_25posortowane();
		}
		if (i % 8 == 3) {
			liczby3.wypelnij_50posortowane();
		}
		if (i % 8 == 4) {
			liczby3.wypelnij_75posortowane();
		}
		if (i % 8 == 5) {
			liczby3.wypelnij_95posortowane();
		}
		if (i % 8 == 6) {
			liczby3.wypelnij_99posortowane();
		}
		if (i % 8 == 7) {
			liczby3.wypelnij_997posortowane();
		}
		start = chrono::high_resolution_clock::now();
		liczby3.introsort(min, max);
		stop = chrono::high_resolution_clock::now();
		cout << chrono::duration_cast<chrono::milliseconds>(stop - start).count() << ";";
		liczby3.czy_posortowane();
		if (i % 8 == 7) cout << "\n";
	}
	
	max = rozmiar4 - 1;
	cout << "500000;\nodwrotnie:;losowo:;25posortowane:;50posortowane:;75posortowane:;95posortowane:;99posortowane:;997posortowane:;\n";
	for (i = 0; i < 800; i++) {
		if (i % 8 == 0) {
			liczby4.wypelnij_posortowane_odwrotnie();
		}
		if (i % 8 == 1) {
			liczby4.wypelnij_losowo();
		}
		if (i % 8 == 2) {
			liczby4.wypelnij_25posortowane();
		}
		if (i % 8 == 3) {
			liczby4.wypelnij_50posortowane();
		}
		if (i % 8 == 4) {
			liczby4.wypelnij_75posortowane();
		}
		if (i % 8 == 5) {
			liczby4.wypelnij_95posortowane();
		}
		if (i % 8 == 6) {
			liczby4.wypelnij_99posortowane();
		}
		if (i % 8 == 7) {
			liczby4.wypelnij_997posortowane();
		}
		start = chrono::high_resolution_clock::now();
		liczby4.introsort(min, max);
		stop = chrono::high_resolution_clock::now();
		cout << chrono::duration_cast<chrono::milliseconds>(stop - start).count() << ";";
		liczby4.czy_posortowane();
		if (i % 8 == 7) cout << "\n";
	}
	
	max = rozmiar5 - 1;
	cout << "1000000;\nodwrotnie:;losowo:;25posortowane:;50posortowane:;75posortowane:;95posortowane:;99posortowane:;997posortowane:;\n";
	for (i = 0; i < 800; i++) {
		if (i % 8 == 0) {
			liczby5.wypelnij_posortowane_odwrotnie();
		}
		if (i % 8 == 1) {
			liczby5.wypelnij_losowo();
		}
		if (i % 8 == 2) {
			liczby5.wypelnij_25posortowane();
		}
		if (i % 8 == 3) {
			liczby5.wypelnij_50posortowane();
		}
		if (i % 8 == 4) {
			liczby5.wypelnij_75posortowane();
		}
		if (i % 8 == 5) {
			liczby5.wypelnij_95posortowane();
		}
		if (i % 8 == 6) {
			liczby5.wypelnij_99posortowane();
		}
		if (i % 8 == 7) {
			liczby5.wypelnij_997posortowane();
		}
		start = chrono::high_resolution_clock::now();
		liczby5.introsort(min, max);
		stop = chrono::high_resolution_clock::now();
		cout << chrono::duration_cast<chrono::milliseconds>(stop - start).count() << ";";
		liczby5.czy_posortowane();
		if (i % 8 == 7) cout << "\n";
	}
	
	return 0;
}
