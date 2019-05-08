#ifndef TACHE_H
#define TACHE_H

#include<iostream>
#include<string>
#include"Date.h"

using namespace std;

class Tache
{
public:
	Tache();
	~Tache();
	void Modifier();
	Date getd();
	Date getf();
	string gettxt();

private:
	string nom_;
	Date debut_;
	Date fin_;
};
#endif