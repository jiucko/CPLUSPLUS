#pragma once
#include <iostream>
using namespace std;

class Base
{
public:
	Base() { cout << "class Base Constructor\n"; }
	virtual ~Base() { cout << "class Base Destructor\n"; }
};

class A :public Base
{
public:
	A() { cout << "class A Constructor\n"; }
	~A() { cout << "class A Destructor\n"; }
};