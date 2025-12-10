#pragma once
#include <vector>
#include <iostream>
#include "Livre.h"
#include "Lecteur.h"
#include "Emprunt.h"
#include "Auteur.h"

class Bibliotheque
{
private:
    
    std::vector<Livre> livres_;
    std::vector<Lecteur> lecteurs_;
    std::vector<Emprunt> emprunts_;
    std::vector<Auteur> auteurs_;

public:
    
    Bibliotheque();

    void ajouterAuteur(const Auteur& auteur);
    void ajouterLivre(const Livre& livre);
    void ajouterLecteur(const Lecteur& lecteur);

    
    void emprunterLivre(int idLecteur, long int isbn, const Date& date);
    void restituerLivre(int idLecteur, long int isbn);

    
    std::vector<Livre> chercherLivresAuteur(const Auteur& auteur) const;
    std::vector<Livre> chercherLivresEmpruntesParLecteur(int idLecteur) const;
    float pourcentageEmprunts() const;
    void afficherLecteurs() const; 
};