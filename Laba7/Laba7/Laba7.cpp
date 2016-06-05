// Laba7.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream> 
#include <string>
#include "Windows.h"
#include <stdio.h>
using namespace std;

int main() {
	string lib, cmd;
	int data;
	cin >> lib;
	HINSTANCE h = 0;

	if (lib == "lib1")
		h = LoadLibrary(L"lib2");
	if (lib == "lib2")
		h = LoadLibrary(L"lib2");

	if (h) 
	{
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			cin >> cmd;
			if (cmd == "add") 
			{
				cin >> data;
				typedef void z(int s);
				FARPROC add = (FARPROC)GetProcAddress((HMODULE)h, "add");
				((z*)add)(data);
			}
			if (cmd == "get") 
			{
				FARPROC get = (FARPROC)GetProcAddress((HMODULE)h, "get");
				cout << get() << endl;
			}
			if (cmd == "del") 
			{
				FARPROC del = (FARPROC)GetProcAddress((HMODULE)h, "del");
				del();
			}
		}
	}
	system("pause");
	return 0;
}
