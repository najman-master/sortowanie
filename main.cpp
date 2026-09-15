#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Uczen
{
    string imie;
    string nazwisko;
    int wiek;
};

int main()
{
    Uczen uczniowie[30];
    int n = 0;

    // Wczytanie danych z pliku
    ifstream plik("uczniowie.txt");

    if (!plik)
    {
        cout << "Nie udalo sie otworzyc pliku uczniowie.txt" << endl;
        return 1;
    }

    while (n < 30 && plik >> uczniowie[n].imie
                         >> uczniowie[n].nazwisko
                         >> uczniowie[n].wiek)
    {
        n++;
    }

    plik.close();

    // Sortowanie po nazwisku
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (uczniowie[j].nazwisko > uczniowie[j + 1].nazwisko)
            {
                swap(uczniowie[j], uczniowie[j + 1]);
            }
        }
    }

    // Zapis do pliku
    ofstream wynik("wynik.txt");

    if (!wynik)
    {
        cout << "Nie udalo sie utworzyc pliku wynik.txt" << endl;
        return 1;
    }

    for (int i = 0; i < n; i++)
    {
        wynik << uczniowie[i].imie << " "
              << uczniowie[i].nazwisko << " "
              << uczniowie[i].wiek << endl;
    }

    wynik.close();

    cout << "Dane zostaly zapisane do pliku wynik.txt" << endl;

    return 0;
}
