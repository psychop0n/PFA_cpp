#ifndef VEHICULE_H
#define VEHICULE_H

#include <string>

class Vehicule {
private:
    std::string marque;
    std::string modele;
    int annee;

public:
    Vehicule(const std::string& marque, const std::string& modele, int annee);
    std::string getMarque() const;
    std::string getModele() const;
    int getAnnee() const;
};

#endif // VEHICULE_H
