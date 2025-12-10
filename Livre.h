#pragma once
#include <string>
#include "Date.h"
#include <vector>
#include "Auteur.h"
#include<iostream>
class Livre
{
private: 
	bool estEmprunte_;
	std::string titre_;
	Auteur auteur_;
	std::string langue_;
	std::string genre_;
	Date datePublication_;
	long int ISBN_;
	std::vector<int> emprunteursPréc_;
public:
	Livre(std::string titre, Auteur auteur, std::string langue, std::string genre, const Date& date, long int ISBN);
	bool estEmprunte() const;
	void setEstEmprunte(bool etat);
	void setTitre(const std::string& titre);
	void setAuteur(const Auteur& auteur);
	void setLangue(const std::string& langue);
	void setGenre(const std::string& genre);
	void setDate(Date date);
	void setEmprunteursPréc(int identifiants);
	
	const std::string& titre() const;
	const Auteur& auteur() const;
	const std::string& langue() const;
	const std::string& genre() const;
	const Date& date() const;
	std::vector<int> emprunteurs() const;
	const long int& ISBN() const;


};
std::ostream& operator<<(std::ostream& os, const Livre& livre);

