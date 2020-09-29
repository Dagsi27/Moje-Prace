#include <cmath>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <vector>
#include <fstream>
using namespace std;

void merge(vector<int>&liczby,int x, int sr, int y)
{
	int i, j, q;
	int rozmiar = liczby.size();
	
	int *t = new int[rozmiar];

	for (i = x; i <= y; i++) t[i] = liczby[i];
	i = x; j = sr + 1; q = x;          
	while (i <= sr && j <= y) {     
		if (t[i]<t[j])
			liczby[q++] = t[i++];
		else
			liczby[q++] = t[j++];
	}
	while (i <= sr) liczby[q++] = t[i++];
	delete[] t;
}

void mergesort(vector<int>&liczby, int x, int y)
{
	int sr;
	if (x<y) {
		sr = (x + y) / 2;
		mergesort(liczby,x, sr);
		mergesort(liczby,sr + 1, y);
		merge(liczby,x, sr, y);
	}
}
int main()
{
	int i;

	int rozmiar, liczba;
	vector<int>liczby;
	vector<int>t;
	fstream plik;

	plik.open("Liczby.txt", ios::in);
	while (plik >> liczba) liczby.push_back(liczba);

	clock_t start = clock();
	mergesort(liczby,0, liczby.size()-1);

	clock_t stop = clock();
	double czas = double(stop - start) / CLOCKS_PER_SEC;
	cout << czas<<endl;


	ofstream fileOut("Merge.txt");

	for (i = 0; i < liczby.size(); i++)
	{
		fileOut << liczby[i] << endl;
	}
	fileOut.close();

	system("pause");
	return 0;
}