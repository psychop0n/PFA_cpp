#include "Facture.h"

Facture::Facture(std::string date, Client* client, std::vector<RendezVous*> rendezVous, std::vector<Service*> services) {
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

std::string Facture::getDetailsFacture() const {
	std::string details = "Facture #" + std::to_string(idFacture) + " du " + date + " pour " + client->getNom() + "\n\n";
	details += "Rendez-vous :\n";
	//for (RendezVous* rdv : rendezVous) {
	//	details += "- " + rdv->getDetailsRendezVous() + "\n";
	//}
	//details += "\nServices :\n";
	//for (Service* service : services) {
	//	details += "- " + service->getDetailsService() + "\n";
	//}
	details += "\nMontant total : " + std::to_string(montant) + " EUR\n";
	return details;
}
