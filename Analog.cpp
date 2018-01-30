/*************************************************************************
                           Analog  -  description
                             -------------------
    début                : 19/01/2018
    copyright            : (C) 2018 par Théo LORETTE-FROIDEVAUX 
    * 						Marie-France GONZALEZ
    e-mail               : theo.lorette-froidevaux@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <Analog> (fichier Analog.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <fstream>
//------------------------------------------------------ Include personnel
#include "Analog.h"
#include "LogLine.h"
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Analog::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
Analog::Analog (string fileName, bool exceptFile, string outputFile, int heure)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Analog>" << endl;
#endif
	string line;
	ifstream in(fileName, ifstream::in);
	
	while(getline(in,line))
	{
		LogLine log(line);
		 
		bool destFound = (nodes.find(log.getRequestURL()) != nodes.end());
		bool srcFound = (nodes.find(log.getSource()) != nodes.end());
		
		if(destFound)
		{
			nodes[log.getRequestURL()].hit++;
			nodes[log.getRequestURL()].sources[log.getSource()]++;
			
		}
		else
		{
			Element elem;
			elem.hit = 1;
			elem.sources[log.getSource()] = 1;
			nodes[log.getRequestURL()] = elem;
		}
		
		if(!srcFound)
		{
			Element elem;
			elem.hit = 0;
			nodes[log.getSource()] = elem;
		}

	}
	
	for(const auto & sm_pair : nodes)
	{
		cout << sm_pair.first << " : " << sm_pair.second.hit << endl;
		for(const auto & sc_pair : sm_pair.second.sources)
		{
			cout << "\t" << sc_pair.first << " : " << sc_pair.second << endl;
		}
	}

} //----- Fin de Analog


Analog::~Analog ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Analog>" << endl;
#endif
} //----- Fin de ~Analog


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

