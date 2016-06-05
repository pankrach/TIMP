// Laba8.cpp: определяет точку входа для консольного приложения.
//
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

class Base 
{
public:
	Base(int v) { value = v; }
	virtual void show() = 0;
protected:
	int value;
};

class A : public Base
{
public:
	void show() { cout << "class A: " << value << endl; }
	A(int v) : Base(v) {};
};

class B : public Base 
{
public:
	void show() { cout << "class B: " << value << endl; }
	B(int v) : Base(v) {};
};

class C : public Base 
{
public:
	void show() { cout << "class C: " << value << endl; }
	C(int v) : Base(v) {};
};

vector<Base*> cls;

class Factory 
{
public:
	virtual Base* create(int) = 0;
	~Factory() {};
};

class AFactory : public Factory
{
public:
	Base* create(int v) { return new A(v); }
};

class BFactory : public Factory 
{
public:
	Base* create(int v) { return new  B(v); }
};

class CFactory : public Factory {
public:
	Base* create(int v) { return new C(v); }
};



class Functor 
{
public:
	virtual void operator()() = 0;
};


class FunctorCreate :public Functor
{
public:
	FunctorCreate() {
		F["A"] = new AFactory;
		F["B"] = new BFactory;
		F["C"] = new CFactory;
	}

	void operator()() {
		string name;
		int i;
		cin >> name;
		cin >> i;
		cls.push_back((F[name]->create(i)));
	}
	~FunctorCreate() {};
private:
	map<string, Factory*> F;
};

class  FunctorShow : public Functor {
public:
	FunctorShow() {};

	void operator()() {
		for (int i = 0; i < cls.size(); i++)
		{
			cls[i]->show();
		}
	}
};

int main()
{
	map<string, Functor*> func;
	func["create"] = new FunctorCreate;
	func["showall"] = new FunctorShow;
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		string s;
		cin >> s;
		(*func[s])();
	}
	system("pause");
	return 0;
}