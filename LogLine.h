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
    
    string getIpSource() { return ipSource; }
	Date getDate() { return date; }
	string getRequestType() { return requestType; }
	string getRequestFile() { return requestFile; }
	string getResponseCode() { return responseCode; }
	int getSize() { return size; }
	string getSource() { return source; }
	string getUserAgent() { return userAgent; }

	public bool isFile()
	{
		 return !(fileExtension=="");
	}
	public bool isWebContent()
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
		date = log.substr(0,log.find_first_of("]"));
		
		log.erase(0,log.find_first_of("\"")+1);
		requestType = log.substr(0,log.find_first_of(" "));
		
		
		log.erase(0,log.find_first_of(" ")+1);	
		requestFile = log.substr(0,log.find_first_of(" "));
		
		//on enleve les trucs apres les ? pour php et ; pour iee
		if(requestFile.find_first_of("?") =! -1)
		{
			requestFile.erase(requestFile.find_first_of("?"));
		}else if(requestFile.find_first_of(";") =! -1)
		{
			requestFile.erase(requestFile.find_first_of("?"));
		}
		
		if(requestFile.find_last_of(".")!=-1)
		{
			fileExtension = requestFile.substr(requestFile.find_last_of(".")+1);
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
	string requestFile;
	string fileExtension; //is empty ("") when requestFile doesn't have an extension
	string responseCode;
	int size;
	string source;
	string userAgent;
};

//-------------------------------- Autres définitions dépendantes de <LogLine>

#endif // LOGLINE_H

