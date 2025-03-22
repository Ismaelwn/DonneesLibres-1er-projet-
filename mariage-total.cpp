#include <stdexcept>
/** @file **/
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

/** Calcule et affiche le nombre total de mariages célébrés entre 2010 et 2015 **/ //réalisé ensemble et fiable à 100% car le nombre obtenu a la fin est identique a celui donné dans la consigne
int main() {
    int Annee; 
    string jourSemaine;
    int NbreMariages;
    int NbreTotalMariages = 0; 
    ifstream fichier;
    fichier.open("donnees/statistiques-des-jours-des-mariages.txt");
    while (fichier >> Annee and fichier >> jourSemaine and fichier >> NbreMariages){ // on lit le fichier ligne par ligne
        NbreTotalMariages = NbreTotalMariages + NbreMariages;
}
        cout<<"le nombre de mariages célébrés entre 2010 et 2015 est : "<<NbreTotalMariages<<endl;//nombre total de mariages célébrés entre 2010 et 2015
        
    
}

