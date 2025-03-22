#include <stdexcept>
/** @file **/
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

/** Infrastructure minimale de test **/
#define CHECK(test) if (!(test)) cerr << "Test failed in file " << __FILE__ << " line " << __LINE__ << ": " #test << endl

vector<string> jours = {"Lundi", "Mardi", "Mercredi", "Jeudi", "Vendredi", "Samedi", "Dimanche"};


/** Construction du tableau des mariages par années
 * On suppose que le fichier contient sur chaque ligne une année entre 2010 et 2015
 * suivi d'un jour, puis d'un nombre de mariages
 * @param nom_fichier, le nom du fichier de données
 * @return un tableau d'entiers tel que dans chaques
 * case d'indice i, on trouve le nombre total de mariages de l'année 2010+i
 **/ //fait ensemble et fiable a 100%
vector<int> litTableauAnnee(string nom_fichier) {
    ifstream fichier;
    fichier.open("donnees/statistiques-des-jours-des-mariages.txt");
    vector<int>donnees;
    donnees = vector<int>(6);
    donnees = {0,0,0,0,0,0}; //on definit la taille du tableau donnees aux nombres d'annees entre 2010 et 2016 et on initialise chaque element du tableau a 0
    int An;
    string jourSemaine;
    int NbreMariages;
    while (fichier >> An and fichier >> jourSemaine and fichier >> NbreMariages){ // lecture du fichier ligne par ligne jusqu'a la fin de ce dernier
                if ( An == 2010 ){ // si l'année lu grace a la variable An est 2010
                    donnees[0] = donnees[0]+ NbreMariages; // on ajoute a l'element donnees[0] le nombre de mariages lus par la variable NbreMariages a cette ligne du fichier
    }else if( An == 2011 ){                    //meme idée
                    donnees[1] = donnees[1]+ NbreMariages;
    }else if( An == 2012 ){                    //meme idée
                    donnees[2] = donnees[2]+ NbreMariages;
    }else if(An == 2013 ){                     //meme idée
                    donnees[3] = donnees[3]+ NbreMariages;
    }else if( An == 2014 ){                    //meme idée
                    donnees[4] = donnees[4]+ NbreMariages;
    }else if( An == 2015 ){                    //meme idée
                    donnees[5] = donnees[5]+ NbreMariages;
    }else if(An == 2016 ){                     //meme idée
                    donnees[6] = donnees[6]+ NbreMariages;
    } 
}
        

return donnees; // on renvoie donnees dont chaque colonne donnees[i] correspond au nombre de mariages célébrés l'année 2010+i
}

/** Test de la fonction litTableauAnnee **/
void testLitTableauAnnee() {
    vector<int> t = litTableauAnnee("donnees/statistiques-des-jours-des-mariages.txt");
    CHECK(t[0] == 9195); // Nombre de mariages en 2010
    CHECK(t[3] == 9443); // Nombre de mariages en 2013
    CHECK(t[5] == 9046); // Nombre de mariages en 2015
}

/** Renvoie le numéro du jour correspondant à la chaîne de caractères
 * @param jour une chaine de caractère contenant un jour de la semaine (première lettre en majuscule)
 * @return un numéro entre 0 et 6 correspondant au jour de la semaine ou
 * -1 si le jour n'est pas valide
 **/ //fait ensemble et fiable a 100%
int indiceJour(string jour) {
    for(int i=0; i < jours.size(); i++) {
        if (jour == jours[i]) {
            return i;
        }
    }
    return -1;
}

void testIndiceJour() {
    CHECK(indiceJour("Lundi") == 0);
    CHECK(indiceJour("Samedi") == 5);
    CHECK(indiceJour("Dimanche") == 6);
    CHECK(indiceJour("samedi") == -1);
}

