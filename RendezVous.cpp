#include "RendezVous.h"


RendezVous::RendezVous(std::string id, std::string date, std::string heure, Voiture vehicule, Client client, Mecanicien mecanicien)
	: id(id), m_date(date), m_heure(heure), m_vehicule(vehicule), m_client(client), m_mecanicien(mecanicien)
{
}

RendezVous::RendezVous(std::string id, std::string date, Voiture vehicule, Client client, Mecanicien mecanicien)
	: id(id), m_date(date), m_heure(date), m_vehicule(vehicule), m_client(client), m_mecanicien(mecanicien)
{
}
RendezVous::RendezVous()
	: RendezVous("", "", *new Voiture, *new Client, *new Mecanicien)
{
}

RendezVous::~RendezVous() {
	std::cout << "Le rendez vous de date " << m_date << " a ete anulee." << std::endl;
}

void RendezVous::setId(std::string id)
{
	id = id;
}

std::string RendezVous::getId() const
{
	return id;
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

void RendezVous::setVehicule(Voiture V)
{
	m_vehicule = V;
}

Voiture RendezVous::getVehicule() const
{
	return m_vehicule;
}

void RendezVous::setClient(Client C)
{
	m_client = C;
}

Client RendezVous::getClient() const
{
	return m_client;
}

void RendezVous::setMecanicien(Mecanicien M)
{
	m_mecanicien = M;
}

Mecanicien RendezVous::getMecanicien() const
{
	return m_mecanicien;
}

std::string RendezVous::getAllDetails() const {
	return "Rendez-vous le " + m_date + " a " + m_heure + " pour la vehicule \"" + m_vehicule.getModele() + "\" avec le mecanicien \"" + m_mecanicien.getNom() + "\".";
}

std::istream& operator>>(std::istream& in, RendezVous& rv) {
	std::cout << std::endl;
	std::cout << "Saisir les donnees du client:" << std::endl;
	std::string s;

	rv.setId(InstanceManager<RendezVous>::getNextID());
	std::cout << "Date: ";
	in >> s;
	rv.setDate(s);

	std::cout << "---" << std::endl;
	std::string id;
	InstanceManager<Client>::printAll();
	std::cout << "Saisir l'ID du client: ";
	in >> id;
	Client c = InstanceManager<Client>::get(id);
	rv.setClient(c);

	std::cout << "---" << std::endl;
	InstanceManager<Voiture>::printAll();
	std::cout << "Saisir l'ID du vehicule: ";
	in >> id;
	Voiture v = InstanceManager<Voiture>::get(id);
	rv.setVehicule(v);

	std::cout << "---" << std::endl;
	InstanceManager<Mecanicien>::printAll();
	std::cout << "Saisir l'ID du mecanicien: ";
	in >> id;
	Mecanicien m = InstanceManager<Mecanicien>::get(id);
	rv.setMecanicien(m);

	return in;
}

std::ostream& operator<<(std::ostream& os, const RendezVous& R) {
	os << "- RendezVous[id=" << R.getId() << "] | ";
	os << "Date: " << R.getDate() << ", ";
	os << "Client: " << R.getClient().getNom() << ", ";
	os << "Vehicule: " << R.getVehicule().getModele() << ", ";
	os << "Mecanicien: " << R.getMecanicien().getNom();

	return os;
}
