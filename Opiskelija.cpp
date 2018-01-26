#include "Opiskelija.h"
#include <iostream>

using std::cout; using std::endl; using std::cin; using std::getline;


Opiskelija::Opiskelija(): Henkilo(), opiskelijanumero_()
{
}

Opiskelija::Opiskelija(string etunimi, string sukunimi, string osoite, string puhelinnumero, string opiskelijanumero):
	Henkilo(etunimi,sukunimi,osoite,puhelinnumero), opiskelijanumero_(opiskelijanumero)
{
}

Opiskelija::Opiskelija(const Opiskelija & alkup): Henkilo(alkup),opiskelijanumero_(alkup.opiskelijanumero_)
{
}


Opiskelija::~Opiskelija()
{
}

Opiskelija Opiskelija::operator=(const Opiskelija & alkup)
{
	if (this != &alkup)
	{
		Henkilo::operator=(alkup);
		opiskelijanumero_ = "";
		opiskelijanumero_ = alkup.opiskelijanumero_;
	}
	return *this;
}

string Opiskelija::annaOpiskelijanumero() const
{
	return opiskelijanumero_;
}

void Opiskelija::asetaOpiskelijanumero(string opiskelijanumero)
{
	opiskelijanumero_ = opiskelijanumero;
}

void Opiskelija::kysyTiedot()
{
	Henkilo::kysyTiedot();
	cout << "Anna opiskelijanumero: ";
	getline(cin, opiskelijanumero_);
}

void Opiskelija::tulosta() const
{
	Henkilo::tulosta();
	cout << opiskelijanumero_ << endl;
}
