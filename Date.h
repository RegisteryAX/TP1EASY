#ifndef DATE_H
#define DATE_H

class Date {
public:
	Date(int month , int day , int year );
	int month() const;
	int day() const;
	int year() const; 
	void updateMonth(int new_month);
	void updateDay(int new_day);
	void updateYear(int new_year);
private:
	int month_;
	int day_;
	int year_; 
};
#endif // DATE_H