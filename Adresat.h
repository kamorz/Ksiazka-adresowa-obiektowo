#ifndef ADRESAT_H
#define ADRESAT_H

#include <iostream>

using namespace std;

class Adresat
{
    int id, idUzytkownika;
    string imie;
    string nazwisko;
    string numerTelefonu;
    string adres;
    string email;

public:
    void ustawID(int noweID);
    void ustawIDUzytkownika(int noweIDUzytkownika);
    void ustawImie (string noweImie);
    void ustawNazwisko (string noweNazwisko);
    void ustawNumerTelefonu (string nowyNumerTelefonu);
    void ustawEmail (string nowyEmail);
    void ustawAdres (string nowyAdres);

    int pobierzID();
    int pobierzIDUzytkownika();
    string pobierzImie();
    string pobierzNazwisko();
    string pobierzNumerTelefonu();
    string pobierzEmail();
    string pobierzAdres();
};

#endif
