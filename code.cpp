#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>

using namespace std;

string toLower(string str)
{
	string lowerStr = str;

	for (size_t i = 0; i < str.length(); ++i) {
		lowerStr[i] = tolower((unsigned char)str[i]);
	}
	return lowerStr;
}

time_t t = time(NULL);
tm* timePtr = localtime(&t);

const int MAX_VALID_YR = timePtr->tm_year + 1901;
const int MIN_VALID_YR = timePtr->tm_year + 1900;

const int MIN_VALID_MNTH = timePtr->tm_mon + 1;
const int MAX_VALID_MNTH = timePtr->tm_mon + 2;

bool isLeap(int year)
{
	return (((year % 4 == 0) &&
		(year % 100 != 0)) ||
		(year % 400 == 0));
}

bool isValidDate(int d, int m, int y)
{

	if (y > MAX_VALID_YR ||
		y < MIN_VALID_YR)
		return false;
	if (m < MIN_VALID_MNTH || m > MAX_VALID_MNTH)
		return false;
	if (d < 1 || d > 31)
		return false;

	if (m == 2)
	{
		if (isLeap(y))
			return (d <= 29);
		else
			return (d <= 28);
	}

	if (m == 4 || m == 6 ||
		m == 9 || m == 11)
		return (d <= 30);

	return true;
}

// Class for selecting flight destinationCitys of your choice

class flightDetails
{

	int flightSerial[15] = { 101, 102, 103, 122, 123, 124, 131, 132, 133, 241, 242, 243, 501, 502, 503 };
	int price[16] = { 12000, 10000, 15000, 11000, 14000, 10000, 12000, 13500, 9000, 12500, 14000, 12000, 16000, 16500, 13500 };
	int selectFlight;
	int perPersonPrice;

public:
	void cairo()
	{
		cout << "\n\n Flights available for cairo:";
		cout << "\n  " << flightSerial[0] << "-Flight (time: 5:00pm) " << price[0] << "/- per person";
		cout << "\n  " << flightSerial[1] << "-Flight (time: 12:00am) " << price[1] << "/- per person";
		cout << "\n  " << flightSerial[2] << "-Flight (time: 8:00pm) " << price[2] << "/- per person";

		cout << "\nChoose your flight: ";
		cin >> selectFlight;

		for (int i = 0; i < 3; i++)
		{
			if (selectFlight == flightSerial[i])
			{
				setPerPersonPrice(price[i]);
				break;
			}
		}
	}

public:
	void aswan()
	{
		cout << "\n You have chosen aswan.";
		cout << "\n Flights available for aswan:";
		cout << "\n  " << flightSerial[3] << "-Flight (time: 3:00pm) " << price[3] << "/- per person";
		cout << "\n  " << flightSerial[4] << "-Flight (time: 7:00pm) " << price[4] << "/- per person";
		cout << "\n  " << flightSerial[5] << "-Flight (time: 2:00am) " << price[5] << "/- per person";

		cout << "\n\nChoose your flight: ";
		cin >> selectFlight;

		for (int i = 3; i <= 5; i++)
		{
			if (selectFlight == flightSerial[i])
			{
				setPerPersonPrice(price[i]);
				break;
			}
		}
	}

public:
	void hur()
	{
		cout << "\n You have chosen hurghada.";
		cout << "\n Flights available for hurghada:";
		cout << "\n  " << flightSerial[6] << "-Flight (time: 4:00pm) " << price[6] << "/- per person";
		cout << "\n  " << flightSerial[7] << "-Flight (time: 9:00pm) " << price[7] << "/- per person";
		cout << "\n  " << flightSerial[8] << "-Flight (time: 2:00am) " << price[8] << "/- per person";

		cout << "\n\nChoose your flight: ";
		cin >> selectFlight;

		for (int i = 6; i <= 8; i++)
		{
			if (selectFlight == flightSerial[i])
			{
				setPerPersonPrice(price[i]);
				break;
			}
		}
	}

public:
	void sharm()
	{
		cout << "\n You have chosen sharm-elsheikh.";
		cout << "\n Flights available for sharm-elsheikh:";
		cout << "\n  " << flightSerial[9] << "-Flight (time: 5:00pm) " << price[9] << "/- per person";
		cout << "\n  " << flightSerial[10] << "-Flight (time: 6:00pm) " << price[10] << "/- per person";
		cout << "\n  " << flightSerial[11] << "-Flight (time: 1:00am) " << price[11] << "/- per person";

		cout << "\n\nChoose your flight: ";
		cin >> selectFlight;

		for (int i = 9; i <= 11; i++)
		{
			if (selectFlight == flightSerial[i])
			{
				setPerPersonPrice(price[i]);
				break;
			}
		}
	}

public:
	void borg()
	{
		cout << "\n Flights available for borg-elarab:";
		cout << "\n  " << flightSerial[12] << "-Flight (time: 4:00am) " << price[12] << "/- per person";
		cout << "\n  " << flightSerial[13] << "-Flight (time: 3:00pm) " << price[13] << "/- per person";
		cout << "\n  " << flightSerial[14] << "-Flight (time: 6:00am) " << price[14] << "/- per person";

		cout << "\n\nChoose your flight: ";
		cin >> selectFlight;

		for (int i = 12; i <= 14; i++)
		{
			if (selectFlight == flightSerial[i])
			{
				setPerPersonPrice(price[i]);
				break;
			}
		}
	}

