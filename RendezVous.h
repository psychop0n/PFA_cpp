#ifndef RENDEZVOUS_H
#define RENDEZVOUS_H

#include <string>
#include <vector>
#include <ctime>
#include <fstream>
#include <iostream>

#include "Vehicule.h"
#include "Client.h"
#include "Mecanicien.h"

class RendezVous {
public:
    RendezVous(std::tm date, std::tm heure, Vehicule* vehicule, Client* client, Mecanicien* mecanicien);
    RendezVous(std::tm date, Vehicule* vehicule, Client* client, Mecanicien* mecanicien);

    std::tm getDate() const;
    std::tm getHeure() const;
    Vehicule* getVehicule() const;
    Client* getClient() const;
    Mecanicien* getMecanicien() const;
    std::string getDetailsRendezVous() const;
    bool saveToFile(const std::string& filename);

private:
    std::tm m_date;
    std::tm m_heure;
    Vehicule* m_vehicule;
    Client* m_client;
    Mecanicien* m_mecanicien;
};

#endif // RENDEZVOUS_H
