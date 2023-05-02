#include "Client.h"

Client::Client(std::string id, const std::string& nom, const std::string& adresse, const std::string& telephone, const std::string& email) : Personne(id, nom, adresse, telephone, email) {}

Client::Client(std::string id, const std::string& nom, const std::string& adresse, const std::string& telephone) : Personne(id, nom, adresse, telephone) {}

Client::Client(std::string id, const std::string& nom, const std::string& adresse) : Personne(id, nom, adresse) {}

Client::Client() : Personne() {}

const std::vector<Vehicule*>& Client::getVehicules() const {
	return vehicules;
}

void Client::ajouterVehicule(Vehicule* vehicule) {
	vehicules.push_back(vehicule);
}

std::ostream& operator<<(std::ostream& os, const Client& client) {
	os << "- Client[id=" << client.getId() << "] | ";
	os << "Nom: " << client.getNom() << ", Adresse: " << client.getAdresse();
	os << ", Telephone: " << client.getTelephone() << ", Email: " << client.getEmail();

	return os;
}

std::istream& operator>>(std::istream& in, Client& client) {
	std::cout << std::endl;
	std::cout << "Saisir les donnees du client:" << std::endl;
	std::string s;
	
	client.setId(InstanceManager<Client>::getNextID());
	std::cout << "Nom: ";
	in >> s;
	client.setNom(s);
	std::cout << "Adresse: ";
	in >> s;
	client.setAdresse(s);
	std::cout << "Telephone: ";
	in >> s;
	client.setTelephone(s);
	std::cout << "Email: ";
	in >> s;
	client.setEmail(s);


	return in;
}
