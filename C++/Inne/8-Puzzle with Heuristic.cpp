#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <tuple> 

using namespace std;

tuple <int,int> find0(vector<vector<int>> puzzel) {
	for (int i = 0; i < puzzel.size(); i++) {
		for (int j = 0; j < puzzel.size(); j++) {
			if (puzzel[i][j] == 0)
			{
				return make_tuple(i, j);
			}
		}
	}
}

void show(vector<vector<int>> puzzel) {
	for (int i = 0; i < puzzel.size(); i++) {
		for (int j = 0; j < puzzel.size(); j++) {
			cout << puzzel[i][j]<<" ";
		}
		cout << endl;
	}
	cout << endl;
}

bool check(vector<vector<int>> puzzel, vector<vector<int>> puzzel2) {
	for (int i = 0; i < puzzel.size(); i++) {
		for (int j = 0; j < puzzel2.size(); j++) {
			if (puzzel[i][j] != puzzel2[i][j])
				return false;
		}
	}
	return true;
}

int countDifference(vector<vector<int>> puzzel, vector<vector<int>> endPuzzel) {
	int count = 0;
	for (int i = 0; i < puzzel.size(); i++) {
		for (int j = 0; j < puzzel[i].size(); j++) {

			if (puzzel[i][j] != endPuzzel[i][j] && puzzel[i][j] != 0) {

				count++;
			}
				
		}
	}
	return count;

}

class Wezel
{
public:
	Wezel* rodzic;
	Wezel* kierunek[4];
	vector<vector<int>> wartosc;
	int odleglosc = 0;
	int roznica = 0;
	bool sprawdzony = false;

	int x, y;
};

class Drzewo
{
public:
	Wezel* root = NULL;
	Wezel* current = NULL;
	vector<vector<int>> endPuzzel;
	bool end = false;

	void addFirst(vector<vector<int>> liczba)
	{
		if(root == NULL){
			Wezel* nowy = new Wezel();
			nowy->wartosc = liczba;
			nowy->sprawdzony = 1;
			
			tie(nowy->x, nowy->y)=find0(liczba);
			int x = nowy->x,y= nowy->y;

			Wezel* kierunek[4] = { new Wezel(),new Wezel(),new Wezel(),new Wezel() };
			int goTo[4] = { x + 1,x - 1,y + 1,y - 1 };

			for (int i = 0; i < 4; i++)
			{
				if (goTo[i] <= 2 && goTo[i] >= 0) {
					kierunek[i]->wartosc = nowy->wartosc;
					kierunek[i]->rodzic = nowy;
					kierunek[i]->odleglosc=nowy->odleglosc+1;
					

					if (i < 2)
						swap(kierunek[i]->wartosc[x][y], kierunek[i]->wartosc[goTo[i]][y]);
					else
						swap(kierunek[i]->wartosc[x][y], kierunek[i]->wartosc[x][goTo[i]]);

					kierunek[i]->roznica = countDifference(kierunek[i]->wartosc, endPuzzel);
					tie(kierunek[i]->x, kierunek[i]->y) = find0(kierunek[i]->wartosc);
					nowy->kierunek[i] = kierunek[i];
				}
			}
			current = nowy;
			root = nowy;
		}
	}

	void add(Wezel* nowy) {
		if (root != NULL) {
			nowy->sprawdzony = 1;
			int x = nowy->x, y = nowy->y;
			vector<vector<int>> liczba = nowy->wartosc;
			Wezel* kierunek[4] = { new Wezel(),new Wezel(),new Wezel(),new Wezel() };
			int goTo[4] = { x + 1,x - 1,y + 1,y - 1 };

			for (int i = 0; i < 4; i++)
			{
				if (goTo[i] <= 2 && goTo[i] >= 0) {
					kierunek[i]->wartosc = nowy->wartosc;
					kierunek[i]->rodzic = nowy;
					kierunek[i]->odleglosc=nowy->odleglosc+1;

					if (i < 2)
						swap(kierunek[i]->wartosc[x][y], kierunek[i]->wartosc[goTo[i]][y]);
					else
						swap(kierunek[i]->wartosc[x][y], kierunek[i]->wartosc[x][goTo[i]]);

					kierunek[i]->roznica = countDifference(kierunek[i]->wartosc, endPuzzel);
					tie(kierunek[i]->x, kierunek[i]->y) = find0(kierunek[i]->wartosc);
					nowy->kierunek[i] = kierunek[i];

					if (check(kierunek[i]->wartosc, endPuzzel)) {
						end = true;
						current = kierunek[i];
						break;
					}
				}
			}
		}
	}

	void findLowest(Wezel* nowy) {

		if (!nowy->sprawdzony) {
			if (current->sprawdzony)
			{
				current = nowy;
			}
			if ((nowy->odleglosc + nowy->roznica) < (current->odleglosc + current->roznica))
			{
				current = nowy;
			}
		}

		for (int i = 0; i < 4; i++)
			if (nowy->kierunek[i] != NULL)
				findLowest(nowy->kierunek[i]);
	}

	void bestWay(Wezel* nowy) {
		cout << "Starts from the Goal State: " << endl;
		while (nowy->rodzic != NULL)
		{
			show(nowy->wartosc);
			nowy = nowy->rodzic;
		}
		show(nowy->wartosc);
	}
};

int main()
{
	Drzewo d;
	//GOAL STATE
	d.endPuzzel = { {0,1,2},{3,4,5},{6,7,8} };

	//INITIAL STATE
	vector<vector<int>> puzzel = { {1,4,2},{6,5,8}, {7,3,0} };

	d.addFirst(puzzel);
	
	while (true)
	{
		if (d.end) break;
		d.findLowest(d.root);
		d.add(d.current);
	}

	d.bestWay(d.current);

	system("Pause");

	return 0;
}