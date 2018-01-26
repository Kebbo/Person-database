#include "koulu.h"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>

using std::cin;using std::cout;


koulu::koulu():nimi_(),koulutusohjelmat_()
{
}

koulu::koulu(string nimi): nimi_(nimi),koulutusohjelmat_()
{
}


koulu::~koulu()
{
}

void koulu::lisaaKoulutusohjelma()
{
	string nimi;
	cout << "Anna nimi: ";
	getline(cin, nimi);
	koulutusohjelmat_.push_back(nimi);

}

void koulu::tulostaKoulutusohjelmat() const
{
	for (unsigned int i = 0;i < koulutusohjelmat_.size();i++)
	{
		cout << koulutusohjelmat_.at(i).annaNimi() << std::endl;
	}
}

void koulu::tulostaKoulutusohjelmienMaara() const
{
	cout << koulutusohjelmat_.size() << std::endl;
}

void koulu::lisaaKoulutusohjelmaanOpettaja()
{
	int index = etsiKoulutusohjelma();

	if (index >= 0) koulutusohjelmat_.at(index).lisaaOpettaja();
	else cout << "Koulutusohjelmaa ei loydy!\n";
}

void koulu::tulostaKoulutusohjelmanOpettajat() const
{
	int index = etsiKoulutusohjelma();

	if (index >= 0)
	{
		koulutusohjelmat_.at(index).tulostaOpettajat();
	}
	else cout << "Koulutusohjelmaa ei loydy!\n";
}

void koulu::lisaaKoulutusohjelmaanOpiskelija()
{
	int index = etsiKoulutusohjelma();

	if (index >= 0) koulutusohjelmat_.at(index).lisaaOpiskelija();
	else cout << "Koulutusohjelmaa ei loydy!\n";
}

void koulu::tulostaKoulutusohjelmanOpiskelijat() const
{
	int index = etsiKoulutusohjelma();

	if (index >= 0)
	{
		koulutusohjelmat_.at(index).tulostaOpiskelijat();
	}
	else cout << "Koulutusohjelmaa ei loydy!\n";
}

void koulu::poistaOpettaja() // etsii koulutusohjelman ja kutsuu sen alta löytyvää poistometodia
{

	string tunnus;
	
	int index = etsiKoulutusohjelma();

	std::cout << "Anna poistettavan opettajan tunnus: ";

	getline(cin, tunnus);

	koulutusohjelmat_.at(index).poistaOpettaja(tunnus);

}

void koulu::poistaOpiskelija() // sama kuin yllä
{
	string tunnus;

	int index = etsiKoulutusohjelma();

	std::cout << "Anna poistettavan opiskelijan opiskelijanumero: ";

	getline(cin, tunnus);

	koulutusohjelmat_.at(index).poistaOpiskelija(tunnus);
}

void koulu::poistaKoulutusohjelma()
{

	int index = etsiKoulutusohjelma();
	if(index>=0)
	{
		koulutusohjelmat_.erase(koulutusohjelmat_.begin()+index);
		std::cout << "Koulutusohjelma poistettu.\n";
	}
	else std::cout << "Koulutusohjelmaa ei loytynyt.\n";
}

void koulu::paivitaKoulutusohjelma()
{
	string nimi;
	int index = etsiKoulutusohjelma();

	if (index >= 0)
	{
		std::cout << "Anna uusi nimi: ";
		getline(cin, nimi);

		koulutusohjelmat_.at(index).asetaNimi(nimi);
	}
	else std::cout << "Koulutusohjelmaa ei loytynyt.\n";

}

