#include "Fournisseur.h"

Fournisseur::Fournisseur(std::string nom, std::string adresse, std::string telephone)
	: nom(nom), adresse(adresse), telephone(telephone) {}

std::string Fournisseur::getNom() const {
	return nom;
}

std::string Fournisseur::getAdresse() const {
	return adresse;
}

std::string Fournisseur::getTelephone() const {
	return telephone;
}



