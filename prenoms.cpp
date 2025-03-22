#include <stdexcept>
/** @file **/
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

/** Calcule et affiche le prénom le plus utilisé une année donnée
 * ainsi que le nombre de naissances cette année là **/ // fait ensemble et fiable a 85% l'exemple est verifié, aucunes erreurs quand on tape n'importe quelle année vu que le fichier est tres grand on ne peut verifier le nombre total de naissances par années et le prenom le plus donné a chaque fois (+ son nombre de fois), en plus l'on a chaque annee a part 2006 et 2015 gabriel comme prenom le plus donnée

int main(){
    cout<<"entrez une année entre 2006 et 2021 : ";
    int annee;
    cin >> annee; //on stocke la reponse au clavier dans la variable annee
    if( annee > 2021 or annee < 2006){
        cout<<"veuillez saisir une année valide, c'est a dire entre 2006 et 2021"<<endl;
    }else{
    ifstream fichier;
    fichier.open("donnees/liste_des_prenoms.txt"); //lecture du fichier
    char genre; //definition de la variable permetant de lire le 1ere element (de type char) de la ligne
    int date; //definition de la variable permettant de lire le 2em element ( de type int) de la ligne
    string prenom;//definition de la variable permettant de lire le 3em element( de type string ) de la ligne
    int nbre;// definition de la variable permettant de lire le 4em element( de type int ) de la ligne
    int total = 0; //variable qui va compter le nombre de naissances dans une annee precise
    int tnbre = 0; //variable qui va contenir le nombre de fois maximum ou le prenom le plus donné a été donné
    string tprenom; // variable qui va contenir le prenom le plus donné
    while( fichier>>genre and fichier>>date and fichier>>prenom and fichier>>nbre){// on lit chaque ligne du fichier et on repete cette operation tant que l'on est encore dans le fichier
    if( date == annee ){
           total += nbre;
            if( tnbre < nbre){// va permettre de donner a tnbre la valeur lue la plus grande(des qu'on trouvera plus grand que tnbre, on stockera dans tnbre ce nombre plus grand et on changera aussi tprenom par le prenom lu sur la ligne ou on a lu un nombre plus grand que tnbre
                  tnbre = nbre;
                  tprenom = prenom;
            }
        }
    }
    
    cout<<"en "<<annee<<", il y a eu "<<total<<" naissances"<<endl;
    cout<<"Le prénom le plus donné a été : "<<tprenom<<" (donné "<<tnbre<< " fois) "<<endl;
}       
}
    
    
  
