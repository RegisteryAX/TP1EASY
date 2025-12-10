#include "Emprunt.h"
#include "Date.h"
#include <string>
#include <vector>
Emprunt::Emprunt(const Date& dateEmprunt, long int ISBN, int ID) : dateEmprunt_(dateEmprunt),ISBN_(ISBN),ID_(ID) {}

void Emprunt::setISBN(const long int& ISBN) {
	ISBN_ = ISBN; 
};

void Emprunt::setID(const int& ID) {
	ID_ = ID;
};

void Emprunt::setDate(const Date& dateEmprunt) {
	dateEmprunt_ = dateEmprunt;
};

const int& Emprunt::isbn() const {
	return ISBN_;
};

const int& Emprunt::id() const {
	return ID_;
};

const Date& Emprunt::dateEmprunt() const {
	return dateEmprunt_;
};