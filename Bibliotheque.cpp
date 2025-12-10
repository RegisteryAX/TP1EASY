#include "Bibliotheque.h"
#include <iostream>

Bibliotheque::Bibliotheque() {
}

void Bibliotheque::ajouterAuteur(const Auteur& auteur) {
    auteurs_.push_back(auteur);
}

void Bibliotheque::ajouterLivre(const Livre& livre) {
    livres_.push_back(livre);
}

void Bibliotheque::ajouterLecteur(const Lecteur& lecteur) {
    lecteurs_.push_back(lecteur);
}

void Bibliotheque::emprunterLivre(int idLecteur, long int isbn, const Date& date) {
    int indexLivre = -1;
    for (int i = 0; i < livres_.size(); i++) {
        if (livres_[i].ISBN() == isbn) {
            indexLivre = i;
            break;
        }
    }

    
    int indexLecteur = -1;
    for (int i = 0; i < lecteurs_.size(); i++) {
        if (lecteurs_[i].id_ == idLecteur) { 
            indexLecteur = i;
            break;
        }
    }

    if (indexLivre == -1) {
        std::cout << "Erreur: Livre introuvable." << std::endl;
        return;
    }
    if (indexLecteur == -1) {
        std::cout << "Erreur: Lecteur introuvable." << std::endl;
        return;
    }

    
    if (livres_[indexLivre].estEmprunte()) {
        std::cout << "Erreur: Ce livre est deja emprunte." << std::endl;
        return;
    }

    livres_[indexLivre].setEstEmprunte(true);
    livres_[indexLivre].setEmprunteursPréc(idLecteur);

    lecteurs_[indexLecteur].isbnEmpruntes_.push_back((int)isbn);

    
    Emprunt nouvelEmprunt(date, (int)isbn, idLecteur);
    emprunts_.push_back(nouvelEmprunt);

    std::cout << "Livre emprunte avec succes." << std::endl;
}

void Bibliotheque::restituerLivre(int idLecteur, long int isbn) {
   
    bool livreTrouve = false;
    for (int i = 0; i < livres_.size(); i++) {
        if (livres_[i].ISBN() == isbn) {
            livres_[i].setEstEmprunte(false);
            livreTrouve = true;
            break;
        }
    }

    bool lecteurTrouve = false;
    for (int i = 0; i < lecteurs_.size(); i++) {
        if (lecteurs_[i].id_ == idLecteur) {
          
            for (int k = 0; k < lecteurs_[i].isbnEmpruntes_.size(); k++) {
                if (lecteurs_[i].isbnEmpruntes_[k] == (int)isbn) {
                   
                    lecteurs_[i].isbnEmpruntes_.erase(lecteurs_[i].isbnEmpruntes_.begin() + k);
                    lecteurTrouve = true;
                    break;
                }
            }
            break;
        }
    }

    for (int i = 0; i < emprunts_.size(); i++) {
        if (emprunts_[i].isbn() == (int)isbn && emprunts_[i].id() == idLecteur) {
            emprunts_.erase(emprunts_.begin() + i);
            break;
        }
    }

    if (livreTrouve && lecteurTrouve) {
        std::cout << "Livre restitue." << std::endl;
    }
    else {
        std::cout << "Erreur lors de la restitution." << std::endl;
    }
}



std::vector<Livre> Bibliotheque::chercherLivresAuteur(const Auteur& auteur) const {
    std::vector<Livre> resultats;
    for (int i = 0; i < livres_.size(); i++) {
    
        if (livres_[i].auteur().id() == auteur.id()) {
            resultats.push_back(livres_[i]);
        }
    }
    return resultats;
}


float Bibliotheque::pourcentageEmprunts() const {
    if (livres_.empty()) return 0.0f;

    int compteur = 0;
    for (int i = 0; i < livres_.size(); i++) {
        if (livres_[i].estEmprunte()) {
            compteur++;
        }
    }
 
    return (float)compteur / livres_.size() * 100.0f;
}


std::vector<Livre> Bibliotheque::chercherLivresEmpruntesParLecteur(int idLecteur) const {
    std::vector<Livre> resultats;

  
    for (int i = 0; i < lecteurs_.size(); i++) {
        if (lecteurs_[i].id_ == idLecteur) {
     
            for (int k = 0; k < lecteurs_[i].isbnEmpruntes_.size(); k++) {
                int isbnCherche = lecteurs_[i].isbnEmpruntes_[k];

            
                for (int j = 0; j < livres_.size(); j++) {
                    if (livres_[j].ISBN() == isbnCherche) {
                        resultats.push_back(livres_[j]);
                        break;
                    }
                }
            }
            break;
        }
    }
    return resultats;
}

void Bibliotheque::afficherLecteurs() const {
    for (int i = 0; i < lecteurs_.size(); i++) {
        std::cout << lecteurs_[i].nom() << " " << lecteurs_[i].prenom() << std::endl;
    }
}