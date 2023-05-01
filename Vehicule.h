#ifndef VEHICULE_H
#define VEHICULE_H

#include <string>
#include "InstanceManager.h"

class Vehicule: public InstanceManager<Vehicule> {
private:
    std::string id;
    std::string marque;
    std::string modele;
    int annee;

public:
    Vehicule(const std::string& id, const std::string& marque, const std::string& modele, int annee);
    void setId(std::string);
    std::string getId() const;
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
