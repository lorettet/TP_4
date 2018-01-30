#include <iostream>
#include <cstring>
#include <unistd.h>
#include <fstream>
#include "Analog.h"
using namespace std;

void usage(int test)
{
	cerr << "Usage : analog [-e [-g outputFile.dot [-t heure]]] file" << test << endl;
}

bool file_exist(const string & fileName)
{
    ifstream infile(fileName.c_str());
    return infile.good();
}

int main(int size, char** args)
{
		cout << "Work in progress..." << endl;
		bool excepteFile = false;
		string fileName = "";
		int heure = -1;
		string outputFile = "";

		if (size == 1) 
		{
			usage(0);
			return 1;
		}
			
		char c;
		while((c = getopt(size,args,"eg:t:")) != -1)
		{
			switch(c)
			{
				cout << c << endl;
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
							usage(3);
							return 1;
						}
					}
					catch (const invalid_argument & ia)
					{
						usage(2);
						return 1;
					}
					break;
			}
			
		}
		fileName = string(args[size-1]);
		if(!file_exist(fileName))
		{
			usage(7);
			return 1;
		}
		Analog a (fileName, excepteFile, outputFile, heure);

		return 0;
}


