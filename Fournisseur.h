#ifndef FOURNISSEUR_H
#define FOURNISSEUR_H

#include <string>

class Fournisseur {
private:
	std::string nom;
	std::string adresse;
	std::string telephone;

public:
	Fournisseur(std::string nom, std::string adresse, std::string telephone);
	std::string getNom() const;
	void setNom(std::string);
	std::string getAdresse() const;
	void setAdresse(std::string);
	std::string getTelephone() const;
	void setTelephone(std::string);
};

#endif // FOURNISSEUR_H
