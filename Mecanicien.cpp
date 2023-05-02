#include "Mecanicien.h"

Mecanicien::Mecanicien(std::string id, std::string nom, std::string adresse, std::string telephone, std::string email, std::string specialite)
	: Personne(id, nom, adresse, telephone, email), specialite(specialite) {}

Mecanicien::Mecanicien(std::string id, std::string nom, std::string adresse, std::string telephone, std::string specialite)
	: Personne(id, nom, adresse, telephone), specialite(specialite) {}

Mecanicien::Mecanicien(std::string id, std::string nom, std::string specialite)
	: Personne(id, nom), specialite(specialite) {}

Mecanicien::Mecanicien()
	: Personne("", ""), specialite("") {}

void Mecanicien::setSpecialite(std::string s)
{
	specialite = s;
}
std::string Mecanicien::getSpecialite() const {
	return specialite;
}

std::ostream& operator<<(std::ostream& os, const Mecanicien& mecanicien) {
	os << "- Mecanicien[id=" << mecanicien.getId() << "] | ";
	os << "Nom: " << mecanicien.getNom() << ", Adresse: " << mecanicien.getAdresse();
	os << ", Telephone: " << mecanicien.getTelephone() << ", Email: " << mecanicien.getEmail();
	os << ", Specialite: " << mecanicien.getSpecialite();
	return os;
}

std::istream& operator>>(std::istream& in, Mecanicien& mecanicien) {
	std::cout << std::endl;
	std::cout << "Saisir les donnees du mecanicien:" << std::endl;
	std::string s;
	mecanicien.setId(InstanceManager<Mecanicien>::getNextID());
	std::cout << "Nom: ";
	in >> s;
	mecanicien.setNom(s);
	std::cout << "Adresse: ";
	in >> s;
	mecanicien.setAdresse(s);
	std::cout << "Telephone: ";
	in >> s;
	mecanicien.setTelephone(s);
	std::cout << "Email: ";
	in >> s;
	mecanicien.setEmail(s);
	std::cout << "Specialite: ";
	in >> s;
	mecanicien.setSpecialite(s);
	
	return in;
;}
