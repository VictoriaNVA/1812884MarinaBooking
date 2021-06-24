#include "marina.h"

using namespace std;

//Menu related code - separated for readability

int menu()
{
	//Menu Output
	cout << "WELCOME TO THE MARINA BERTH BOOKING SYSTEM" << endl;
	simulate_marina();
	cout << endl;
	cout << "MAIN MENU\n" << endl;
	cout << "1. Record New Booking" << endl
		<< "2. Delete Record" << endl
		<< "3. Display All Records" << endl
		<< "4. Exit" << endl;
	cout << endl;
	
	//Switch statement for the user's choice of menu option
	int choice;
	cin >> choice; 
	switch (choice)
	{
	case 1:
		system("CLS");//clear console
		simulate_marina();
		cout << "\n1. Record New Booking\n" << endl;
		register_boat();
		break;
	case 2:
		system("CLS");
		simulate_marina();
		cout << "\n2.Delete a record: \n" << endl;
		delete_record();
		break;
	case 3:
		system("CLS");
		cout << "3.Records & Marina Space" << endl;
		records();
		break;
	case 4:
		system("CLS");
		save_records();
		cout << "\nSee you later!" << endl;
		return 0;
	}
	cout << endl;
}

//Returns to menu & clears console
void return_to_menu()
{
	system("PAUSE"); 
	system("CLS"); 
	menu();
}
