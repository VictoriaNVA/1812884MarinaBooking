#include "marina.h"

using namespace std;

//Global variables
vector <Boat> berths;
vector <Boat> holding_bay;
const int marina_length = 150;
//setting the initial value of available berth space
int free_space = marina_length;

/*Getting rid of index 0
*in order to later output
*the boats and their ID starting with 1*/
void index_0 ()
{
	Boat h;
	berths.insert(berths.begin(), h);
	holding_bay.insert(holding_bay.begin(), h);
}

/*
*Code for the vector adapted from:
*"Store class objects in vector"
*By: nirvanarupali
*Source Link: https://www.dreamincode.net/forums/topic/63358-store-class-objects-in-vector/ 
*/

//Storing boats (objects data) inside vector
void add_boat(Boat* b)
{
	b->get_type();
	b->get_length();
	b->get_draft();
	berths.push_back(*b);
}

//Output of the Berth Records, organized as a table
void Boat::print_records()
{
	if (length < 10)
	{
		cout << type << " | " << "  " << length << " m  | " << "  " << draft << " m       |    " << boat_name << "     " << owner_name << endl;
		cout << "--|-----------|--------|-------------|--------------------|----------------------|" << endl;
	}
	else
	{
		cout << type << " | " << " " << length << " m  | " << "  " << draft << " m       |    " << boat_name << "     " << owner_name << endl;
		cout << "--|-----------|--------|-------------|--------------------|----------------------|" << endl;
	}
}

//Printing the header for the Berth Records
void print_berths()
{
	cout << "ID| Boat Type | Length | Draft depth |     Boat Name      |      Owner Name      |\n"
		 <<"--|-----------|--------|-------------|--------------------|----------------------|" << endl;

	//Iterate through the berths vector, starting with index 1
	//index 0 is not used for output convenience
	for (unsigned int i = 1; i < berths.size(); i++)
	{
		cout << i << " | ";
		berths[i].print_records();
	}
}

//Similarly printing the header for the Holding Bay
void print_bay()
{
	cout << "ID| Boat Type | Length | Draft depth |     Boat Name      |      Owner Name      |\n"
		<< "--|-----------|--------|-------------|--------------------|----------------------|" << endl;

	//Iterate through the holding_bay vector, starting with index 1
	for (unsigned int i = 1; i < holding_bay.size(); i++)
	{
		cout << i << " | ";
		holding_bay[i].print_records();
	}
}

/*Writing to file 
*Note: The objects are written to file
*only when the app is closed through the MENU option 4
*
*Sources used:
*The writing format was inspired from:
*https://stackoverflow.com/questions/34174169/writing-vector-of-objects-to-file
*Writing to file code adjusted from: 
*https://stackoverflow.com/questions/61697375/c-writing-a-vector-of-objects-to-file
*/


//Setting the format
void Boat::write_boats(ofstream& f) const
{
	f << owner_name << ';' << boat_name << ';' << type << ';' << length << ';' << draft << '\n';
}

//Actually writing the objects to the file
void save_records()
{
	ofstream file("records_file.txt");

	berths.erase(berths.begin() + 0);

	for (const Boat& b : berths)
	{
		b.write_boats(file);
	}
}

//Reading from file 
void read_boats()
{
	ifstream infile("records_file.txt");
	
	string line;

	string owner;
	string boat;
	string type;
	int l;
	int d;
	
	//Read the line up to the ';' delimiter
	while (getline(infile, line, ';'))
	{
		Boat b;

		owner = line;
		b.set_owner(owner); 

		getline(infile, line, ';');
		boat = line;
		b.set_boat_name(boat);

		getline(infile, line, ';');
		type = line;
		b.set_type(type);

		getline(infile, line, ';');
		l = stoi(line);
		b.set_length(l);
		free_space -= l;

		getline(infile, line);
		d = stoi(line);
		b.set_draft(d);

		//Adding the object/s from file inside the vector
		berths.push_back(b);
	}

}

