#include "Fournisseur.h"

Fournisseur::Fournisseur(std::string nom, std::string adresse, std::string telephone)
	: nom(nom), adresse(adresse), telephone(telephone) {}

void Fournisseur::setNom(std::string n) {
	nom = n;
}
std::string Fournisseur::getNom() const {
	return nom;
}

void Fournisseur::setAdresse(std::string a) {
	adresse = a;
}
std::string Fournisseur::getAdresse() const {
	return adresse;
}

void Fournisseur::setTelephone(std::string t) {
	telephone = t;
}
std::string Fournisseur::getTelephone() const {
	return telephone;
}



