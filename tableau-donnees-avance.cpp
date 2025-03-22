#include <stdexcept>
/** @file **/
#include <fstream>
#include <sstream>
#include "tableau-donnees-avance.hpp"



int chercheIndice(vector<string> t, string valeur) { 
    for ( int i = 0; i<t.size(); i++){ //on parcours chaque element du tableau et a chaque debut de boucle on regarde si la valeur du tableau a l'indice i ou on est, est egale a la valeur que l'on cherche, si c'est le cas on renvoie l'indice de la valeur du tableau qui a validé cette condition sinon on finit par sortir de la boucle, et comme on a pas trouvé de valeurs dans le tableau correspondant, on renvoie -1
        if( t[i] == valeur){
            return i;
        }
    }
    return -1;
}

vector<string> distinct(vector<vector<string>> data, int j) {
    vector<string>y;
    for ( int i = 0; i< data.size(); i++){ // on parcours les elements du tableau ligne par ligne sur la meme colonne
        if (chercheIndice(y, data[i][j]) == -1){ // si l'element n'est pas deja present dans y on le rajoute
            y.push_back(data[i][j]);
           
    }
    }
    return y; // on renvoie y qui contient uniquement dont les cases contiennent uniquement des valeurs distincts
}


vector<double> conversionDouble(vector<string> t) { // on s'inspire de la fonction conversionInt
     vector<double> resultat = vector<double>(t.size()); //on remplace le type int par double a chaque fois
    for(int i =0; i < t.size(); i++) {
        istringstream(t[i]) >> resultat[i];
    }
    return resultat;
}


vector<int> groupByInt(vector<vector<string>> data, vector<string> valeurs, int j1, int j2) {
    vector<int>y; 
    y = vector<int>(valeurs.size()); // on donne la taille du tableau valeurs au tableau y 
    for( int z = 0; z< valeurs.size(); z++){ // on parcours le tableau de valeurs 
        vector<string>zi; // je l'ai initialisé dans une boucle pour qu'il s'initialise a chaque fois en tableau vide
        for( int i = 0; i < data.size(); i++){ //on parcours chaque ligne(tableau) du tableau data
            if ( data[i][j1] == valeurs[z]){// pour chaque ligne si la valeur de data a la colonne j1
                zi.push_back(data[i][j2]);// on rajoute la valeur de data a cette ligne de la colonne j2 au tableau zi
            }
        }
        int resultat = 0; // dans la 1ere boucle, pour que le total de chaque element du tableau valeurs soit reinitialisé a chaque 1ere boucle 
        vector<int> resulta = vector<int>(zi.size());
        for(int i = 0; i < zi.size(); i++) {
            istringstream(zi[i]) >> resulta[i];
        }
        for( int k = 0; k<resulta.size(); k++){ //on convertis en tableau int  zi qui est le tableau de string qui contient toutes les valeurs les valeurs selon lesquelles doit se faire le regroupement et puis a l'aide de la boucle on additionne tous les elements du tableau converti en entier pour obtenir une somme
            resultat += resulta[k];
        } 
            y[z] = resultat;
            
    }
    return y;
}
    
                
                
                
        
    
vector<double> groupByDouble(vector<vector<string>> data, vector<string> valeurs, int j1, int j2) { //meme raisonnement GroupByInt
    vector<double>y; 
    y = vector<double>(valeurs.size());
    for( int z = 0; z< valeurs.size(); z++){
        vector<string>zi;
        for( int i = 0; i < data.size(); i++){
            if ( data[i][j1] == valeurs[z]){
                zi.push_back(data[i][j2]);
            }
        }
        double resultat = 0;
        for( int k = 0; k<conversionDouble(zi).size(); k++){
            resultat += conversionDouble(zi)[k];
        } 
            y[z] = resultat;
            
    }
    return y;
}


template<class T>
vector<T> conversion(vector<string> t) {
    // Remplacer cette ligne et la suivante par le code adéquat
    throw runtime_error("Fonction conversion non implantée ligne 35");
}

template<class T>
vector<T> groupBy(vector<vector<string>> data, vector<string> valeurs, int j1, int j2) {
    // Remplacer cette ligne et la suivante par le code adéquat
    throw runtime_error("Fonction groupBy non implantée ligne 41");
}

// Force l'instanciation des templates
template vector<int> conversion<int>(vector<string> t);
template vector<double> conversion<double>(vector<string> t);
template vector<int> groupBy<int>(vector<vector<string>> data, vector<string> valeurs, int j1, int j2);
template vector<double> groupBy<double>(vector<vector<string>> data, vector<string> valeurs, int j1, int j2);

