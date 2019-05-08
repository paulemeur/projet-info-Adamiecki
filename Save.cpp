#include<fstream>
#include<iostream>
#include"Save.h"

using namespace std;

void enregistrer(Date d, string file)
{
	ofstream myfile;
	myfile.open(file);
}


int main() {
	ofstream myfile;
	myfile.open("example.txt");
	myfile << "Writing this to a file.\n";
	myfile.close();
	return 0;
}