	void setPerPersonPrice(int price)
	{
		perPersonPrice = price;
	}

	int getperPersonPrice()
	{
		return perPersonPrice;
	}

	int getSelectFlight()
	{
		return selectFlight;
	}
};

// Class Node saving user information

class Node
{
public:
	string name = "", date = "", departureCity = "", destinationCity = "", gender = "", CNIC = "";
	int age = 0, bookingCode = 0, ticketSerialNo = 0;
	float fare = 0;
	Node* next = NULL;
};


// Class for the main process of booking tickets

class bookingProcedureOfTicket
{

private:
	Node* head = NULL;
	Node* current = NULL;
	Node* front = NULL;
	Node* rear = NULL;
	int Bcode = 0;
	int Bcode2 = 0;
	flightDetails call;

public:
	int Age = 0;
	int members = 0;
	int count = 0;
	float sum = 0;
	float fare = 0;
	float discount = 0;
	float discountFare = 0;
	float totalFare = 0;
	string cnic = "";
	int numberOfBooking = 0;

public:

	bool isValidCity(string city)
	{
		if (toLower(city) == "cairo" || toLower(city) == "hurghada" ||
			toLower(city) == "aswan" || toLower(city) == "borg-elarab")
		{
			return true;
		}
		return false;
	}


	// This method will contain all the passenger info
	void inputPassengersInfo()
	{
		Bcode = rand();
		Bcode2 = 8971 + Bcode;

		string departureCity = "", destinationCity = "", date = "";
		int change = 1;

		do {
			if (change == 1 || change == 2)
			{
				do
				{
					cout << "DEPARTURE\n";
					cout << "    Our flights are only available from aswan, cairo, sharm-elsheikh, hurghada and borg-elarab.\n";
					cout << "\nEnter your departure city from above mentioned cities: ";
					cin >> departureCity;
				} while (!isValidCity(departureCity));
			}

			if (change == 1 || change == 3)
			{
				do
				{
					cout << "DESTINATION\n";
					cout << "    Our flights are only available to aswan, cairo, sharm-elsheikh, hurghada and borg-elarab.\n";
					cout << "\nEnter your destination city from above mentioned cities: ";
					cin >> destinationCity;
				} while (!isValidCity(destinationCity));

			}

			if (toLower(departureCity) == toLower(destinationCity))
			{
				cout << "\nDeparture and Destination cities cannot be same." << endl;
				cout << "\nTo change both Enter 1.\nTo change Deaprture Enter 2.\nTo Change Destnation Enter 3.\n" << endl;
				cout << "Select: ";
				cin >> change;
			}
		} while (toLower(departureCity) == toLower(destinationCity));

		// Date Input
		int d = 0, m = 0, y = 0;
		bool validDate = false;

		do
		{
			cout << "\nEnter Date: ";
			cin >> d;
			cout << "Enter Month: ";
			cin >> m;
			cout << "Enter Year: ";
			cin >> y;

			validDate = isValidDate(d, m, y);

			if (!validDate)
			{
				cout << "\nPlease enter a valid date, month and year. You can book seats upto 30 days in advance.\n";
			}

		} while (!validDate);

		date = to_string(d) + "/" + to_string(m) + "/" + to_string(y);

		cout << "\nFor how many people you want to book tickets: ";
		cin >> members;

		cout << endl;

		numberOfBooking = count + members;


		for (int i = 1; i <= members; i++)
		{
			Node* passenger_newnode = new Node();

			cout << "Enter passenger name: ";
			cin >> passenger_newnode->name;

			cout << "Enter your age: ";
			cin >> passenger_newnode->age;

			passenger_newnode->date = date;

			cout << "Enter gender: ";
			cin >> passenger_newnode->gender;

			// CNIC validation
			cout << "Enter National ID (without dashes): ";
			cin >> cnic;

			if (cnic.length() != 13)
			{
				cout << "Enter correct National ID (without dashes): ";
				cin >> cnic;
			}

			cnic = cnic.insert(5, "-");
			cnic = cnic.insert(13, "-");

			passenger_newnode->CNIC = cnic;

			cout << "Your ticket Serial No. is: S-" << i;
			passenger_newnode->ticketSerialNo = i;
			cout << "\n----------------------------------------------------\n" << endl;

			passenger_newnode->departureCity = departureCity;
			passenger_newnode->destinationCity = destinationCity;

			passenger_newnode->bookingCode = Bcode2;


			count++; // incrementing number of bookings


			if (numberOfBooking > 2)
			{
				if (front == NULL)
				{
					front = passenger_newnode;
					rear = passenger_newnode;
				}

				else
				{
					rear->next = passenger_newnode;
					rear = passenger_newnode;
				}
			}


			else
			{
				if (head == NULL)
				{
					head = passenger_newnode;
					passenger_newnode->next = NULL;
				}

				else
				{
					current = head;

					while (current->next != NULL)
					{
						current = current->next;
					}

					current->next = passenger_newnode;
				}
			}

		}


		// Check if user has entered correct destinationCity according to available flights

		if (destinationCity == "Cairo" || destinationCity == "cairo")
		{
			call.cairo();
		}
		else if (destinationCity == "Hurghada" || destinationCity == "hurghada")
		{
			call.hur();
		}
		else if (destinationCity == "Aswan" || destinationCity == "aswan")
		{
			call.aswan();
		}
		else if (destinationCity == "Borg-elarab" || destinationCity == "borg-elarab")
		{
			call.borg();
		}
		else if (destinationCity == "Sharm-elsheikh" || destinationCity == "sharm-elsheikh")
		{
			call.sharm();
		}
		else
		{
			cout << "Wrong destination City\n";
		}


		// Conditions for printing message
		if (numberOfBooking > 2)
		{
			cout << "\nYour booking code is " << Bcode2;
			cout << "\nNo more seats are availbale, you are added in the waiting list" << endl;
		}
		else
		{
			cout << "\nYour booking code is " << Bcode2;
			cout << "\nTo proceed and view total price, Press 2.";
		}



	}


