#include "generatorClass.h"
#include <iostream>
using namespace std ;
#include <fstream>

    void showTable(int *tab, int tSize) {
    for(int i=0; i<tSize; i++) {
        cout << tab[i] << endl ;
        }
    }

    void copyValuesFromTableToTable(int *originalTable, int *toCopyTable, int tSize) {
        for(int i=0; i<tSize; i++){
            toCopyTable[i] = originalTable[i] ;
        }
    }

    void swapValuesInTable(int *first, int *secound){
        int pom = *secound ;
        *secound = *first ;
        *first = pom ;
    }

    int * generateRandomNumbersIntoTable(int tSize){
        //int *outputTable = new int [tSize] // np 1 000 000
        LinearCongurentMethod *generator = new LinearCongurentMethod(12, tSize) ;
        return generator->generateSequenceToTable(tSize) ;

    }

    void reverseTable(int *tab, int tSize){
        int *pomTab = new int[tSize] ;
        copyValuesFromTableToTable(tab, pomTab, tSize) ;
        int pomX = 0 ;
        for(int i=tSize -1; i>=0; i--){
            tab[pomX] = i;
            pomX ++ ;
        }

    }


    unsigned long long int LinearCongurentMethod::power(int podstawa, int wykladnik){
        unsigned long long int wynik = 1;

        for (int i = 0; i<wykladnik; i++)
            wynik*=podstawa;

        return wynik;
    }

    int* LinearCongurentMethod::factorNumber(int firstFactoredNumber){
        if(firstFactoredNumber == 1){
            int tab[1] = {1};
            return tab ;
        }
        else {
            int tabSize= 1;
            int currentMod = 2;
            int originalNumber = firstFactoredNumber ;
            while(firstFactoredNumber > 1){
                while(firstFactoredNumber % currentMod != 0){
                    currentMod ++ ;
                }
                //cout << currentMod << endl ;
                tabSize ++ ;
                firstFactoredNumber /= currentMod ;
                currentMod = 2;
            }
            int *factoredNumbers = new int[tabSize] ;
            int actIndex = 0 ;
            while(originalNumber > 1){
                while(originalNumber % currentMod != 0){
                    currentMod ++ ;
                }
                factoredNumbers[actIndex] = currentMod ;
                actIndex ++ ;
                originalNumber /= currentMod ;
                currentMod = 2;
            }
            factoredNumbers[actIndex] = 1 ;
            factoredTableSize = tabSize ;
            return factoredNumbers ;
        }
    }

    int LinearCongurentMethod::checkNWD(int a, int b){
        int c ;
        while( b != 0){
            c = a % b  ;
            a = b ;
            b = c ;
        }
        return  a ;
    }

    void LinearCongurentMethod::calculateGainC() {
        if(factoredTableSize== 2){
            int pomA = ( factoredNumbers[0] + factoredNumbers[1] ) * 2 /3;
            c =  (pomA + factoredNumbers[0]) / 2 ;
        }
        else{
            c = m ;
            for(int i=0; i<factoredNumbers[i]; i++){
                c -= factoredNumbers[i] / 2 ;
            }
        }
        int pomNWD = checkNWD(m, c) ;
        if(pomNWD != 1){
            while(c < m){
                c++ ;
                pomNWD = checkNWD(m, c) ;
            }
        }
        if(c == m)
            c = m - 1 ;
    }

    void LinearCongurentMethod::calculateMultiplierA() {   // przyjmuje ze m > 2
        int tabASize = m - 2 ;
        int *tableA = new int[tabASize] ;
        a = 2 ;
        int actA = 2 ;
        int actLambda = 1 ;
        unsigned long long int actPOW ;
        for(int i=0; i< tabASize; i++) {
            actPOW = power(actA, actLambda) ;
            while( actPOW % m != 1){
                actLambda ++ ;
                actPOW = power(actA, actLambda) ;
            }
            tableA[i] = actLambda ;
            actLambda = 1;
            actA ++ ;
        }
        int maxLambda = -1 ;
        for(int i=0; i<tabASize; i++){
            if(tableA[i] > maxLambda)
                maxLambda = tableA[i] ;
        }
        int numberOfMaxLambda = 0 ;
        for(int i=0; i<tabASize; i++){
            if(tableA[i] == maxLambda)
                numberOfMaxLambda ++ ;
        }

        int *potentialMultiplierA = new int[numberOfMaxLambda] ;
        int mIndex = 0 ;
        for(int i=0; i<tabASize; i++){
            if(tableA[i] == maxLambda){
                potentialMultiplierA[mIndex] = i + 2;
                mIndex ++ ;
            }
        }
        a = potentialMultiplierA[mIndex-1] ;
    }

    void LinearCongurentMethod::generateSequenceToFile(fstream &outputFile) {
        Xn = (a * X0 + c) % m ;
        for(int i=0; i<n-1; i++) {
            outputFile << Xn << endl ;
            Xn = (a * Xn + c) % m ;
        }
    }

    int* LinearCongurentMethod::generateSequenceToTable(int actN) {
        int *tab = new int[n] ;
        Xn = (a * X0 + c) % m ;
        tab[0] = X0;
        for(int i=1; i<actN; i++) {
            tab[i] = Xn ;
            Xn = (a * Xn + c) % m ;
        }
        return tab ;
    }

    LinearCongurentMethod::LinearCongurentMethod(int maximalNumber, int numberOfNumbers){
       if(numberOfNumbers<1){
            cout << "Error: Amount of generated numbers must be higher that 0" << endl ;
            return ;
       }
       else if(maximalNumber < 1){
            cout << "Error: Maximal number must be higher that 0" << endl ;
            return ;
       }
       else{
            Xmax = maximalNumber ;
            m = Xmax + 1 ;
            n =  numberOfNumbers;
            X0 = 5 ;

            factoredNumbers = factorNumber(m) ;
            calculateGainC();
            calculateMultiplierA() ;

       }
    }
