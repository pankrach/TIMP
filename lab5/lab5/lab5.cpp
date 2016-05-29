// lab5.cpp: определяет точку входа для консольного приложения.
//
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;
vector<int> tree;

void add() {
	int k, i;
	cin >> k;
	if (tree.size() == 0)
		tree.insert(tree.begin(), k);
	else {
		for (i = 0; i < tree.size(); i++) {
			if (k <= tree[i]) {
				tree.insert(tree.begin() + i, k);
				break;
			}
		}
		if (i == tree.size())
			tree.push_back(k);
	}
}

int main()
{
	string cmd;
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> cmd;
		if (cmd == "add")
		{
			add();
		}
		if (cmd == "get")
		{
			cout << tree[0] << endl;
		}
		if (cmd == "del")
		{
			tree.erase(tree.begin());
		}
	}
	return 0;
}