#include "Date.h"
#include <iostream>
#include "Livre.h"
#include <string>
#include <vector>
using namespace std;
int main() {
	Date anniv(05, 10, 2002);
	cout << "mon anniversaire est le  " << anniv.month() << " " << anniv.day() << " " << anniv.year()<<endl;
	Livre miserable("miserable","Kaisoun","arabe","realité",anniv,123);
	cout << "le titre est " << miserable.titre();
}