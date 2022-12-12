#pragma once
#include <iostream>
#include<string> 
using namespace std;
const string monthNames[]{ "January","February","March","April","May","June","July","August","September","October","November","December" };
const int monthLengths[]{ 31,28,31,30,31,30,31,31,30,31,30,31 };
extern const string Names[];
extern const string Surnames[];
extern const string EnterWindow; 
extern const string Answer;
extern const string EnterWindow;
extern const string ReservationWindow;
extern const string DrawPersData;
extern const string NewOrder;
extern const string NewOrder2;

struct Date
{

private:
	int day;//day starting with one
	int month;//month number starting with zero
	int year = 22;
public:
	Date()
	{
		day = 1;
		month = 0;
		year = 22;
	}
	Date(int _day, int _month, int _year)
	{
		this->SetDate(_day, _month, _year);
	}
	void SetDate(int _day, int _month, int _year)
	{
		if (_month > 12 || _month < 1)
		{
			cout << _month << endl;
			cout << "Incorrect input. Try again\n";
			return;
		}
		if (_day > monthLengths[_month - 1] || _day < 1)
		{
			cout << "Incorrect input, day with this number doesn't appear to be in " << monthNames[_month - 1] << ". Try again\n";
			return;
		}
		day = _day;
		month = _month - 1;
		year = _year;
	};
	void SetDate(int _day, int _month, int _year, bool& success)
	{
		if (_month > 12 || _month < 1)
		{
			cout << _month << endl;
			cout << "Incorrect input. Try again\n";
			success = false;
			return;
		}
		if (_day > monthLengths[_month - 1] || _day < 1)
		{
			cout << "Incorrect input, day with this number doesn't appear to be in " << monthNames[_month - 1] << ". Try again\n";
			success = false;
			return;
		}
		day = _day;
		month = _month - 1;
		year = _year;
		success = true;
	}
	/// <summary>
	/// Get date in form of "the Xth day of Xber";
	/// </summary>
	/// <returns>String line with date</returns>
	string GetDate()
	{
		string date = "the " + to_string(day);
		switch (day % 10)
		{
		case 1:
			date.append("st");
			break;
		case 2:
			date.append("nd");
			break;
		case 3:
			date.append("rd");
			break;
		default:
			date.append("th");
			break;

		}
		date.append(" day of ");
		date.append(monthNames[month]);
		return date;
	}
	/// <returns>number of nights or -1 if incorrect input</returns>
	int operator - (Date date2)
	{
		if (month == date2.month)
		{
			if (year == date2.year)
			{
				if (day - date2.day < 0)return -1;
				return day - date2.day;
			}
		}
		else
		{
			int fromSecondToEnd = monthLengths[date2.month] - date2.day;
			int result = fromSecondToEnd;

			//check if year changes
			int countTo = month;
			if (date2.month > month && date2.year<year)countTo += 12;
			if (date2.month > month && date2.year >= year)
			{
				return -1;//error
			}
			for (int i = date2.month + 1; i < countTo; i++)
			{
				if (i <= 11)result += monthLengths[i];
				else result += monthLengths[i - 12];
			}
			result += day;
			return result;
		}
	}
};
struct OrderInfo
{
private:
	int number;//Number of order(10000-99999)
	int room;//Number of room
	Date arrivalDate;
	Date departureDate;
	string ordererName;
public:

	OrderInfo()
	{
		number = 0;
		room = 0;
		arrivalDate = Date();
		departureDate = Date();
	};
	OrderInfo(int _number, int _room, Date _ar, Date _dep, string _name)
	{
		number = _number;
		room = _room;
		arrivalDate = _ar;
		departureDate = _dep;
		ordererName = _name;
	}
	int GetOrderNumber() { return number; }
	int GetRoomNumber() { return room; }
	Date GetArrival() { return arrivalDate; }
	Date GetDeparture() { return departureDate; }
	string GetName() { return ordererName; }
};

