#pragma once

#include <string>

using std::string;

class Henkilo
{
public:
	Henkilo();
	Henkilo(string etunimi, string sukunimi, string osoite, string puhelinnumero);
	Henkilo(const Henkilo&alkup);
	~Henkilo();

	Henkilo& operator =(const Henkilo&alkup);

	string annaEtunimi() const;
	string annaSukunimi() const;
	string annaOsoite() const;
	string annaPuhelinnumero() const;

	void asetaEtunimi(string);
	void asetaSukunimi(string);
	void asetaOsoite(string);
	void asetaPuhelinnumero(string);

	void kysyTiedot();
	void tulosta() const;


private:
	string etunimi_;
	string sukunimi_;
	string osoite_;
	string puhelinnumero_;
};

