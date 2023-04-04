#include "Service.h"

Service::Service(std::string nom, double prix) : nom(nom), prix(prix) {}

std::string Service::getNom() const {
	return nom;
}

double Service::getPrix() const {
	return prix;
}

