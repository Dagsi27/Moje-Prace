#include <iostream>
#include <vector>

using namespace std;

class Lista
{
public:
	Lista * nastepny;
	int wartosc;
};



class Kolejka
{
public:
	Lista * Head = NULL;

	void push(int liczba)
	{
		Lista* nowy = new Lista();
		nowy->wartosc = liczba;
		nowy->nastepny = NULL;
		if (Head == NULL)
			Head = nowy;
		else
		{
			Lista* temp = Head;
			while (temp->nastepny != NULL)
				temp = temp->nastepny;
			temp->nastepny = nowy;
		}
	}
	int pop()
	{
		int wynik;
		if (Head != NULL) {
			wynik = Head->wartosc;
			Lista* temp = Head->nastepny;
			Head = temp;
		}
		return wynik;
	
	}
	void show()
	{
		Lista* temp = Head;
		while (temp->nastepny != NULL)
		{
			cout << temp->wartosc << endl;
			temp = temp->nastepny;

		}
		cout << temp->wartosc << endl << endl;
	}
	void clear()
	{
		Head = NULL;
		delete Head;
	}
};

int main()
{
	Kolejka k;

	k.push(1);
	k.push(2);
	k.push(3);
	k.push(4);
	k.push(5);

	k.show();

	cout << k.pop()<<endl;
	cout << k.pop() << endl;
	cout << k.pop() << endl;
	cout << endl;
	k.show();

	k.clear();

	system("pause");

	return 0;
}
