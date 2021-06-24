# Marina Berth Booking System

This is a C++ University assignment representing system for booking boats in a Marina. 

## Self-Reflection
This project was my first exposure to C++ and it was challenging but also really fun! I believe I learned a lot, especially about reading from and writing to file. The code could certainly be improved, and a more Object-Oriented approach for different types of boats would be desirable
## Running Instructions
#### The Console application is pretty intuitive but detailed instructions of how the app works can be found below.

1. Upon running the application, MAIN MENU is displayed.
2. To navigate through the menu, type the figure associated to the menu option. (E.g. If you want to record a new booking, type 1 and ENTER)
3. When recording a new booking, you must provide the length and draft sizes of the boat, in meters. The application will check the numbers to see if they meet the marina criteria. If the size is alright, you will be prompted to provide how long you want the berth space for, in months. Based on your answer, the system will provide a price quote. You must accept or reject the price quote by typing Y for yes or N for no. You do not necessarily have to type the letter in capital, as the system was built to recognize them in lowercase too.
  - If you rejected the offer, an appropriate message will be displayed and then you can return to MENU by pressing any key.
  - If you accepted the offer, you will be prompted for more information about yourself and the boats, then the system will inform you that the boat has been recorded. You can return to the MENU by pressing any key.
4. If you want to view the boat records in detail, you can type 3 in the menu screen to go in the Display All Records menu option. This section displays the marina available space and the boats recorded so far, in a table-like structure. You can return to the MENU by pressing any key.
5. If you want to delete a boat, you can type 2 in the menu screen. First, you will be asked if you want to proceed with deleting a boat. You must type Y for yes or N for no, similar to accepting or rejecting the price in the Recording section.
  - N -> Press any key to return to the menu
  - Y -> You will be asked to provide the ID of the boat you want to delete. You can see the ID of a boat in the simulation of the marina at the top of the console and in the Display All Records section. The boats situated after the boat to be deleted will be moved in the Holding Bay, the boat will be deleted, and the boats from the Holding Bay will show back in the Marina. Once again, to return to the MENU, you can press any key.
6. If you want to exit the application while also saving the boats recorded so far in a text file, you must type 4 in the MENU screen. This will display an appropriate message (See you later!) and stop the application. If you start the application again, the boats you recorded in the previous run will now show both in the top Marina Simulation and in the Display All Records section.
