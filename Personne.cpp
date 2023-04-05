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

void Personne::setNom(std::string n) {
	nom = n;
}
std::string Personne::getNom() const {
	return nom;
}

void Personne::setAdresse(std::string a) {
	adresse = a;
}
std::string Personne::getAdresse() const {
	return adresse;
}

void Personne::setTelephone(std::string t) {
	telephone = t;
}
std::string Personne::getTelephone() const {
	return telephone;
}

void Personne::setEmail(std::string e) {
	email = e;
}
std::string Personne::getEmail() const
{
	return email;
}

std::ostream& operator<<(std::ostream& os, const Personne& personne) {
	os << "Nom: " << personne.getNom() << ", ";
	return os;
}
