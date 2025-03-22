#include <stdexcept>
/** @file **/
#include <iostream>
#include "tableau-donnees.hpp"
#include "tableau-lecture-csv.hpp"
using namespace std;

/** Affiche le genre et l'espece de l'arbre le plus haut de Paris
 * parmi les "arbres remarquables"
 **/ //fait ensemble et fiable a 100%
int main() {
    vector<vector<string>>y = litTableauCSV("donnees/arbresremarquablesparis.csv", 19);
    vector<string>z = colonne(y,12); // Pour comparer les tailles des arbres, on crée un vecteur colonne contenant toutes les tailles en type string, que l'on convertira dans la ligne d'apres en tableau d'entiers pour obtenir l'indice du plus grand element du tableau
    int indice = indiceMax(conversionInt(z));
    string max = z[indice];
    vector<vector<string>>zi = selectLignes(y,12 ,max );// on cree un tableau de tableau d'une ligne pour pouvoir obtenir le nom francais, le genre et l'espece qui sont sur la meme ligne ( dont il n'en existe qu'une d'ou le tableau de tableau d'une ligne )que la taille du plus grand arbre de paris
    cout<<"le nom français du plus haut arbre de Paris est "<<zi[0][1]<<endl;
    cout<<"son genre est "<<zi[0][2]<<" et il est de l'espece : "<<zi[0][3]<<endl;
    cout<<"(il mesure "<<zi[0][12]<<" mètres)."<<endl;
    
    
}

