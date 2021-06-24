#include "marina.h"

using namespace std;

//Separated from the marina.cpp file, to avoid clutter

//setters
void Boat::set_owner(string o)
{
	owner_name = o;
}
void Boat::set_boat_name(string b)
{
	boat_name = b;
}
void Boat::set_type(string t)
{
	type = t;
}
void Boat::set_length(int l)
{
	length = l;
}
void Boat::set_draft(int d)
{
	draft = d;
}

//getters
string Boat::get_owner()
{
	return owner_name;
}
string Boat::get_boat_name()
{
	return boat_name;
}
string Boat::get_type()
{
	return type;
}
int Boat::get_length()
{
	return length;
}
int Boat::get_draft()
{
	return draft;
}