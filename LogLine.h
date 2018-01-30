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
    
    string getIpSource() { return ipSource; }
	Date getDate() { return date; }
	string getRequestType() { return requestType; }
	string getRequestURL() { return requestURL; }
	string getRequestFile() { return requestFile; }
	string getResponseCode() { return responseCode; }
	int getSize() { return size; }
	string getSource() { return source; }
	string getUserAgent() { return userAgent; }

	bool isFile()
	{
		 return !(fileExtension=="");
	}
	bool isWebContent()
	{
		if(fileExtension != "jpg" || "gif" || "ico" ||"css"||"js"){
			return true;
		}
	}

//------------------------------------------------- Surcharge d'opérateurs



//-------------------------------------------- Constructeurs - destructeur
    LogLine ( string log)
    {
		#ifdef MAP
			cout << "Appel au constructeur de <LogLine>" << endl;
		#endif	
		
		//on admet que le fichier est tout beau et pas d'exceptions
		ipSource = log.substr(0,log.find_first_of(" "));
	
		log.erase(0,log.find_first_of("[")+1);
		date = Date(log.substr(0,log.find_first_of("]")));
		
		log.erase(0,log.find_first_of("\"")+1);
		requestType = log.substr(0,log.find_first_of(" "));
		
		
		log.erase(0,log.find_first_of(" ")+1);	
		requestURL = log.substr(0,log.find_first_of(" "));
		
		//on enleve les trucs apres les ? pour php et ; pour iee
		if(requestURL.find_first_of("?") != string::npos)
		{
			requestURL.erase(requestURL.find_first_of("?"));
		}else if(requestURL.find_first_of(";") != string::npos)
		{
			requestURL.erase(requestURL.find_first_of("?"));
		}
		
		if(requestURL.find_last_of(".")!=string::npos)
		{
			fileExtension = requestURL.substr(requestURL.find_last_of(".")+1);
			//on admet que le point n'est jamais le dernier caractere
		}
		
		log.erase(0,log.find_first_of("\"")+2);
		responseCode = log.substr(0,log.find_first_of(" "));

		log.erase(0,log.find_first_of(" ")+1);
		string sizeString = log.substr(0,log.find_first_of(" "));
		if(sizeString == "-"){
			size = 0;
		}else{
			size = stoi(sizeString);
		}
		
		log.erase(0,log.find_first_of("\"")+1);
		source = log.substr(0,log.find_first_of("\""));
		
				
		if(source.find(localhost) != string::npos)
		{
			cout << source << endl;
			source.erase(0,localhost.size());
			cout << source << endl;
		}
		
		log.erase(0,log.find_first_of(" ")+2);
		userAgent = log.substr(0,log.find_first_of("\""));
	}
    

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
	string requestURL;
	string requestFile;
	string fileExtension; //is empty ("") when requestURL doesn't have an extension
	string responseCode;
	int size;
	string source;
	string userAgent;
};

//-------------------------------- Autres définitions dépendantes de <LogLine>

#endif // LOGLINE_H

