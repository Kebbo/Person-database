#pragma once
#include "Henkilo.h"
class Opiskelija :
	public Henkilo
{
public:
	Opiskelija();
	Opiskelija(string etunimi,string sukunimi,string osoite,string puhelinnumero,string opiskelijanumero);
	Opiskelija(const Opiskelija&alkup);
	~Opiskelija();

	Opiskelija operator=(const Opiskelija&alkup);

	string annaOpiskelijanumero() const;
	void asetaOpiskelijanumero(string opiskelinanumero);

	void kysyTiedot();
	void tulosta() const;


private:
	string opiskelijanumero_;
};

