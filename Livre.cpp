#include "Livre.h"
#include "Date.h"
#include "Auteur.h"
#include <string>

Livre::Livre(std::string titre, Auteur auteur, std::string langue, std::string genre, const Date& date, long int ISBN)
	: datePublication_(date),titre_(titre),auteur_(auteur),langue_(langue),genre_(genre), ISBN_(ISBN)
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

const Date&  Livre::date() const
{
	return datePublication_;
}

std::vector<int> Livre::emprunteurs() const
{
	return emprunteursPréc_;
}