static struct Base
{
public:
	void DrawPersonalData(string name)
	{
		cout << "X---------------------Orders----------------------------X\n" << "All orders of " << name << endl;
	}
	void ShowOrderInfo(OrderInfo o)
	{
		if (o.GetName() == "") { return; }
		cout << "X-----Order #" << o.GetOrderNumber() << " info:-----------\n";
		cout << "|Room number - " << o.GetRoomNumber() << endl;
		cout << "|Orderer's name - " << o.GetName() << endl;
		cout << "|Arrival time - " << o.GetArrival().GetDate() << " after 12PM" << endl;
		cout << "|Departure time - " << o.GetDeparture().GetDate() << " before 12PM" << endl;
	}
	OrderInfo roomsFor1[150][300]{};//Array with data about room occupancy, each row contains timeline of booking for this room
	OrderInfo roomsFor2[150][300]{};
	int orderNumbers[90000];
	Base()
	{
	}
	/// <summary>
	/// Is certain room free for some period of time?
	/// </summary>
	/// <param name="number"> - Number of room</param>
	/// <param name="ar"> - Arrival date</param>
	/// <param name="dep"> - Departure date</param>
	/// <returns>true, if free</returns>
	bool IsFree(int number, Date ar, Date dep)
	{
		OrderInfo* orders;
		if (number >= 150)
		{
			orders = roomsFor2[(number - 150)];
		}
		else orders = roomsFor1[number];
		for (int i = 0; i < 300; i++)
		{
			OrderInfo o = *orders;
			if (o.GetOrderNumber() < 10000)break;
			if (DoTwoPeriodsIntersect(ar, dep, o.GetArrival(), o.GetDeparture()))return false;
			orders++;
		}
		return true;
	}
	bool DoTwoPeriodsIntersect(Date d11, Date d12, Date d21, Date d22)
	{
		if (d21 - d11 == -1 && d11 - d22 == -1)return true;
		if (d21 - d12 == -1 && d12 - d22 == -1)return true;
		if (d21 - d11 == -1 && d12 - d22 == -1)return true;
		if (d21 - d12 == -1 && d11 - d22 == -1)return true;
		return false;
	}
	void FillBaseWithRandomOrders()
	{
		for (int i = 0; i < 300; i++)
		{
			int a = rand() % 5;
			if (a == 0)
			{
				Date ar;
				Date dep;
				do
				{
					int m1 = 1 + rand() % 12;
					int d1 = 1 + rand() % monthLengths[m1 - 1];
					int y1 = 22 + rand() % 2;
					ar = Date(d1, m1, y1);
					int m2 =1+ rand() % 12;
					int d2 = 1 + rand() % monthLengths[m2-1];
					int y2 = 22 + rand() % 2;
					dep = Date(d2, m2, y2);
				} while (dep - ar < 1);
				string ordererName = (Names[rand() % 100]);
				ordererName.append(" ");
				ordererName.append(Surnames[rand() % 100]);
				if (IsFree(i, ar, dep))RegisterNewOrder(OrderInfo(FindFreeOrderNumber(), i, ar, dep, ordererName));
			}
		}
	}
	int FindFreeOrderNumber()
	{
		int i;
		do
		{
			i = rand()%30000 + rand() % 30000+ rand() % 39999;
		} while (orderNumbers[i] == 1);
		return i + 10000;
	}
	OrderInfo allOrders[90000];
	void RegisterNewOrder(OrderInfo order)
	{
		if (order.GetOrderNumber() < 10000)
		{
			cout << "Wrong order number\n"; 
			return;
		}
		orderNumbers[order.GetOrderNumber() - 10000] = 1;
		int roomId = order.GetRoomNumber();
		if (roomId > 150)
		{
			roomId -= 150;
			for (int i = 0; i < 300; i++)
			{
				OrderInfo& r = roomsFor2[roomId][i];
				if (r.GetOrderNumber() == 0)
				{
					r = order;
					return;
				}
			}
			cout << "Error in registering: Not enough space";
		}
		else
		{
			for (int i = 0; i < 300; i++)
			{
				OrderInfo& r = roomsFor1[roomId][i];
				if (r.GetOrderNumber() == 0)
				{
					r = order;
					allOrders[order.GetOrderNumber() - 10000] = order;
					return;
				}
			}
			cout << "Error in registering: Not enough space";
		}

	}
	void PrintAllOrders(string name)
	{
		for (auto o : allOrders)
		{
			if (o.GetName() == name)
			{
				ShowOrderInfo(o);
			}
		}
	};
}base;
