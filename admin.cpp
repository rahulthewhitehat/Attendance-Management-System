#include <iostream>
#include <string>
#include <fstream>
#include "user.h"
#include <iomanip>
using namespace std;
int absent;
class Admin : public user
{   private:
    string username,password;
public:
    int deleteAllStudents();
    int checkListOfStudentsRegistered();
    int registerStudent();
};

int adminView(); 
int deleteAllStudents();      
int checkListOfStudentsRegistered(); 
int adminLogin();
int registerStudent();
int m = 0;
int k = 0;

int adminLogin()
{
	system("cls");
	cout<<"\n --------------------------------- Admin Login ---------------------------------------";

    string username;
	string password;
	
	cout<<"\n Enter username : ";
	cin>>username;
	cout<<"\n Enter password : ";
	cin>>password;
	
	if(username=="admin" && password=="admin@123")
	{
	    adminView();
	    getchar();	
       }   
    else
       {
        cout<<"\n Error ! Invalid Credentials..Try Again!!!";
        cout<<"\n Press any key for Main Menu! ";
        getchar();getchar();
      }
   return 0;
}

int adminView()
{	
    int goBack = 0;
    while(1)
    {
		system("cls");
		cout<<"\n 1 => Register a Student";
		cout<<"\n 2 => Delete all registered students";
		cout<<"\n 3 => Check List of all registered students";
		cout<<"\n 0 => Log Out & Go Back <- \n";
		int choice;
		
		cout<<"\n Enter you choice: ";
		cin>>choice;
		
		switch(choice) {
            case 1:
                registerStudent();
                break;
            case 2:
                deleteAllStudents();
                break;
            case 3:
                checkListOfStudentsRegistered();
                break;
            case 0:
                goBack = 1;
                break;
            default:
                cout << "\n Invalid choice. Enter again! ";
                getchar();
        }
	   if(goBack == 1)
	   {
	   	break; 
           }
   }
   return 0;
}

int deleteAllStudents()
{
	remove("db.dat");
    cout<<"\n All Records are cleared!";
	cout<<"\n Please any key to continue..";
	
	getchar(); getchar();
	return 0;
}


int checkListOfStudentsRegistered() {
    cout << "\n---------------- List of Student Registered by Name ----------------\n\n\n";
    cout << "------------------------------------------------------------------------" << endl;
    cout << left << setw(20) << "Name" << setw(20) << "Present" << setw(20) << "Absent"<< endl;
    cout << "------------------------------------------------------------------------" << endl;

    //check if record already exists...
    ifstream read;
    read.open("db.dat");

    if (read) {
        string line;
        while (getline(read, line)) {
            string filename = line;
            ifstream read1;
            read1.open(filename.c_str(), ios::app);

            string name, attendance;
            if (read1) {
                // Assuming name is the first line in the file
                getline(read1, name); // Get the student's name
                // Assuming attendance is the last line in the file
                while (getline(read1, line)) {
                    attendance = line; // Keep overwriting 'attendance' until we get to the last line
                }
                cout << left << setw(20) << name << setw(20) << attendance  << absent <<endl;
            }
            read1.close();
        }
        read.close();
    } else {
        cout << "\nNo Record found :(" << endl;
    }

    cout << "\nPress any key to continue.." << endl;
    getchar(); getchar();
    return 0;
}

int registerStudent()
{
    cout<<"\n --------------- Form to Register Student ------------------- \n";
    string name, username, password, rollno, branch;
    int total;

    cout<<"\n Enter Name : ";     cin>>name;
    cout<<"\n Enter Username : ";     cin>>username;
    cout<<"\n Enter Password : ";     cin>>password;
    cout<<"\n Enter Roll No: ";     cin>>rollno;
    getchar();
    cout<<"\n Enter branch : ";     cin>>branch;
	cout<<"\n Enter initial number of Presents :"; cin>>m;
    cout<<"\n Initial Number of Absents: "; cin>>absent;

    //check if record already exist..
    ifstream read;
    read.open("db.dat");
    
    if(read)
    {      int recordFound =0; 
	   string line;
    	    while(getline(read, line)) {
        	if(line == username+".dat" )
        	{
        		recordFound = 1 ;
        	    break;
			}
        }
        if(recordFound == 1)
        {
        	cout<<"\n Username already registered. Please choose another username! ";
        	getchar(); getchar();
        	read.close();
        	return 0;
		}
	}
    read.close();

    ofstream out;
	out.open("db.dat", ios::app);
	out<<username+".dat"<<"\n";
	out.close();

	ofstream out1;
	string temp = username+".dat";
	out1.open(temp.c_str());
	out1<<name<<"\n"; 	out1<<username<<"\n"; 	out1<<password<<"\n";
	out1<<rollno<<"\n"; 	out1<<branch<<"\n";
	out1<<m<<"\n";
	out1.close();
	cout<<"\n Student Registered Successfully !!";
    cout<<"\n Please any key to continue...";
	getchar(); getchar();
	return 0;		
}
