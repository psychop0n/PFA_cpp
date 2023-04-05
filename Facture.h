#ifndef FACTURE_H
#define FACTURE_H

#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <stdexcept>

#include "Client.h"
#include "RendezVous.h"
#include "Service.h"

static int nbFactures;

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
	void setIdFacture(int id);
	int getIdFacture() const;
	void setDate(std::string date);
	std::string getDate() const;
	void setMontant(double montant);
	double getMontant() const;
	void setClient(Client* client);
	Client* getClient() const;
	int addRendezVous(RendezVous*);
	RendezVous* getRendezVous(int i);
	void AnnulerRendezVous(RendezVous*);
	void AnnulerRendezVous(std::string);
	int addService(Service*);
	Service* getService(int i);

	std::string getAllDetails() const;
	bool saveToFile(const std::string& filename);
};

#endif // FACTURE_H
