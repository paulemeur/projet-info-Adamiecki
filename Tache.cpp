#include<iostream>
#include<string>
#include"Date.h"
#include"Tache.h"

using namespace std;

Tache::Tache()
{
	cout << "Entrez le nom de la tache." << endl;
	cin >> nom_;
	cout << endl;
	cout << "Date de debut : ";
	debut_ = Date();
	cout << endl << "Date de fin : ";
	fin_ = Date();
	while(debut_.ordre(fin_) == 1)
	{
		cout << "Impossible, la fin est avant le debut." << endl;
		debut_.~Date();
		fin_.~Date();
		cout << endl << "Date de debut : ";
		debut_ = Date();
		cout << endl << "Date de fin : ";
		fin_ = Date();
	}
}

Tache::~Tache()
{
}

void Tache::Modifier()
{
	int choix;
	cout << "Que voulez-vous changer \?" << endl << "1/Nom" << endl << "2/Date de debut" << endl << "3/Date de fin" << endl << "4/Annuler" << endl;
	cin >> choix;
	switch (choix)
	{
	case(1):
		cin >> nom_;
	case(2):
		debut_.~Date();
		debut_ = Date();
	case(3):
		fin_.~Date();
		fin_ = Date();
	case(4):
		break;
	default:
		cout << "entrez un nombre valide." << endl;
		Modifier();
	}
}

Date Tache::getd()
{
	return debut_;
}

Date Tache::getf()
{
	return fin_;
}

string Tache::gettxt()
{
	return nom_;
}