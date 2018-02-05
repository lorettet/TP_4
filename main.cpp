#include <iostream>
#include <cstring>
#include <unistd.h>
#include <fstream>
#include "Analog.h"
using namespace std;

void usage()
{
	cerr << "Usage : analog [-e [-g outputFile.dot [-t heure]]] file" << endl;
}

bool file_exist(const string & fileName)
{
    ifstream infile(fileName.c_str());
    return infile.good();
}

int main(int size, char** args)
{
		bool excepteFile = false;
		string fileName = "";
		int heure = -1;
		string outputFile = "";

		if (size == 1) 
		{
			usage();
			return 1;
		}
			
		char c;
		while((c = getopt(size,args,"eg:t:")) != -1)
		{
			switch(c)
			{
				case 'e':
					excepteFile = true;
					break;
				case 'g':
					outputFile = optarg;
					break;
				case 't':
					try
					{
						heure = stoi(optarg);
						if(heure > 23 || heure < 0)
						{
							usage();
							return 1;
						}
					}
					catch (const invalid_argument & ia)
					{
						usage();
						return 1;
					}
					break;
			}
			
		}

		// Vérification du fichier de entré
		fileName = string(args[size-1]);
		if(fileName.find(".log") == string::npos)
		{
			cerr << "Le fichier n'est pas un fichier de log" << endl;
			usage();
			return 1;
		}
		if(!file_exist(fileName))
		{
			cerr << "Le fichier " << fileName << " n'existe pas" << endl;
			return 1;
		}
		
		// Vérification de l'extension .dot
		if(outputFile!="" && outputFile.find(".dot") == string::npos)
		{
			cerr << "Le fichier de sorti n'est pas un .dot" << endl;
			usage();
			return 1;
		}
		
		// Vérification de l'existence du fichier de sorti
		if(outputFile != "")
		{
			if(file_exist(outputFile))
			{
				
				while(true)
				{
					cout << "Le fichier " << outputFile << " existe déjà, voulez vous l'écraser? (y/n)" << endl;
					string rep;
					cin >> rep;
					if(rep == "y")
						break;
					else if (rep == "n")
						return 0;
					else
						cerr << "Réponse incorrecte" << endl;
				}
			}
		}
		
		// Vérification du temps
		{
			if(heure > 23 || heure < -2)
			{
				cerr << "Heure invalide"<< endl;
				usage();
				return 1;
			}
		}
		
		
		Analog a (fileName, excepteFile, outputFile, heure);

		return 0;
}


