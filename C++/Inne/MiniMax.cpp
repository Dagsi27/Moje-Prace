#include <iostream>
#include <cstdlib>
#include <vector>
#include <limits>
using namespace std;

#define INF numeric_limits<int>::max()

class Wezel
{
public:
	Wezel* rodzic;
	Wezel* prawe;
	Wezel* lewe;
	int wartosc;
	int numer;
	bool minmax;
};

class Drzewo
{
public:
	Wezel* root = NULL;
	int length = 0;

	void Push(int liczba,bool minmax)
	{
		Wezel* nowy = new Wezel();
		nowy->wartosc = liczba;
		nowy->numer = length + 1;
		nowy->minmax = minmax;

		if (length == 0)
		{
			root = nowy;
		}
		else
		{
			int tmp = nowy->numer;
			vector<int> kierunek;

			while (tmp > 1)
			{
				kierunek.push_back(tmp % 2);
				tmp /= 2;
			}

			Wezel* rodzic = root;

			for (int i = kierunek.size() - 1; i >= 1; i--)
			{
				if (kierunek[i] == 0)
					rodzic = rodzic->lewe;
				else
					rodzic = rodzic->prawe;
			}

			if (kierunek[0] == 0)
				rodzic->lewe = nowy;
			else
				rodzic->prawe = nowy;
			nowy->rodzic = rodzic;

		}
		length++;

	}

	int Length()
	{
		return length;
	}

	void maximin(Wezel* nowy)
	{
		if (nowy->lewe != NULL)
			maximin(nowy->lewe);
		if (nowy->prawe != NULL)
			maximin(nowy->prawe);

		if (nowy->rodzic != NULL)
		{
			if (nowy->rodzic->minmax == 1) {
				if (nowy->wartosc > nowy->rodzic->wartosc) {
					nowy->rodzic->wartosc = nowy->wartosc;
					if (nowy->rodzic->rodzic != NULL) {
						if (nowy->rodzic->wartosc > nowy->rodzic->rodzic->wartosc) {
							nowy->rodzic->prawe = NULL;
						}
					}
				}
			}
			else {
				if (nowy->wartosc < nowy->rodzic->wartosc) {
					nowy->rodzic->wartosc = nowy->wartosc;
					if (nowy->rodzic->rodzic != NULL) {
						if (nowy->rodzic->wartosc < nowy->rodzic->rodzic->wartosc) {
							nowy->rodzic->prawe = NULL;
						}
					}

				}
			}

		}
	}

};

int main()
{
	Drzewo d;
	d.Push(-INF,1);
	d.Push(INF,0);
	d.Push(INF,0);
	d.Push(-INF,1);
	d.Push(-INF,1);
	d.Push(-INF,1);
	d.Push(-INF,1);
	d.Push(-1,0);
	d.Push(3,0);
	d.Push(5,0);
	d.Push(1,0);
	d.Push(-6,0);
	d.Push(-4,0);
	d.Push(0,0);
	d.Push(9,0);

	d.maximin(d.root);
	cout <<"Wynik: MINIMAX(A)= "<< d.root->wartosc << endl;

	system("Pause");


	return 0;
}