#pragma once
#include "Date.h"
#include <string>
#include <vector>
class Emprunt
{
public:
	Date dateEmprunt_;
	int ISBN_;
	int ID_;
private:
	Emprunt(const Date& dateEmprunt, int ISBN, int ID);
	void setISBN(const int& ISBN);
	void setID(const int& ID);
	void setDate(const Date& dateEmprunt);
	const int& isbn() const;
	const int& id() const;
	const Date& dateEmprunt() const;
};

