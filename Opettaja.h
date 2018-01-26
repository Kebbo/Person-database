#pragma once
#include "Tyontekija.h"

class Opettaja :
	public Tyontekija
{
public:
	Opettaja();
	Opettaja(string etunimi, string sukunimi, string osoite, string puhelinnumero, float palkka, string tunnus, string opetusala);
	Opettaja(const Opettaja&alkup);
	~Opettaja();
	Opettaja operator=(const Opettaja&alkup);

	string annaOpetusala() const;
	void asetaOpetusala(string opetusala);

	void tulosta() const;
	void kysyTiedot();

private:
	string opetusala_;
};

