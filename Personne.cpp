#include "Personne.h"

Personne::Personne(const std::string& id, const std::string& nom, const std::string& adresse, const std::string& telephone, const std::string& email)
	: id(id), nom(nom), adresse(adresse), telephone(telephone), email(email)
{

}

Personne::Personne(const std::string& id,  const std::string& nom, const std::string& adresse, const std::string& telephone)
	: Personne(id, nom, adresse, telephone, "")
{
}

Personne::Personne(const std::string& id,  const std::string& nom, const std::string& adresse)
	: Personne(id, nom, adresse, "", "")
{
}

Personne::Personne(const std::string& id, const std::string& nom)
	: Personne(id, nom, "", "", "")
{
}

void Personne::setId(std::string i) {
	id = i;
}
std::string Personne::getId() const {
	return id;
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
	os << "Personne| ID: " << personne.getId() << ", Nom: " << personne.getNom() << ".";
	return os;
}
