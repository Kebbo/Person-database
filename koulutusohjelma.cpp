#include "koulutusohjelma.h"
#include <iostream>



koulutusohjelma::koulutusohjelma():nimi_(), opiskelijat_(),opettajat_()
{
}

koulutusohjelma::koulutusohjelma(string nimi): nimi_(nimi),opiskelijat_(),opettajat_()
{
}


koulutusohjelma::~koulutusohjelma()
{
}

void koulutusohjelma::lisaaOpettaja()
{
	Opettaja temp;
	temp.kysyTiedot();
	opettajat_.push_back(temp);
}

void koulutusohjelma::lisaaOpettaja(Opettaja temp)
{
	opettajat_.push_back(temp);
}

void koulutusohjelma::lisaaOpiskelija()
{
	Opiskelija temp;
	temp.kysyTiedot();
	opiskelijat_.push_back(temp);
}

void koulutusohjelma::lisaaOpiskelija(Opiskelija temp)
{
	opiskelijat_.push_back(temp);
}

void koulutusohjelma::tulostaOpettajat() const
{
	for (unsigned int i = 0;i < opettajat_.size();i++)
	{
		opettajat_.at(i).tulosta();
	}
}

void koulutusohjelma::tulostaOpiskelijat() const 
{
	for (unsigned int i = 0;i < opiskelijat_.size();i++)
	{
		opiskelijat_.at(i).tulosta();
	}
}

int koulutusohjelma::annaOpiskelijamaara() const
{
	return opiskelijat_.size();
}

int koulutusohjelma::annaOpettajamaara() const
{
	return opettajat_.size();
}

void koulutusohjelma::poistaOpettaja(string tunnus)
{
	int index = etsiOpettaja(tunnus);
	if (index >= 0)
	{
		opettajat_.erase(opettajat_.begin() + index);
		std::cout << "Opettaja poistettu.\n";
	}
	else std::cout << "Opettajaa ei loytynyt.\n";
}

void koulutusohjelma::poistaOpiskelija(string opiskelijanro)
{
	int index = etsiOpiskelija(opiskelijanro);
	if (index >= 0)
	{
		opiskelijat_.erase(opiskelijat_.begin() + index);
		std::cout << "Opiskelija poistettu.\n";
	}
	else std::cout << "Opiskelijaa ei loytynyt.\n";
}

string koulutusohjelma::annaNimi() const
{
	return nimi_;
}

void koulutusohjelma::asetaNimi(string nimi)
{
	nimi_ = nimi;
}

int koulutusohjelma::etsiOpiskelija(string opiskelijanro) const
{
	for (int i = 0;i < annaOpiskelijamaara();i++)
	{
		if (opiskelijat_.at(i).annaOpiskelijanumero() == opiskelijanro) return i;
	}
	return -1;
}

int koulutusohjelma::etsiOpettaja(string tunnus) const
{
	for (int i = 0;i < annaOpettajamaara();i++)
	{
		if (opettajat_.at(i).annaTunnus() == tunnus) return i;
	}
	return -1;
}

void koulutusohjelma::asetaOpiskelija(Opiskelija uusi,int index)
{
	opiskelijat_.at(index) = uusi;
}

void koulutusohjelma::asetaOpettaja(Opettaja uusi,int index)
{
	opettajat_.at(index) = uusi;
}

Opettaja koulutusohjelma::annaOpettaja(int index) const
{
	return opettajat_.at(index);
}

Opiskelija koulutusohjelma::annaOpiskelija(int index) const
{
	return opiskelijat_.at(index);
}
