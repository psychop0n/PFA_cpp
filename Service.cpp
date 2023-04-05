#include "Service.h"

Service::Service(std::string nom, double prix) : nom(nom), prix(prix) {}

void Service::setNom(std::string n) {
	nom = n;
}
std::string Service::getNom() const {
	return nom;
}

void Service::setPrix(double p) {
	prix = p;
}
double Service::getPrix() const {
	return prix;
}

std::string Service::getAllDetails() const {
	return "Service: " + nom + ", Prix: " + std::to_string(prix);
}

std::ostream& operator<<(std::ostream& os, const Service& S) {
	os << "Nom: " << S.getNom() << ", ";
	os << "Prix: " << S.getPrix();
	return os;
}
