/*************************************************************************
                           Analog  -  description
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
//
//
//------------------------------------------------------------------------

class Analog
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //

	
	

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
    Analog ( string pFileName, bool pExceptFile, string pOutputFile, int pHeure);
    // Mode d'emploi :
    //
    // Contrat :
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
	
	void getTop10();
	
	void getGraphAndTop10();
	
	void ajoutTop10 ( string url, int hits, pair<string,int>* top10);
	
	void makeGraph();
	
	void afficherTop10 ( pair<string,int>* top10 );
	
//----------------------------------------------------- Attributs protégés
	unordered_map<string, Element> nodes;
	string fileName;
	bool exceptFile;
	string outputFile;
	int heure;

};

//-------------------------------- Autres définitions dépendantes de <Analog>

#endif // ANALOG_H

