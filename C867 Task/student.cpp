//Create Student class and functions
#include <iostream>
#include "degree.h"
#include "student.h"
#include <string>

using namespace std;

		//Constructor
		Student::Student(string aStudentID, string aFirstName, string aLastName, string aEmail, int aAge, int aDaysToCompleteCourse1, int aDaysToCompleteCourse2, int aDaysToCompleteCourse3, string aDegree) 
		{
			studentID = aStudentID;
			firstName = aFirstName;
			lastName = aLastName;
			email = aEmail;
			age = aAge;
			daysToCompleteCourse[0] = {aDaysToCompleteCourse1};
			daysToCompleteCourse[1] = {aDaysToCompleteCourse2};
			daysToCompleteCourse[2] = {aDaysToCompleteCourse3};
			if (aDegree == "SECURITY") {
				degreeProgram = SECURITY;
			}
			else if (aDegree == "NETWORK") {
				degreeProgram = NETWORK;
			}
			else if (aDegree == "SOFTWARE") {
				degreeProgram = SOFTWARE;
			}
			else {
				cout << "Invalid degree program specified" << endl;
			}
		}
		string Student::getStudentID() {
			string pubStudentID;
			pubStudentID = studentID;
			return pubStudentID;
		}
		void Student::setStudentID(string gStudentID) {
			studentID = gStudentID;
		}
		string Student::getFirstName() {
			string pubFirstName;
			pubFirstName = firstName;
			return pubFirstName;
		}
		void Student::setFirstName(string gFirstName) {
			firstName = gFirstName;
		}
		string Student::getLastName() {
			string pubLastName;
			pubLastName = lastName;
			return pubLastName;
		}
		void Student::setLastName(string gLastName) {
			lastName = gLastName;
		}
		string Student::getEmail() {
			string pubEmail;
			pubEmail = email;
			return pubEmail;
		}
		void Student::setEmail(string gEmail) {
			email = gEmail;
		}
		int Student::getAge() {
			int pubAge;
			pubAge = age;
			return pubAge;
		}
		void Student::setAge(int gAge) {
			age = gAge;
		}
		int Student::getCourse1CompletionDays() {
			int course1;
			course1 = daysToCompleteCourse[0];
			return course1;
		}
		int Student::getCourse2CompletionDays() {
			int course2;
			course2 = daysToCompleteCourse[1];
			return course2;
		}
		int Student::getCourse3CompletionDays() {
			int course3;
			course3 = daysToCompleteCourse[2];
			return course3;
		}
		int* Student::getAllCourseCompletionDays() {
			return daysToCompleteCourse;
		}
		void Student::setCourseCompletionDays(int gCourse1, int gCourse2, int gCourse3) {
			daysToCompleteCourse[gCourse1, gCourse2, gCourse3];
		}
		string Student::getDegreeProgram() {
			int pubDegreeNum;
			string pubDegreeName;
			pubDegreeNum = degreeProgram;
			if (pubDegreeNum == SECURITY) {
				return "SECURITY";
			}
			else if (pubDegreeNum == NETWORK) {
				return "NETWORK";
			}
			else if (pubDegreeNum == SOFTWARE) {
				return "SOFTWARE";
			}
			else {
				return "Invalid Degree Program";
			}
		}
		void Student::setDegreeProgram(string gProgramName) {
			if (gProgramName == "SECURITY") {
				degreeProgram = SECURITY;
			}
			else if (gProgramName == "NETWORK") {
				degreeProgram = NETWORK;
			}
			else if (gProgramName == "SOFTWARE") {
				degreeProgram = SOFTWARE;
			}
			else {
				cout << "Invalid Degree Program, no changes made. Please enter a value of SECURITY, NETWORK, or SOFTWARE.";
			}
		}
		void Student::printTableHeader() {
			static string tableHeader = "Values are presented as follows: \nStudent ID | First Name | Last Name | Email | Age | Days to Complete Three Courses | Degree Program\n";
			cout << tableHeader << endl;
		}
		void Student::printStudentRecord(string gStudentID) {
			cout << getStudentID() << "\t";
			cout << getFirstName() << "\t";
			cout << getLastName() << "\t";
			cout << getEmail() << "\t";
			cout << getAge() << "\t";
			cout << getAllCourseCompletionDays()[0] << ", ";
			cout << getAllCourseCompletionDays()[1] << ", ";
			cout << getAllCourseCompletionDays()[2] << "\t";
			cout << getDegreeProgram() << "\t" << endl;
		}