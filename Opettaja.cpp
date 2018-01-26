#include "Opettaja.h"
#include <iostream>

using std::cout; using std::endl; using std::cin; using std::getline;


Opettaja::Opettaja():Tyontekija(),opetusala_()
{
}

Opettaja::Opettaja(string etunimi, string sukunimi, string osoite, string puhelinnumero, float palkka, string tunnus, string opetusala):
	Tyontekija(etunimi, sukunimi, osoite, puhelinnumero, palkka, tunnus), opetusala_(opetusala)
{
}

Opettaja::Opettaja(const Opettaja & alkup): Tyontekija(alkup),opetusala_(alkup.opetusala_)
{
}


Opettaja::~Opettaja()
{
}

Opettaja Opettaja::operator=(const Opettaja & alkup)
{
	if (this != &alkup)
	{
		Tyontekija::operator=(alkup);
		opetusala_ = "";
		opetusala_ = alkup.opetusala_;
	}
	return *this;
}

string Opettaja::annaOpetusala() const
{
	return opetusala_;
}

void Opettaja::asetaOpetusala(string opetusala)
{
	opetusala_ = opetusala;
}

void Opettaja::tulosta() const
{
	Tyontekija::tulosta();
	cout << opetusala_ << endl;
}

void Opettaja::kysyTiedot()
{
	Tyontekija::kysyTiedot();
	cout << "Anna opetusala: ";
	getline(cin,opetusala_);
}
