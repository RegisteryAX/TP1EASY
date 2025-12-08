#pragma once
#include<string>
#include<vector>
class Lecteur
{
public:
	int id_;
	std::string nom_;
	std::string prenom_;
	std::vector<int> isbnEmpruntes_;
private:
	Lecteur(int id, std::string nom, std::string prenom);
	void setNom(const std::string& nom);
	void setPrenom(const std::string& prenom);
	void setISBNPr(const int& isbn);
	const std::string& nom() const;
	const std::string& prenom() const;
	const std::vector<int> isbnempr() const;

};

