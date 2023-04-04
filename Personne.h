#ifndef PERSONNE_H
#define PERSONNE_H

#include <string>
#include <iostream>

class Personne {
private:
    std::string nom;
    std::string adresse;
    std::string telephone;
    std::string email;

public:
    Personne(const std::string& nom, const std::string& adresse, const std::string& telephone, const std::string& email);
    Personne(const std::string& nom, const std::string& adresse, const std::string& telephone);
    Personne(const std::string& nom, const std::string& adresse);
    Personne(const std::string& nom);
    std::string getNom() const;
    std::string getAdresse() const;
    std::string getTelephone() const;
    std::string getEmail() const;
};

#endif // PERSONNE_H
