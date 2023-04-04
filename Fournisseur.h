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
	std::string getAdresse() const;
	std::string getTelephone() const;
};

#endif // FOURNISSEUR_H
