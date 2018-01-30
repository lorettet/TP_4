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
Analog::Analog (string pFileName, bool pExceptFile, string pOutputFile, int pHeure) : fileName(pFileName), exceptFile(pExceptFile), outputFile(pOutputFile), heure(pHeure)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Analog>" << endl;
#endif
	
	// Pas de graph a générer
	if(outputFile == "")
	{
		pair<string,int>* top10 = getTop10();
		for(unsigned int i = 0; i<10; i++)
		{
			cout << i << " : " << top10[i].first << " -> " << top10[i].second << " hits";
		}
		delete top10;
		return;
	}
	
	// Génération graph et top10
	getGraphAndTop10();

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

bool Analog::filter( LogLine log)
{
	bool ok = false;
	if(exceptFile)
	{
		ok = log.isWebContent();
		if(heure != -1)
		{
			ok = ok && (heure == log.getDate().getHeure());  
		}
	}
	return ok;
}

pair<string, int>* Analog::getTop10()
{
	// a faire en dynamique!!!!!! sinon le return il retournera pas le tableau mdr
	// on utilisera la fonction filtre sur les log pour 
}

void Analog::getGraphAndTop10( )
{
	string line;
	ifstream in(fileName, ifstream::in);
	
	while(getline(in,line))
	{
		LogLine log(line);
		 
		bool destFound = (nodes.find(log.getRequestURL()) != nodes.end());
		bool srcFound = (nodes.find(log.getSource()) != nodes.end());
		
		// Desination existe deja dans la map des noeuds
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
		
		// Source n'existe pas dans la map des noeuds
		if(!srcFound)
		{
			Element elem;
			elem.hit = 0;
			nodes[log.getSource()] = elem;
		}

	}
	
	// Affichage de test
	for(const auto & sm_pair : nodes)
	{
		cout << sm_pair.first << " : " << sm_pair.second.hit << endl;
		for(const auto & sc_pair : sm_pair.second.sources)
		{
			cout << "\t" << sc_pair.first << " : " << sc_pair.second << endl;
		}
	}
}
