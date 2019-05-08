#ifndef DATE_H
#define DATE_H

#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Date
{
public:
	Date();
	Date(int j, int m, int a);
	~Date();
	void Coherent();
	int ordre(Date d);
	int diff(Date d);
	void setj(int j);
	void setm(int m);
	void seta(int a);
	int getj();
	int getm();
	int geta();
	Date ajout_jour(int i);

private:
	int jour_;
	int mois_;
	int annee_;
};
#endif