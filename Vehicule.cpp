#include "Vehicule.h"

Vehicule::Vehicule(const std::string& marque, const std::string& modele, int annee)
	: marque(marque), modele(modele), annee(annee)
{
}

std::string Vehicule::getMarque() const
{
	return marque;
}

std::string Vehicule::getModele() const
{
	return modele;
}

int Vehicule::getAnnee() const
{
	return annee;
}
