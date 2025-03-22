#include <stdexcept>
/** @file **/
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

/** Calcule et affiche le nombre de mariages un samedi entre 2010 et 2015 **/ //réalisé ensemble et fiable a 100% car le nombre de mariages le samedi obtenu est le meme que le nombre de mariages le samedi donné dans la consigne
int main() {
    // Remplacer cette ligne et la suivante par le code adéquat
    int Annee;
    string jourSemaine;
    int NbreMariages;
    int NbreTotalMariages = 0;
    ifstream fichier;
    fichier.open("donnees/statistiques-des-jours-des-mariages.txt");
    while (fichier >> Annee and fichier >> jourSemaine and fichier >> NbreMariages){ //on lit le fichier ligne par ligne
        if (jourSemaine == "Samedi"){ // si l'element du fichier qui correspond au jour de la semaine que l'on lit est le samedi on ajoute a NbreTotalMariages le nbreMariages lu ( nombre de mariages)
        NbreTotalMariages = NbreTotalMariages + NbreMariages;
} 
}
   cout<<"Le nombre total de mariages celebres un samedi est : "<<NbreTotalMariages<<endl; 
   
}

