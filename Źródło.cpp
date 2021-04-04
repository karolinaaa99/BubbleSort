#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

void init(int tab[], int n) //funkcja zapełniająca tablicę tab o rozmiarze n losowymi licbami
{
	for (int i = 0; i < n; i++)
	{
		tab[i] = rand() % 100 + 1; //zapelniam tablice liczbami losowymi z przedzialu <1, 100>
	}
}

void print(int tab[], int n) //funkcja do wyświetlenia danych z tablicy
{
	for (int i = 0; i < n; i++)
	{
		cout << tab[i] << " ";
	}
}

void sort(int tab[], int n) //sortowanie babelkowe, bubblesort
{
	int temp, i, zmiana;
	do
	{
		zmiana = 0;
		i = n - 1;
		do
		{
			i--;
			if (tab[i + 1] < tab[i])
			{
				temp = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = temp;
				zmiana = 1;
			}
		} while (i != 0);
	} while (zmiana != 0);
}


int main()
{
	cout << "BubbleSort" << endl;
	cout << "************" << endl;

	int n;
	clock_t poczatek;
	clock_t koniec;
	double wynik;

	srand(time(NULL));
	cout << endl;

	poczatek = clock();

	cout << "Podaj ile liczb chcesz posortowac n = ";
	cin >> n;
	cout << endl;

	int* tab = new int[n];

	//zapelniam tablice
	init(tab, n);

	cout << "Zawartosc tablicy przed sortowaniem:"<<endl;
	print(tab, n);
	cout << endl;

	//wywoluje algorytm sortowania babelkowego
	sort(tab, n);
	cout << endl;

	cout << "Zawartosc tablicy po sortowaniu:" << endl;
	print(tab, n);
	cout << endl;

	koniec = clock();
	wynik = (double)(koniec - poczatek) / CLOCKS_PER_SEC;
	cout << endl;

	cout << "Czas dzialania sortowania babelkowego: "<<wynik<<" sek"<<endl;


	return 0;
}