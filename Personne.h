#ifndef PERSONNE_H
#define PERSONNE_H

#include <string>
#include <iostream>
#include "InstanceManager.h"

class Personne: public InstanceManager<Personne> {
private:
    std::string id;
    std::string nom;
    std::string adresse;
    std::string telephone;
    std::string email;

public:
    Personne(const std::string& id, const std::string& nom, const std::string& adresse, const std::string& telephone, const std::string& email);
    Personne(const std::string& id, const std::string& nom, const std::string& adresse, const std::string& telephone);
    Personne(const std::string& id, const std::string& nom, const std::string& adresse);
    Personne(const std::string& id, const std::string& nom);
    void setId(std::string);
    std::string getId() const;
    void setNom(std::string);
    std::string getNom() const;
    void setAdresse(std::string);
    std::string getAdresse() const;
    void setTelephone(std::string);
    std::string getTelephone() const;
    void setEmail(std::string);
    std::string getEmail() const;

    friend std::ostream& operator<<(std::ostream&, const Personne&);
};

#endif // PERSONNE_H