void koulu::paivitaOpiskelija()
{
	
	string tunnus;
	Opiskelija temp;
	int index = etsiKoulutusohjelma();

	if (index >= 0)
	{
		std::cout << "Anna opiskelijanumero: ";
		getline(cin, tunnus);
		int index2 = koulutusohjelmat_.at(index).etsiOpiskelija(tunnus);
		if (index2 >= 0)
		{
			std::cout << "Uudet tiedot:\n";
			temp.kysyTiedot();

			koulutusohjelmat_.at(index).asetaOpiskelija(temp, index2);
			std::cout << "Tiedot paivitetty.\n";
		}
		else std::cout << "Opiskelijaa ei loytynyt\n";
	}
	else std::cout << "Koulutusohjelmaa ei loytynyt.\n";
}

void koulu::paivitaOpettaja()
{
	string tunnus;
	Opettaja temp;

	int index = etsiKoulutusohjelma();
	if (index >= 0)
	{
		std::cout << "Anna opettajan tunnus: ";
		getline(cin, tunnus);
		int index2 = koulutusohjelmat_.at(index).etsiOpettaja(tunnus);
		if (index2 >= 0)
		{
			std::cout << "Uudet tiedot:\n";
			temp.kysyTiedot();

			koulutusohjelmat_.at(index).asetaOpettaja(temp, index2);
			std::cout << "Tiedot paivitetty.\n";
		}
		else std::cout << "Opettajaa ei loytynyt\n";
	}
	else std::cout << "Koulutusohjelmaa ei loytynyt.\n";
}

void koulu::tallennaTiedot()
{
	std::ofstream opettajat("opettajat.csv", std::fstream::trunc | std::fstream::out); // avataan tiedosto ja tyhjennetään se

	for (int i = 0;i < koulutusohjelmat_.size();i++)
	{
		for (int j = 0; j < koulutusohjelmat_.at(i).annaOpettajamaara();j++)
		{
			opettajat << koulutusohjelmat_.at(i).annaNimi() << ';'
				<< koulutusohjelmat_.at(i).annaOpettaja(j).annaEtunimi() << ';'
				<< koulutusohjelmat_.at(i).annaOpettaja(j).annaSukunimi() << ';'
				<< koulutusohjelmat_.at(i).annaOpettaja(j).annaOsoite() << ';'
				<< koulutusohjelmat_.at(i).annaOpettaja(j).annaPuhelinnumero() << ';'
				<< koulutusohjelmat_.at(i).annaOpettaja(j).annaTunnus() << ';'
				<< koulutusohjelmat_.at(i).annaOpettaja(j).annaPalkka() << ';'
				<< koulutusohjelmat_.at(i).annaOpettaja(j).annaOpetusala() << '\n';
		}
	}
	opettajat.close();
	std::ofstream opiskelijat("opiskelijat.csv", std::fstream::trunc | std::fstream::out);
	for (int i = 0;i < koulutusohjelmat_.size();i++)
	{
		for (int j = 0;j < koulutusohjelmat_[i].annaOpiskelijamaara();j++)
		{
			opiskelijat << koulutusohjelmat_.at(i).annaNimi() << ';'
				<< koulutusohjelmat_.at(i).annaOpiskelija(j).annaEtunimi() << ';'
				<< koulutusohjelmat_.at(i).annaOpiskelija(j).annaSukunimi() << ';'
				<< koulutusohjelmat_.at(i).annaOpiskelija(j).annaOsoite() << ';'
				<< koulutusohjelmat_.at(i).annaOpiskelija(j).annaPuhelinnumero() << ';'
				<< koulutusohjelmat_.at(i).annaOpiskelija(j).annaOpiskelijanumero() << '\n';
		}
	}
	
	
	opiskelijat.close(); // suljetaan tiedosto
	
	std::cout << "Tiedot tallennettu.\n";

}

