#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

vector<int> uzupelnij(vector<int>tab, int size)
{
	for (int i = 0; i < size; i++)
		tab.push_back(0);
	return tab;
}

void wyswietl(vector<int>tab, int size)
{
	cout << "TEST";
	for (int i = 0; i < size; i++)
		cout << i + 1 << ": " << tab[i] << endl;
}

void zmien(vector<int>tab, int size, string nazwa)
{
	ofstream fileOut(nazwa);
	for (int i = 0; i < size; i++)
	{
		fileOut << tab[i] << endl;
	}

	fileOut.close();
}

vector<int> wrzuc(vector<int>tab, string nazwa)
{
	fstream fileIn;
	int liczba;
	fileIn.open(nazwa);
	if (!fileIn.good())
		cout << "BLAD!" << endl;

	while (fileIn >> liczba)
		tab.push_back(liczba);

	fileIn.close();

	return tab;
}

void zrob(vector<int>tab, int size, int x, int y, string nazwa)
{
	int liczba;
	ofstream fileOut(nazwa);
	for (int i = 0; i < size; i++)
	{
		liczba = (std::rand() % x) + y;
		fileOut << liczba << endl;

	}

	fileOut.close();
}

void sort_bubble(vector<int>tab, int size, string nazwa)
{
	clock_t start = clock();
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size - 1; j++)
		{
			if (tab[j] > tab[j + 1])
				swap(tab[j], tab[j + 1]);

		}
	}

	zmien(tab, size, nazwa);

	clock_t stop = clock();
	double czas = double(stop - start) / CLOCKS_PER_SEC;
	cout << "Wynik sortowanie babelkowy: " << czas << endl;
}


int main() {
	vector<int>liczby;

	liczby = wrzuc(liczby, "liczby.txt");


	sort_bubble(liczby, liczby.size(), "Bubble.txt");

	system("pause");

	return 0;
}