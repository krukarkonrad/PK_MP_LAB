#ifndef GENERATORCLASS_H_INCLUDED
#define GENERATORCLASS_H_INCLUDED

#include <iostream>
using namespace std ;
#include <fstream>

// pokazuje tablice
void showTable(int *tab, int tSize);
// kopiuje zawartosc jednej tablicy do drugiej
void copyValuesFromTableToTable(int *originalTable, int *toCopyTable, int tSize);
// zamienia 2 wartosci w tablicy
void swapValuesInTable(int *first, int *secound);
// losuje wartosci do tablicy uzywajac generatora
int * generateRandomNumbersIntoTable(int tSize);
// odwraca tablice
void reverseTable(int *tab, int tSize) ;

class LinearCongurentMethod{
private:
    int a= -1 ; // mno¿nik
    int Xn =-1 ; // poprzednia liczba
    int Xmax= -1 ; // maksymalna liczba
    int c= -1 ; // przyrost
    int m= -1 ; // zakres generowanych liczb
    int n= -1 ; //liczba wygenerowanych liczb
    int X0 = -1 ; // ziarno, pierwsza liczba na podstawie której bêdziemy generowali kolejne
    int factoredTableSize = 1;
    int *factoredNumbers ;

public:
        //Konstruktor ustawiający zmienne i wywołujący podfunkcje
    LinearCongurentMethod(int maximalNumber, int numberOfNumbers);
    unsigned long long int power(int podstawa, int wykladnik) ;

    /**
        Funkcja zwracaj¹ca dynamiczn¹ tablicê z wszystkimi czynnikami pierwszymi danej liczby
        Pewnym problemem jeœli chodzi o wydajnoœæ obliczeniow¹ mo¿e byæ u¿ycie 2 razy pêtli while,
        lecz dzieki takiemu rozwi¹zaniu oszczêdzamy na z³o¿onoœci pamiêciowej alokuj¹c tylko tyle miejsca
        ile potrzebujem.
        Pierwsza pêtla sprawdza jak du¿¹ tablicê potrzebujemy, a druga wype³nia t¹ tablicê czynnikami pierwszymi
    **/
    int* factorNumber(int firstFactoredNumber);

        //algorytm Euklidesa
    int checkNWD(int a, int b);

    /**
        Funkcja obliczająca przyrost C
        Jest w niej dobierane pewne c, a nastepnie sprawdzane z warunkiem NWD(c,n) = 1
    **/
    void calculateGainC();

    /**
        Funkcja obliczajaca mnożnik a
        Tworzy ona tablicę z lambdami a następnie wybiera takie a, zeby lambda była możliwie największa
    **/
    void calculateMultiplierA() ;   // przyjmuje ze m > 2 ;

        //Funkcja generująca kolejne liczby bazując na poprzednich
    void generateSequenceToFile(fstream &outputFile);

        //Funkcja generująca sekwencje i zwracająca tablicę z danymi. Przydaję sie w 2 programie
    int* generateSequenceToTable(int actN);

};





#endif // GENERATORCLASS_H_INCLUDED
