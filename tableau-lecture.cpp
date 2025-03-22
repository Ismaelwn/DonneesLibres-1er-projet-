#include <stdexcept>
/** @file **/
#include <fstream>
#include <sstream>
#include "tableau-lecture.hpp"


vector<vector<string>> litTableau(string nom_fichier, int nb_colonnes) {
    ifstream fichier;
    fichier.open(nom_fichier);
    string lecteur;
    vector<string>t;
    t = vector<string>(nb_colonnes);
    vector<vector<string>>tab;
    while(fichier){
        for ( int i = 0; i < nb_colonnes; i++){
            fichier>>lecteur;
            if (fichier){
            t[i] = lecteur;
    }
        }
    if (fichier){
        tab.push_back(t);
    }}
    return tab;
}


