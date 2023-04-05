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
    void setMarque(std::string);
    std::string getMarque() const;
    void setModele(std::string);
    std::string getModele() const;
    void setAnnee(int);
    int getAnnee() const;
    // abstract
    virtual std::string getAllDetails() = 0;
};

#endif // VEHICULE_H
