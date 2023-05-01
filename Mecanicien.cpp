#include "Mecanicien.h"

Mecanicien::Mecanicien(std::string id, std::string nom, std::string adresse, std::string telephone, std::string email, std::string specialite)
	: Personne(id, nom, adresse, telephone, email), specialite(specialite) {}

Mecanicien::Mecanicien(std::string id, std::string nom, std::string adresse, std::string telephone, std::string specialite)
	: Personne(id, nom, adresse, telephone), specialite(specialite) {}

Mecanicien::Mecanicien(std::string id, std::string nom, std::string specialite)
	: Personne(id, nom), specialite(specialite) {}

void Mecanicien::setSpecialite(std::string s)
{
	specialite = s;
}
std::string Mecanicien::getSpecialite() const {
	return specialite;
}
