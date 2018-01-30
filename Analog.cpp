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
		getTop10();
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
	bool ok = true;
	if(exceptFile)
	{
		ok = log.isWebContent();

	}
	if(heure != -1)
	{
		ok = ok && (heure == log.getDate().getHeure());  
	}
	return ok;
}

void Analog::getTop10()
{
	pair<string, int> top10[10];
	//TODO : lire et ajouter, ne pas oubier de filtrer
	
	
	afficherTop10(top10);
}

void Analog::getGraphAndTop10( )
{
	string line;
	ifstream in(fileName, ifstream::in);
	
	pair<string, int> top10[10];
	
	while(getline(in,line))
	{
		LogLine log(line);

		if(!filter(log))
		{
			cout << log.getRequestURL() << endl;
			continue;
		}

		 
		bool destFound = (nodes.find(log.getRequestURL()) != nodes.end());
		bool srcFound = (nodes.find(log.getSource()) != nodes.end());
		
		// Destination existe deja dans la map des noeuds
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
		ajoutTop10 ( log.getRequestURL(), nodes[log.getRequestURL()].hit, top10);
		
		// Source n'existe pas dans la map des noeuds
		if(!srcFound)
		{
			Element elem;
			elem.hit = 0;
			nodes[log.getSource()] = elem;
		}

	}
	
	// Affichage de test
	/*for(const auto & sm_pair : nodes)
	{
		cout << sm_pair.first << " : " << sm_pair.second.hit << endl;
		for(const auto & sc_pair : sm_pair.second.sources)
		{
			cout << "\t" << sc_pair.first << " : " << sc_pair.second << endl;
		}
	}*/
	
	// Affichage top10
	afficherTop10(top10);
}

void Analog::afficherTop10 ( pair<string,int>* top10 )
{
	for (unsigned int i = 0; i < 10; i++)
	{
		cout << (i+1) << " : " << top10[i].first << " " << top10[i].second << endl;
	}
}

void Analog::ajoutTop10 ( string url, int hits, pair<string,int>* top10)
{
	unsigned int i = 0;
	
	// On ne parcourt pas le tableau si le tuple n'est meme pas superieur au dernier (cas le plus fréquent)
	if(hits < top10[9].second)
		return;
	
	//On cherche si on peut placer le tuple dans le tableau
	while(i < 10)
	{
		
		//Si on est passé devant un tuple
		if(hits > top10[i].second)
		{
			// si on est sur une case vide ou le meme tuple
			if(top10[i].second == 0 || top10[i].first == url)
			{
				top10[i] = pair<string,int>(url,hits);
				return;
			}
			
			// sinon on décale les autres
			pair<string, int> save (url,hits);
			for(unsigned int j = i; j<10; j++)
			{
				auto tmp = top10[j];
				
				top10[j] = save;
				
				save = tmp;
			}
			return;
		}
		i++;
	}
}
