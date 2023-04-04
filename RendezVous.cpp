#include "RendezVous.h"


RendezVous::RendezVous(std::tm date, std::tm heure, Vehicule* vehicule, Client* client, Mecanicien* mecanicien)
    : m_date(date), m_heure(heure), m_vehicule(vehicule), m_client(client), m_mecanicien(mecanicien)
{
}

RendezVous::RendezVous(std::tm date, Vehicule* vehicule, Client* client, Mecanicien* mecanicien)
    : m_date(date), m_heure(date), m_vehicule(vehicule), m_client(client), m_mecanicien(mecanicien)
{
}

std::tm RendezVous::getDate() const
{
    return m_date;
}

std::tm RendezVous::getHeure() const
{
    return m_heure;
}

Vehicule* RendezVous::getVehicule() const
{
    return m_vehicule;
}

Client* RendezVous::getClient() const
{
    return m_client;
}

Mecanicien* RendezVous::getMecanicien() const
{
    return m_mecanicien;
}

std::string RendezVous::getDetailsRendezVous() const {
    return "Rendez-vous le pour le service avec le mecanicien \"" + m_mecanicien->getNom() + "\".";
}
bool RendezVous::saveToFile(const std::string& filename) {
    std::ofstream outputFile(filename, std::ios::out);
    if (outputFile.is_open()) {
        outputFile << m_vehicule->getMarque() << " " << m_vehicule->getModele() << "\n";
        outputFile << m_client->getNom() << "\n";
        outputFile.close();
        std::cout << "RendezVous has been saved to file " << filename << std::endl;
        return true;
    }
    else {
        std::cerr << "Unable to open file " << filename << " for writing" << std::endl;
        return false;
    }
}
