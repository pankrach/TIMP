#include "stdafx.h"
#include <iostream>
#include <fstream>
#include "string"
using namespace std;

void compare(ifstream& f1, ifstream& f2, string name) {
	string s1, s2;
	int i = 0;
	while (!f1.eof()) {
		i++;
		getline(f1, s1);

		while (!f2.eof()) {
			getline(f2, s2);
			if (s1 == s2) break;
			if (f2.eof())
				cout << name << " " << i << " \"" << s1 << "\"" << endl;
		}
		f2.seekg(0);
	}
	f1.seekg(0);
}


int _tmain(int argc, _TCHAR* argv[])
{
	string name1, name2;
	cin >> name1;
	cin >> name2;
	ifstream f1(name1);
	ifstream f2(name2);

	compare(f1, f2, name1);
	compare(f2, f1, name2);

	return 0;
}