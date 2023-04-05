#ifndef CLIENT_H
#define CLIENT_H

#include <vector>
#include "Personne.h"
#include "Vehicule.h"

class Client : public Personne {
private:
    std::vector<Vehicule*> vehicules;

public:
    Client(const std::string& nom, const std::string& adresse, const std::string& telephone, const std::string& email);
    Client(const std::string& nom, const std::string& adresse, const std::string& telephone);
    Client(const std::string& nom, const std::string& adresse);
    const std::vector<Vehicule*>& getVehicules() const;
    void ajouterVehicule(Vehicule*);

    friend std::ostream& operator<<(std::ostream&, const Client&);
};

#endif // CLIENT_H
