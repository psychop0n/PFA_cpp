#include "Facture.h"

Facture::Facture(std::string date, Client* client, std::vector<RendezVous*> rendezVous, std::vector<Service*> services) {
	this->idFacture = ++nbFactures;
	this->date = date;
	this->client = client;
	this->rendezVous = rendezVous;
	this->services = services;

	double totalMontant = 0;
	for (Service* service : services) {
		totalMontant += service->getPrix();
	}
	this->montant = totalMontant;
}

int Facture::getIdFacture() const {
	return idFacture;
}

void Facture::setIdFacture(int id) {
	idFacture = id;
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

Client* Facture::getClient() const {
	return client;
}

void Facture::setClient(Client* client) {
	this->client = client;
}

RendezVous* Facture::getRendezVous(int i) {
	return this->rendezVous[i];
}

int Facture::addRendezVous(RendezVous* R) {
	int i = this->rendezVous.size();
	this->rendezVous.push_back(R);
	return i;
}

void Facture::AnnulerRendezVous(RendezVous* R) {
	for (auto P = this->rendezVous.begin(); P != this->rendezVous.end(); P++)
	{
		if (R == (*P)) {
			this->rendezVous.erase(P);
			std::cout << "Le rendez vous de date " << R->getDate() << " a ete anulee." << std::endl;
			return;
		}
	}
}

void Facture::AnnulerRendezVousAvecDate(std::string date) {
	for (auto P = this->rendezVous.begin(); P != this->rendezVous.end(); P++)
	{
		if (date == (*P)->getDate()) {
			this->rendezVous.erase(P);
			std::cout << "Le rendez vous de date " << date << " a ete anulee." << std::endl;
			return;
		}
	}
}

Service* Facture::getService(int i) {
	return this->services[i];
}

int Facture::addService(Service* F) {
	int i = this->services.size();
	this->services.push_back(F);
	this->montant += F->getPrix();
	return i;
}

std::string Facture::getAllDetails() const {
	std::string details = "Facture #" + std::to_string(idFacture) + " du " + date + " pour " + client->getNom() + "\n\n";
	details += "Rendez-vous :\n";
	for (RendezVous* rdv : rendezVous) {
		details += "- " + rdv->getAllDetails() + "\n";
	}
	details += "\nServices :\n";
	for (Service* service : services) {
		details += "- " + service->getAllDetails() + "\n";
	}
	details += "\nMontant total : " + std::to_string(montant) + " TND\n";
	return details;
}

bool Facture::saveToFile(const std::string& filename) {
	std::ofstream outputFile(filename, std::ios::out);
	if (outputFile.is_open()) {
		outputFile << this->getAllDetails();
		outputFile.close();
		std::cout << "Facture has been saved to file " << filename << std::endl;
		return true;
	}
	else {
		std::cerr << "Unable to open file " << filename << " for writing" << std::endl;
		return false;
	}
}
