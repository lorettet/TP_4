/*************************************************************************
                           Date  -  description
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

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types
Mois enum { "Janvier", "Fevrier", "Mars", "Avril", "Mai", 
	"Juin", "Juillet", "Aout", "Septembre", "Octobre", "Novembre", 
	"Decembre"  }
//------------------------------------------------------------------------
// Rôle de la classe <Date>
//
//
//------------------------------------------------------------------------

class Date
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //
	int getJour() { return jour; }
	Mois getMois { return mois; }
	int getAnnee { return annee };
	int getHeure;
	int getMinute;
	int getSeconde;

//------------------------------------------------- Surcharge d'opérateurs
    Date & operator = ( const Date & unDate );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    Date ( const Date & unDate );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Date ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Date ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées
	int jour;
	Mois mois;
	int annee;
	int heure;
	int minute;
	int seconde;
//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <Date>

#endif // DATE_H

