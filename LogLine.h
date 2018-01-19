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

//------------------------------------------------------------- Constantes

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
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //
    
    string getIpSource() { return ipSource; }
	Date getDate() { return date; }
	string getRequestType() { return requestType; }
	string getRequestFile() { return requestFile; }
	string getResponseCode() { return responseCode; }
	int getSize() { return size; }
	string getSource() { return source; }
	string getUserAgent() { return userAgent; }


//------------------------------------------------- Surcharge d'opérateurs



//-------------------------------------------- Constructeurs - destructeur
    LogLine ( string log);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~LogLine ( ) { }
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
	string requestFile;
	string responseCode;
	int size;
	string source;
	string userAgent;
};

//-------------------------------- Autres définitions dépendantes de <LogLine>

#endif // LOGLINE_H

