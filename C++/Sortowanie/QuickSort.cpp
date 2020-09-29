#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

void quick_sort(vector<int>&liczby, int lewy, int prawy)
{
	int i, j, obrot;

	i = (lewy + prawy) / 2;
	obrot = liczby[i];
	liczby[i] = liczby[prawy];
	for (j = i = lewy; i < prawy; i++)
		if (liczby[i] < obrot)
		{
			swap(liczby[i], liczby[j]);
			j++;
		}
	liczby[prawy] = liczby[j]; liczby[j] = obrot;
	if (lewy < j - 1)  quick_sort(liczby, lewy, j - 1);
	if (j + 1 < prawy) quick_sort(liczby, j + 1, prawy);
}
int main()
{
	srand(time(NULL));
	int rozmiar, liczba;
	vector<int>liczby;
	fstream plik;

	plik.open("Liczby.txt", ios::in);
	liczby.push_back(0);
	while (plik >> liczba) liczby.push_back(liczba);

	rozmiar=liczby.size();

	clock_t start = clock();
	quick_sort(liczby, 0, rozmiar - 1);
	clock_t stop = clock();
	double czas = double(stop - start) / CLOCKS_PER_SEC;
	cout << "Wynik Quick Sort: " << czas << endl;

	ofstream fileOut("quicksort.txt");
	for (int i = 0; i < rozmiar; i++)
	{
		fileOut << liczby[i] << endl;
	}

	fileOut.close();

	system("pause");

	return 0;
}