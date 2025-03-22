#include <stdexcept>
/** @file **/
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

/** Calcule et affiche le prénom le plus donné une année donnée
 * ainsi que le nombre de naissance cette année là **/ //fait ensemble et meme fiabilité que la fonction main de prenom.cpp
int main() {
    // Remplacer cette ligne et la suivante par le code adéquat
    cout<<"entrez une année entre 2006 et 2021 : ";
    string annee;
    cin >> annee;
    ifstream fichier("donnees/liste_des_prenoms.csv");
    string entete;
    getline(fichier, entete);
    string nombre1;
    string sexe;
    string date;
    string prenoms;
    string nombre2;
    int nombre;
    int total = 0;
    int tnbre = 0;
    string tprenom;
    
        while(getline(fichier,nombre1,';') and getline(fichier,sexe,';') and getline(fichier,date,';') and getline(fichier,prenoms,';') and getline(fichier, nombre2)){
        istringstream(nombre2) >> nombre;
        if (annee == date){
            total += nombre;
            if( tnbre < nombre){
                tprenom = prenoms;
                tnbre = nombre;
}
}
        }
   
cout<<"en "<<annee<<", il y a eu "<<total<<" naissances"<<endl;
cout<<"Le prénom le plus donné a été : "<<tprenom<<" (donné "<<tnbre<< " fois) "<<endl;



}            
            
    

    


