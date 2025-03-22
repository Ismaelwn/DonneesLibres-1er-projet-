#include <stdexcept>
/** @file **/
#include <iostream>
#include <fstream>
#include <sstream>
#include "tableau-lecture-csv.hpp"


vector<vector<string>> litTableauCSV(string nom_fichier, int nb_colonnes){
    ifstream fichier;
    fichier.open(nom_fichier);
    string entete;
    getline(fichier ,entete);
    string lecteur;
    vector<string>t;
    t = vector<string>(nb_colonnes);
    vector<vector<string>>tab;
    while(fichier){ // on repete tant qu'on est encore dans le fichier
        for ( int i = 0; i < nb_colonnes-1; i++){ // la boucle s'arrete a nb_colonnes-2 car l'element d'indice nb_colonnes-2  
            getline(fichier, lecteur,';');        // est le dernier element delimité par un ";" 
            t[i] = lecteur;
           }
        
        getline(fichier, lecteur); //on lit le dernier element de la ligne
        if ( lecteur.size() > 0 and lecteur[lecteur.length()-1] == '\r' ){ // cela permet de ne pas inclure l'espace restant apres l'element lorsqu'on lit la valeur de la derniere colonne de chaque ligne
            lecteur.resize(lecteur.length() - 1); 
           }
    t[nb_colonnes-1] = lecteur; //on affecte le dernier element de la ligne
    if (fichier){//on verifie toujours si on est pas en dehors du fichier
        tab.push_back(t);// on ajoute cette ligne au tableau que l'on va renvoyer
    }
}
    return tab; // on renvoie le tableau avec toutes les lignes (ou autres tableaux) ajoutées
}


        

vector<vector<string>> litTableauCSV(string nom_fichier) {
   throw runtime_error("Fonction main non implantée ligne 38");
}




