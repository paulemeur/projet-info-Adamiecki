#include<iostream>
#include"CImg.h"
#include<vector>
#include"Tache.h"
#include<string>

using namespace std;
using namespace cimg_library;

void main()
{
	Tache a;
	Tache b;
	Date dref(20, 4, 2019);
	vector<char> jours = { 'L','M','M','J','V','S','D' };
	vector<int> nb = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	vector<Tache> L = { a,b }; 	//inclure liste de taches triée du tableau

	const unsigned char rcolor[3] = { 0,0,200 };
	const unsigned char lcolor[3] = { 0,0,0 };
	const unsigned char white[3] = { 255,255,255 };

	CImg<unsigned char> grid(800, 50+40*L.size(), 1, 3, 255);
	grid.draw_rectangle(0, 0, 800, 50, rcolor);
	grid.draw_line(0, 25, 800, 25,lcolor);

	int k=(L[0].getd()).diff(L[int(L.size()) - 1].getf());
	if (k > 168)
	{
		int s = (dref.diff(L[0].getd())) % 6;
		for (int i = 1; i <= k; i++)
		{
			if ((L[0].getd().ajout_jour(s)).getm()==12 && (L[0].getd().ajout_jour(s)).getj()==31)
			{
				grid.draw_line(800 * i / k, 0, 800 * i / k, 25, lcolor);
			}
			if ((L[0].getd().ajout_jour(s)).getj() == nb[(L[0].getd().ajout_jour(s)).getm() - 1])
			{
				grid.draw_line(800 * i / k, 25, 800 * i / k, 50, lcolor);
			}
		}
	}
	if (42 < k <= 168)
	{
		int s = (dref.diff(L[0].getd()))%6;
		for (int i = 1; i <= k; i++)
		{
			if (s + k % 6 == 6)
			{
				grid.draw_line(800 * i / k, 25, 800 * i / k, 50, lcolor);
			}
			if ((L[0].getd().ajout_jour(s)).getm() == 2 && (L[0].getd().ajout_jour(s)).getj() == 28 && (L[0].getd().ajout_jour(s)).geta() % 4 == 0 && (L[0].getd().ajout_jour(s)).geta() % 400 != 0)
			{
				grid.draw_line(800 * i / k, 0, 800 * i / k, 25, lcolor);
			}
			else if ((L[0].getd().ajout_jour(s)).getj() == nb[(L[0].getd().ajout_jour(s)).getm() - 1])
			{
				grid.draw_line(800 * i / k, 0, 800 * i / k, 25, lcolor);
			}
		}
	}
	if (k <= 42)
	{
		int j;
		if ((L[0].getd()).ordre(dref) <= 0)
		{
			j = (5 + (L[0].getd()).diff(dref)) % 6;
		}
		else
		{
			j = (5 + dref.diff((L[0].getd()))) % 6;
		}
		for (int i = 1; i<=k; i++)
		{
			grid.draw_line(800*i/k, 25, 800 * i / k, 50, lcolor);
			grid.draw_text(35,int((400 / k) + (800 * i / k)),&jours[(j+i)%6],lcolor,rcolor,12);
			if (jours[(j + i) % 6] == 'L')
			{
				grid.draw_line(800 * i / k, 0, 800 * i / k, 0, lcolor);



				if (i <= 7 && k - i > 7)
				{
					string txt = to_string((L[0].getd()).getj()) + "/" + to_string((L[0].getd()).getm()) + "-" + to_string(((L[0].getd()).ajout_jour(i)).getj()) + "/" + to_string(((L[0].getd()).ajout_jour(i)).getm());
					const char* sem = txt.c_str();
					grid.draw_text(10, int(400 *i/ k), sem, lcolor, rcolor, 12);
				}
				if (k - i <= 7 && i > 7)
				{
					string txt = to_string(((L[0].getf()).ajout_jour(-i)).getj()) + "/" + to_string(((L[0].getf()).ajout_jour(-i)).getm()) + "-" + to_string((L[L.size-1].getf()).getj()) + "/" + to_string((L[L.size()-1].getf()).getm());
					const char* sem = txt.c_str();
					grid.draw_text(10, int(400 * i / k), sem, lcolor, rcolor, 12);
				}
				if (i <= 7 && k - i <= 7)
				{
					string txt = to_string((L[0].getd()).getj()) + "/" + to_string((L[0].getd()).getm()) + "-" + to_string((L[L.size-1].getf()).getj()) + "/" + to_string((L[L.size()-1].getf()).getm());
					const char* sem = txt.c_str();
					grid.draw_text(10, int(400 * i / k), sem, lcolor, rcolor, 12);
				}
				if (i > 7 && k - i > 7)
				{
					string txt = to_string(((L[0].getd()).ajout_jour(i)).getj()) + "/" + to_string(((L[0].getd()).ajout_jour(i)).getm()) + "-" + to_string(((L[0].getd()).ajout_jour(i+7)).getj()) + "/" + to_string(((L[0].getd()).ajout_jour(i+7)).getm());
					const char* sem = txt.c_str();
					grid.draw_text(10, int(400 * i / k), sem, lcolor, rcolor, 12);
				}
			}
		}
	}

	for (int i = 0; i < L.size(); i++)
	{
		grid.draw_rectangle(int((L[0].getd()).diff(L[i].getd()) * 800 / k), 50 + 40 * i + 5, int((L[0].getd()).diff(L[i].getf()) * 800 / k), 50 + 40 * i + 5 + 20, rcolor);
		const char* nom = (L[i].gettxt()).c_str();
		grid.draw_text(50 + 40 * i + 20, 5 + int((L[0].getd()).diff(L[i].getf()) * 800 / k), nom, lcolor, white, 10);
	}

	CImgDisplay disp(grid, "Test", 0, false, false);
	while (1)
	{
	}
}