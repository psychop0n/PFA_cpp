#ifndef RENDEZVOUS_H
#define RENDEZVOUS_H

#include <string>
#include <vector>
#include <iostream>

#include "Vehicule.h"
#include "Client.h"
#include "Mecanicien.h"

class RendezVous {
private:
    std::string m_date;
    std::string m_heure;
    Vehicule* m_vehicule;
    Client* m_client;
    Mecanicien* m_mecanicien;

public:
    RendezVous(std::string date, std::string heure, Vehicule* vehicule, Client* client, Mecanicien* mecanicien);
    RendezVous(std::string date, Vehicule* vehicule, Client* client, Mecanicien* mecanicien);
    ~RendezVous();

    void setDate(std::string);
    std::string getDate() const;
    void setHeure(std::string);
    std::string getHeure() const;
    void setVehicule(Vehicule *);
    Vehicule* getVehicule() const;
    void setClient(Client*);
    Client* getClient() const;
    void setMecanicien(Mecanicien*);
    Mecanicien* getMecanicien() const;

    std::string getAllDetails() const;
    friend std::ostream& operator<<(std::ostream&, const RendezVous&);
};

#endif // RENDEZVOUS_H
