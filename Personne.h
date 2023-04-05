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
