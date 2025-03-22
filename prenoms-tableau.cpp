#include <stdexcept>
/** @file **/
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

/** Infrastructure minimale de test **/
#define CHECK(test) if (!(test)) cerr << "Test failed in file " << __FILE__ << " line " << __LINE__ << ": " #test << endl

vector<vector<string>> tableauTest = {
    { "M", "2011", "Bubulle", "3"},
    { "F", "2012", "Bichette", "4"},
    { "F", "2011", "Babouche", "7"},
    { "F", "2011", "Ziboulette", "1"}
};

/** Affiche le contenu d'un tableau de chaînes à deux dimensions
 * @param tableau un tableau à deux dimensions
 **/ //fait ensemble et fiable a 100%
void afficheTableau(vector<vector<string>> tableau) {
    for ( int i = 0; i < tableau.size();i++){ // on parcours les lignes(tableaux) du tableau2D tableau
        for ( int j = 0; j < tableau[i].size();j++){ // on parcours les colonnes de chaque ligne
            cout<<tableau[i][j]<<" "; // on affiche l'element de la case de ligne i et de colonnes j de tableau suivi d'un espace
}
cout<<endl;}}
void testAfficheTableau() {
    afficheTableau(tableauTest);
}


/** Construction d'un tableau 2D de chaines de caractères lu depuis un fichier
 * @param fichier le nom d'un fichier contenant un nombre fixe
  * de colonnes séparées par des espaces
 * @param nb_colonnes le nombre de colonnes du fichier
 * @return un tableau de chaines de caractères à deux dimensions
 **/ //fait ensemble et fiable a 100%
vector<vector<string>> litTableau(string nom_fichier, int nb_colonnes) {
    ifstream fichier;
    fichier.open(nom_fichier);
    string lecteur; // variable qui va lire toutes les valeurs du fichier
    vector<string>t;
    t = vector<string>(nb_colonnes); //on lui donne la taille de nb_colonne
    vector<vector<string>>tab;
    while(fichier){ 
        for ( int i = 0; i < nb_colonnes; i++){ // on lit les elements du fichier nb_colonnes fois et chaque fois que l'on un element du fichier on le stocke dans notre tableau t de taille nb_colonnes
            fichier>>lecteur;
            if (fichier){
            t[i] = lecteur;
    }
        }//on sort de la boucle for et on ajoute le tableau t au tableau de tableau tab
    if (fichier){ 
        tab.push_back(t); 
    }
}
    return tab;
}

/** Test de la fonction litTableau **/
void testLitTableau() {
    CHECK(litTableau("donnees/donnees-test.txt", 4) == tableauTest);
    vector<vector<string>> t = litTableau("donnees/liste_des_prenoms.txt", 4);
    CHECK(t.size() == 22994);
    CHECK(t[0][0] == "F");
    CHECK(t[4][2] == "Astrid");
    CHECK(t[5][3] == "12");
}

/** Extraction d'une colonne d'un tableau de données
 * @param t un tableau 2D de chaines de caractères
 * @param i un numéro de colonne
 * @return la colonne j, représentée par un vecteur de chaines de caractères
 **/ //fait ensemble et fiable a 100%
vector<string> colonne(vector<vector<string>> t, int j) { 
    vector<string>z;
    z = vector<string>(t.size()); // vu qu'on prend un element de chaque ligne(tableau) de t, i faut que le tableau dans lequel on va stocker ces elements est autant de cases que le tableau 2D ait de lignes
    for ( int i = 0; i < z.size(); i++){ // vu que l'indice de la colonne est toujours le meme on parcours uniquement les lignes du tableau donné en arguments
        z[i] = t[i][j];
    }
    return z;
}

/** Test de la fonction colonne **/
void testColonne() {
    CHECK(colonne(tableauTest, 0) == vector<string>({"M","F","F","F"}));
    CHECK(colonne(tableauTest, 1) == vector<string>({"2011","2012","2011","2011"}));
    CHECK(colonne(tableauTest, 2) == vector<string>({"Bubulle","Bichette","Babouche","Ziboulette"}));
    CHECK(colonne(tableauTest, 3) == vector<string>({"3","4","7","1"}));
}

/** Convertit un tableau de chaines de caractères en un tableau d'entiers
 * @param t, un vecteur de chaines de caractères
 * @return un vecteur d'entiers
 **/ //fait ensemble et fiable a 100%
vector<int> conversionInt(vector<string> t) {
    vector<int> resultat = vector<int>(t.size());
    for(int i =0; i < t.size(); i++) {
        istringstream(t[i]) >> resultat[i];
    }
    return resultat;
}

void testConversionInt() {
    CHECK(conversionInt({}) == vector<int>({}));
    CHECK(conversionInt({"1","2","3"}) == vector<int>({1,2,3}));
}

/** copier la fonction somme déjà écrite **/ //fait ensemble et fiable a 100%
int somme(vector<int> t) {
    // Remplacer cette ligne et la suivante par le code adéquat
    int s = 0;
    for ( int i = 0; i < t.size(); i++){
        s = s + t[i];
    }
    return s;
}


