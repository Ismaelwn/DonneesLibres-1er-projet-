#include <stdexcept>
/** @file **/
#include <fstream>
#include <iostream>
#include "tableau-lecture.hpp"
#include "tableau-donnees.hpp"
#include "tableau-donnees-avance.hpp"
using namespace std;


/**
 * Calcule et affiche :
 * - le nombre total de naissances de garçons et de naissances de filles
 * - l'année qui a eu le plus de naissances (garçons et filles confondus), avec leur nombre
 * - le nombre de naissances en moyenne par an
 * - les nombres de prénoms féminins et masculins différents
 * - le prénom masculin et le prénom féminin le plus populaire
 **/
int main() {
    // Remplacer cette ligne et la suivante par le code adéquat
    vector<vector<string>>data = litTableau("donnees/liste_des_prenoms.txt",4);
    vector<vector<string>>zF = selectLignes(data, 0, "F"); //tableau de tableau caracterisé par le fait que tous les naissances soit des filles
    vector<vector<string>>zM = selectLignes(data, 0, "M");//tableau de tableau caracterisé par le fait que tous les naissances soit des garcons
    int nF = distinct(zF, 2).size(); // nombre de prenoms feminins
    int nM = distinct(zM,2).size(); // nombre de prenoms masculins
    
    cout<<"Il y a eu "<< somme(conversionInt(colonne(selectLignes(data, 0, "M"),3))) <<" naissances de garçons et "<<somme(conversionInt(colonne(selectLignes(data, 0, "F"),3))) <<" naissances de filles"<<endl;

   cout<<"l'année avec le plus de naissances est : "<<distinct(data, 1)[indiceMax(groupByInt(data, distinct(data, 1), 1, 3))]<<" avec " <<  groupByInt(data, distinct(data, 1), 1, 3)[indiceMax(groupByInt(data, distinct(data, 1), 1, 3))]<<" naissances "  << endl;
   cout<<"En moyenne, naissent "<< (somme(conversionInt(colonne(selectLignes(data, 0, "M"),3)))+somme(conversionInt(colonne(selectLignes(data, 0, "F"),3))))/distinct(data, 1).size()<<" enfants par an"<<endl;
   cout<<"il y a eu "<<nF<<" prénoms de filles differents et "<<nM<<" prénoms de garcons differents"<<endl;
; 
    cout<<"le prénom masculin le plus populaire est "<< distinct(zM,2)[indiceMax(groupByInt(zM, distinct(zM,2), 2, 3))] <<" avec "<< somme(conversionInt(colonne((selectLignes(zM, 2,distinct(zM,2)[indiceMax(groupByInt(zM, distinct(zM,2), 2, 3))])),3))) <<" naissances "<<endl;
    cout<<"le prénom feminin le plus populaire est "<< distinct(zF,2)[indiceMax(groupByInt(zF, distinct(zF,2), 2, 3))] <<" avec "<< somme(conversionInt(colonne((selectLignes(zF, 2,distinct(zF,2)[indiceMax(groupByInt(zF, distinct(zF,2), 2, 3))])),3))) <<" naissances "<<endl;
    
}
