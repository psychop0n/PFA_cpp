#include "Facture.h"

Facture::Facture(std::string id, std::string date, Client client, std::vector<RendezVous> rendezVous, std::vector<Service> services) {
	this->id = id;
	this->date = date;
	this->client = client;
	this->rendezVous = rendezVous;
	this->services = services;

	double totalMontant = 0;
	for (Service service : services) {
		totalMontant += service.getPrix();
	}
	this->montant = totalMontant;
}

Facture::Facture() {
	this->montant = 0;
}

std::string Facture::getId() const {
	return id;
}

void Facture::setId(std::string id) {
	id = id;
}

std::string Facture::getDate() const {
	return date;
}

void Facture::setDate(std::string date) {
	this->date = date;
}

double Facture::getMontant() const {
	return montant;
}

void Facture::setMontant(double montant) {
	this->montant = montant;
}

Client Facture::getClient() const {
	return client;
}

void Facture::setClient(Client client) {
	this->client = client;
}

RendezVous Facture::getRendezVous(int i) {
	return this->rendezVous[i];
}

std::vector<Service> Facture::getServices() const {
		return this->services;
}

int Facture::addRendezVous(RendezVous R) {
	int i = int(this->rendezVous.size());
	this->rendezVous.push_back(R);
	return i;
}

void Facture::AnnulerRendezVous(RendezVous R) {
	for (auto P = this->rendezVous.begin(); P != this->rendezVous.end(); P++)
	{
		if (R.getId() == (*P).getId()) {
			this->rendezVous.erase(P);
			std::cout << "Le rendez vous de date " << R.getDate() << " a ete anulee." << std::endl;
			return;
		}
	}
}

void Facture::AnnulerRendezVous(std::string date) {
	for (auto P = this->rendezVous.begin(); P != this->rendezVous.end(); P++)
	{
		if (date == (*P).getDate()) {
			this->rendezVous.erase(P);
			return;
		}
	}
}

Service Facture::getService(int i) {
	return this->services[i];
}

int Facture::addService(Service F) {
	int i = int(this->services.size());
	this->services.push_back(F);
	this->montant += F.getPrix();
	return i;
}

std::string Facture::getAllDetails() const {
	std::string details = "Facture #" + id + " du " + date + " pour " + client.getNom() + "\n\n";
	details += "Rendez-vous :\n";
	for (RendezVous rdv : rendezVous) {
		details += "- " + rdv.getAllDetails() + "\n";
	}
	details += "\nServices :\n";
	for (Service service : services) {
		details += "- " + service.getAllDetails() + "\n";
	}
	details += "\nMontant total : " + std::to_string(montant) + " TND\n";
	return details;
}

bool Facture::saveToFile(const std::string& filename) {
	std::ofstream outputFile(filename, std::ios::out);
	if (outputFile.is_open()) {
		outputFile << this->getAllDetails();
		outputFile.close();
		std::cout << "Facture enregistree dans le fichier " << filename << std::endl;
		return true;
	}
	else {
		std::cerr << "Unable to open file " << filename << " for writing" << std::endl;
		throw "Unable to open file " + filename + " for writing";
	}
}

std::ostream& operator<<(std::ostream& os, const Facture& F) {
	os << "- Facture[id=" << F.getId() << "] | ";
	os << "Date: " << F.getDate() << ", ";
	os << "Montant: " << F.getMontant() << " TND";
	os << "Client: " << F.getClient().getNom() << std::endl;
	// Show services
	for (Service service : F.getServices()) {
		os << "  ";
		os << service << std::endl;
	}
	return os;
}

std::istream& operator>>(std::istream& in, Facture& F) {
	std::cout << std::endl;
	std::cout << "Saisir les donnees de la facture:" << std::endl;
	std::string s;
	F.setId(InstanceManager<Facture>::getNextID());
	std::cout << "Date: ";
	in >> s;
	F.setDate(s);
	std::cout << "---" << std::endl;
	InstanceManager<Client>::printAll();
	std::cout << "Saisir l'ID du client: ";
	in >> s;
	Client c = InstanceManager<Client>::get(s);
	F.setClient(c);
	std::cout << "---" << std::endl;
	std::cout << "Saisir les donnees des rendez-vous:" << std::endl;
	std::cout << "Combien de rendez-vous ? ";
	int n;
	in >> n;
	InstanceManager<RendezVous>::printAll();
	for (int i = 0; i < n; i++) {
		std::cout << "Saisir l'ID du rendez-vous numero " << i << ": ";
		in >> s;
		RendezVous rv = InstanceManager<RendezVous>::get(s);
		F.addRendezVous(rv);
	}
	std::cout << "---" << std::endl;
	std::cout << "Saisir les donnees des services:" << std::endl;
	std::cout << "Combien de services ? ";
	in >> n;
	for (int i = 0; i < n; i++) {
		Service s;
		in >> s;
		F.addService(s);
	}
	return in;
}
