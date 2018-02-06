/*************************************************************************
                           Date  -  Représente une date
                             -------------------
    début                : 19/01/2018
    copyright            : (C) 2018 par Théo LORETTE-FROIDEVAUX 
    * 						Marie-France GONZALEZ
    e-mail               : theo.lorette-froidevaux@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Date> (fichier Date.h) ----------------
#if ! defined ( DATE_H )
#define DATE_H

//--------------------------------------------------- Interfaces utilisées
#include <iostream>
using namespace std;
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Date>
// Permet d'extraire la date d'un fichier de log Apache.
//
//------------------------------------------------------------------------

class Date
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

	int getJour() { return jour; }
	string getMois() { return mois; }
	int getAnnee() { return annee; }
	int getHeure() { return heure; }
	int getMinute() { return minute; }
	int getSeconde() { return seconde; }

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
	Date () {}

    Date ( string apacheDate )
    {
		#ifdef  MAP
		cout << "Appel au constructeur de <Date>" << endl;
		#endif
			jour = stoi(apacheDate.substr(0,2));
			mois = apacheDate.substr(3,3);
			annee = stoi(apacheDate.substr(7,4));
			heure = stoi(apacheDate.substr(12,2));
			minute = stoi(apacheDate.substr(15,2));
			seconde = stoi(apacheDate.substr(18,2));
	}
    // Mode d'emploi : Prend en paramêtre une date au format trouvé dans
    // les logs Apache et créer un objet Date.
    //
    // Contrat :
    //

    virtual ~Date ( ) 
    {
		#ifdef  MAP
		cout << "Appel au destructeur de <Date>" << endl;
		#endif	
	}

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées
	int jour;
	string mois;
	int annee;
	int heure;
	int minute;
	int seconde;
//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <Date>

#endif // DATE_H

