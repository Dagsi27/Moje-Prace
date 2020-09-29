#include <iostream>
#include <vector>
using namespace std;

class Wezel
{
public:
	Wezel *rodzic;
	Wezel* prawe;
	Wezel* lewe;
	int wartosc;
	int numer;
};

class Drzewo
{
public:
	Wezel* root = NULL;
	int length = 0;
	void Push(int liczba)
	{
		Wezel* nowy = new Wezel();
		nowy->wartosc = liczba;
		nowy->numer = length + 1;

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
	void pre_order(Wezel* nowy)
	{
		cout << nowy->wartosc << " ";
		if (nowy->lewe != NULL)
			pre_order(nowy->lewe);
		if (nowy->prawe != NULL)
			pre_order(nowy->prawe);

	}
	void in_order(Wezel* nowy)
	{
		if (nowy->lewe != NULL)
			pre_order(nowy->lewe);
		cout << nowy->wartosc << " ";
		if (nowy->prawe != NULL)
			pre_order(nowy->prawe);

	}
	void post_order(Wezel* nowy)
	{
		if (nowy->lewe != NULL)
			pre_order(nowy->lewe);
		if (nowy->prawe != NULL)
			pre_order(nowy->prawe);
		cout << nowy->wartosc << " ";
	}
};
int main()
{
	Drzewo d;

	d.Push(56);
	d.Push(3);
	d.Push(9);
	d.Push(6);
	d.Push(43);
	d.Push(94);
	d.Push(52);
	d.Push(51);
	d.Push(11);
	d.Push(2);
	d.Push(15);
	d.Push(17);
	d.Push(69);
	d.Push(45);
	d.Push(25);

	d.pre_order(d.root);
	cout << endl;
	d.in_order(d.root);
	cout << endl;
	d.post_order(d.root);

	system("pause");

	return 0;
}