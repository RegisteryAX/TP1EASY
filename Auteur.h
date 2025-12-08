#pragma once
#include <string>
#include <iostream>
#include "Date.h"
class Auteur
{
private:
	int id_;
	std::string nom_;
	std::string prenom_;
	Date dateNaissance_;

public :
	Auteur(int id, std::string nom, std::string prenom, const Date& dateNaissance);
	const std::string& nom() const;
	const std::string& prenom() const;
	const int& id() const;
	const Date& date() const;
	void setNom(const std::string& nom);
	void setPrenom(const std::string& prenom);
	void setDate(const Date& date);
};

	