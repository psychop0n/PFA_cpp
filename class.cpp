#include <iostream>
#include<string>
#include<vector>
#include "Date.h" // Import de la classe Date
#include "Client.h" // Import de la classe Client
#include "RendezVous.h" // Import de la classe RendezVous
#include "Services.h" // Import de la classe Services
#include "Reparation.h" // Import de la classe Reparation
using namespace std;

// comments in line :67 , 85


void Date::Date(int day = 1, int month = 1, int year = 2023){
    this->day = day;
    this->month = month;
    this->year = year;    

} 

bool Date::isValid(){
            // Vérifie si la date est valide
        if (day < 1 || day > 31 || month < 1 || month > 12 || year < 0) {
            return false;
        }
        if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) {
            return false;
        }
        if (month == 2) {
            if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
                if (day > 29) {
                    return false;
                }
            } else {
                if (day > 28) {
                    return false;
                }
            }
        }
        return true;
}

void Personne::Personne(string nom  , string adresse , string telephone , string email ){
    this->nom = nom;
    this->adresse = adresse;
    this->telephone = telephone;    
    this->email = email;
}
void Personne::Personne(string nom  , string adresse , string telephone ){
    this->nom = nom;
    this->adresse = adresse;
    this->telephone = telephone;    

}    
void Personne::Personne(string nom  , string adresse){
    this->nom = nom;
    this->adresse = adresse;
    
}

void Personne::afficherPersonne(){
    cout << nom << " " << prenom << endl;
    cout << adresse << endl;
    cout << "Tél: " << telephone << endl;

}

void Client::Client(string nom  , string adresse , string telephone , string email ):{
    // for u boss rayen

}

void Client::afficherClient() {
    afficherPersonne();
    cout << "Email: " << getEmail() << endl;
}

void Client::ajoutervéhicule(Vehicule vehicule){
    if (nbVehicules < MAX_VEHICULES) {
        vehicules[nbVehicules] = vehicule;
        nbVehicules++;
        }
}

void Mecanicien::afficherRendezVous(){
    cout << "Rendez-vous pour le mécanicien " << getNom() << " " << getPrenom() << ":" << endl;
    cout << "La date est" << rendezvous.getdate() << "temps : " << rendezvous.gettemps() << endl; // this line is a bit suspucious **

} 

void Service::Service(string nom_service , double prix){
    this->nom_service = nom_service;
    this->prix = prix;
}

void Srevice::afficherService(){
    cout << "Nom du service : " << nom << endl;
    cout << "Prix : " << prix << " euros" << endl;  
}

void RendezVous::RendezVous(Date date , Time temps , Client client , Mecancien mecancien){
    this->date = date;
    this->client = client;
    this->temps = temps;
    this->mecancien = mecancien;
}



void Facture::Facture(Date date, Client client, RendezVous rendezvous, Services services, int idfacture, double montant){
    this->date = date;
    this->client = client;
    this->rendezvous = rendezvous;
    this->services = services;
    this->idfacture = idfacture;
    this->montant = montant;
    
}

string Facture::getDetailsFacture(){
        string details = "Facture #" + getIdfacture()  + "\n";
        details += "Date : " + date.AfficherDate() + "\n";
        details += "Client : " + client.getNom() + " " + client.getPrenom() + "\n";
        details += "Services : " + services.afficherService() + "\n";
        details += "Montant : " + getMontant() + " euros\n";
        return details;

}