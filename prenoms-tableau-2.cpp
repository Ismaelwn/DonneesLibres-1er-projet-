#include <stdexcept>
/** @file **/
#include <fstream>
#include <iostream>
#include "tableau-donnees.hpp"
#include "tableau-lecture.hpp"
using namespace std;


/**
 * Demande à l'utilisateur un prénom et calcule
 * - le nombre de garçons et filles à qui l'on a donné ce prénom
 * - la meilleure année pour ce prénom pour les garçons et filles
 **/
int main() {
  
    vector<vector<string>>z = litTableau("donnees/liste_des_prenoms.txt", 4);
    vector<string>q = colonne(z, 3);
    vector<int>u = conversionInt(q);
    int totalnaissance = somme(u);
    cout<<"Nombre total de naissances : "<<totalnaissance<<endl;
    cout<<"choississez un prénom : ";
    string prenom;
    cin>> prenom;
    vector<vector<string>>y = selectLignes(z,2,prenom);
    vector<vector<string>>yG = selectLignes(y, 0,"M");
    vector<vector<string>>yF = selectLignes(y, 0,"F");
    
    vector<string>pG = colonne(yG, 3); //garcon
    vector<int>jG = conversionInt(pG);
    int indiceG = indiceMax(jG);
    string MaxnaissanceG;
    int totalprenomG;
    string MaxanneeG;
    if( indiceG >= 0){
     MaxnaissanceG = pG[indiceG];
     vector<vector<string>>eG = selectLignes(y, 3,MaxnaissanceG);
     MaxanneeG = eG[0][1];
     totalprenomG = somme(jG);
    }
   
    
    
    vector<string>pF = colonne(yF, 3); //filles
    vector<int>jF = conversionInt(pF);
    int indiceF = indiceMax(jF);
    string MaxnaissanceF;
    int totalprenomF;
    string MaxanneeF;
    if( indiceF >= 0){
     MaxnaissanceF = pF[indiceF];
     vector<vector<string>>eF = selectLignes(y, 3,MaxnaissanceF);
     MaxanneeF = eF[0][1];
     totalprenomF = somme(jF);
    }
    
   
    
    

    
    
   
    
    if ( MaxnaissanceG > "0"){
        cout<<"Le prénom "<<prenom<<" a été donné à " <<totalprenomG<<" garçons entre 2006 et 2021"<<endl;
        cout<<"L’année la plus forte est "<<MaxanneeG<<" avec "<< MaxnaissanceG<<" enfants"<<endl;    
    }else{
        cout<<"le prenom "<< prenom <<" n'a été donné à aucuns garçons entre 2006 et 2021"<<endl;
    }
     if ( MaxnaissanceF > "0"){
        cout<<"Le prénom "<<prenom<<" a été donné à " <<totalprenomF<<" filles entre 2006 et 2021"<<endl;
        cout<<"L’année la plus forte est "<<MaxanneeF<<" avec "<< MaxnaissanceF<<" enfants"<<endl;    
    }else{
       cout<<"le prenom "<< prenom <<" n'a été donné à aucunes filles entre 2006 et 2021"<<endl;
    }
           
}

