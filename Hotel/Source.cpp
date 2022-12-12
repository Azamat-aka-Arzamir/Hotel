#include <string>
#include <iostream>
#include "Header.h"

using namespace std;

int ReadInt();
//
bool IsInteger(string& s)
{
	if (s.empty() || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+'))) return false;
	char* p;
	strtol(s.c_str(), &p, 10);
	return (*p == 0);
}
Date ReadDate()
{
	Date output;
	bool success = false;
	while (!success)
	{
		int d1, m1, y1;
		cout << "day (number): ";
		d1 = ReadInt();
		cout << "month (number): ";
		m1 = ReadInt();
		cout << "year (last 2 numbers): ";
		y1 = ReadInt();
		output.SetDate(d1, m1, y1, success);
		cout << endl;
	}
	return output;
}
/// <summary>
/// "Check reservation status"
/// </summary>
void FirstOption()
{
	cout << "\n \n \n \n";
	string name;
	cout << ReservationWindow;
	char n[1000];
	cin.clear();
	cin.ignore(10000, '\n');
	cin.getline(n, 1000, '\n');
	name = n;
	//Parsing input as name or number
	if (IsInteger(name))
	{
		int i = stoi(name);
		if (i > 100000 || i < 10000)
		{
			cout << "\nWrong number, must be 10 000 - 99 999\n\n";
			return;
		}
		base.ShowOrderInfo(base.allOrders[i - 10000]);
	}
	else
	{
		base.DrawPersonalData(name);
		base.PrintAllOrders(name);
	}
	cout << "\n \n \n \n";
}
/// <summary>
/// Make new order
/// </summary>
void SecondOption()
{
	cout << "\n \n \n \n";
	Date d1;
	Date d2;
	string choice;
	//ask dates until second is after first
	while (d2 - d1 < 1)
	{
		cout << NewOrder;
		d1 = ReadDate();
		cout << NewOrder2;
		d2 = ReadDate();
	}
	int b = 0;
	//ask for room size until it 1 or 2
	while (b != 1 && b != 2)
	{
		cout << "How many beds do you need (1/2)?\n";
		b = ReadInt();
	}
	int counter = 0;//To print rows with equal number of members
	cout << "\nDo you want to choose room by yourself?(y/n)\n";

	int choosenRoom = -1;
	while (choice != "y" && choice != "n")
	{
		cin >> choice;
	}
	//automaticaly choosen room (first available)
	if (choice == "n")
	{
		if (b == 1)
		{
			for (int i = 0; i < 150; i++)
			{
				if (base.IsFree(i, d1, d2))
				{
					choosenRoom = i;
				}
			}
		}
		if (b == 2)
		{
			for (int i = 159; i < 300; i++)
			{
				if (base.IsFree(i, d1, d2))
				{
					choosenRoom = i;
				}
			}
		}
	}
	//manual choice
	else
	{
		//put out table of rooms with 15 columns
		cout << "\nThese rooms are free for this period: \n";
		if (b == 1)
		{
			for (int i = 0; i < 150; i++)
			{
				if (base.IsFree(i, d1, d2))
				{
					counter++;
					cout << i << ", ";
					if (counter == 14) { cout << endl; counter = 0; }
				}
			}
		}
		if (b == 2)
		{
			for (int i = 159; i < 300; i++)
			{
				if (base.IsFree(i, d1, d2))
				{
					counter++;
					cout << i << ", ";
					if (counter == 14) { cout << endl; counter = 0; }
				}
			}
		}
		//ask for choosing room until it is in right range and isn't occupied
		while (choosenRoom > 150 + (150 * (b - 1)) || choosenRoom < (150 * (b - 1)))
		{
			cout << "\n Which room do you want to order?\n";
			choosenRoom = ReadInt();
			if (!base.IsFree(choosenRoom, d1, d2))
			{
				cout << "This room is occupied.\n";
				choosenRoom = -1;
			}
		}
	}
	//random discount
	int discount = rand() % 3 * 10;
	int sum = (50 + 50 * b) * (d2 - d1);
	//summary
	cout << "\n--------------------------------------\nOne night = " << (50 + 50 * b);
	cout << "\nNights = " << (d2 - d1);
	cout << "\ntotal = " << sum;
	cout << "\nIt will cost " << sum - sum * discount * 0.01f << " (" << discount << "% discount)\n";
	choice = "";
	cout << "\n\nContinue?(y/n): ";
	while (choice != "y" && choice != "n")
	{
		cin >> choice;
	}
	if (choice == "n") return;
	else
	{
		cout << "\nEnter your name :";
		char n[1000];
		cin.clear();
		cin.ignore(10000, '\n');
		cin.getline(n, 1000, '\n');
		auto o = OrderInfo(base.FindFreeOrderNumber(), choosenRoom, d1, d2, n);
		base.RegisterNewOrder(o);
		cout << "\n\nSuccesfully registered!\n\n";
		base.ShowOrderInfo(o);
		cout << "\n \n \n \n";
	}
}


int main()
{
	srand(time(NULL));
	Date d1;
	Date d2;
	bool success = false;
	for (int i = 0; i < 10; i++)base.FillBaseWithRandomOrders();
	int a = 0;
	//main menu
	while (a != 4)
	{
		cout << EnterWindow;
		cout << Answer;
		a = ReadInt();
		string name;
		string choice;
		switch (a)
		{
		case 1:
			FirstOption();
			break;
		case 2:
			SecondOption();
			break;
		case 3:
			for (int i = 0; i < 89999; i++)
			{
				base.ShowOrderInfo(base.allOrders[i]);
			}
			break;
		}
	}
}
int ReadInt()
{
	int result;
	while (true)
	{
		cin >> result;
		if (cin.fail())
		{
			cout << "Incorrect input, try again" << endl;
			cin.clear();
			cin.ignore(10000, '\n');
		}
		else break;
	}
	return result;
}
