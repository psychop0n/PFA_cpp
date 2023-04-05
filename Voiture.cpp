#include "Voiture.h"

Voiture::Voiture(const std::string& marque, const std::string& modele, int annee, const std::string& serie)
	: Vehicule(marque, modele, annee), serie(serie) {}

void Voiture::setSerie(std::string s) {
	serie = s;
}
std::string Voiture::getSerie() const {
	return serie;
}

std::string Voiture::getAllDetails() {
	return "Marque: " + getMarque() + ", Modele: " + getModele() + ", Serie: " + serie;
}

