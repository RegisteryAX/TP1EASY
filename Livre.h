#pragma once
#include <string>
#include "Date.h"
#include <vector>
class Livre
{
private: 
	std::string titre_;
	std::string auteur_;
	std::string langue_;
	std::string genre_;
	Date datePublication_;
	long int ISBN_;
	std::vector<int> emprunteursPréc_;
public:
	Livre(std::string titre, std::string auteur, std::string langue, std::string genre, const Date& date, long int ISBN);

	void setTitre(const std::string& titre);
	void setAuteur(const std::string& auteur);
	void setLangue(const std::string& langue);
	void setGenre(const std::string& genre);
	void setDate(Date date);
	void setEmprunteursPréc(int identifiants);
	
	const std::string& titre() const;
	const std::string& auteur() const;
	const std::string& langue() const;
	const std::string& genre() const;
	const Date& date() const;
	std::vector<int> emprunteurs() const;



};

