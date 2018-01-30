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
    Analog ( string fileName, bool exceptFile, string outputFile, int heure);
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

//----------------------------------------------------- Attributs protégés
	unordered_map<string, Element> nodes;

};

//-------------------------------- Autres définitions dépendantes de <Analog>

#endif // ANALOG_H

