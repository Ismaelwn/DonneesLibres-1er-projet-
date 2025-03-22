#include <stdexcept>
/** @file **/
#include <fstream>
#include <sstream>
#include "tableau-donnees.hpp"



void afficheTableau(vector<vector<string>> tableau) {
    // Remplacer cette ligne et la suivante par le code adéquat
    for ( int i = 0; i < tableau.size();i++){
        for ( int j = 0; j < tableau[i].size();j++){
            cout<<tableau[i][j]<<" ";
}
cout<<endl;}}




int moyenne(vector<int> t) {
    // Remplacer cette ligne et la suivante par le code adéquat
   return somme(t)/t.size();
}

int somme(vector<int> t) {
    // Remplacer cette ligne et la suivante par le code adéquat
     int s = 0;
    for ( int i = 0; i < t.size(); i++){
        s = s + t[i];
    }
    return s;
}




int indiceMax(vector<int> t) {
    // Remplacer cette ligne et la suivante par le code adéquat
    if (t.size()==0){
       return -1;
   }else{
       int k = t[0];
       int indice = 0;
       for ( int i = 1; i < t.size(); i++){
           if ( k < t[i] ){
               k = t[i];
               indice = i;
           }
       }
return indice;
   }
}



vector<string> colonne(vector<vector<string>> t, int j) {
    // Remplacer cette ligne et la suivante par le code adéquat
     vector<string>z;
    z = vector<string>(t.size());
    for ( int i = 0; i < z.size(); i++){
        z[i] = t[i][j];
    }
    return z;
}




vector<int> conversionInt(vector<string> t) {
    // Remplacer cette ligne et la suivante par le code adéquat
    vector<int> resultat = vector<int>(t.size());
    for(int i =0; i < t.size(); i++) {
        istringstream(t[i]) >> resultat[i];
    }
    return resultat;
}



vector<vector<string>> selectLignes(vector<vector<string>> t, int j, string valeur) {
    // Remplacer cette ligne et la suivante par le code adéquat
     vector<vector<string>>k;
    for(int i = 0; i < t.size();i++){
        if ( t[i][j] == valeur ){
            k.push_back(t[i]);
        }
    }
    return k;
}


