#include "Sovellus.h"
#include <iostream>
#include <string>
#include "koulu.h"


Sovellus::Sovellus()
{
}


Sovellus::~Sovellus()
{
}

void Sovellus::aja() const
{
	koulu amk("amk");
	do 
	{
		try
		{
			std::string valinta = tulostaValikko();
			if (valinta == "1") amk.lisaaKoulutusohjelma();
			else if (valinta == "2") amk.tulostaKoulutusohjelmat();
			else if (valinta == "3") amk.tulostaKoulutusohjelmienMaara();
			else if (valinta == "4")amk.lisaaKoulutusohjelmaanOpettaja();
			else if (valinta == "5")amk.tulostaKoulutusohjelmanOpettajat();
			else if (valinta == "6")amk.lisaaKoulutusohjelmaanOpiskelija();
			else if (valinta == "7")amk.tulostaKoulutusohjelmanOpiskelijat();
			else if (valinta == "8")amk.poistaKoulutusohjelma();
			else if (valinta == "9")amk.poistaOpettaja();
			else if (valinta == "10")amk.poistaOpiskelija();
			else if (valinta == "11")amk.paivitaKoulutusohjelma();
			else if (valinta == "12")amk.paivitaOpettaja();
			else if (valinta == "13")amk.paivitaOpiskelija();
			else if (valinta == "14")amk.lueTiedot();
			else if (valinta == "15")amk.tallennaTiedot();
			else if (valinta == "0")break;
			else
			{
				std::cout << "Virheellinen syote.\n";
			}
		}
		catch (...)
		{
			std::cerr << "Oho! Tapahtu virhe.\n";
		}
	} while (0==0);
}

std::string Sovellus::tulostaValikko() const
{
	std::string valinta;

	std::cout << "1) Lisaa koulutusohjelma\n"
		<< "2) Tulosta koulutusohjelmien nimet\n"
		<< "3) Tulosta koulutusohjelmien maara\n"
		<< "4) Lisaa koulutusohjelmaan opettaja\n"
		<< "5) Tulosta koulutusohjelman opettajat\n"
		<< "6) Lisaa koulutusohjelmaan opiskelija\n"
		<< "7) Tulosta koulutusohjelman opiskelijat\n"
		<< "8) Poista koulutusohjelma\n"
		<< "9) Poista opettaja\n"
		<< "10) Poista opiskelija\n"
		<< "11) Paivita koulutusohjelman nimi\n"
		<< "12) Paivita opettajan tiedot\n"
		<< "13) Paivita opiskelijan tiedot\n"
		<< "14) Lue tiedot\n"
		<< "15) Tallenna tiedot\n"
		<< "0) Lopeta\n";

	std::cout << "Valinta: ";
	std::getline(std::cin, valinta);
	return valinta;
}
