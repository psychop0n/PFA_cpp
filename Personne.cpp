#include "Personne.h"

Personne::Personne(const std::string& nom, const std::string& adresse, const std::string& telephone, const std::string& email)
	: nom(nom), adresse(adresse), telephone(telephone), email(email)
{
}

Personne::Personne(const std::string& nom, const std::string& adresse, const std::string& telephone)
	: Personne(nom, adresse, telephone, "")
{
}

Personne::Personne(const std::string& nom, const std::string& adresse)
	: Personne(nom, adresse, "", "")
{
}

Personne::Personne(const std::string& nom)
	: Personne(nom, "", "", "")
{
}

std::string Personne::getNom() const
{
	return nom;
}

std::string Personne::getAdresse() const
{
	return adresse;
}

std::string Personne::getTelephone() const
{
	return telephone;
}

std::string Personne::getEmail() const
{
	return email;
}

std::ostream& operator<<(std::ostream& os, const Personne& personne) {
	os << "Nom: " << personne.getNom() << ", ";
	os << "Age: " << personne.getEmail();
	return os;
}
