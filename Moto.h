#ifndef MOTO_H
#define MOTO_H

#include "Vehicule.h"

class Moto : public Vehicule {
public:
    Moto(const std::string& marque, const std::string& modele, int annee);
};

#endif // MOTO_H
