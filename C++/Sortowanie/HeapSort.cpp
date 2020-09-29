#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

void heapify(vector<int>&tab, int heap_size, int i)
{
	int largest, temp;
	int l = 2 * i, r = (2 * i) + 1;
	if (l <= heap_size && tab[l]>tab[i])
		largest = l;
	else largest = i;
	if (r <= heap_size && tab[r]>tab[largest])
		largest = r;
	if (largest != i)
	{
		temp = tab[largest];
		tab[largest] = tab[i];
		tab[i] = temp;
		heapify(tab, heap_size, largest);
	}
}
void budKopiec(vector<int>&tab, int rozmiar)
{
	for (int i = rozmiar / 2; i>0; i--)
		heapify(tab, rozmiar, i);
}

void sort(vector<int>&tab, int rozmiar)
{
	int temp;
	budKopiec(tab, rozmiar);
	for (int i = rozmiar; i>1; i--)
	{
		temp = tab[i];
		tab[i] = tab[1];
		tab[1] = temp;
		rozmiar--;
		heapify(tab, rozmiar, 1);
	}
}

int main()
{
	fstream plik;
	vector<int>tab;
	int liczba;

	plik.open("Liczby.txt", ios::in);
	tab.push_back(0);
	while (plik >> liczba) tab.push_back(liczba);

	plik.close();

	int rozmiar = tab.size()-1;
	
	clock_t start = clock();
	sort(tab, rozmiar);
	clock_t stop = clock();
	double czas = double(stop - start) / CLOCKS_PER_SEC;
	cout << czas<<endl;
	plik.open("HeapSort.txt", ios::out);
	for (int i = 1; i < tab.size(); i++)
	{
		plik << tab[i] << endl;
	}
	plik.close();


	system("pause");
	return 0;
}