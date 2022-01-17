//Create Student class and functions
#pragma once
#include <iostream>
#include "degree.h"
#include <string>

using namespace std;


class Student {
private:
	string studentID, firstName, lastName, email;
	int age;
	int daysToCompleteCourse[3] = { 0 };
	eDegreeProgram degreeProgram;

public:
	//Constructor Declarations
	Student(string aStudentID, string aFirstName, string aLastName, string aEmail, int aAge, int aDaysToCompleteCourse1, int aDaysToCompleteCourse2, int aDaysToCompleteCourse3, string aDegree);
	
	//Function Declarations
	string getStudentID();

	void setStudentID(string gStudentID);

	string getFirstName();

	void setFirstName(string gFirstName);

	string getLastName();

	void setLastName(string gLastName);

	string getEmail();

	void setEmail(string gEmail);

	int getAge();

	void setAge(int gAge);

	int getCourse1CompletionDays();

	int getCourse2CompletionDays();

	int getCourse3CompletionDays();

	int* getAllCourseCompletionDays();

	void setCourseCompletionDays(int gCourse1, int gCourse2, int gCourse3);

	string getDegreeProgram();

	void setDegreeProgram(string gProgramName);

	static void printTableHeader();
	
	void printStudentRecord(string gStudentID);

};