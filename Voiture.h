#ifndef VOITURE_H
#define VOITURE_H

#include <string>
#include <iostream>
#include "Vehicule.h"

class Voiture : public Vehicule {
private:
    std::string serie;

public:
    Voiture(const std::string& id, const std::string& marque, const std::string& modele, int annee, const std::string& serie);
    Voiture();
    void setSerie(std::string);
    std::string getSerie() const;

    std::string getAllDetails();
    friend std::ostream& operator<<(std::ostream&, const Voiture&);
    friend std::istream& operator>>(std::istream&, Voiture&);
};

#endif // VOITURE_H
