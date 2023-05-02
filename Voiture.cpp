#include "Voiture.h"

Voiture::Voiture(const std::string& id, const std::string& marque, const std::string& modele, int annee, const std::string& serie)
	: Vehicule(id, marque, modele, annee), serie(serie) {}

Voiture::Voiture()
	: Vehicule("", "", "", 0), serie("") {}

void Voiture::setSerie(std::string s) {
	serie = s;
}
std::string Voiture::getSerie() const {
	return serie;
}

std::string Voiture::getAllDetails() {
	return "Marque: " + getMarque() + ", Modele: " + getModele() + ", Serie: " + serie;
}

std::ostream& operator<<(std::ostream& os, const Voiture& V) {
	os << "- Voiture[id=" << V.getId() << "] | ";
	os << "Marque: " << V.getMarque() << ", Modele: " << V.getModele();
	os << ", Serie: " << V.getSerie();

	return os;
}

std::istream& operator>>(std::istream& in, Voiture& V) {
	std::cout << std::endl;
	std::cout << "Saisir les donnees du client:" << std::endl;
	std::string s;

	V.setId(InstanceManager<Voiture>::getNextID());
	std::cout << "Marque: ";
	in >> s;
	V.setMarque(s);
	std::cout << "Modele: ";
	in >> s;
	V.setModele(s);
	std::cout << "Serie: ";
	in >> s;
	V.setSerie(s);

	return in;
}
