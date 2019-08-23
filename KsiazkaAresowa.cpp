#include "KsiazkaAdresowa.h"

void KsiazkaAdresowa::rejestracjaUzytkownika()
{
    Uzytkownik uzytkownik = podajDaneNowegoUzytkownika(uzytkownicy);
    uzytkownicy.push_back(uzytkownik);
    //dopiszUzytkownikaDoPliku(uzytkownik);
    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
    system("pause");
}

Uzytkownik KsiazkaAdresowa::podajDaneNowegoUzytkownika()
{
    Uzytkownik uzytkownik;

    uzytkownik.id = pobierzIdNowegoUzytkownika(uzytkownicy);

    do
    {
        cout << endl << "Podaj login: ";
        uzytkownik.login = wczytajLinie();
    } while (czyIstniejeLogin(uzytkownicy, uzytkownik.login) == true);

    cout << "Podaj haslo: ";
    uzytkownik.haslo = wczytajLinie();

    return uzytkownik;
}

int KsiazkaAdresowa::pobierzIdNowegoUzytkownika()
{
    if (uzytkownicy.empty() == true)
        return 1;
    else
        return uzytkownicy.back().id + 1;
}

bool KsiazkaAdresowa::czyIstniejeLogin(string login)
{
    vector <Uzytkownik>::iterator itr = uzytkownicy.begin();
    while (itr != uzytkownicy.end())
    {
        if (itr -> login == login)
        {
            cout << endl << "Istnieje uzytkownik o takim loginie." << endl;
            return true;
        }
        else
            itr++;
    }
    return false;
}
