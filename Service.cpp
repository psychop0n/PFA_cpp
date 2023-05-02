#include "Service.h"

Service::Service(std::string id, std::string nom, double prix) : id(id), nom(nom), prix(prix) {}
Service::Service() : Service("", "", 0) {}

void Service::setId(std::string id)
{
	id = id;
}

std::string Service::getId() const
{
	return id;
}

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
	os << "- Service[id=" << S.getId() << "] | ";
	os << "Nom: " << S.getNom() << ", Prix: " << S.getPrix();
	return os;
}

std::istream& operator>>(std::istream& in, Service& S) {
	std::cout << std::endl;
	std::cout << "Saisir les donnees du service:" << std::endl;
	std::string s;
	S.setId(InstanceManager<Service>::getNextID());
	std::cout << "Nom: ";
	in >> s;
	S.setNom(s);
	std::cout << "Prix: ";
	in >> s;
	S.setPrix(std::stod(s));
	return in;
}

Service operator+(Service& S1, Service& S2) {
	Service S(InstanceManager<Service>::getNextID(), S1.getNom() + ", " + S2.getNom(), S1.getPrix() + S2.getPrix());
	return S;
}

