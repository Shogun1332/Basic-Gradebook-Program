#include <iostream>
#include "student.h"
#include "degree.h"
#include "roster.h"
using namespace std;

void courseInfo() {
	string courseTitle = "C867 | Scripting and Programming - Applications";
	string langUsed = "Language: C++";
	string wguStuID = "Student ID: 001165536";
	string authorName = "Name: Dominik Tolman";
	string result = courseTitle + "\n" + langUsed + "\n" + wguStuID + "\n" + authorName;
	cout << result << endl << endl;
	}



int main()
{
	const string studentData[5] = { 
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Dominik,Tolman,dtolma4@wgu.edu,27,14,70,21,SOFTWARE"
	};
	courseInfo();
	Roster classRoster;
	classRoster.parseTableData(studentData);
	classRoster.printAllStudents();
	cout << endl;
	classRoster.printInvalidEmails();
	
	cout << "Average completion times:" << endl;
	for (int i = 0; i < Roster::numStudents; i++) {
		classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->getStudentID());
		}
	cout << endl;

	classRoster.printByDegreeProgram("SOFTWARE");
	classRoster.removeFromRoster("A3");
	classRoster.removeFromRoster("A3"); //This should provide an error, it does - good
		
	return 0;
}