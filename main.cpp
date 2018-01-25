#include <iostream>
#include <cstring>
using namespace std;

void usage(int test)
{
	cout << "Usage : analog [-e [-g outputFile.dot [-t heure]]] file" << test << endl;
}

int main(int size, char** args)
{
		cout << "Work in progress..." << endl;
		bool excepteFile = false;
		string fileName = "";
		int heure = -1;
		string outputFile = "";

		if (size>9 || size == 1) 
		{
			usage(0);
			return 1;
		}
			
		for (int i = 1; i < size; i++)
		{
			if(strcmp(args[i], "-e") == 0)
			{
				cout << "-e ok" << endl;
				excepteFile = true;
			}
			else if(strcmp(args[i], "-g") == 0)
			{
				cout << "-g ok" << endl;
				++i;
				if(i == size)
				{
					usage(1);
					return 1;
				}
				string nextString = args[i];
				cout << nextString << endl;
				if(nextString.size()>3)
				{
					cout << nextString.substr(nextString.size()-4,4) << endl;
					if(nextString.substr(nextString.size()-4,4) == ".dot")
					{
						outputFile = nextString;
					}
					else 
					{
						usage(2);
						return 1;
					}
				}
				else
				{
					usage(3);
					return 1;
				}
			}
			else if(strcmp(args[i], "-t")==0)
			{
				cout << "-t ok" << endl;
				++i;
				if (i == size)
				{
					usage(4);
					return 1;
				}
				try 
				{
					heure = stoi(args[i]);
				}
				catch(exception e)
				{
					usage(5);
					return 1;
				}
				if(heure<0)
				{
					usage(6);
					return 1;
				}
			}
			else
			{
				cout << "filename ok" << endl;
				fileName = args[i];
			}
		}
		if(fileName == "")
		{
			usage(7);
			return 1;
		}
		cout << "OK : " << fileName << " " << excepteFile << " " << outputFile << " " << heure << endl;

		return 0;
}


