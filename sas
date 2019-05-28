#ifndef KLASA_H_INCLUDED
#define KLASA_H_INCLUDED

#include <iostream>
#include <string.h>
using namespace std;

class dane
{
private:
public:
    char imie[10];
    char nazwisko[25];
    char telefon[10];
    class dane *nastepny;
    dane(char *i,char *n,char *t);
    dane();
};
class lista:public dane
{
private:
    class dane *pierwszy;
public:
    void wyswietl();
    void dodaj();

};
class marka
{
private:
public:
    char mark[10];
    char typ[10];
    char rok[10];
    char cena[10];
    class marka *nastepny;
    marka(char *m, char *t, char *r, char *c);
    marka();
};
class lista2:public marka
{
private:
    class marka *pierwszy;
public:
    void wyswietl();
    void dodaj(char *m, char *t, char *r, char *c);
    lista2(char *m="Marka", char *t="Typ", char *r="Rok", char *c="Cena");
};
#endif // KLASA_H_INCLUDED

--------------------------------------------------------------

#include "klasa.h"
#include <fstream>
#include <cstdlib>

void lista::dodaj()
{
    cout << "Podaj dane\n";
    cout << "\tImie: ";
    cin >> this->imie;
    cout << "\tNazwisko: ";
    cin >> this->nazwisko;
    cout << "\tTelefon: ";
    cin >> this->telefon;
};

void lista::wyswietl()
{
    cout << "Lista:" << endl;
    class dane *obiekt=this;
    while (obiekt!=NULL)
    {
        cout << "Imie: "<<obiekt->imie<<"";
        cout << "Nazwisko: "<<obiekt->nazwisko<<"";
        cout << "Telefon: "<<obiekt->telefon<<"";
    }
};

--------------------------------------------------------------------

#include <iostream>
#include "klasa.h"
#include "klasa.cpp"
#include <conio.h>
using namespace std;

int main()
{
    class lista *lis=NULL, *osoba=NULL;
    osoba=lis;
    char znak;
    do
    {
        cout << "Twoj wybor: " << endl;
        znak=getch();
        switch(znak)
            {
            case '1':
                osoba->dodaj();
                break;
            case '2':
                osoba->wyswietl();
                break;
            case '5':
                cout << "Koniec" << endl;
                break;
            default:
                cout << "Wybierz ponownie" << endl;
            }
    }
while (znak!='5');
return 0;
}
