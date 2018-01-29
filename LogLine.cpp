/*************************************************************************
                           LogLine  -  description
                             -------------------
    début                : 19/01/2018
    copyright            : (C) 2018 par Théo LORETTE-FROIDEVAUX 
    * 						Marie-France GONZALEZ
    e-mail               : theo.lorette-froidevaux@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <LogLine> (fichier LogLine.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "LogLine.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

string LogLine::getIpSource() { return ipSource; }
//Date LogLine::getDate() { return date; }
string LogLine::getRequestType() { return requestType; }
string LogLine::getRequestFile() { return requestFile; }
string LogLine::getResponseCode() { return responseCode; }
int LogLine::getSize() { return size; }
string LogLine::getSource() { return source; }
string LogLine::getUserAgent() { return userAgent; }


bool LogLine::isFile()
{
	 return !(fileExtension == "");
}

bool LogLine::isWebContent()
{
	if(fileExtension != "jpg" || "gif" || "ico" ||"css"||"js")
	{
		return true;
	}
}
//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur

//prerequis: on admet que la ligne du fichier est toute belle et pas d'exceptions
LogLine::LogLine (string log)
{
	#ifdef MAP
		cout << "Appel au constructeur de <LogLine>" << endl;
	#endif	
	
	ipSource = log.substr(0,log.find_first_of(" "));

	log.erase(0,log.find_first_of("[")+1);
	string tmp = log.substr(0,log.find_first_of("]"));
	//date = new Date(tmp);
	
	log.erase(0,log.find_first_of("\"")+1);
	requestType = log.substr(0,log.find_first_of(" "));
	
	
	log.erase(0,log.find_first_of(" ")+1);	
	requestFile = log.substr(0,log.find_first_of(" "));
	
	//on enleve les trucs apres les ? pour php et ; pour iee
	if(requestFile.find_first_of("?") != -1)
	{
		requestFile.erase(requestFile.find_first_of("?"));
	}else if(requestFile.find_first_of(";") != -1)
	{
		requestFile.erase(requestFile.find_first_of(";"));
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



LogLine::~LogLine ( )
{
	#ifdef MAP
		cout << "Appel au destructeur de <LogLine>" << endl;
	#endif
} //----- Fin de ~LogLine


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

