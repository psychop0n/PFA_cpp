#include "Mecanicien.h"

Mecanicien::Mecanicien(std::string nom, std::string adresse, std::string telephone, std::string email, std::string specialite)
	: Personne(nom, adresse, telephone, email), specialite(specialite) {}

Mecanicien::Mecanicien(std::string nom, std::string adresse, std::string telephone, std::string specialite)
	: Personne(nom, adresse, telephone), specialite(specialite) {}

Mecanicien::Mecanicien(std::string nom, std::string specialite)
	: Personne(nom), specialite(specialite) {}

void Mecanicien::setSpecialite(std::string s)
{
	specialite = s;
}
std::string Mecanicien::getSpecialite() const {
	return specialite;
}
