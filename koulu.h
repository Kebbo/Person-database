#pragma once

#include <string>
#include <vector>
#include <iostream>
#include <fstream>

#include "koulutusohjelma.h"
#include "Tyontekija.h"

using std::string;using std::vector;


class koulu
{
public:
	koulu();
	koulu(string nimi);
	~koulu();

	void lisaaKoulutusohjelma();
	void tulostaKoulutusohjelmat() const;
	void tulostaKoulutusohjelmienMaara() const;
	void lisaaKoulutusohjelmaanOpettaja();
	void tulostaKoulutusohjelmanOpettajat() const;
	void lisaaKoulutusohjelmaanOpiskelija();
	void tulostaKoulutusohjelmanOpiskelijat() const;

	void poistaOpettaja();
	void poistaOpiskelija();

	void poistaKoulutusohjelma();

	void paivitaKoulutusohjelma();
	void paivitaOpiskelija();
	void paivitaOpettaja();

	void tallennaTiedot();
	void lueTiedot();

	void asetaNimi(string nimi);
	string annaNimi() const;
	int etsiKoulutusohjelma() const;
	void tulostaKoulutusohjelmienmaara() const;
	int annaKoulutusohjelmienmaara() const;

private:
	string nimi_;
	vector <koulutusohjelma> koulutusohjelmat_;
	vector <Tyontekija> tyontekijat_;
};

