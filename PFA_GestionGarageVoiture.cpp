#include <iostream>
#include <vector>

#include "Client.h"
#include "Voiture.h"
#include "RendezVous.h"
#include "Service.h"
#include "Mecanicien.h"
#include "Facture.h"
#include "InstanceManager.h"

void scenario() {
    //Client c(InstanceManager<Client>::getNextID(), "Rayen", "Manaa", "rayen.manaa12@gmail.com");
    //InstanceManager<Client>::add(c);
    //c = *new Client(InstanceManager<Client>::getNextID(), "Seifeddine", "Massoudi", "seifeddine.massoudi@gmail.com");
    //InstanceManager<Client>::add(c);

    //std::cout << "Client 1: " << InstanceManager<Client>::getByIndex(0) << std::endl;
    //std::cout << "Client 2: " << InstanceManager<Client>::getByIndex(1) << std::endl;

    //// Voitures
    //Voiture v(InstanceManager<Voiture>::getNextID(), "Renault", "Clio 3", 2007, "100 TN 5000");
    //InstanceManager<Voiture>::add(v);
    //v = *new Voiture(InstanceManager<Voiture>::getNextID(), "Peugeot", "407", 2011, "101 TN 5001");
    //InstanceManager<Voiture>::add(v);
    //std::cout << "Voiture 1: " << InstanceManager<Voiture>::getByIndex(0).getAllDetails() << std::endl;
    //std::cout << "Voiture 2: " << InstanceManager<Voiture>::getByIndex(1).getAllDetails() << std::endl;

    //// Mecanicien
    //Mecanicien m(InstanceManager<Personne>::getNextID(), "Hamrouni", "Generaliste");
    //InstanceManager<Mecanicien>::add(m);
    //std::cout << "Mecanicien: " << InstanceManager<Mecanicien>::getByIndex(0) << std::endl;

    //// Services
    //Service service1(InstanceManager<Service>::getNextID(), "Vidange", 50.00);
    //Service service2(InstanceManager<Service>::getNextID(), "Vérification des freins", 25.00);
    //Service service3(InstanceManager<Service>::getNextID(), "Rotation du pneu", 20.00);

    //// Rendez Vous
    //c = InstanceManager<Client>::getByIndex(0);
    //v = InstanceManager<Voiture>::getByIndex(0);
    //m = InstanceManager<Mecanicien>::getByIndex(0);
    //RendezVous appt1("2023-05-05", "10:00:00", &v, &c, &m);
    //RendezVous appt2("2023-05-06", "10:00:00", &v, &c, &m);
    //c = InstanceManager<Client>::getByIndex(1);
    //v = InstanceManager<Voiture>::getByIndex(1);
    //RendezVous appt3("2023-06-06", "10:00:00", &v, &c, &m);

    //// Facture
    //Facture bill(InstanceManager<Facture>::getNextID(), "2023-04-07", &c, { &appt1 }, { &service1 });
    //// Detailles du facture
    //c = InstanceManager<Client>::getByIndex(0);
    //std::cout << "----" << std::endl << bill.getAllDetails() << "----" << std::endl;

    //// supprimer 1er rendez vous
    //bill.AnnulerRendezVous(&appt1);

    //// ajout service et rendez-vous
    //bill.addRendezVous(&appt2);
    //bill.addService(&service2);
    //std::cout << "Apres annulation du rendez vous:" << std::endl << bill.getAllDetails() << "----" << std::endl;

    //// Enregistrer dans le fichier
    //std::string nom_fichier_facture = "facture_" + bill.getId() + ".txt";
    //bill.saveToFile(nom_fichier_facture);


    //// Client 2:
    //Service s = service3 + service1;
    //c = InstanceManager<Client>::getByIndex(0);
    //Facture bill2(InstanceManager<Facture>::getNextID(), "2023-06-06", &c, { &appt3 }, { &s });
    //std::cout << "--------------------------------------------------" << std::endl << std::endl;
    //std::cout << "----" << std::endl << bill2.getAllDetails() << "----" << std::endl;
    //nom_fichier_facture = "facture_" + bill2.getId() + ".txt";
    //bill2.saveToFile(nom_fichier_facture);
}

char displayMainMenu() {
    char choice;
    std::cout << "[1] - Gerer les clients" << std::endl;
    std::cout << "[2] - Gerer les vehicules" << std::endl;
    std::cout << "[3] - Gerer les mecaniciens" << std::endl;
    std::cout << "[4] - Gerer les rendez-vous" << std::endl;
    std::cout << "[5] - Gerer les factures" << std::endl;
    std::cout << "[6] - Enregistrer facture dans un fichier." << std::endl;
    std::cout << "[7] - Quitter" << std::endl;
    std::cin >> choice;
    return choice;
}

void saveInvoiceToFile() {
    InstanceManager<Facture>::printAll();
    std::cout << "Entrez l'ID de la facture: ";
    std::string factureId;
    std::cin >> factureId;
    Facture f = InstanceManager<Facture>::get(factureId);
    f.saveToFile("facture_" + factureId + ".txt");
}

int main() {
    char choice;
    while ((choice = displayMainMenu()) != '7') {
        switch (choice) {
        case '1':
            InstanceManager<Client>::manageMenu();
            break;
        case '2':
            InstanceManager<Voiture>::manageMenu();
            break;
        case '3':
            // Call the function to manage mechanics
            InstanceManager<Mecanicien>::manageMenu();
            break;
        case '4':
            // Call the function to manage appointments
            InstanceManager<RendezVous>::manageMenu();
            break;
        case '5':
            // Call the function to manage invoices
            InstanceManager<Facture>::manageMenu();
            break;
        case '6':
            // Save invoice to file
            saveInvoiceToFile();
            break;
        default:
            std::cout << "Choix invalide" << std::endl;
        }
    }
    std::cout << "Au revoir!" << std::endl;
}
