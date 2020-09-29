#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

class Kolejka
{
public:
	void push(vector<int>&tab, int x) {
		tab.push_back(x);
	}

	int pop(vector<int>&tab) {
		int wynik = tab[0];
		tab.erase(tab.begin());
		return wynik;
	}
	int length(vector<int>&tab) {
		return tab.size();
	}
	void show(vector<int>&tab) {
		for (int i = 0; i<tab.size(); i++)
			cout << tab[i] << " ";
		cout << endl;
	}
};


int main()
{
	Kolejka s;

	vector<int>tablica;


	s.push(tablica,5);
	s.push(tablica, 2);
	s.push(tablica, 1);
	s.push(tablica, 7);
	s.show(tablica);
	s.pop(tablica);
	s.show(tablica);
	cout << "Dlugosc wynosi:" << s.length(tablica)<<endl;


	system("pause");

	return 0;
}