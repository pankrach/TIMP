// lib2.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <vector>
#include <iostream>

using namespace std;
vector<int> tree;

extern "C" 
{
	__declspec(dllexport) void add(int data) 
	{
		tree.push_back(data);
	}
	__declspec(dllexport) void get() 
	{
		return tree.front();
	}
	__declspec(dllexport) void del() 
	{
		tree.erase(tree.begin());
	}
}
