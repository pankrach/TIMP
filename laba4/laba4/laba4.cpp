#include "stdafx.h"
#include <iostream>
using namespace std;

int n;
int* A;

void pryam(int kor)
{
	cout << kor << " ";

	for (int i = 0; i < n; i++)
		if (A[i] == kor)
			pryam(i);
}


void obrat(int kor)
{
	for (int i = 0; i < n; i++)
		if (A[i] == kor)
			obrat(i);

	cout << kor << " ";
}


void simmet(int kor) 
{
	int i = 0;
	while ((A[i] != kor) && (i < n))
		i++;
	if (i < n)
		simmet(i);

	cout << kor << " ";

	if (i < n)
		for (int k = i + 1; k < n; k++)
			if (A[k] == kor)
				simmet(k);
}


int main() {

	cin >> n;
	A = new int[n];
	for (int i = 0; i < n; i++)
		cin >> A[i];

	int kor = 0;
	while (A[kor] != -1)
		kor++;

	pryam(kor);
	cout << endl;
	obrat(kor);
	cout << endl;
	simmet(kor);
	cout << endl;

	delete[] A;
	system("pause");
	return 0;
}