//Price quote & user input for further boat information
int berth_offer(Boat* b, int& length)
{
	int months;
	int price;
	char answer;
	char gettype;

	string owner;
	string boat_name;
	string type;

	cout << "\nHow many months would you like to book the berth for, in figures: ";
	cin >> months;

	price = (10 * length) * months;

	cout << "\nPrice Quote: " << price << " GBP." << endl;
	cout << "\nWould you like to proceed ? Press Y for yes or N for no: ";
	cin >> answer;

	if (answer == 'y' || answer == 'Y')
	{
		cin.ignore();
		cout << "\nPlease fill in the additional details:" << endl;
		cout << "Name: ";

		getline(cin, owner);

		cout << "Boat Name: ";
		getline(cin, boat_name);

		/*Character switch case for the Boat type
		*meant to ease user input */
		cout << "Boat Type Initial (S - Sailing, N - Narrow, M - Motor): ";
		cin >> gettype;

		switch (gettype)
		{
		case 's': case 'S':
			type = " Sailing ";
			break;
		case 'n': case 'N':
			type = " Narrow  ";
			break;
		case 'm': case 'M':
			type = " Motor   ";
			break;
		}

		b->set_owner(owner);
		b->set_boat_name(boat_name);
		b->set_type(type);

		cout << "\nBoat successfully registered.\nThank you for booking with us!" << endl;
		add_boat(b);
	}
	else if (answer == 'n' || answer == 'N')
	{
		cout << "We're sorry to hear that. Have a good day!" << endl;
		berths.back();
		berths.pop_back();
		//Reset the length if the transaction does not proceed
		free_space += length;
		return 0;
	}
	else
	{
		//If user input isn't recognized, function starts over
		cout << "\nInput error! Try again." << endl;
		berth_offer(b, length);
	}
}

/*
*Checking  boat dimensions;
*Bool value is used in register_boat()
*to differentiate valid boats & add them to the vector
*/
bool check_size(int& length, int& draft)
{
	if (length > 15)
	{
		cout << "\nBoat exceeds 15m length limit! Transaction terminated.\n" << endl;
		return_to_menu();
		return false;
	}
	else if (draft > 5)
	{
		cout << "\nBoat exceeds 5m draft limit! Transaction terminated.\n" << endl;
		return_to_menu();
		return false;
	}
	else if (length > 15 && draft > 5)
	{
		cout << "\nBoat exceeds both length and draft limits! Transaction terminated.\n" << endl;
		return_to_menu();
		return false;
	}
	else
	{
		return true;
	}
}

//Checking if the available space in the marina is enough for the new boat
void boat_validation(Boat* b, int& length, int& draft)
{
	if (check_size(length, draft) && length < free_space)
	{
		free_space -= length;
		berth_offer(b, length);
	}
	else
	{
		cout << "\nNot enough space in the Marina!\nTransaction Terminated." << endl;
	}
	cout << endl;
}

/*Getting user input about boat length and draft
*to check if the measures fit the marina criteria*/
void register_boat()
{
	Boat* b = new Boat;
	int length;
	string type;
	int draft;

	cout << "To register your boat, please fill in the following information:" << endl;
	cout << "\nBoat length in meters : ";
	cin >> length;
	b->set_length(length);
	cout << "Draft depth in meters : ";
	cin >> draft;
	b->set_draft(draft);
	boat_validation(b, length, draft);
	return_to_menu();

}

//Displaying marina space & berth records (or lack thereof)
void records()
{
	cout << endl;

	if (free_space == 150)
	{
		cout << "No records to display." << "\n Marina space available: " << free_space << " m." << endl;
	}
	else
	{
		cout << "Marina space available : " << free_space << " m." << endl;
		cout << "\nBerth Records: " << endl;
		cout << endl;
		print_berths();
	}
	return_to_menu();
}

//Deleting a record
void delete_record()
{
	char back; 
	int index;
	//making sure the menu option was not mistakenly chosen
	cout << "Would you like to delete a record? Type Y or N:  ";
	cin >> back;
	if (back == 'N' || back == 'n')
	{
		return_to_menu();
	}
	else
	{
		cout << "\nEnter ID of the record to delete:  ";
		cin >> index;
		free_space += berths.at(index).get_length();

		/*Move the boats situated after the boat to be deleted
		*inside the holding bay vector, starting with the end boat
		*and deleting them from the berths vector*/
		for (int i = berths.size() - 1; i > index; i--)
		{
			holding_bay.push_back(berths[i]);
			berths.erase(berths.begin() + i);
		}
		
		//Print the current marina and holding bay
		system("CLS");
		simulate_marina();

		//Remove the boat record no longer needed
		berths.erase(berths.begin() + index);
		cout << "\nBoat record successfully deleted." << endl;
		
		/*Move the boats from the holding bay back into the marina
		*and delete them from the holding_bay vector*/
		for (int i = holding_bay.size() - 1; i > 0; i--)
		{
			berths.push_back(holding_bay[i]);
			holding_bay.erase(holding_bay.begin() + i);
		}

		//Print the updated marina
		simulate_marina();

		//Return
		cout << "\nReturning to menu..." << endl;
		return_to_menu();
	}
}

