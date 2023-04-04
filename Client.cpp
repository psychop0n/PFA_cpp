#include "Client.h"

Client::Client(const std::string& nom, const std::string& adresse, const std::string& telephone, const std::string& email) : Personne(nom, adresse, telephone, email) {}

Client::Client(const std::string& nom, const std::string& adresse, const std::string& telephone) : Personne(nom, adresse, telephone) {}

Client::Client(const std::string& nom, const std::string& adresse) : Personne(nom, adresse) {}

const std::vector<Vehicule*>& Client::getVehicules() const {
	return vehicules;
}

void Client::ajouterVehicule(Vehicule* vehicule) {
	vehicules.push_back(vehicule);
}

