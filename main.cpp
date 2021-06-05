#include <iostream>
#include<string>
#include<cstring>
#include<fstream>
#include<stdio.h>
#include<cstdio>

using namespace std;

//time_t now = time(0);

struct librarian
{
	string username;
	string password;

public:

	librarian()
	{
		this->username = "main";
		this->password = "pass1";

	}
};

struct user
{
	int ID;
	string Name;
	string password;
	char account_type;  //  S, T, G  --> Student, Staff, Guest
	char* creation_date;  // = ctime(&now);
	string contact_numbers[2];

public:

	user()
	{
		ID = 0;
		Name = "";
		password = "pass";
	    account_type = 'G';  // the default account type is to be guest
		 
	}

};


struct book {

	string Title;
	int production_year;
	int number_of_copies;
	string category;
	int	edition;
};

bool buy (int userid, string userpass)
{
	double offset;
	ifstream users;
	users.open("users.txt");
	
		if (users.fail())
			cout << "file couldn't open! ";
while (!users.eof())
{
	geline(users,line);
	
	if((offset = line.find(userid,0)) != string :: npos)
		if((offset = line.find(T,0)) != string :: npos)
	return true; //staff account
	else
		return false;
		
}
	
}

int main()
{
	librarian manager;
	manager.username = "Ramy";
	manager.password = "passmanager";

	librarian employee1;
	employee1.username = "Ahmed";
	employee1.password = "passemployee1";

	librarian employee2;
	employee2.username = "Mina";
	employee2.password = "passemployee2";

	librarian employee3;
	employee3.username = "Ali";
	employee3.password = "passemployee3";

	system("cls");

	cout << "MAIN MENU" << "\n\n\n\n[1] Add a new 'user' account" << "\n\n\[2] add a new Book" << "\n\n[3] Buy a book"
		"\n\n[4] Dispay the report for the new users 7 days ago" << "\n\n[5] Exit";

	cout << "\n\n\n\n choose a number between (1-5)  ";

	int responce;

	cin >> responce;

	system("cls");

	user new_user;
string checkuser;
string checkpass;

	if (responce == 1)
	{
		//case 1: // add new user
		cout<<"Enter the librarian user name: ";
		cin >> checkuser;
		cout << "Enter password: ";
		cin>> checkpass;
		if ((checkuser == manager.username && checkpass == manager.pasword)(checkuser == employee1.username && checkpass == employee1.pasword)
			(checkuser == employee2.username && checkpass == employee2.pasword)(checkuser == employee3.username && checkpass == employee3.pasword))
			{
				ofstream users;
		users.open("users.txt");

		cout << "\n Enter new user's ID: ";
		cin >> new_user.ID;

		cout << "\nEnter new user's name: ";
		cin >> new_user.Name;

		cout << "\nEnter new user's password: ";
		cin >> new_user.password;

		cout << "\n enter new user's account type: ";
		cin >> new_user.account_type;

		cout << "\nenter new user's contact number/s (Max 3): ";
		cin >> new_user.contact_numbers[1];

		cout << "\nEnter creation date: ";
		cin >> new_user.creation_date;  
		users << new_user.account_type << " " << new_user.creation_date << " " << new_user.ID << new_user.Name << " " << new_user.password
			<< "" << new_user.contact_numbers;
		users.close();
			}
			else
				return 0;
	}
	else if (responce == 2)
	{//buy book
		book new_book;

		ofstream books;
		books.open("books.txt");
		cout << "Enter the book title: ";
		cin >> new_book.Title;

		cout << "Enter the book production year: ";
		cin >> new_book.production_year;

		cout << "\nEnter the book edition: ";
		cin >> new_book.edition;

		cout << "\nEnter the book number of copies: ";
		cin >> new_book.number_of_copies;

		cout << "\nEnter the book category: ";
		cin >> new_book.category;

		books << new_book.Title << " " << new_book.production_year << " " << new_book.edition << " " << new_book.category;

		books.close();
	}
	else if (responce == 3) //buy book
	{
		int userID;
		string userpass;
		char acctype;

		cout << "Enter user ID";
		cin >> userID;

		cout << "Enter password";
		cin >> userpass;

		cout << "Enter account type";
		cin >> acctype;

		if (acctype != 'T') {
			cout << "your account type restrict you from buying the book!";
			return 1;
		}
	}
	else if (responce == 4)
	{
		ifstream users("users.txt");

		if (users.fail())
			cout << "file couldn't open! ";
		while (users)
			cout << new_user.account_type << " " << new_user.creation_date << " " << new_user.ID << new_user.Name << " " << new_user.password
			<< "" << new_user.contact_numbers;
		cout << "press enter to exit";
		users.close();
		return 1;

	}
	else
		return 1;

	return 0;

}