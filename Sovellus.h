#pragma once
#include <string>
#include "koulu.h"

class Sovellus
{
public:
	Sovellus();
	~Sovellus();

	void aja() const;
	std::string tulostaValikko() const;
};

