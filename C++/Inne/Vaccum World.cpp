#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <tuple> 

using namespace std;

void show(vector<bool>plansza)
{
	for (int i = 0; i < plansza.size(); i++)
	{
		cout << plansza[i] << " ";
	}
	cout << endl;
}

class Wezel
{
public:
	Wezel* rodzic;
	Wezel* coRobic[4];//lewo,prawo,sprzatnij,nic nie rob
	vector<bool> plansza; // 1 brud / 0 czyste
	int poz;
	int brud = 0;
	int kierunek = 0;
};

class Drzewo
{
public:
	Wezel* root = NULL;
	Wezel* end = NULL;


	void addFirst(vector<bool> plansza, int pozycja)
	{
		if (root == NULL) {
			Wezel* nowy = new Wezel();
			nowy->plansza = plansza;
			nowy->brud = plansza.size();
			nowy->poz = pozycja;
			Wezel* toDo[4] = { new Wezel(),new Wezel(),new Wezel(),new Wezel() };
			
			
			for (int i = 0; i < 4; i++)
			{
				toDo[i]->rodzic = nowy;
				toDo[i]->plansza = nowy->plansza;
				toDo[i]->poz = nowy->poz;
				toDo[i]->brud = nowy->brud;
				nowy->coRobic[i] = toDo[i];
			}

			if (toDo[0]->poz > 0) {
				toDo[0]->poz--;
				toDo[0]->kierunek = 0;
			}

			if (toDo[1]->poz < toDo[1]->plansza.size()-1) {
				toDo[1]->poz++;
				toDo[1]->kierunek = 1;
			}

			if (toDo[2]->plansza[toDo[2]->poz] == true) {
				toDo[2]->plansza[toDo[2]->poz] = false;
				toDo[2]->brud--;
				toDo[2]->kierunek = 2;
			}
			toDo[3]->kierunek = 3;
			root = nowy;
			
		}
	}

	void add(Wezel* nowy) {
		if (root != NULL) {

			Wezel* toDo[4] = { new Wezel(),new Wezel(),new Wezel(),new Wezel() };

			for (int i = 0; i < 4; i++)
			{
				toDo[i]->rodzic = nowy;
				toDo[i]->plansza = nowy->plansza;
				toDo[i]->poz = nowy->poz;
				toDo[i]->brud = nowy->brud;
				nowy->coRobic[i] = toDo[i];
			}

			if (toDo[0]->poz > 0) {
				toDo[0]->poz--;
				toDo[0]->kierunek = 0;
			}

			if (toDo[1]->poz < toDo[1]->plansza.size() - 1) {
				toDo[1]->poz++;
				toDo[1]->kierunek = 1;
			}
			
			if (toDo[2]->plansza[toDo[2]->poz] == true) {
				toDo[2]->plansza[toDo[2]->poz] = false;
				toDo[2]->brud--;
				toDo[2]->kierunek = 2;
			}

			toDo[3]->kierunek = 3;

			for (int i = 0; i < 4; i++)
			{
				if (toDo[i]->brud == 0)
				{
					end = toDo[i];
					break;
				}
			}

			
		}
	}

	void adding(Wezel* nowy) {

		for (int i = 0; i < 4; i++) {
			if (nowy->coRobic[i] != NULL)
				adding(nowy->coRobic[i]);
		}
		if (nowy->coRobic[0] == NULL)
		{
			add(nowy);
		}
			
	}

	void bestWay(Wezel* nowy) {
		vector<string>wynik;
		while (nowy->rodzic != NULL)
		{
			if (nowy->kierunek == 0) wynik.push_back("Idz w Lewo");
			else if(nowy->kierunek == 1) wynik.push_back("Idz w Prawo");
			else if (nowy->kierunek == 2) wynik.push_back("Sprzatnij");
			else if (nowy->kierunek == 3) wynik.push_back("Nic nie rob");
			nowy = nowy->rodzic;
		}
		for (int i = wynik.size()-1; i >= 0; i--)
			cout << wynik[i] << endl;
	}
};

int main()
{
	Drzewo d;
	
	vector<bool> plansza = { 1 , 1 , 1 };

	d.addFirst(plansza,1);
	
	while (true) {
		if (d.end != NULL)break;
		d.adding(d.root);
	}
	cout << "Wynik: " << endl<<endl;
	d.bestWay(d.end);
	cout << endl;
	system("Pause");

	return 0;
}