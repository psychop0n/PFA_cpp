#ifndef VOITURE_H
#define VOITURE_H

#include <string>
#include "Vehicule.h"

class Voiture : public Vehicule {
private:
    std::string serie;

public:
    Voiture(const std::string& marque, const std::string& modele, int annee, const std::string& serie);
    std::string getSerie() const;
};

#endif // VOITURE_H
