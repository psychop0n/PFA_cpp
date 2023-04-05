#include "Vehicule.h"

Vehicule::Vehicule(const std::string& marque, const std::string& modele, int annee)
	: marque(marque), modele(modele), annee(annee)
{
}

void Vehicule::setMarque(std::string m)
{
	marque = m;
}
std::string Vehicule::getMarque() const
{
	return marque;
}

void Vehicule::setModele(std::string m)
{
	modele = m;
}
std::string Vehicule::getModele() const
{
	return modele;
}

void Vehicule::setAnnee(int a)
{
	annee = a;
}
int Vehicule::getAnnee() const
{
	return annee;
}
