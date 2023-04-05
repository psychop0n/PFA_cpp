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
    cout << "Client 1: " << client1 << endl;
    cout << "Client 2: " << client2 << endl;

    // Voitures
    Voiture voiture1("Renault", "Clio 3", 2007, "100 TN 5000");
    Voiture voiture2("Peugeot", "407", 2011, "101 TN 5001");
    cout << "Voiture 1: " << voiture1.getAllDetails() << endl;
    cout << "Voiture 2: " << voiture2.getAllDetails() << endl;

    // Mecanicien
    Mecanicien mecanicien("Hamrouni", "Generaliste");
    cout << "Mecanicien: " << mecanicien << endl;

    // Services
    Service service1("Vidange", 50.00);
    Service service2("Vérification des freins", 25.00);
    Service service3("Rotation du pneu", 20.00);

    // Rendez Vous
    RendezVous appt1("2023-05-05", "10:00:00", &voiture1, &client1, &mecanicien);
    RendezVous appt2("2023-05-06", "10:00:00", &voiture1, &client1, &mecanicien);
    RendezVous appt3("2023-06-06", "10:00:00", &voiture2, &client2, &mecanicien);

    // Facture
    Facture bill("2023-04-07", &client1, { &appt1 }, { &service1 });
    // Detailles du facture
    cout << "----" << endl << bill.getAllDetails() << "----" << endl;

    // supprimer 1er rendez vous

    // ajout service et rendez-vous
    bill.AnnulerRendezVous(&appt1);
    bill.addRendezVous(&appt2);
    bill.addService(&service2);
    cout << "Apres annulation du rendez vous:" << endl << bill.getAllDetails() << "----" << endl;

    // Enregistrer dans le fichier
    std::string nom_fichier_facture = "facture_" + std::to_string(bill.getIdFacture()) + ".txt";
    bill.saveToFile(nom_fichier_facture);


    // Client 2:
    Facture bill2("2023-06-06", &client2, { &appt3 }, { &service3 });
    cout << "--------------------------------------------------" << endl << endl;
    cout << "----" << endl << bill2.getAllDetails() << "----" << endl;
    nom_fichier_facture = "facture_" + std::to_string(bill2.getIdFacture()) + ".txt";
    bill2.saveToFile(nom_fichier_facture);

}
