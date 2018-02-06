/*************************************************************************
                           LogLine  -  description
                             -------------------
    début                : 19/01/2018
    copyright            : (C) 2018 par Théo LORETTE-FROIDEVAUX 
    * 						Marie-France GONZALEZ
    e-mail               : theo.lorette-froidevaux@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <LogLine> (fichier LogLine.h) ----------------
#if ! defined ( LOGLINE_H )
#define LOGLINE_H

//--------------------------------------------------- Interfaces utilisées
#include <string>
#include "Date.h"

//------------------------------------------------------------- Constantes
static const string localhost = "http://intranet-if.insa-lyon.fr";
//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <LogLine>
//
//
//------------------------------------------------------------------------

class LogLine
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    
    string getIpSource();
	Date getDate();
	string getRequestType();
	string getRequestURL();
	string getResponseCode();
	int getSize();
	string getSource();
	string getUserAgent();

	bool isFile();
	// Mode d'emploi : Vérifie si l'objet de la requete contient une 
	// extension.
    //
    // Contrat :
    //
    
	bool isWebContent();
	// Mode d'emploi : Vérifie si l'objet de la requête n'est pas de 
	// type image/css/js
    //
    // Contrat :
    //

//------------------------------------------------- Surcharge d'opérateurs



//-------------------------------------------- Constructeurs - destructeur

    LogLine (string log);
	// Mode d'emploi : Extrait toutes les données d'une ligne de log
	// Apache
    //
    // Contrat : La ligne doit respecter la structure standard 
    // d'un fichier de log Apache
    //


    virtual ~LogLine ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées
//----------------------------------------------------- Attributs protégés
	string ipSource;
	// L'adresse ip de la source
	
	Date date;
	// Date à laquel la requête a été effectuée
	
	string requestType;
	// Type de la requête
	
	string requestURL;
	// Fichier objet de la requête
	
	string fileExtension;
	// Extension du fichier demandé
	
	string responseCode;
	// Code HTTP de la réponse
	
	int size;
	// Taille de la réponse
	
	string source;
	// url de la source
	
	string userAgent;
	// User agent de la source
};

//-------------------------------- Autres définitions dépendantes de <LogLine>

#endif // LOGLINE_H

