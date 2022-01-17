#include <iostream>
#include <string>
#include "degree.h"
#include "roster.h"
using namespace std;

void Roster::parseTableData(const string StudentData[]) {
	for(int i = 0; i <= (numStudents - 1); i++) {
		//Getting Student ID
		int right = StudentData[i].find(","); //Find first comma, should be index value 2
		string pStuID = StudentData[i].substr(0, right); //Substring starting at index 0, will contain 2 values as that is the current value of right

		//Getting First Name
		int left = right + 1; //Move past first comma, into second value container. Variable left should be set to 3 currently.
		right = StudentData[i].find(",", left); //Set variable right to index value of the comma after index variable left. Value is dependant on how long the first name is.
		string pFirstName = StudentData[i].substr(left, right - left); //Substring starting at index position left. Includes a number of characters equal to the value of right minus left

		//Getting Last Name
		left = right + 1; //Move past second comma, into the third value container.
		right = StudentData[i].find(",", left); //Moves the right variable to the next comma after the variable left
		string pLastName = StudentData[i].substr(left, right - left);

		//Getting Email Address
		left = right + 1; //Move past third comma, into the fourth value container.
		right = StudentData[i].find(",", left); //Moves the right variable to the next comma after the variable left
		string pEmail = StudentData[i].substr(left, right - left);

		//Getting Age
		left = right + 1;
		right = StudentData[i].find(",", left);
		string stringAge = StudentData[i].substr(left, right - left);
		int pAge = stoi(stringAge); //stoi called to convert string variable stringAge to an int.

		//Getting First Course Completion Days
		left = right + 1;
		right = StudentData[i].find(",", left);
		string stringCourse1 = StudentData[i].substr(left, right - left);
		int pCourse1 = stoi(stringCourse1);

		//Getting Second Course Completion Days
		left = right + 1;
		right = StudentData[i].find(",", left);
		string stringCourse2 = StudentData[i].substr(left, right - left);
		int pCourse2 = stoi(stringCourse2);

		//Getting Third Course Completion Days
		left = right + 1;
		right = StudentData[i].find(",", left);
		string stringCourse3 = StudentData[i].substr(left, right - left);
		int pCourse3 = stoi(stringCourse3);

		//Getting Degree Program
		left = right + 1;
		//We no longer need to reassign variable right, as there is no comma to end the data entry.
		string pDegreeProg = StudentData[i].substr(left, string::npos); //using npos as we do not update the variable right. npos will take us to the end of the string when used in len

		addToRoster(pStuID, pFirstName, pLastName, pEmail, pAge, pCourse1, pCourse2, pCourse3, pDegreeProg); //call function to add parsed student data to Roster
	}
}

void Roster::addToRoster(string pStuID, string pFirstName, string pLastName, string pEmail, int pAge, int pCourse1, int pCourse2, int pCourse3, string pDegreeProg) {
	classRosterArray[++index] = new Student(pStuID, pFirstName, pLastName, pEmail, pAge, pCourse1, pCourse2, pCourse3, pDegreeProg); //simple function to add a student to a roster in the class roster array under a new index value
}

void Roster::removeFromRoster(string pStuID) {
	bool studentFound = false;
	for (int i = 0; i <= index; i++) { 
		if (classRosterArray[i]->Student::getStudentID() == pStuID) { 
			studentFound = true;
			if (i < numStudents - 1) {
				Student* placeholder = classRosterArray[i];
				classRosterArray[i] = classRosterArray[numStudents - 1];
				classRosterArray[numStudents - 1] = placeholder;
			}
			index--; 
		}
	}
	if (studentFound){
		cout << "Student " << pStuID << " has been removed from the roster." << endl << endl;
		this->printAllStudents();
	}
	else {
		cout << "Student " << pStuID << " not found." << endl << endl;
	}
}
void Roster::printAllStudents() {
	Student::printTableHeader();
	for (int i = 0; i <= index; i++) {
		classRosterArray[i]->Student::printStudentRecord("A" + (i + 1));
	};
	cout << endl;
}
void Roster::printAverageDaysInCourse(string pStuID) {
	for (int i = 0; i <= index; i++) {
		string tmpID = classRosterArray[i]->Student::getStudentID();
		if (tmpID == pStuID) {
			cout << "Average time to complete a course for student " << pStuID << ": ";
			cout << (classRosterArray[i]->Student::getCourse1CompletionDays() + classRosterArray[i]->Student::getCourse2CompletionDays() + classRosterArray[i]->Student::getCourse3CompletionDays()) / 3 << endl;
		}
	}
}
void Roster::printInvalidEmails() {
	bool invalidFound;
	bool noInvalids;
	int invalidCount = 0;
	cout << "Invalid Email Addresses:" << endl;
	for (int i = 0; i <= index; i++) {
		string tmpEmail = classRosterArray[i]->getEmail();
		if (tmpEmail.find(' ') < 200) {
			invalidFound = true;
			invalidCount++;
			cout << tmpEmail << " - Invalid due to whitespace rules." << endl;
		} 
		else if (tmpEmail.find('@') > 200) {
			invalidFound = true;
			invalidCount++;
			cout << tmpEmail << " - Invalid due to missing '@' rules." << endl;
		}
		else if (tmpEmail.find('.') > 200) {
			invalidFound = true;
			invalidCount++;
			cout << tmpEmail << " - Invalid due to missing '.' rules." << endl;
		}
		else {
			invalidFound = false;
		}
	}
	if (!invalidFound && invalidCount == 0) {
		cout << "No invalid emails found." << endl;
	}
	cout << endl;
}
void Roster::printByDegreeProgram(string degreeProgram) {
	cout << "Students in the " << degreeProgram << " program are as follows:" << endl;
	for (int i = 0; i <= index; i++) {
		string tmpDegree = classRosterArray[i]->getDegreeProgram();
		if (tmpDegree == degreeProgram) {
			string tmpID = classRosterArray[i]->getStudentID();
			classRosterArray[i]->printStudentRecord(tmpID);
		}
		else if (tmpDegree != degreeProgram) {

		}
		else {
			cout << "No students found in degree program " << degreeProgram << endl;
		}
	}
	cout << endl;
}
Roster::~Roster() {
	cout << "Destruction is imminent..." << endl;
	for (int i = 0; i < numStudents; i++) {
		delete classRosterArray[i];
		classRosterArray[i] = nullptr;
	}
	cout << "Destruction complete, memory has been released." << endl;
}

//{ "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY", "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK", "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY", "A5,Dominik,Tolman,dtolma4@wgu.edu,27,14,70,21,SOFTWARE"}