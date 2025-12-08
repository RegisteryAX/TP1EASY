#include "Auteur.h"
#include <string>
#include <iostream>
#include "Date.h"

Auteur::Auteur(int id, std::string nom, std::string prenom, const Date& dateNaissance) :id_(id), nom_(nom), prenom_(prenom), dateNaissance_(dateNaissance) {}
const std::string& Auteur::nom() const {
	return nom_;
};
const std::string& Auteur::prenom() const {
	return prenom_;
};
const int& Auteur::id() const {
	return id_;
};
const Date& Auteur::date() const {
	return dateNaissance_;
};

void Auteur::setNom(const std::string& nom) {
	nom_ = nom;
};

void Auteur::setPrenom(const std::string& prenom) {
	prenom_ = prenom;
};

void Auteur::setDate(const Date& date) {
	dateNaissance_ = date;
};