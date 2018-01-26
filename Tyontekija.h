#pragma once
#include "Henkilo.h"


class Tyontekija :
	public Henkilo
{
public:
	Tyontekija();
	Tyontekija(string etunimi, string sukunimi, string osoite, string puhelinnumero,float palkka, string tunnus);
	Tyontekija(const Tyontekija&alkup);
	~Tyontekija();

	Tyontekija operator=(const Tyontekija&alkup);

	float annaPalkka() const;
	string annaTunnus() const;
	void asetaTunnus(string tunnus);
	void asetaPalkka(float palkka);

	void kysyTiedot();
	void tulosta() const;


private:
	float palkka_;
	std::string tunnus_;
};

