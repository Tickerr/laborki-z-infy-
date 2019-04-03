#include <stdio.h>
#include <stdlib.h>

struct baza
{
    char imie[10];
    char nazwisko[25];
    int telefon;
};

int main()
{
    char znak;
    FILE *wsk_pliku;
    struct baza osoba, *wsk_osoby;
    wsk_osoby=&osoba;
    //menu
    printf("\nMenu\n");
    printf("1. Wprowadz dane\n");
    printf("2. Zapisz dane\n");
    printf("3. Wczytaj dane\n");
    printf("4. Wyswietl dane\n");
    printf("5. Koniec\n");
    //program
    do
    {
        fflush(stdin);
        printf("\nWybor: ");
        scanf("%c", &znak);
        switch(znak)
        {
        case '1' :
            printf("\nWprowadzanie danych\n");
            printf("\nPodaj dane osoby:\n");
            printf("\tImie: "); scanf("%s",osoba.imie);
            printf("\tNazwisko: "); scanf("%s",osoba.nazwisko);
            printf("\tTelefon: "); scanf("%d",&osoba.telefon);
        break;
        case '2' :
            printf("\nZapis danych\n");
            if((wsk_pliku=fopen("baza.txt","w+"))!=NULL)
                {
            fprintf(wsk_pliku,"%s",wsk_osoby->imie); fprintf(wsk_pliku,"\n");
            fprintf(wsk_pliku,"%s",wsk_osoby->nazwisko); fprintf(wsk_pliku,"\n");
            fprintf(wsk_pliku,"%d",wsk_osoby->telefon); fprintf(wsk_pliku,"\n");
            fclose(wsk_pliku);
                };
                break;
        case '3' :
            printf("\nWczytywanie danych\n");
             if((wsk_pliku=fopen("baza.txt","r"))!=NULL)
                {
                    fscanf(wsk_pliku,"%s",wsk_osoby->imie);
                    fscanf(wsk_pliku,"%s",wsk_osoby->nazwisko);
                    fscanf(wsk_pliku,"%d",&wsk_osoby->telefon);
                    fclose(wsk_pliku);
                }
            else
                printf("Blad otwarcia pliku\n");
                break;
        case '4' :
            printf("\nOto Twoje dane\n");
            if((wsk_pliku=fopen("baza.txt","r"))!=NULL)
            {
            printf("\tImie: %s\n",wsk_osoby->imie);
            printf("\tNazwisko: %s\n", wsk_osoby->nazwisko);
            printf("\tTelefon: %d", wsk_osoby->telefon);
            fclose(wsk_pliku);
            }
            else
                printf("\nBrak danych\n");
            break;
        case '5' :
            printf("\nKoniec\n");
            break;
        default :
            printf("\nWybierz ponownie\n");


        }
    }
    while (znak!='5');
    return 0;
}

