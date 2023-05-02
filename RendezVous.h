#ifndef RENDEZVOUS_H
#define RENDEZVOUS_H

#include <string>
#include <vector>
#include <iostream>

#include "Vehicule.h"
#include "Voiture.h"
#include "Client.h"
#include "Mecanicien.h"
#include "InstanceManager.h"

class RendezVous: public InstanceManager<RendezVous> {
private:
    std::string id;
    std::string m_date;
    std::string m_heure;
    Voiture m_vehicule;
    Client m_client;
    Mecanicien m_mecanicien;

public:
    RendezVous(std::string id, std::string date, std::string heure, Voiture vehicule, Client client, Mecanicien mecanicien);
    RendezVous(std::string id, std::string date, Voiture vehicule, Client client, Mecanicien mecanicien);
    RendezVous();
    ~RendezVous();

    void setId(std::string);
    std::string getId() const;
    void setDate(std::string);
    std::string getDate() const;
    void setHeure(std::string);
    std::string getHeure() const;
    void setVehicule(Voiture);
    Voiture getVehicule() const;
    void setClient(Client);
    Client getClient() const;
    void setMecanicien(Mecanicien);
    Mecanicien getMecanicien() const;

    std::string getAllDetails() const;
    friend std::ostream& operator<<(std::ostream&, const RendezVous&);
    friend std::istream& operator>>(std::istream&, RendezVous&);
};

#endif // RENDEZVOUS_H
