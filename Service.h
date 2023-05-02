#ifndef SERVICE_H
#define SERVICE_H

#include <string>
#include <iostream>
#include "InstanceManager.h"

class Service: public InstanceManager<Service> {
private:
    std::string id;
    std::string nom;
    double prix;
public:
    Service(std::string id, std::string nom, double prix);
    Service();
    void setId(std::string);
    std::string getId() const;
    void setNom(std::string);
    std::string getNom() const;
    double getPrix() const;
    void setPrix(double);

    std::string getAllDetails() const;
    friend std::ostream& operator<<(std::ostream&, const Service&);
    friend std::istream& operator>>(std::istream&, Service&);
    friend Service operator+(Service&, Service&);
};

#endif  // SERVICE_H
