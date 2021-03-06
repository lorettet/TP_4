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
Date LogLine::getDate() { return date; }
string LogLine::getRequestType() { return requestType; }
string LogLine::getRequestURL() { return requestURL; }
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
	return (fileExtension != "jpg" && fileExtension != "gif" && fileExtension != "ico" && fileExtension != "css" && fileExtension != "js" && fileExtension != "png");
}
//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur

LogLine::LogLine ( string log)
{
	#ifdef MAP
		cout << "Appel au constructeur de <LogLine>" << endl;
	#endif	

	ipSource = log.substr(0,log.find_first_of(" "));
	log.erase(0,log.find_first_of("[")+1);
	
	date = Date(log.substr(0,log.find_first_of("]")));
	log.erase(0,log.find_first_of("\"")+1);
	
	requestType = log.substr(0,log.find_first_of(" "));
	log.erase(0,log.find_first_of(" ")+1);	
	
	requestURL = log.substr(0,log.find_first_of(" "));
	log.erase(0,log.find_first_of("\"")+2);
	//on enleve les parametres apres "?" pour php et ";" pour iee
	if(requestURL.find_first_of("?") != string::npos)
	{
		requestURL.erase(requestURL.find_first_of("?"));
	}
	if(requestURL.find_first_of(";") != string::npos)
	{
		requestURL.erase(requestURL.find_first_of(";"));
	}

	
	if(requestURL.find_last_of(".")!=string::npos)
	{
		fileExtension = requestURL.substr(requestURL.find_last_of(".")+1);
		//on admet que le point n'est jamais le dernier caractere
	}
	
	//On ajoute un "/" au fichier sans extension
	if(fileExtension == "" && requestURL[requestURL.size()-1] != '/')
	{
		requestURL += "/";
	}
	

	responseCode = log.substr(0,log.find_first_of(" "));
	log.erase(0,log.find_first_of(" ")+1);
	
	string sizeString = log.substr(0,log.find_first_of(" "));
	log.erase(0,log.find_first_of("\"")+1);
	if(sizeString == "-"){
		size = 0;
	}else{
		size = stoi(sizeString);
	}
	
	source = log.substr(0,log.find_first_of("\""));
	log.erase(0,log.find_first_of(" ")+2);
	//on enleve les argements apres "?" ou ";"
	if(source.find_first_of("?") != string::npos)
	{
		source.erase(source.find_first_of("?"));

	}
	if(source.find_first_of(";") != string::npos)
	{
		source.erase(source.find_first_of(";"));
	}
	
	if(source.find(localhost) != string::npos)
	{
		source.erase(0,localhost.size());
	}
	
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

