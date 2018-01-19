#include <iostream>
using namespace std;

#include "Date.h"

int main(int size, char** args)
{
		cout << "Working in progress..." << endl;
		Date d ("01/Oct/2012:13:30:46 +0200");
		cout << d.getJour() << endl;
		cout << d.getMois() << endl;
		cout << d.getAnnee() << endl;
		cout << d.getHeure() << endl;
		cout << d.getMinute() << endl;
		cout << d.getSeconde() << endl;
		return 0;
}