/** Construction du tableau des mariages par jour
 * On suppose que le fichier contient sur chaque ligne une année entre 2010 et 2015
 * suivie d'un jour, puis d'un nombre de mariages
 * @param nom_fichier, le nom du fichier de données
 * @return un tableau d'entiers tel que dans chaque
 * case d'indice i, on trouve le nombre total de mariages célébrés le jour i
 **/ //fait ensemble et fiable a 100%
vector<int> litTableauJours(string nom_fichier) {
    ifstream fichier;
    fichier.open("donnees/statistiques-des-jours-des-mariages.txt");
    vector<int>compteur;
    compteur = vector<int>(7);
    compteur = {0,0,0,0,0,0,0};//on definit la taille du tableau compteur au nombre de jour qu'il y a dans une semaine et on initialise chaque element du tableau a 0
    int Annee;
    string jourSemaine;
    int NbreMariages;
    while( fichier >> Annee and fichier >> jourSemaine and fichier >> NbreMariages){ //on lit le fichier ligne par ligne jusqu'a que la derniere ligne du fichier soit lu
        int i = indiceJour(jourSemaine); //on fait appel a la fonction IndiceJour qui lorsqu'on lui donne en argument un jour de la semaine renvoie un indice que l'on va utilisé pour placer le nombre de mariages lu sur cette ligne du fichier dans la case compteur[i] du tableau compteur
        compteur[i] = compteur[i] + NbreMariages;
}
    return compteur;
}

/** Test de la fonction litTableauJours **/
void testLitTableauJours() {
    vector<int> t = litTableauJours("donnees/statistiques-des-jours-des-mariages.txt");
    CHECK(t[0] == 4171); // Nombre de mariages le lundi
    CHECK(t[3] == 4393); // Nombre de mariages le jeudi
    CHECK(t[6] == 2); // Nombre de mariages le dimanche
}

/** Renvoie la somme d'un tableau d'entiers
 * @param t, un tableau d'entier
 * @return la somme des valeurs du tableau
 **/ //fait ensemble et fiable a 100%
int somme(vector<int> t) {
    // Remplacer cette ligne et la suivante par le code adéquat
    int s = 0;
    for ( int i = 0; i < t.size(); i++){ // on parcours toutes les case du tableau ( simple ) 
        s = s + t[i]; // et on additionne son contenue dans la variable s
}
    return s; // on obtient la somme de toutes les valeurs des cases du tableau mis en argument( ou parametre)
}
/** Test de la fonction somme **/
void testSomme() {
    CHECK(somme({1,2,3}) == 6);
    CHECK(somme({}) == 0);
    CHECK(somme({2,2,4,8}) == 16);
}

/** Renvoie la moyenne d'un tableau d'entier
 * @param t, un tableau d'entiers
 * @return la moyenne (entière) des valeurs
 * (on arrondit à l'entier inférieur)
 **/ //fait ensemble et fiable a 100%
int moyenne(vector<int> t) {
    // Remplacer cette ligne et la suivante par le code adéquat
    return somme(t)/t.size(); //on appelle la fonction somme pour qu'elle fasse la somme de toutes les valeurs du tableau et on divise par la taille du tableau ( car sa taille correspond au nombre de case du tableau et donc aux nombres de valeurs que l'on a additionné)
}

/** Test de la fonction moyenne **/
void testMoyenne() {
    CHECK(moyenne({1,2,3}) == 2);
    CHECK(moyenne({1}) == 1);
    CHECK(moyenne({2,2,4,8}) == 4);
}


/** Renvoie l'indice de la valeur maximale du tableau
 * @param t, un tableau d'entier
 * @return l'indice de la valeur maximale ou -1 si le tableau est vide
 **/
