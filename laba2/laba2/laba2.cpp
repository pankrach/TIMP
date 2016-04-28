#include "stdafx.h"
#include <fstream>
#include <iostream>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	char  name[255];
	char string[255];
	char* result;
	
	cin >> name;
	ifstream fin(name);	
	while (!fin.eof()) {
		fin.getline(name, 255);	
		if ((strstr(name, "\func")) != NULL)
		{ 
			result = strstr(name, "\func"); 
			result+=6;
			if (strstr(result, "*/") != NULL) 
			{
				strcpy_s(string, result);
				string[strlen(result) - 2] = '\0';
				cout << string << endl;
			}
			else
			cout << result << endl;
		}
	}

	return 0;
}