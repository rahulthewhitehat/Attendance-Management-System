#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <sstream>
#include "user.h"
#include <vector>
int Attendance();
int teacherView();
int teacherlogin();

class teacher: public user
{
    string username,password;
public:
    int Attendance();
    int teacherView();
};

int teacherlogin()
{
	system("cls");
	cout<<"\n -------------------- Teacher Login ------------------------";

    string username;
	string password;
	
	cout<<"\n Enter username : ";
	cin>>username;
	cout<<"\n Enter password : ";
	cin>>password;
	
	if(username=="teacher" && password=="teacher@123")
	{   teacherView();
	    getchar();	
       }   
    else
       {
        cout<<"\n Error ! Invalid Credentials...";
        cout<<"\n Press any key for main menu ";
        getchar();getchar();
      }
   
   return 0;
}

#include <limits>

int Attendance() {
    std::cout << "\n ---------------- Mark Attendance -------------------- \n";

    std::ifstream read("db.dat");
    if (!read) {
        std::cerr << "\n Could not open the database file (db.dat)." << std::endl;
        return -1; // Return an error code
    }

    std::string filename;
    while (getline(read, filename)) {
        std::ifstream studentFile(filename);
        if (!studentFile) {
            std::cerr << "Cannot open file: " << filename << std::endl;
            continue; // Skip to the next iteration of the loop
        }

        std::string studentName;
        getline(studentFile, studentName); // Get the student's name, which is the first line in the file
        studentFile.close();

        std::cout << "Name: " << studentName << std::endl; // Display only the student's name

        std::cout << "1: Present" << "\t" << "0 : Absent" << std::endl;
        std::cout << "Enter choice: ";
        int presence;
        std::cin >> presence;

        // Open the file to read the current attendance and update it
        std::ifstream readAttendance(filename);
        std::string line;
        std::vector<std::string> lines;
        while (getline(readAttendance, line)) {
            lines.push_back(line); // Store all lines in a vector
        }
        readAttendance.close();

        // Check if the attendance count line is a valid integer
        int attendanceCount = 0;
        if (!lines.empty()) {
            std::string attendanceLine = lines.back();
            try {
                attendanceCount = std::stoi(attendanceLine);
            } catch (const std::invalid_argument& e) {
                std::cerr << "Invalid attendance count in file: " << filename << std::endl;
                continue; // Skip to the next student
            }
        }

        if (presence == 1) {
            attendanceCount++; // Increment the attendance count
        } else if(presence==0) {
            absent++;
        } else if (presence != 0) {
            std::cout << "Invalid input. Please enter 1 for present or 0 for absent." << std::endl;
            continue; // Ask for the input again or handle error
        }

        // Now open the file to write the updated attendance count
        std::ofstream writeAttendance(filename);
        if (!writeAttendance) {
            std::cerr << "Cannot open file for writing: " << filename << std::endl;
            continue; // Skip to the next student
        }

        // Write all the lines back to the file along with the updated attendance
        for (size_t i = 0; i < lines.size() - 1; ++i) {
            writeAttendance << lines[i] << std::endl;
        }
        writeAttendance << attendanceCount << std::endl; // Write the new count as the last line

        std::cout << "Attendance marked as " << (presence == 1 ? "present" : "absent") << " for " << studentName << std::endl;
    }

    std::cout << "\n Press any key to continue.." << std::endl;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore the newline left in the input buffer
    std::cin.get(); // Wait for user input
    return 0;
}

int teacherView()
{	
    int goBack = 0;
    while(1)
    {
		system("cls");
		cout<<"\n 1 Mark Attendance";
		cout<<"\n 0. Log Out & Go Back <- \n";
		int choice;
		cout<<"\n Enter you choice: ";
		cin>>choice;
		
		switch(choice)
		{
			case 1: Attendance();break;  
			case 0: goBack = 1;break;
	                default: cout<<"\n Invalid choice. Enter again ";
	                 getchar();           	
	   }   
	   
	   if(goBack == 1)
	   {
	   	break; 
           }
   }
   return 0;
}