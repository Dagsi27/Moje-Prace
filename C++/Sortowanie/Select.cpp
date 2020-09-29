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

void sort_wybieranie(vector<int>tab, int size, string nazwa)
{
	clock_t start = clock();
	int k;
	for (int i = 0; i < size; i++)
	{
		k = i;
		for (int j = i + 1; j < size; j++)
			if (tab[j] < tab[k])
				k = j;

		swap(tab[k], tab[i]);
	}
	zmien(tab, size, nazwa);
	clock_t stop = clock();
	double czas = double(stop - start) / CLOCKS_PER_SEC;
	cout << "Wynik sortowanie przez wybieranie: " << czas << endl;
}

int main() {
	srand(time(NULL));

	vector<int>liczby;

	liczby = wrzuc(liczby, "liczby.txt");


	sort_wybieranie(liczby, liczby.size(), "Select.txt");

	system("pause");

	return 0;
}