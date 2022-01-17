#pragma once
#include <iostream>
#include <string>
#include "student.h"
#include "degree.h"
using namespace std;

class Roster {
	public:
		//const declaration so that the array will accept it
		const static int numStudents = 5;
		int index = -1;

		//Array of Pointers to hold the studentData table
		Student* classRosterArray[numStudents];

		//Declaration of parse function used to parse the studentData table's data
		void parseTableData(const string StudentData[]);

		//Declaration of the rest of the functions
		void addToRoster(string pStuID, string pFirstName, string pLastName, string pEmail, int pAge, int pCourse1, int pCourse2, int pCourse3, string pDegreeProg);

		void removeFromRoster(string pStuID);

		void printAllStudents();

		void printAverageDaysInCourse(string pStuID);

		void printInvalidEmails();

		void printByDegreeProgram(string degreeProgramString);

		~Roster();
};