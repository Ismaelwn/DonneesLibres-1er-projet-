#include <stdexcept>
/** @file **/
#include <iostream>
#include "tableau-donnees.hpp"
#include "tableau-donnees-avance.hpp"
#include "tableau-lecture-csv.hpp"
using namespace std;

/** Affiche l'année avec le plus de naissances et l'année avec le plus de mariages
 **/ //fait ensemble et fiable a 100%
int main() {
    // Remplacer cette ligne et la suivante par le code adéquat
    vector<string>Achercher = {"Naissances", "Mariages"}; //dans la consigne, on nous demande le nombre de declarations de deux elements, en les regroupant dans un tableau on peut automatiser l'affichage
    for( int i = 0; i< Achercher.size();i++){ // on va afficher le nombre de declarations pour chaque element du tableau
    vector<vector<string>>y = litTableauCSV("donnees/statistiques_de_creation_d_actes_d_etat_civil_par_arrondissement.csv", 4);
    vector<vector<string>>yi = selectLignes(y , 0, Achercher[i]);// on selectionne les lignes qui nous interesse pour chaque element du tableau
    vector<string>y2 = colonne(yi, 3);
    vector<int>yii = conversionInt(y2);
    int indice = indiceMax(yii); // on cherche l'indice du plus grand nombre de declarations
    string Max = y2[indice]; // on copie la valeur du plus grand nombre de declarations dans le tableau dans une variable
    vector<vector<string>>p = selectLignes(yi, 3, Max);// on cree un tableau de tableau de string ( qui ne possedera qu'une ligne) pour obtenir l'année grace a Max qui correspond au plus grand nombre de declarations
    
    cout<<"L'année pendant laquelle il y a eu le plus de déclarations de "<<Achercher[i]<< " est : "<<p[0][1]<<endl;
    cout<< "( il y a eu "<<p[0][3]<<" déclarations)"<<endl;

    
    
}
}