/** copier la fonction moyenne déjà écrite **/ //fait ensemble et fiable a 100%
int moyenne(vector<int> t) {
    // Remplacer cette ligne et la suivante par le code adéquat
     return somme(t)/t.size();
}

/** copier la fonction indiceMax déjà écrite **/ //fait ensemble et fiable a 100%
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


/** Sélection des lignes d'un tableau de données
 * Sélectionne un ensemble de lignes en fonction d'un critère donné
 * @param t, un tableau contenant des lignes de données
 * @param j, l'indice de la colonne à vérifier
 * @param valeur, une chaine de caractères correspondant au critère
 * @return un tableau de données ne contenant que les lignes de t telles
 *  que la colonne j ait la valeur correspondant au critère
 **/ //fait ensemble et fiable a 100%
vector<vector<string>> selectLignes(vector<vector<string>> t, int j, string valeur) {
    // Remplacer cette ligne et la suivante par le code adéquat
    vector<vector<string>>k; 
    for(int i = 0; i < t.size();i++){ // on parcours l'uniquement les lignes puisque la colonne de chaque ligne a analysé est donné
        if ( t[i][j] == valeur ){ // si l'element du tableau a la colonne j de la ligne i correspond a la valeur on ajoute la ligne i au tableau 2D k
            k.push_back(t[i]); //vu qu'on ne connait pas d'avance le nombre de lignes que l'on va reprendre, le tableau 2D dans lequel on va reprendre les lignes selectionnées n'a pas de taille predefini et on utilise l'operation push_back pour ajouter la ligne si elle valide la condition
        }
    }
    return k;
}

/** Test de la fonction selectLignes **/
void testSelectLignes() {
    CHECK(selectLignes(tableauTest, 0, "M") == vector<vector<string>>({{ "M", "2011", "Bubulle", "3"}}));
    CHECK(selectLignes(tableauTest, 1, "2011") == vector<vector<string>>({{ "M", "2011", "Bubulle", "3"}, { "F", "2011", "Babouche", "7"}, { "F", "2011", "Ziboulette", "1"}}));
}

/** Lance les tests de litTableau, selectLignes et colonne puis
 * affiche le nombre total de naissances puis
 * demande à l'utilisateur un prénom et calcule et affiche
 * - le nombre de garçons et filles à qui l'on a donné ce prénom
 * - la meilleure année pour ce prénom pour les garçons et filles
 **/ //fait ensemble et fiable a 100%
int main() {
    //test
    testAfficheTableau();
    testLitTableau();
    testColonne();
    testConversionInt();
    testSelectLignes();
    //test
    vector<vector<string>>z = litTableau("donnees/liste_des_prenoms.txt", 4);
    int totalnaissance = somme(conversionInt(colonne(z, 3)));// on selectionne la colonne 3 de z qu'on convertit en tableau d'entier afin de pouvoir appeler la fonction somme et avoir le total de naissances
    cout<<"Nombre total de naissances : "<<totalnaissance<<endl;
    cout<<"choississez un prénom : ";
    string prenom;
    cin>> prenom;
    vector<vector<string>>y = selectLignes(z,2,prenom); // prenom contient le nom qu'on a ecrit au clavier, y correspond au tableau2D où sur chaque 3e colonne de chaque ligne, on a le prenom qu'on a marqué au clavier
    vector<vector<string>>yG = selectLignes(y, 0,"M"); // yG correspond y correspond au tableau2D où sur chaque 3e colonne de chaque ligne, on a le prenom qu'on a marqué au clavier mais donné a des garcons
    vector<vector<string>>yF = selectLignes(y, 0,"F"); //yF correspond y correspond au tableau2D où sur chaque 3e colonne de chaque ligne, on a le prenom qu'on a marqué au clavier mais donné a des filles
    
    
    
    vector<string>pG = colonne(yG, 3); //garcon
    vector<int>jG = conversionInt(pG); // on convertit en tableau d'entiers pour pouvoir utiliser la fonction IndiceMax
    int indiceG = indiceMax(jG);// on cherche l'indice dans le tableau jG du plus grand nombre de naissances
    string MaxnaissanceG;
    int totalprenomG;
    string MaxanneeG;
    if( indiceG >= 0){ //au cas ou les tableau 2D Yg ou Y sont vides il n'y aura pas d'indiceMax( on aura -1 qui ne correspond a aucun indice ce qui va provoquer une erreur de segmentation si on cherche pG[-1]
     MaxnaissanceG = pG[indiceG]; //on stocke la valeur du plus grand nombre
     vector<vector<string>>eG = selectLignes(y, 3,MaxnaissanceG); //on cree un tableau 2D ne contenant qu'une ligne pour obtenir l'année qui est dans la meme ligne(ou sous tableau) que MaxnaissanceG
     MaxanneeG = eG[0][1]; // on obtient l'année qui repond a la condition
     totalprenomG = somme(jG); 
    }
    
    vector<string>pF = colonne(yF, 3); //filles, même idée qu'avec les naissances de garcons
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