#include <stdexcept>
/** @file **/
#include <iostream>
#include "tableau-donnees.hpp"
#include "tableau-donnees-avance.hpp"
#include "tableau-lecture-csv.hpp"
using namespace std;

/** Affiche le nombre d'arbres du genre Platanus, et le nombre d'espèces
 *  différentes pour ce genre Platanus, parmi les "arbres remarquables"
 **/ //fait ensemble et fiable a 100%
int main() {
    vector<vector<string>>y = litTableauCSV("donnees/arbresremarquablesparis.csv", 19);
    vector<vector<string>>ki = selectLignes(y, 2, "Platanus");// on utilise selectLignes pour pouvoir obtenir un tableau de tableau où l'element de la 3e colonne est toujours "Platanus" et donc la taille de ce tableau de tableau correspond au nombre d'arbres de genre Platanus
    vector<string>u = distinct(ki, 3);// la 4e colonne correspond au genre de l'arbre, si on utilise distinct (qui permet d'eliminer les repetitions dans une colonne d'un indice precis) sur le tableau de tableau ki sur sa 4eme colonne, on elimine les repetitions de nom d'especes et donc la taille de ce tableau de tableau correspondra au nombre d'especes
    
    
    
    cout<<"il existe "<<u.size()<<"  especes."<<endl;
    cout<<"il y a "<<ki.size()<<" arbres de genre Platanus."<<endl; 
}