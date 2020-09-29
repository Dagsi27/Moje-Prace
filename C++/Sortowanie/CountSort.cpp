#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

int max(vector<int> tab)
{
	int wynik = tab[0];
	for (int i = 0; i < tab.size(); i++)
		if (wynik < tab[i])
			wynik = tab[i];

	return wynik;
}

int min(vector<int> tab)
{
	int wynik = tab[0];
	for (int i = 0; i < tab.size(); i++)
		if (wynik > tab[i])
			wynik = tab[i];

	return wynik;
}

void countsort(vector<int>&liczby, int od, int doo, int n) {
	int dl = doo - od + 1;
	int* zlicz = new int[dl];
	for (int i = 0; i < dl; i++)
		zlicz[i] = 0;
	for (int i = 0; i < n; i++)
		zlicz[liczby[i] - od]++;
	int x = 0;
	for (int i = 0; i < dl; i++)
		for (int j = 0; j < zlicz[i]; j++)
			liczby[x++] = i + od;
}

int main()
{
	srand(time(NULL));
	int rozmiar, liczba;
	vector<int>liczby;
	fstream plik;

	plik.open("Liczby.txt", ios::in);
	while (plik >> liczba) liczby.push_back(liczba);

	rozmiar = liczby.size();

	clock_t start = clock();
	countsort(liczby, min(liczby), max(liczby), rozmiar);
	clock_t stop = clock();
	double czas = double(stop - start) / CLOCKS_PER_SEC;
	cout << czas << endl;

	ofstream fileOut("Przez_Zliczanie.txt");
	for (int i = 0; i < rozmiar; i++)
	{
		fileOut << liczby[i] << endl;
	}

	fileOut.close();

	system("pause");

	return 0;
}