#include <iostream>
#include <vector>

using namespace std;

const int MAXINT = 2147483647;

class Krawedz
{
public:
	Krawedz * numer;
	int v1;
	int v2;
	int waga;
};

class Dijkstry
{
private:
	int size;
	int *d;
	int *p;
	int k;
public:

	bool unique(vector<int>tab,int find)
	{
		for (int i = 0; i < tab.size(); i++)
			if (find == tab[i])
				return false;
		return true;
	}

	void insert(int maximum)
	{
		size = maximum;
		d = new int[size];
		p = new int[size];
		d[0] = 0;
		p[0] = -1;
		for (int i = 1; i < size; i++)
		{
			d[i] = MAXINT;
			p[i] = -1;
		}
	}

	void QtoS(Krawedz * macierz,int start,int koniec)
	{
		k = koniec;
		Krawedz *m = macierz;
		vector<int>ciag;
		ciag.push_back(start);
		ciag.push_back(koniec);
		int i = 0;
		while(ciag[i]!=koniec)
		{
			m = macierz;
			while (m->numer != NULL) 
			{
				if (m->v1 == ciag[i])
					if (d[m->v2] > d[m->v1] + m->waga) 
					{
						d[m->v2] = d[m->v1] + m->waga;
						p[m->v2] = m->v1;
						if (unique(ciag, m->v2))
						{
							ciag[ciag.size() - 1] = m->v2;
							ciag.push_back(koniec);

						}
					}
				m = m->numer;
			}
			i++;
		}
	}
	
	void show()
	{
		for (int i = 0; i < size; i++)
			cout << "U: " << i << " D[" << i << "]: " << d[i] << " P[" << i << "]: " << p[i] << endl;
		cout << endl << "Najkrotsza droga do " << k << " wynosi: " << d[k]<<endl<<endl;
	}

};

class Macierz
{
public:
	Krawedz * Head = NULL;

	void push(int v1, int v2, int waga)
	{
		Krawedz *nowy = new Krawedz();
		nowy->v1 = v1;
		nowy->v2 = v2;
		nowy->waga = waga;
		if (Head == NULL)
			Head = nowy;
		else
		{
			Krawedz* temp = Head;
			while (temp->numer != NULL)
				temp = temp->numer;
			temp->numer = nowy;
		}
	}

	void show()
	{
		Krawedz* temp = Head;
		while (temp->numer != NULL)
		{
			cout << "Krawedz " << temp->v1 << " i " << temp->v2 << " ma wage: " << temp->waga << endl;
			temp = temp->numer;
		}
		cout << "Krawedz " << temp->v1 << " i " << temp->v2 << " ma wage: " << temp->waga << endl;
	}
	int max()
	{
		Krawedz* temp = Head;
		int wynik = temp->v1;
		while (temp->numer != NULL)
		{
			if (temp->v1 > wynik)
				wynik = temp->v1;
			else if (temp->v2 > wynik)
				wynik = temp->v2;
			temp = temp->numer;
		}
		return wynik + 1;
	}

};

int main()
{
	Macierz m;
	Dijkstry d;

	m.push(0, 1, 3);
	m.push(0, 4, 3);
	m.push(4, 5, 2);
	m.push(1, 2, 1);
	m.push(2, 3, 3);
	m.push(2, 5, 1);
	m.push(5, 3, 1);
	m.push(5, 0, 6);
	m.push(3, 1, 3);
	

	//m.show();
	d.insert(m.max());

	d.QtoS(m.Head,0,3);//macierz / OD(zawsze ma byc 0) / DO(dowolne)
	
	d.show();
	system("pause");

	return 0;
}