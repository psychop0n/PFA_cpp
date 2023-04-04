#ifndef SERVICE_H
#define SERVICE_H

#include <string>

class Service {
private:
    std::string nom;
    double prix;
public:
    Service(std::string nom, double prix);
    std::string getNom() const;
    double getPrix() const;
};

#endif  // SERVICE_H
