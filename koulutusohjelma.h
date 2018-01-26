#pragma once
#include "Opettaja.h"
#include "Opiskelija.h"

#include <string>
#include <vector>

using std::string; using std::vector;

class koulutusohjelma
{
public:
	koulutusohjelma();
	koulutusohjelma(string nimi);
	~koulutusohjelma();

	void lisaaOpettaja();
	void lisaaOpettaja(Opettaja temp);
	void lisaaOpiskelija();
	void lisaaOpiskelija(Opiskelija temp);
	void tulostaOpettajat() const;
	void tulostaOpiskelijat() const;
	int annaOpiskelijamaara() const;
	int annaOpettajamaara() const;

	void poistaOpettaja(string tunnus);
	void poistaOpiskelija(string opiskelijanro);
	string annaNimi() const;
	void asetaNimi(string nimi);

	int etsiOpiskelija(string opiskelijanro)const;
	int etsiOpettaja(string tunnus)const;

	void asetaOpiskelija(Opiskelija uusi,int index);
	void asetaOpettaja(Opettaja uusi,int index);
	Opettaja annaOpettaja(int index)const;
	Opiskelija annaOpiskelija(int index) const;
private:
	string nimi_;
	vector <Opiskelija> opiskelijat_;
	vector <Opettaja> opettajat_;
};

