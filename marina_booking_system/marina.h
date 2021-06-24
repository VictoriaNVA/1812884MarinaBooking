#ifndef MARINA_H
#define MARINA_H

#include <fstream>
#include <iostream>
#include <iomanip>  
#include <cstdlib>
#include <string>
#include <vector>

using namespace std;

//parent class
class Boat 
{
protected:
	string owner_name;
	string boat_name;
	string type;
	int length;
	int draft;
public:
	//setters
	void set_type(string t);
	void set_length(int l);
	void set_draft(int d);
	void set_owner(string owner);
	void set_boat_name(string boat);
	//getters
	string get_owner();
	string get_boat_name();
	string get_type();
	int get_length();
	int get_draft();

	//other methods
	void print_records();
	void write_boats(ofstream& f) const;
	void output();
};

//derived classes - not in use
//class Narrowboat : public Boat {};
//class Sailingboat : public Boat {};
//class Motorboat : public Boat {};

//function declarations
void add_boat(Boat* b);

int berth_offer(Boat* b, int& length);

void boat_validation(Boat* b, int& length, int& draft);

bool check_size(int& length, int& draft);

void delete_record();

void index_0();

int menu();

void print_bay();

void print_berths();

void read_boats();

void records();

void register_boat();

void return_to_menu();

void save_records();

void simulate_marina();

#endif