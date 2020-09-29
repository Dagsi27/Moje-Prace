#include <iostream>
#include <vector>
#include <string>

using namespace std;

int max(int x, int y)
{
	if (x > y)
		return x;
	else
		return y;
}

void show(int **tab, int m, int n)
{
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++)
			cout << tab[i][j] << " ";
		cout << endl;
	}
}
void wynik(string wynik)
{
	cout << "Wynik: ";
	for (int i = wynik.size() - 1; i >= 0; i--)
		cout << wynik[i];
	cout << endl;
}

void clear(int **tab, int m)
{
	for (int i = 0; i < m; i++)
		delete[] tab[i];

	delete[] tab;
}

int main()
{
	string s1, s2, w;
	
	cin >> s2;
	cin >> s1;

	int m = s1.length() + 1;
	int n = s2.length() + 1;

	int **tab = new int*[m];
	for (int i = 0; i < m; i++)
		tab[i] = new int[n];

	for (int i = 0; i < m; i++)
		tab[i][0] = 0;

	for (int j = 0; j < n; j++)
		tab[0][j] = 0;

	for (int i = 1; i < m; i++)
		for (int j = 1; j < n; j++)
			if (s1[i - 1] == s2[j - 1])
				tab[i][j] = tab[i - 1][j - 1] + 1;
			else
				tab[i][j] = max(tab[i - 1][j], tab[i][j - 1]);

	show(tab, m, n);
	
	int i=m-1, j=n-1;

	while (i != 0 && j != 0)
	{
		if (tab[i-1][j] == tab[i][j] )
			i--;
		else if (tab[i][j-1] == tab[i][j])
			j--;
		else
		{
			w+= s2[j-1];
			i--; j--;
		}
	}
	wynik(w);
	clear(tab, m);

	system("pause");
	return 0;
}
