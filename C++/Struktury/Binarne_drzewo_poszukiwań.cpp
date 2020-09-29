#include<iostream>
#include <vector>

using namespace std;

class Wezel
{
public:
	Wezel* prawe;
	Wezel* lewe;
	int wartosc;
};

class Drzewo
{
	int ostatni;
public:
	Wezel * root = NULL;

	Wezel * find(int liczba)
	{
		if (root == NULL)
			return 0;
		else
		{
			Wezel* tmp = root;
			while (tmp->prawe != NULL || tmp->lewe != NULL)
			{
				ostatni = tmp->wartosc;
				if (tmp->wartosc < liczba)
					tmp = tmp->prawe;
				else if (tmp->wartosc > liczba) 
					tmp = tmp->lewe;
				if (tmp->wartosc==liczba)
					return tmp;
			}
			return 0;
		}
	}
	
	void push(int liczba)
	{
		Wezel* nowy = new Wezel();
		nowy->wartosc = liczba;
		if (root == NULL)
			root = nowy;
		else
		{
			Wezel* tmp = root;
			while (tmp->prawe != NULL || tmp->lewe != NULL)
			{
				if (tmp->wartosc < liczba)
					if (tmp->prawe != NULL)
						tmp = tmp->prawe;
					else
						break;
				else if (tmp->wartosc > liczba)
					if (tmp->lewe != NULL)
						tmp = tmp->lewe;
					else
						break;
				
			}
			
			if (tmp->wartosc < liczba)
				tmp->prawe = nowy;
			else if (tmp->wartosc > liczba)
				tmp->lewe = nowy;

		}
	}
	void drop(Wezel* tmp)
	{
		if (tmp->lewe != NULL && tmp->prawe != NULL)
		{
			int liczba;
			Wezel* nowy = tmp;
			if (tmp->prawe->lewe != NULL) {
				nowy = nowy->prawe;
				while (nowy->lewe->lewe != NULL)
					nowy = nowy->lewe;
				liczba = nowy->lewe->wartosc;
				tmp->wartosc = liczba;
				nowy->lewe = NULL;
			}
			else
			{
				tmp->wartosc = tmp->prawe->wartosc;
				if (tmp->prawe->prawe != NULL)
				{
					tmp->prawe = tmp->prawe->prawe;
				}
				else
					tmp->prawe = NULL;
			}

		}
		else if (tmp->lewe != NULL || tmp->prawe != NULL)
		{
			int liczba;
			if (tmp->lewe != NULL)
			{
				tmp = find(ostatni);
				tmp->lewe = tmp->lewe->lewe;
			}
			else if(tmp->prawe !=NULL)
			{
				tmp = find(ostatni);
				tmp->prawe = tmp->prawe->prawe;
			}
		}
		else
		{
			tmp=find(ostatni);
			if (tmp->lewe != NULL)
				tmp->lewe = NULL;
			else
				tmp->prawe = NULL;
		}
	}

	void pre_order(Wezel* nowy)
	{
		cout << nowy->wartosc << " ";
		if (nowy->lewe != NULL)
			pre_order(nowy->lewe);
		if (nowy->prawe != NULL)
			pre_order(nowy->prawe);

	}
	
	int max()
	{
		while (root->prawe != NULL)
			root = root->prawe;
		return root->wartosc;
	}
	int min()
	{
		while (root->lewe != NULL)
			root = root->lewe;
		return root->wartosc;
	}
};
int main()
{
	Drzewo d;

	d.push(8);
	d.push(3);
	d.push(10);
	d.push(1);
	d.push(6);
	d.push(14);
	d.push(4);
	d.push(7);
	d.push(13);
	d.pre_order(d.root);
	cout << endl;
	d.drop(d.find(3));
	d.pre_order(d.root);
	cout << endl << d.max();
	cout<<endl<<d.min();
	system("pause");
	return 0;
}
