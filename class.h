#include <iostream>
#include <string>
#include<vector>

using namespace std;


// classe véhicule et ces classes filles  & classe fournisseur for u boss :)
// If u can verify both of Client and Mecanicien classes my mind has been shufflin dealin with'em (partie l'héritage)(so chatgpt did the whole work)
// line 82  "Vehicule vehicules[MAX_VEHICULES]" does this line mean a table of vehicules?(btw chagpt helped me with it it seems right so i put it )
// in line 178 i ve created an AfficheVehicule function so remember it once ur up with vehicule class (i ve  created affiche func almost in the whole classes)


class Date {
private:
    int day;
    int month;
    int year;
public:
    // Constructeur
    void Date(int day = 1, int month = 1, int year = 2023) ;

    
    int getDay() const { return day; }
    int getMonth() const { return month; }
    int getYear() const { return year; }
    
    void setDay(int day) { this->day = day; }
    void setMonth(int month) { this->month = month; }
    void setYear(int year) { this->year = year; }


    // vérifier si la date existe ou pas 
    bool isValid();

    // Affiche la date au format JJ/MM/AAAA
    void AfficherDate() const {
        cout << day << "/" << month << "/" << year;
    }
};


//------------------------------------------------------------------------------------------------------


class Personne{
    private:
    string nom;
    string prenom;
    string adresse;
    string telephone;
    
    public:
    void Personne(string nom  , string adresse , string telephone , string email );
    void Personne(string nom  , string adresse , string telephone);
    void Personne(string nom  , string adresse );
    
    //Getters
    string getNom() const { return nom; }
    string getAdresse() const { return adresse; }
    string getTelephone() const { return telephone; }
    string getEmail() const { return email; }
    

    //Setters
    void setNom(string nom) { this->nom = nom; }
    void setAdresse(string adresse) { this->adresse = adresse; }
    void setTelephone(string telephone) { this->telephone = telephone; }
    void setEmail(string email) { this->email = email; }

    //Affichage
    void afficherPersonne();
}


//------------------------------------------------------------------------------------------------------


class Client : public Personne{
   private:
    string email;
    Vehicule vehicules[MAX_VEHICULES];
    int nbVehicules;
   
   public:
    // Constructeurs
    void Client(string nom  , string adresse , string telephone , string email );
    void Client(string nom  , string adresse , string telephone);
    void Client(string nom  , string adresse);

    
    // Getters
    string getEmail() const { return email; }
    int getNbVehicules() const { return nbVehicules; }
    Vehicule getVehicule(int index) const { return vehicules[index]; }
    
    
    
    // Setters
    void setEmail(string email) { this->email = email; }
    
    
    // Ajout d'une véhicule 
    void ajoutervéhicule(Vehicule vehicule); 
    void afficherClient();
};


//------------------------------------------------------------------------------------------------------



class Mecanicien : public Personne {
    private:
    string specialite;
    vector<RendezVous> rendezvous;

    public:
    Mecanicien(string nom, string prenom, string adresse, string telephone, string specialite)
    : Personne(nom, prenom, adresse, telephone), specialite(specialite) {}

    // Getters
    string getSpecialite() const { return specialite; }
    vector<RendezVous> getRendezVous() const { return rendezvous; }

    // Setter
    void setSpecialite(string specialite) { this->specialite = specialite; }

    // Ajouter un rendez-vous
    void ajouterRendezVous(const RendezVous& rdv) {
        rendezvous.push_back(rdv);
    }

    // Afficher tous les rendez-vous du mécanicien
    void afficherRendezVous() ;
};



//------------------------------------------------------------------------------------------------------


class Service{
    private:
    string nom_service;
    double prix;

    public:
    void Service(string nom_service , double prix);
    string getNomservice() {return nom_service};
    double getPrix(){return prix};
    void setNom(string nom) { this->nom = nom};
    void setPrix(float prix) { this->prix = prix}; 
    void afficherService();
}
//------------------------------------------------------------------------------------------------------



class RendezVous{
    private:
    Date date;
    Time temps;
    Client client;
    Mecancien mecancien ;
    Vehicules véhicules;


    public:
    void RendezVous(Date date , Time temps , Client client , Mecancien mecancien);
    Date getDate() {
        return date.AfficherDate();
    }
    Time gettemps() {
        return temps.AfficherTime();
    }
    Vehicules getVehicule() {
        return véhicules.AfficherVehicule();
    }
    Client getClient() {
        return client;
    }

    Mecancien getMecancien() {
        return mecancien;
    }


   

}


//------------------------------------------------------------------------------------------------------


class Facture {
  private:
    Date date;
    Client client;
    RendezVous rendezvous;
    Service services;
    int idfacture;
    double montant;

  public:
    void Facture(Date date, Client client, RendezVous rendezvous, Services services, int idfacture, double montant);

    int getIdfacture() {
        return idfacture;
    }
    
    void setIdfacture(int id) {
        idfacture = id;
    }

   Date getDate() {
        return date.AfficherDate();
    }

    void setDate(int day , int month , int year) {
        this->date = Date(day,month,year);
    }

    double getMontant() {
        return montant;
    }

    void setMontant(double montant) {
        this->montant = montant;
    }

    

    Client getClient() {
        return client;
    }

    void setClient(Client client) {
        this->client = client;
    }

    string getDetailsFacture();
};
