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
	
	cout << "Work in progress..." << endl;
	
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
	string line;
	ifstream in(fileName, ifstream::in);
	
	pair<string, int> top10[10];
	while(getline(in,line))
	{
		LogLine log(line);
		
		if(!filter(log))
		{
			continue;
		}
		
		// Destination existe deja dans la map des noeuds

		nodes[log.getRequestURL()].hit++;

		ajoutTop10 ( log.getRequestURL(), nodes[log.getRequestURL()].hit, top10);
	}
	
	in.close();
	
	// Affichage top10
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
			continue;
		}
		
		bool destFound = (nodes.find(log.getRequestURL()) != nodes.end());
		
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
	}
	
	in.close();
	
	makeGraph();
	
	// Affichage top10
	afficherTop10(top10);
}

void Analog::afficherTop10 ( pair<string,int>* top10 )
{
	for (unsigned int i = 0; i < 10; i++)
	{
		if(top10[i].second == 0)
			return;
		cout << (i+1) << " : " << top10[i].first << " " << top10[i].second << endl;
	}
}

void Analog::makeGraph()
{
	ofstream out(outputFile);
	
	out << "digraph{" << endl;
	for (const auto & i : nodes)
	{
		string url = i.first;
		for(const auto & j : i.second.sources)
		{		
				out << "\"" << j.first << "\" -> \"" << url << "\" [label=" << j.second << "];" << endl;
		}
	}
	
	out << "}" << endl;
	
	out.close();
}

void Analog::ajoutTop10 ( string url, int hits, pair<string,int>* top10)
{
	// On ne parcourt pas le tableau si le tuple n'est meme pas superieur au dernier (cas le plus fréquent)
	if(hits < top10[9].second)
		return;
		
	for(unsigned int i = 0; i<10 ; i++)
	{
		//si case vide, on insere
		if(top10[i].second == 0)
		{
			top10[i] = pair<string,int> (url, hits);
			return;
		}
		
		// si la valeur est supérieur
		if(hits > top10[i].second)
		{
			
			// on regarde si l'url est dans la suite du tableau
			for(unsigned int j = i; j<10;j++)
			{
				// si c'est le cas, on l insere
				if(top10[j].first == url)
				{
					top10[j] = pair<string,int>(url,hits);
					
					//  et eventuellement on le remonte
					while(j!=0)
					{
						if(top10[j-1].second < top10[j].second)
						{
							auto tmp = top10[j-1];
							top10[j-1] = top10[j];
							top10[j] = tmp;
							j--;
						}
						else
						{
								return;
						}
					}
					return;
				}
			}
			
			// si on ne l'a pas trouvé, on l'insere et on decale les autres
			auto save = pair<string, int> (url, hits);
			for(unsigned int j = i; j < 10; j++)
			{
				auto tmp = top10[j];
				top10[j] = save;
				save = tmp;
			}
			return;
		}
		
		
	}
}