	// Display Queue

	void showWaitingList()
	{
		current = front;

		if (current == NULL)
			cout << "Waiting list is empty" << endl;

		else
		{
			while (current != NULL)
			{
				cout << "_____________________________________________________________________ " << endl << endl;
				cout << "| Serial No.:     \t" << "S-" << current->ticketSerialNo << " \t\t\t|" << endl;
				cout << "| Passenger Name: \t" << current->name << " \t\t\t|" << endl;
				cout << "| Age:            \t" << current->age << " \t\t\t|" << endl;
				cout << "| National ID:           \t" << current->CNIC << " \t|" << endl;
				cout << "| Booking Date:   \t" << current->date << " \t\t|" << endl;
				cout << "| From:           \t" << current->departureCity << " \t\t|" << endl;
				cout << "| To:             \t" << current->destinationCity << " \t\t|" << endl;
				cout << "_____________________________________________________________________ " << endl << endl;

				current = current->next;
			}
		}

	}

	// To calculate Total Price of tickets

	void calculatePrice()
	{
		current = head;
		bool found = false;
		fare = call.getperPersonPrice();
		totalFare = sum = 0;

		int bcode;

		cout << "Enter your booking code: ";
		cin >> bcode;

		if (current == NULL)
			cout << "\nNo price to display";

		while (current != NULL)
		{
			if (bcode == current->bookingCode)
			{
				if (current->age > 0 && current->age <= 6)
				{
					discount = call.getperPersonPrice() * 0.5; // 50% discount
					discountFare = call.getperPersonPrice() - discount;
					current->fare = discountFare;
					sum += discountFare; // Total fare
				}
				else if (current->age > 6 && current->age <= 12)
				{
					discount = call.getperPersonPrice() * 0.3; // 30% discount
					discountFare = call.getperPersonPrice() - discount;
					current->fare = discountFare;
					sum += discountFare; // Total fare
				}
				else if (current->age >= 60)
				{
					discount = call.getperPersonPrice() * 0.2; // 20% discount
					discountFare = call.getperPersonPrice() - discount;
					current->fare = discountFare;
					sum += discountFare; // Total fare
				}
				else
				{
					fare = call.getperPersonPrice();
					current->fare = fare;
					sum += fare;
				}

				found = true;
			}
			current = current->next;
		}


		if (found = false)
		{
			cout << "Enter correct booking code" << endl;
		}
		else
		{
			totalFare = sum;
			cout << "Your Total Fare is: " << totalFare;
		}
	}

