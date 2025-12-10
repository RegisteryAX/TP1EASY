#pragma once
#include "Date.h"
#include <string>
#include <vector>
class Emprunt
{
private:
	Date dateEmprunt_;
	long int ISBN_;
	int ID_;
	
public:
	Emprunt(const Date& dateEmprunt, long int ISBN, int ID);
	void setISBN(const long int& ISBN);
	void setID(const int& ID);
	void setDate(const Date& dateEmprunt);
	const int& isbn() const;
	const int& id() const;
	const Date& dateEmprunt() const;

};

