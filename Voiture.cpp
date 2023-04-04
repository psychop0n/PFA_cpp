#include "Voiture.h"

Voiture::Voiture(const std::string& marque, const std::string& modele, int annee, const std::string& serie)
	: Vehicule(marque, modele, annee), serie(serie) {}

std::string Voiture::getSerie() const {
	return serie;
}