	// This will display the information of all the bookings

	void viewInfo()
	{
		cout << endl;

		current = head;
		int bookCode;
		bool found = false;

		cout << "Enter ticket code: ";
		cin >> bookCode;

		if (current == NULL)
		{
			cout << "There is no booking to display." << endl;
		}

		while (current != NULL)
		{
			if (bookCode == current->bookingCode)
			{
				cout << "_____________________________________________________________________ " << endl << endl;
				cout << "| Serial No.:     \t" << "S-" << current->ticketSerialNo << " \t\t\t|" << endl;
				cout << "| Passenger Name: \t" << current->name << " \t\t\t|" << endl;
				cout << "| Age:            \t" << current->age << " \t\t\t|" << endl;
				cout << "| National ID:           \t" << current->CNIC << " \t|" << endl;
				cout << "| Booking Date:   \t" << current->date << " \t\t|" << endl;
				cout << "| From:           \t" << current->departureCity << " \t\t|" << endl;
				cout << "| To:             \t" << current->destinationCity << " \t\t|" << endl;
				cout << "| Flight No.:     \tPA-" << call.getSelectFlight() << " \t\t|" << endl;
				cout << "| Fare:           \t" << current->fare << " \t\t\t|" << endl;
				cout << "_____________________________________________________________________ " << endl;
				cout << endl;
				found = true;
			}
			current = current->next;
		}
		if (found != true)
		{
			cout << "Booking not found" << endl;
		}
	}

	// Modify any user Ticket incase of incorrect information

	void modifyTicket()
	{
		int bcode;
		int serial;
		int found = -1;

		cout << "Enter your booking code: ";
		cin >> bcode;

		cout << "\nEnter serial number to edit: S-";
		cin >> serial;

		current = head;
		while (current != NULL)
		{
			if (bcode == current->bookingCode && serial == current->ticketSerialNo)
			{
				cout << "Enter passenger name: ";
				cin >> current->name;

				cout << "Enter your age: ";
				cin >> current->age;

				cout << "Enter date: ";
				cin >> current->date;

				cout << "Enter gender: ";
				cin >> current->gender;

				found = 0;
				cout << endl;
				break;
			}
			current = current->next;
		}

		if (found == -1)
		{
			cout << "Record not Found" << endl;
		}
	}

	// Method to confirm payment after booking