int indiceMax(vector<int> t) { //fait ensemble et fiable a 100%
    // Remplacer cette ligne et la suivante par le code adéquat
   if (t.size()==0){ // si le tableau est vide
       return -1;
   }else{
       int k = t[0]; //on donne la valeur du premiere element du tableau a une variable k
       int indice = 0;
       for ( int i = 1; i < t.size(); i++){// on commence a 1 car on ne veut pas recomparer t[0] et k qui sont equivalentes avant de rentrer dans la boucle
           if ( k < t[i] ){ // si on trouve dans une case du tableau un element plus grand que k, on donne a k sa valeur et on stocke dans la variable indice son indice
               k = t[i];
               indice = i;
           }
       }
return indice;
   }
}
    

/** Test de la fonction IndiceMax **/
void testIndiceMax() {
    CHECK(indiceMax({}) == -1);
    CHECK(indiceMax({1,2,3}) == 2);
    CHECK(indiceMax({1,3,2}) == 1);
    CHECK(indiceMax({1}) == 0);
    CHECK(indiceMax({2,8,4,4}) == 1);
}

/** Lance les fonctions de test puis affiche :
 * - le nombre total de mariages
 * - le nombre moyen de mariages célébrés par an
 * - l'année où l'on a célébré le plus de mariages (et leur nombre)
 * - le jour de la semaine où l'on célèbre le plus de mariages (et leur nombre)
 * - le pourcentage de mariages célébrés un samedi
 **/ //fait ensemble et fiable a 100%
int main() {
    //Test
    testLitTableauAnnee();
    testLitTableauJours();
    testSomme();
    testMoyenne();
    testIndiceMax();
    //test
    int stock = 0;
    vector<int>z = litTableauAnnee("statistiques-des-jours-des-mariages.txt"); //tableau  avec le nbre de mariages par an
    for ( int i = 0; i < z.size(); i++ ){
    stock += z[i];//hors(a la fin) de la boucle, stock est le nombre de mariages totales( on aurait pu faire un appel de la fonction somme avec z en argument)
}
    int MoyenneMariageAn = stock / z.size(); // on aurait ici aussi pu faire appel a la fonction moyenne
    int q = indiceMax(z);//l'indice de la case la ou il y a eu le plus de mariages (annees)
    int MaxMariage = z[q]; // on stocke dans cette variable le nombre maximum de mariages
    vector<int>y = litTableauJours("statistiques-des-jours-des-mariages.txt"); //tableau avec le nombre de mariages chaque jour
    int u = indiceMax(y); //l'indice de la case la ou il y a eu le plus de mariages (jours)
    int MaxAnnee = 2010 + q; // chaque colonne du tableau z a un indice, pour savoir quel case du tableau correspond a quel annee, on utilise la formule : 2010+i, avec i l'indice de la case que l'on cherche a faire correspondre, donc q qui correspond a l'indice où la valeur d'une case est la plus grande, est ajouté a 2010 on obtient l'année ou le nombre de mariages est le plus elevé
    int MaxMariageJour = y[u]; //u est l'indice de la case ou se trouve le plus grand nombre mariages du tableau et on stocke dans cette variable le plus grand nombre de mariages
    string JourMaxMariage = jours[u]; //on lit dans le tableau jours, la case d'indice u qui correspond au jour où il y a eu le plus grand nombre de mariages
    double PourcentSamedi = y[5]*100.00/stock; // on multiple par 100.00 pour avoir notre pourcentage sous la forme d'un nombre decimal
    cout<<"Le nombre de total de mariages célébrés entre 2010 et 2015 est de "<<stock<<endl;
    cout<<"Le nombre de mariages célébrés en moyenne par an est de "<<MoyenneMariageAn<<endl;
    cout<<"L’année où l’on a célébré le plus de mariages est "<<MaxAnnee<<" avec "<<MaxMariage<<" mariages "<<endl;
    cout<<"Le jour de la semaine où l’on a célébré le plus de mariages est le "<<JourMaxMariage<<" avec "<<MaxMariageJour<<" mariages "<<endl; 
    cout<<"Le pourcentage de mariages célébrés le samedi est de "<<PourcentSamedi<<"%"<<endl;
    

}

    


