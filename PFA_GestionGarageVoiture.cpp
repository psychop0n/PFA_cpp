#include <iostream>
#include <vector>
#include "Client.h"
#include "Voiture.h"
#include "RendezVous.h"
#include "Service.h"
#include "Facture.h"

using namespace std;

int main() {
    // Clients
    Client client1("Rayen", "Manaa", "rayen.manaa12@gmail.com");
    Client client2("Seifeddine", "Massoudi", "seifeddine.massoudi@gmail.com");

    // Voitures
    Voiture voiture1("Renault", "Clio 3", 2007, "100TN5000");

    // Mecanicien
    Mecanicien mecanicien("Hamrouni", "general");

    // Services
    Service service1("Vidange", 50.00);
    Service service2("Vérification des freins", 25.00);
    Service service3("Rotation du pneu", 20.00);

    // Rendez Vous
    struct tm date;
    time_t now = time(0);
    localtime_s(&date, &now);
    RendezVous appt1(date, &voiture1, &client1, &mecanicien);
    RendezVous appt2(date, &voiture1, &client2, &mecanicien);

    // Liste des rendez-vous
    vector<RendezVous*> appts;
    appts.push_back(&appt1);
    appts.push_back(&appt2);

    // Facture
    Facture bill("2023-04-07", &client1, appts, { &service1, &service2, &service3 });

    // Detailles du facture
    cout << bill.getDetailsFacture() << endl;

    // Enregistrer dans le fichier
    for (auto const& a : appts) {
        a->saveToFile("appointments.txt");
    }
}