	void confirmPayment()
	{
		current = head;

		int bcode, userInput;
		string cnic;
		bool found = false;

		cout << "Enter your booking code: ";
		cin >> bcode;

		cout << "\nEnter National ID number of booking of 1st person(with dashes): ";
		cin >> cnic;

		if (current == NULL)
		{
			cout << "\nThere is no booking aganist entered booking code" << endl;
		}

		while (current != NULL)
		{
			if (bcode == current->bookingCode && cnic == current->CNIC)
			{
				found = true;
				break;
			}
			current = current->next;
		}

		if (found)
		{

			cout << "\nYour Total Fare is: " << totalFare << endl;

			cout << "\nPay fare amount to confirm ticket: ";
			cin >> userInput;

			if (userInput == totalFare)
			{
				cout << "\nYour booking is confirmed, enjoy your trip!!!";
			}
			else
			{
				cout << "\nPlease pay the required amount" << endl;

				cout << "\nPay fare amount to confirm ticket: ";
				cin >> userInput;

				if (userInput == totalFare)
				{
					cout << "\nYour booking is confirmed, enjoy your trip!!!";
				}

				else
				{
					cout << "\nYour Booking is cancelled, book again." << endl;
				}
			}
		}
		else
		{
			cout << "\nBookings not found, book your ticket first" << endl;
		}
	}

	// To clear all passenger data from the system

	void DeletingPassengerInfo()
	{
		current = head;
		int Bcode;
		bool found = false;

		cout << "Enter your booking code to cancel booking: ";
		cin >> Bcode;

		if (head == NULL)
		{
			cout << "No booking to cancel" << endl;
		}
		else
		{
			// Check if there's only one node in the list
			if (current->next == NULL)
			{
				if (Bcode == current->bookingCode)
				{
					head = NULL;
					delete current;
					found = true;
				}
			}
			else
			{
				// If the first node is the one to delete
				if (current == head && Bcode == current->bookingCode)
				{
					head = current->next;
					delete current;
					found = true;
				}
				else // If deleting node from end or middle
				{
					Node* previous = nullptr;
					while (current != NULL)
					{
						if (Bcode == current->bookingCode)
						{
							if (previous != nullptr)
							{
								previous->next = current->next;
							}
							delete current;
							found = true;
							break; // Assuming you want to delete only the first occurrence, remove this if you want to delete all occurrences
						}

						previous = current;
						current = current->next;
					}
				}
			}

			if (!found)
			{
				cout << "\nBooking not found" << endl;
			}
			else {
				cout << "\nBooking is cancelled successfully" << endl;
			}
		}
	}
};

class Menu
{
	int choice = 0;
	bookingProcedureOfTicket call;

public:
	void showMenu()
	{

		do
		{
			cout << endl;
			cout << "\n----------------------------------" << endl;
			cout << "  Galala International Airline ";
			cout << "\n";
			cout << "----------------------------------";

			cout << "\n 11 Services for the Cities";
			cout << "\n 1 Booking";
			cout << "\n 2 Price";
			cout << "\n 3 View Ticket details";
			cout << "\n 4 Modify Ticket details";
			cout << "\n 5 Payment confirmation ";
			cout << "\n 6 Cancel your booking";
			cout << "\n 7 Show waiting List";
			cout << "\n 0 Exit \n";
			cout << "\nEnter your Choice:  ";
			cin >> choice;

			switch (choice)
			{
			case 11:
				cout << endl;
				cout << "\n    Aswan \n";
				cout << "\n    Sharm-elsheikh \n";
				cout << "\n    Hurghada \n";
				cout << "\n    Borg-elarab \n";
				cout << "\n    cairo \n" << endl;

				break;
			case 1:
				cout << endl;
				cout << "\n    Book Flight Tickets \n"
					<< endl;
				call.inputPassengersInfo();
				break;
			case 2:
				cout << endl;
				call.calculatePrice();
				break;
			case 3:
				cout << endl;
				call.viewInfo();
				break;
			case 4:
				cout << endl;
				call.modifyTicket();
				break;
			case 5:
				cout << endl;
				call.confirmPayment();
				break;
			case 6:
				cout << endl;
				call.DeletingPassengerInfo();
				break;
			case 7:
				cout << endl;
				call.showWaitingList();
			}

		} while (choice != 0);
	}
};

int main()
{
	Menu call;

	call.showMenu();

	return 0;
}