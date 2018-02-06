/*************************************************************************
                           Analog  -  Classe principale
                             -------------------
    début                : 19/01/2018
    copyright            : (C) 2018 par Théo LORETTE-FROIDEVAUX 
    * 						Marie-France GONZALEZ
    e-mail               : theo.lorette-froidevaux@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Analog> (fichier Analog.h) ----------------
#if ! defined ( ANALOG_H )
#define ANALOG_H

//--------------------------------------------------- Interfaces utilisées
#include <iostream>
#include <unordered_map>
#include "LogLine.h"
using namespace std;
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types
typedef struct
{
	int hit;
	unordered_map<string, int> sources;
} Element;
//------------------------------------------------------------------------
// Rôle de la classe <Analog>
// Permet de lire et d'extraire des statistiques d'un fichier de logs 
// d'un serveur Apache. Permet aussi de construire un graph de navigation
//
//------------------------------------------------------------------------

class Analog
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
	void Analyse();
	// Mode d'emploi : Lance l'analyse du fichier
    //
    // Contrat :
    //

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
    Analog ( string pFileName, bool pExceptFile, string pOutputFile, int pHeure);
    // Mode d'emploi : Prépare l'analyse d'un fichier de log Apache.
    //
    // Contrat : Aucune vrification n'est effectué sur les fichiers.
    //

    virtual ~Analog ( );
    // Mode d'emploi : 
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

	bool filter( LogLine log );
    // Mode d'emploi : Vérifie si la ligne de log correspond aux attentes
    //
    // log : la ligne de log à filtrer
    //
    // Contrat :
    //
    
	void getTop10();
    // Mode d'emploi : Affiche uniquement le top 10 des fichiers les
    // plus demandés.
    //
    // Contrat :
    //
    
	void getGraphAndTop10();
    // Mode d'emploi : Affiche le top 10 des fichiers les plus demandés
    // et créé le fichier .dot correpondant au graphe
    //
    // Contrat :
    //
	
	void ajoutTop10 ( string url, int hits, pair<string,int>* top10);
    // Mode d'emploi : Ajoute dans le tableau passé en paramètre le 
    // tuple <url,nb de hit>. 
    //
    // url : l'url du site cible
    // hits : le nombre de hit
    // top10 : le tableau donnée/résultat représentant le top 10
    //
    // Contrat : Le tableau doit être de taille 10. Le tableau est trié
    // à la fin de la méthode.
    //
	
	void makeGraph();
    // Mode d'emploi : Construit le tableau à partir des informations
    // récupérés dans le fichier de log.
    //
    // Contrat : les maps doivent être remplies.
    //
	
	void afficherTop10 ( pair<string,int>* top10 );
    // Mode d'emploi : Affiche le top 10
    //
    // top10 : le tableau représentant le top 10 à afficher
    //
    // Contrat :
    //
	
//----------------------------------------------------- Attributs protégés
	unordered_map<string, Element> nodes;
	// map contenant pour chaque page, le nombre de fois qu'elle a été
	// visitée, ainsi que tous les sites qui l'ont visitée
	
	string fileName;
	// le nom du fichier de log
	
	bool exceptFile;
	// vrai si on doit exclure les fichiers image/css/js
	
	string outputFile;
	// le nom du fichier .dot de sortie. est vide si aucun fichier .dot
	// n'est demandé
	
	int heure;
	// Représente l'heure sur laquel on filtre les logs. Vaut -1 si on
	// veut prendre tous les logs.

};

//-------------------------------- Autres définitions dépendantes de <Analog>

#endif // ANALOG_H

