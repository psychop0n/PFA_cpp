#ifndef SERVICE_H
#define SERVICE_H

#include <string>
#include <iostream>

class Service {
private:
    std::string nom;
    double prix;
public:
    Service(std::string nom, double prix);
    void setNom(std::string);
    std::string getNom() const;
    double getPrix() const;
    void setPrix(double);

    std::string getAllDetails() const;
    friend std::ostream& operator<<(std::ostream&, const Service&);
    friend Service operator+(Service&, Service&);
};

#endif  // SERVICE_H
