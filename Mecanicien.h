#ifndef MECANICIEN_H
#define MECANICIEN_H

#include <string>
#include <vector>
#include "Personne.h"

class Mecanicien : public Personne {
private:
    std::string specialite;

public:
    Mecanicien(std::string, std::string nom, std::string adresse, std::string telephone, std::string email, std::string specialite);
    Mecanicien(std::string, std::string nom, std::string adresse, std::string telephone, std::string specialite);
    Mecanicien(std::string, std::string nom, std::string specialite);
    void setSpecialite(std::string);
    std::string getSpecialite() const;
};

#endif  // MECANICIEN_H
