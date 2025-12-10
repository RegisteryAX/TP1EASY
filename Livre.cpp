#include "Livre.h"
#include "Date.h"
#include "Auteur.h"
#include <string>
#include <iostream> // Added for std::ostream

Livre::Livre(std::string titre, Auteur auteur, std::string langue, std::string genre, const Date& date, long int ISBN)
    : datePublication_(date), titre_(titre), auteur_(auteur), langue_(langue), genre_(genre), ISBN_(ISBN), estEmprunte_(false)
{
}

void Livre::setTitre(const std::string& titre)
{
    titre_ = titre;
}

void Livre::setAuteur(const Auteur& auteur)
{
    auteur_ = auteur;
}

void Livre::setLangue(const std::string& langue)
{
    langue_ = langue;
}

void Livre::setGenre(const std::string& genre)
{
    genre_ = genre;
}

void Livre::setDate(Date date)
{
    datePublication_ = date;
}

void Livre::setEmprunteursPréc(int identifiants)
{
    emprunteursPréc_.push_back(identifiants);
}

const std::string& Livre::titre() const
{
    return titre_;
}

const Auteur& Livre::auteur() const
{
    return auteur_;
}

const std::string& Livre::langue() const
{
    return langue_;
}

const std::string& Livre::genre() const
{
    return genre_;
}

const Date& Livre::date() const
{
    return datePublication_;
}

std::vector<int> Livre::emprunteurs() const
{
    return emprunteursPréc_;
}

bool Livre::estEmprunte() const {
    return estEmprunte_; 
};

void Livre::setEstEmprunte(bool etat) {
    estEmprunte_ = etat;
};

const long int& Livre::ISBN() const {
    return ISBN_;
};


std::ostream& operator<<(std::ostream& os, const Livre& livre) {
    os << "Titre : " << livre.titre() << "\n";
    
    os << "Auteur : " << livre.auteur().nom() << " " << livre.auteur().prenom() << "\n";
    os << "Langue : " << livre.langue() << " | Genre : " << livre.genre() << "\n";

    
    os << "Date : " << livre.date().day() << "/" << livre.date().month() << "/" << livre.date().year() << "\n";

    os << "ISBN : " << livre.ISBN() << "\n";
    os << "Statut : " << (livre.estEmprunte() ? "Emprunte" : "Disponible") << "\n";

    return os;
}