void koulu::lueTiedot()
{
	string buffer_ohjelma;
	Opettaja temp;
	Opiskelija temp2;
	int index=-1;
	string buffer_tiedot;
	std::ifstream opettajat("opettajat.csv");

	if (opettajat.is_open())
	{
		while (opettajat.peek() != EOF) // luetaan tiedostoa loppuun saakka
		{
			getline(opettajat, buffer_ohjelma, ';'); // luetaan puolipisteeseen asti
			for (unsigned int i = 0; i < koulutusohjelmat_.size(); i++)
			{
				if (buffer_ohjelma == koulutusohjelmat_.at(i).annaNimi())
				{
					index = i;
					break;
				}
				else index = -1;
			}
			if (index < 0)
			{
				koulutusohjelmat_.push_back(buffer_ohjelma);
				index = koulutusohjelmat_.size() - 1;
			}
			getline(opettajat, buffer_tiedot, ';');
			temp.asetaEtunimi(buffer_tiedot);
			getline(opettajat, buffer_tiedot, ';');
			temp.asetaSukunimi(buffer_tiedot);
			getline(opettajat, buffer_tiedot, ';');
			temp.asetaOsoite(buffer_tiedot);
			getline(opettajat, buffer_tiedot, ';');
			temp.asetaPuhelinnumero(buffer_tiedot);
			getline(opettajat, buffer_tiedot, ';');
			temp.asetaTunnus(buffer_tiedot);
			getline(opettajat, buffer_tiedot, ';');
			temp.asetaPalkka(atof(buffer_tiedot.c_str()));
			getline(opettajat, buffer_tiedot);
			temp.asetaOpetusala(buffer_tiedot);

			koulutusohjelmat_.at(index).lisaaOpettaja(temp);

		}
		opettajat.close();
	}
	else std::cout << "Tiedostoa opettajat.csv ei loydy.\n";
	std::ifstream opiskelijat("opiskelijat.csv");
	if (opiskelijat.is_open())
	{
		while (opiskelijat.peek() != EOF) // luetaan tiedostoa loppuun saakka
		{
			getline(opiskelijat, buffer_ohjelma, ';'); // luetaan puolipisteeseen asti
			for (unsigned int i = 0; i < koulutusohjelmat_.size(); i++)
			{
				if (buffer_ohjelma == koulutusohjelmat_.at(i).annaNimi())
				{
					index = i;
					break;
				}
				else index = -1;
			}
			if (index < 0)
			{
				koulutusohjelmat_.push_back(buffer_ohjelma);
				index = koulutusohjelmat_.size() - 1;
			}
			getline(opiskelijat, buffer_tiedot, ';');
			temp2.asetaEtunimi(buffer_tiedot);
			getline(opiskelijat, buffer_tiedot, ';');
			temp2.asetaSukunimi(buffer_tiedot);
			getline(opiskelijat, buffer_tiedot, ';');
			temp2.asetaOsoite(buffer_tiedot);
			getline(opiskelijat, buffer_tiedot, ';');
			temp2.asetaPuhelinnumero(buffer_tiedot);
			getline(opiskelijat, buffer_tiedot);
			temp2.asetaOpiskelijanumero(buffer_tiedot);
			

			koulutusohjelmat_.at(index).lisaaOpiskelija(temp2);

		}
		opiskelijat.close();
	}
	else std::cout << "Tiedostoa opiskelijat.csv ei loydy\n";
}

void koulu::asetaNimi(string nimi)
{
	nimi_ = nimi;
}

string koulu::annaNimi() const
{
	return nimi_;
}

int koulu::etsiKoulutusohjelma() const
{
	string nimi;
	cout << "Anna koulutusohjelman nimi: ";
	getline(cin, nimi);
	for (unsigned int i = 0; i<koulutusohjelmat_.size(); i++)
	{
		if (nimi == koulutusohjelmat_.at(i).annaNimi())
		{
			return i;
		}
	}
	return -1; // ei löytynyt, palautetaan -1
}

void koulu::tulostaKoulutusohjelmienmaara() const
{
	std::cout << "Koulutusohjelmia on " << annaKoulutusohjelmienmaara() << std::endl;
}

int koulu::annaKoulutusohjelmienmaara() const
{
	return koulutusohjelmat_.size();
}
