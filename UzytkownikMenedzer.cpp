#include "UzytkownikMenedzer.h"

int UzytkownikMenedzer::pobierzIdZalogowanegoUzytkownika()
{
    return idZalogowanegoUzytkownika;
}

bool UzytkownikMenedzer::czyUzytkownikJestZalogowany()
{
    if (idZalogowanegoUzytkownika>0)
        return true;
    else
        return false;
}

void UzytkownikMenedzer::rejestracjaUzytkownika()
{
    Uzytkownik uzytkownik = podajDaneNowegoUzytkownika();
    uzytkownicy.push_back(uzytkownik);

    plikZUzytkownikami.dopiszUzytkownikaDoPliku(uzytkownik);
    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
    system("pause");
}

Uzytkownik UzytkownikMenedzer::podajDaneNowegoUzytkownika()
{
    Uzytkownik uzytkownik;

    uzytkownik.ustawID(pobierzIdNowegoUzytkownika());
    string login;
    do
    {
        cout << endl << "Podaj login: ";
        cin>>login;
        uzytkownik.ustawLogin(login);
    }
    while (czyIstniejeLogin(uzytkownik.pobierzLogin()) == true);
    string haslo;
    cout << "Podaj haslo: ";
    cin>>haslo;
    uzytkownik.ustawHaslo(haslo);

    return uzytkownik;
}

int UzytkownikMenedzer::pobierzIdNowegoUzytkownika()
{
    if (uzytkownicy.empty() == true)
        return 1;
    else
        return uzytkownicy.back().pobierzID() + 1;
}

bool UzytkownikMenedzer::czyIstniejeLogin(string login)
{
    for (int i=0; i<uzytkownicy.size(); i++)
    {
        if (uzytkownicy[i].pobierzLogin()==login)
        {
            cout<<endl<<"Istnieje uzytkownik o takim loginie";
            return true;
        }

    }
    return false;
}

void UzytkownikMenedzer::wypiszWszystkichUzytkownikow()
{
    for (int i=0; i<uzytkownicy.size(); i++)
    {
        cout<<"ID: "<<uzytkownicy[i].pobierzID()<<" ";
        cout<<"Login:"<<uzytkownicy[i].pobierzLogin()<<endl;
        cout<<"Haslo: "<<uzytkownicy[i].pobierzHaslo()<<endl<<endl;
    }
}

int UzytkownikMenedzer::logowanieUzytkownika()
{
    cin.sync();
    Uzytkownik uzytkownik;
    string login = "", haslo = "";

    cout << endl << "Podaj login: ";
    login = MetodyPomocnicze::wczytajLinie();

    int przeszukiwaczUzytkownikow = 0; //uzytkownicy.begin();
    while (przeszukiwaczUzytkownikow < uzytkownicy.size())
    {
        if (uzytkownicy[przeszukiwaczUzytkownikow].pobierzLogin() == login)
        {
            for (int iloscProb = 3; iloscProb > 0; iloscProb--)
            {
                cout << "Podaj haslo. Pozostalo prob: " << iloscProb << ": ";
                haslo = MetodyPomocnicze::wczytajLinie();

                if (uzytkownicy[przeszukiwaczUzytkownikow].pobierzHaslo() == haslo)
                {
                    cout << endl << "Zalogowales sie." << endl << endl;
                    system("pause");
                    idZalogowanegoUzytkownika= uzytkownicy[przeszukiwaczUzytkownikow].pobierzID();
                    return idZalogowanegoUzytkownika;
                }
            }
            cout << "Wprowadzono 3 razy bledne haslo." << endl;
            system("pause");
            return 0;
        }
        przeszukiwaczUzytkownikow++;
    }

    cout << "Nie ma uzytkownika z takim loginem" << endl << endl;

    system("pause");
    system("cls");
    return 0;
}

int UzytkownikMenedzer::wylogujUzytkownika()
{
    idZalogowanegoUzytkownika = 0;
    system("cls");
    return idZalogowanegoUzytkownika;
}

void UzytkownikMenedzer::zmianaHaslaZalogowanegoUzytkownika(int idZalogowanegoUzytkownika)
{
    cin.sync();
    string noweHaslo = "";
    cout << "Podaj nowe haslo: ";
    noweHaslo = MetodyPomocnicze::wczytajLinie();

    for (int przeszukiwaczUzytkownikow = 0; przeszukiwaczUzytkownikow< uzytkownicy.size(); przeszukiwaczUzytkownikow++)
    {
        if (uzytkownicy[przeszukiwaczUzytkownikow].pobierzID() == idZalogowanegoUzytkownika)
        {
            uzytkownicy[przeszukiwaczUzytkownikow].ustawHaslo(noweHaslo);
            cout << "Haslo zostalo zmienione." << endl << endl;
            system("pause");
        }
    }
    plikZUzytkownikami.zapiszWszystkichUzytkownikowDoPliku(uzytkownicy);
}

