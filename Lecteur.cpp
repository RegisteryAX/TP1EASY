#include "Lecteur.h"
#include <vector>
#include <string>
Lecteur::Lecteur(int id, std::string nom, std::string prenom) : id_(id),nom_(nom),prenom_(prenom){};

void Lecteur::setNom(const std::string& nom) {
	nom_ = nom;
};
void Lecteur::setPrenom(const std::string& prenom) {
	prenom_ = prenom;
};

void Lecteur::setISBNPr(const int& isbn) {
	isbnEmpruntes_.push_back(isbn);
};
const std::string& Lecteur::nom() const {
	return nom_;
};
const std::string& Lecteur::prenom() const {
	return prenom_;
};
const std::vector<int> Lecteur::isbnempr() const {
	return isbnEmpruntes_;
};