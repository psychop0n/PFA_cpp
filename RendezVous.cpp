#include "RendezVous.h"


RendezVous::RendezVous(std::string date, std::string heure, Vehicule* vehicule, Client* client, Mecanicien* mecanicien)
	: m_date(date), m_heure(heure), m_vehicule(vehicule), m_client(client), m_mecanicien(mecanicien)
{
}

RendezVous::RendezVous(std::string date, Vehicule* vehicule, Client* client, Mecanicien* mecanicien)
	: m_date(date), m_heure(date), m_vehicule(vehicule), m_client(client), m_mecanicien(mecanicien)
{
}

RendezVous::~RendezVous() {
	std::cout << "Le rendez vous de date " << m_date << " a ete anulee." << std::endl;
}

void RendezVous::setDate(std::string D)
{
	m_date = D;
}

std::string RendezVous::getDate() const
{
	return m_date;
}

void RendezVous::setHeure(std::string HH)
{
	m_heure = HH;
}

std::string RendezVous::getHeure() const
{
	return m_heure;
}

void RendezVous::setVehicule(Vehicule* V)
{
	m_vehicule = V;
}

Vehicule* RendezVous::getVehicule() const
{
	return m_vehicule;
}

void RendezVous::setClient(Client* C)
{
	m_client = C;
}

Client* RendezVous::getClient() const
{
	return m_client;
}

void RendezVous::setMecanicien(Mecanicien* M)
{
	m_mecanicien = M;
}

Mecanicien* RendezVous::getMecanicien() const
{
	return m_mecanicien;
}

std::string RendezVous::getAllDetails() const {
	return "Rendez-vous le " + m_date + " à " + m_heure + " pour la vehicule \"" + m_vehicule->getModele() + "\" avec le mecanicien \"" + m_mecanicien->getNom() + "\".";
}

std::ostream& operator<<(std::ostream& os, const RendezVous& R) {
	os << "Date: " << R.getDate() << ", ";
	os << "Client: " << R.getClient()->getNom() << ", ";
	os << "Vehicule: " << R.getVehicule()->getModele() << ", ";
	os << "Mecanicien: " << R.getMecanicien()->getNom();
	return os;
}
