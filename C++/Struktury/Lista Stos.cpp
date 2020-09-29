#include <iostream>
#include <vector>

using namespace std;

class Lista
{
public:
	Lista * nastepny;
	int wartosc;
};

class Stos
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
		if (Head == NULL)
			return NULL;
		else
		{
			Lista* nowy = new Lista();
			int wynik;
			if (Head->nastepny == NULL)
			{
				wynik = Head->wartosc;
				Head = NULL;
				delete Head;
			}
			else
			{
				Lista* temp = Head;
				while (temp->nastepny->nastepny!=NULL)
				{
					temp = temp->nastepny;

				}
				wynik = temp->nastepny->wartosc;
				temp->nastepny = NULL;
				delete temp->nastepny;

			}
			return wynik;
		}
	}
	void show()
	{
		Lista* temp = Head;
		while (temp->nastepny != NULL)
		{
			cout << temp->wartosc << endl;
			temp = temp->nastepny;
			
		}
		cout << temp->wartosc << endl<<endl;
	}
	void clear()
	{
		Head = NULL;
		delete Head;
	}
};



int main()
{
	Stos s;

	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);

	s.show();

	cout << s.pop() << endl;
	cout << s.pop() << endl;
	cout << endl;
	s.show();

	s.clear();

	system("pause");

	return 0;
}
