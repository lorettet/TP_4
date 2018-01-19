#include <iostream>
using namespace std;

void usage()
{
	cout << "Usage : analog [-e [-g outputFile [-t heure]]] file" << endl;
	return 1;
}

int main(int size, char** args)
{
		cout << "Work in progress..." << endl;
		
		bool excepteFile = false;
		string fileName = "";
		int heure = -1;
		string outputFile = "";
		
		
		if (size>8) usage();
			
		for (int i = 0; i < size; i++)
		{
			switch (args[i])
			{
				case "-e":
					excepteFile = true;
					break;
				case ""
			}
		}

		
		return 0;
}


