#include "Tyontekija.h"
#include <iostream>

using std::cout; using std::endl; using std::cin; using std::getline;


Tyontekija::Tyontekija(): Henkilo(),tunnus_(),palkka_(0.0)
{
}

Tyontekija::Tyontekija(string etunimi, string sukunimi, string osoite, string puhelinnumero, float palkka, string tunnus):
	Henkilo(etunimi,sukunimi,osoite,puhelinnumero),palkka_(palkka),tunnus_(tunnus)
{
}

Tyontekija::Tyontekija(const Tyontekija & alkup): Henkilo(alkup),palkka_(alkup.palkka_),tunnus_(alkup.tunnus_)
{
}


Tyontekija::~Tyontekija()
{
}

Tyontekija Tyontekija::operator=(const Tyontekija&alkup)
{
	if (this != &alkup)
	{
		Henkilo::operator=(alkup);
		palkka_ = 0;
		tunnus_ = "";

		palkka_ = alkup.palkka_;
		tunnus_ = alkup.tunnus_;
	}
	return *this;
}

float Tyontekija::annaPalkka() const
{
	return palkka_;
}

string Tyontekija::annaTunnus() const
{
	return tunnus_;
}

void Tyontekija::asetaTunnus(string tunnus)
{
	tunnus_ = tunnus;
}

void Tyontekija::asetaPalkka(float palkka)
{
	palkka_ = palkka;
}

void Tyontekija::kysyTiedot()
{
	string palkka;
	Henkilo::kysyTiedot();
	cout << "Anna palkka: ";
	getline(cin,palkka);
	cout << "Anna tunnus: ";
	getline(cin, tunnus_);
	palkka_ = atof(palkka.c_str());


}

void Tyontekija::tulosta() const
{
	Henkilo::tulosta();
	cout << "Palkka: " << palkka_ << " " << tunnus_ << " ";
}
