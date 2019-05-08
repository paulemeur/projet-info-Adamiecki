#include<iostream>
#include<string>
#include<vector>
#include"Date.h"

using namespace std;

Date::Date()
{
	cout << "Entrez jour : " << endl;
	cin >> jour_;
	cout << "Entrez mois : " << endl;
	cin >> mois_;
	cout << "Entrez annee : " << endl;
	cin >> annee_;
	Coherent();
}

Date::Date(int j, int m, int a) :jour_(j), mois_(m), annee_(a)
{}

Date::~Date()
{
}

void Date::Coherent()
{
	vector<int> nb = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (mois_ < 1 || mois_>12)
	{
		cout << "Saisissez un mois valable." << endl;
		cin >> mois_;
		Coherent();
	}
	if (jour_<0 || jour_>nb[mois_ - 1])
	{
		cout << "Saisissez un mois valable." << endl;
		cin >> jour_;
		Coherent();
	}
	if ((mois_ == 2 && jour_ == 29 && annee_ % 4 != 0) && (mois_ == 2 && jour_ == 29 && annee_ % 400 == 0))
	{
		cout << "Attention, ce n'est pas une année bisextile." << endl;
		cin >> jour_;
		Coherent();
	}

}

int Date::ordre(Date d)
{
	if (annee_ < d.annee_)
	{
		return -1;
	}
	if (annee_ > d.annee_)
	{
		return 1;
	}
	if (annee_ == d.annee_)
	{
		if (mois_ < d.mois_)
		{
			return -1;
		}
		if (mois_ > d.mois_)
		{
			return 1;
		}
		if (mois_ == d.mois_)
		{
			if (jour_ < d.jour_)
			{
				return -1;
			}
			if (jour_ > d.jour_)
			{
				return 1;
			}
			if (jour_ == d.jour_)
			{
				return 0;
			}
		}
	}
}

void Date::setj(int j)
{
	jour_ = j;
}

void Date::setm(int m)
{
	mois_ = m;
}

void Date::seta(int a)
{
	annee_ = a;
}

int Date::getj()
{
	return jour_;
}

int Date::getm()
{
	return mois_;
}

int Date::geta()
{
	return annee_;
}
int Date::diff(Date d)
{
	int k = 0;
	vector<int> nb = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	Date trigger(jour_,mois_,annee_+1);
	while (d.ordre(trigger) == -1)
	{
		k += 365;
		trigger.seta(trigger.annee_ + 1);
	}
	trigger.seta(trigger.annee_ - 1);
	trigger.setm(trigger.mois_ + 1);

	while (d.ordre(trigger) == -1)
	{
		if ((mois_ == 2 && annee_ % 4 != 0) && (mois_ == 2 && annee_ % 400 == 0))
		{
			k += 28;
		}
		else
		{
			k += nb[mois_ - 1];
		}
		trigger.setm(trigger.mois_ + 1);
	}
	trigger.setm(trigger.mois_ - 1);
	trigger.setj(trigger.jour_ + 1);
	
	while (d.ordre(trigger) != 0)
	{
		k += 1;
		trigger.setj(trigger.jour_ + 1);
	}
	return k;
}

Date Date::ajout_jour(int i)
{
	if (i > 0)
	{
		vector<int> nb = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		if (jour_ + i <= nb[mois_ - 1] && i < nb[mois_ - 1])
		{
			setj(i + getj());
		}
		else
		{
			while (i > nb[mois_ - 1])
			{
				if (mois_ != 11)
				{
					mois_++;
				}
				else
				{
					mois_ = 0;
					annee_++;
				}
				i -= nb[mois_ - 1];
			}
			if (jour_ + i <= nb[mois_ - 1])
			{
				jour_ += i;
			}
			else
			{
				if (mois_ == 11)
				{
					mois_ = 0;
					annee_++;
					jour_ = jour_ + i - nb[11];
				}
				else
				{
					mois_++;
					jour_ = jour_ + i - nb[mois_ - 2];
				}
			}
		}
	}
	else
	{
		{
			vector<int> nb = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
			if (jour_ + i >= 0 && i < nb[mois_ - 1])
			{
				setj(i + getj());
			}
			else
			{
				while (-i > nb[mois_ - 1])
				{
					if (mois_ != 0)
					{
						mois_--;
					}
					else
					{
						mois_ = 11;
						annee_--;
					}
					i += nb[mois_ - 1];
				}
				if (jour_ + i >= 0)
				{
					jour_ += i;
				}
				else
				{
					if (mois_ == 0)
					{
						mois_ = 11;
						annee_--;
						jour_ = -(jour_ + i - nb[11]);
					}
					else
					{
						mois_--;
						jour_ = -(jour_ + i - nb[mois_]);
					}
				}
			}
		}
	}
	Date d(jour_, mois_, annee_);
	return d;
}