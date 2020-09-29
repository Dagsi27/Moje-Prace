#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

class Wezel
{
public:
	Wezel* rodzic;
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

			while (tmp>1)
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

	int Pop()
	{	
		if (length < 1) {
			cout << "ERROR: ";
			return 0;
		}
		else {
			Wezel* nowy = new Wezel();
			int wynik;
			if (length == 1)
			{
				wynik = root->wartosc;
				root = NULL;
				delete root;
			}
			else
			{
				vector<int> kierunek = vector<int>();
				int tmp = length;
				while (tmp > 1)
				{
					kierunek.push_back(tmp % 2);
					tmp /= 2;
				}

				Wezel* rodzic = root;
				for (int i = kierunek.size() - 1; i >= 1; i--)
				{
					if (kierunek[i] == 0)
					{
						rodzic = rodzic->lewe;
					}
					else
					{
						rodzic = rodzic->prawe;
					}
				}

				if (kierunek[0] == 0)
				{
					wynik = rodzic->lewe->wartosc;
					rodzic->lewe = NULL;
					delete rodzic->lewe;

				}
				else
				{
					wynik = rodzic->prawe->wartosc;
					rodzic->prawe = NULL;
					delete rodzic->prawe;

				}

			}
			length--;
			return wynik;
		}	
	}

	int Length()
	{
		return length;
	}

	void Show()
	{
		cout << endl;
		int tmp;
		vector<int> kierunek = vector<int>();
		if (length == 1) {
			Wezel* rodzic = root;
			cout << "Root: " << rodzic->wartosc << endl;
		}
		for (int i = 2; i <=length; i++)
		{
			Wezel* rodzic=root;
			tmp = i;
			while (tmp > 1)
			{
				kierunek.push_back(tmp % 2);
				tmp /= 2;
			}

			for (int j = kierunek.size() - 1; j > 0; j--)
			{
				if (kierunek[j] == 0)
					rodzic = rodzic->lewe;
				else
					rodzic = rodzic->prawe;
			}

			if(i%2==0)
				cout <<"  Root: " << rodzic->wartosc<<endl;

			if (kierunek[0] == 0) {
				cout << "L: " << rodzic->lewe->wartosc<<"    ";
			}
			else
				cout << "R: " << rodzic->prawe->wartosc<<endl<<endl;

				
			kierunek.clear();
			
		}
		cout << endl;
		
	}
};

int main()
{
	Drzewo d;



	d.Push(56);
	d.Push(3);
	d.Push(9);
	d.Push(6);
	d.Push(5);
	d.Push(6);
	cout << "POP: " << d.Pop() << endl;
	cout << "POP: " << d.Pop() << endl;
	cout << "POP: " << d.Pop() << endl;
	cout << "POP: " << d.Pop() << endl;
	cout <<"LENGTH: " << d.Length()<<endl;

	d.Show();


	system("Pause");

	return 0;
}