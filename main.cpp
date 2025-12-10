#include <iostream>
#include <vector>
#include "Bibliotheque.h"
#include "Date.h"
#include "Auteur.h"
#include "Livre.h"
#include "Lecteur.h"

int main() {
    Bibliotheque maBibliotheque;

    Date d1(1, 1, 1980);
    Date d2(31, 7, 1965);
    Date dToday(10, 12, 2025);

    Auteur a1(1, "Hugo", "Victor", d1);
    Auteur a2(2, "Rowling", "JK", d2);
    Auteur a3(3, "Tolkien", "JRR", d1);

    maBibliotheque.ajouterAuteur(a1);
    maBibliotheque.ajouterAuteur(a2);
    maBibliotheque.ajouterAuteur(a3);

    Livre l1("Les Miserables", a1, "Francais", "Roman", d1, 10001);
    Livre l2("Harry Potter 1", a2, "Anglais", "Fantasy", d1, 10002);
    Livre l3("Harry Potter 2", a2, "Anglais", "Fantasy", d1, 10003);
    

    maBibliotheque.ajouterLivre(l1);
    maBibliotheque.ajouterLivre(l2);
    maBibliotheque.ajouterLivre(l3);
  

    Lecteur lec1(1, "Dupont", "Jean");
    Lecteur lec2(2, "Martin", "Alice");
    Lecteur lec3(3, "Smith", "John");

    maBibliotheque.ajouterLecteur(lec1);
    maBibliotheque.ajouterLecteur(lec2);
    maBibliotheque.ajouterLecteur(lec3);

    std::cout << "Liste des Lecteurs " << std::endl;
    maBibliotheque.afficherLecteurs();
    std::cout << std::endl;

    std::cout << "Test Emprunts " << std::endl;
    maBibliotheque.emprunterLivre(1, 10001, dToday);
    maBibliotheque.emprunterLivre(1, 10002, dToday);

    maBibliotheque.emprunterLivre(2, 10002, dToday);

    maBibliotheque.emprunterLivre(2, 10004, dToday);
    std::cout << std::endl;

    std::cout << "Verification Lecteur 1 (Apres emprunt) " << std::endl;
    std::cout << lec1;

    std::vector<Livre> livresLec1 = maBibliotheque.chercherLivresEmpruntesParLecteur(1);
    for (size_t i = 0; i < livresLec1.size(); i++) {
        std::cout << livresLec1[i] << std::endl;
    }
    std::cout << std::endl;

    std::cout << "Recherche Livres Auteur (Rowling)" << std::endl;
    std::vector<Livre> livresRowling = maBibliotheque.chercherLivresAuteur(a2);
    for (size_t i = 0; i < livresRowling.size(); i++) {
        std::cout << "- " << livresRowling[i].titre() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "Statistiques " << std::endl;
    std::cout << "Pourcentage emprunts : " << maBibliotheque.pourcentageEmprunts() << "%" << std::endl;
    std::cout << std::endl;

    std::cout << "Test Restitution" << std::endl;
    maBibliotheque.restituerLivre(1, 10001);

    std::cout << "Pourcentage emprunts apres retour : " << maBibliotheque.pourcentageEmprunts() << "%" << std::endl;

    return 0;
}