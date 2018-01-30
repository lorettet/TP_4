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
	string getRequestFile();
	string getResponseCode();
	int getSize();
	string getSource();
	string getUserAgent();

	bool isFile();
	bool isWebContent();

//------------------------------------------------- Surcharge d'opérateurs



//-------------------------------------------- Constructeurs - destructeur

    LogLine (string log); //utile?

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
	Date date;
	string requestType;
	string requestURL;
	string fileExtension; //is empty ("") when requestURL doesn't have an extension
	string responseCode;
	int size;
	string source;
	string userAgent;
};

//-------------------------------- Autres définitions dépendantes de <LogLine>

#endif // LOGLINE_H

