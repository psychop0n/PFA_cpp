#ifndef FACTURE_H
#define FACTURE_H

#include <string>
#include <vector>

#include "Client.h"
#include "RendezVous.h"
#include "Service.h"

class Facture {
private:
	int idFacture;
	std::string date;
	double montant;
	Client* client;
	std::vector<RendezVous*> rendezVous;
	std::vector<Service*> services;

public:
	Facture(std::string date, Client* client, std::vector<RendezVous*> rendezVous, std::vector<Service*> services);
	int getIdFacture() const;
	void setIdFacture(int id);
	std::string getDate() const;
	void setDate(std::string date);
	double getMontant() const;
	void setMontant(double montant);
	Client* getClient() const;
	void setClient(Client* client);
	std::string getDetailsFacture() const;
};

#endif // FACTURE_H
