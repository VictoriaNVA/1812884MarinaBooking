#include "marina.h"

using namespace std;

//global extern vectors
extern vector <Boat> berths;
extern vector <Boat> holding_bay;

void Boat::output()
{
	cout << boat_name << endl;
}

//Output Marina and Holding Bay
void simulate_marina()
{
	//Check if the Marina is empty & output if it's not
	if (berths.size() > 1)
	{
		cout << "\nMARINA:" << endl;
		cout << "ID| Boat Name" << '\n'
			<< "--|---------------" << endl;
		for (unsigned int i = 1; i < berths.size(); i++)
		{
			cout << i << " | ";
			berths[i].output();
		}
	}
	else
	{
		cout << "\nMARINA: empty";
	}

	//Check if the Holding Bay is empty & output if it's not
	if (holding_bay.size() > 1)
	{
		cout << "\nHOLDING BAY:" << endl;
		for (unsigned int i = 1; i < holding_bay.size(); i++)
		{
			holding_bay[i].output();
		}
	}
	else
	{
		cout << "\nHOLDING BAY: empty" << endl;
	}
}