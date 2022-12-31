//============================================================================
// Name        : Assignment_02.cpp
// Author      : Ritanshu Koul
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
using namespace std;

class Student{
	static int total_students;
	string name,blood_group,contact_address,classs,date_of_birth,telephone_number;
	int roll_number,division;
public:
	// Friend Function Declaration
	friend void access_values(Student);

	// Friend Class
	friend class Display;

	// Inline Function
	inline void getName(){
		cout << "Name = " << name << endl;
	}
	inline void getRollnumber(){
		cout << "Roll Number = " << roll_number << endl;
	}
	inline void getDivision(){
		cout << "Division = " << division << endl;
	}
	inline void getContact(){
		cout << "Contact Address = " << contact_address << endl;
	}
	inline void getClass(){
		cout << "Class = " << classs << endl;
	}
	inline void getDateofBirth(){
		cout << "Date of Birth = " << date_of_birth << endl;
	}
	inline void getTelephone(){
		cout << "Telephone Number = " << telephone_number << endl;
	}
	inline void getBloodGroup(){
		cout << "Blood Group = " << blood_group << endl;
	}
	Student(){
			name = "Ritanshu";
			blood_group = "B+";
			contact_address = "PICT,Pune";
			roll_number = 21167;
			classs = "SE";
			division = 1;
			date_of_birth = "22/10/2003";
			telephone_number = "8825123456";
			total_students += 1;
		}
	Student(string n,string blood,string contact,int roll,string classss,int div,string dob,string tele){
		this->name = n;
		blood_group = blood;
		contact_address = contact;
		roll_number = roll;
		classs = classss;
		division = div;
		date_of_birth = dob;
		telephone_number = tele;
		total_students += 1;
	}
	// Copy Constructor
	Student(Student& s1){
		this->name = s1.name;
		this->blood_group = s1.blood_group;
		this->contact_address = s1.contact_address;
		this->classs = s1.classs;
		this->date_of_birth = s1.date_of_birth;
		this->telephone_number = s1.telephone_number;
		this->roll_number = s1.roll_number;
		this->division = s1.division;
		total_students += 1;
	}
	void setValues(){
		cout << "Enter the name of the student: ";
		cin >> name;
		cout << "Enter the blood group of the student: ";
		cin >> blood_group;
		cout << "Enter the contact address of the student: ";
		cin >> contact_address;
		cout << "Enter the roll number of the student: ";
		cin >> roll_number;
		cout << "Enter the class of the student: ";
		cin >> classs;
		cout << "Enter the division of the student; ";
		cin >> division;
		cout << "Enter the date of birth of the student: ";
		cin >> date_of_birth;
		cout << "Enter the mobile number of the student: ";
		cin >> telephone_number;
	}
	void getValues(){
		cout << "-------------------------------------------------------" << endl;
		cout << "Displaying Information of Student: " << endl;
		cout << "Name of the student -> " << name << endl;
		cout << "Blood Group of Student -> " << blood_group << endl;
		cout << "Contact Address is -> " << contact_address << endl;
		cout << "Roll Number -> " << roll_number << endl;
		cout << "Class -> " << classs << endl;
		cout << "Division of the student -> " << division << endl;
		cout << "Date of birth of the student -> " << date_of_birth << endl;
		cout << "Mobile Number of the Student -> " << telephone_number << endl;
		cout << "-------------------------------------------------------" << endl;
	}
	static void getStudentCount(){
		cout << "TOTAL NUMBER OF STUDENTS = " << total_students << endl;
	}
	~Student()
	{
		cout << "=> Record of Student deleted." << endl;
	}
};


class Display{
public:
	void showmembers(Student &m){
		cout << "-------------------------------------------------------" << endl;
				cout << "Displaying Information of Student: " << endl;
				cout << "Name of the student -> " << m.name << endl;
				cout << "Blood Group of Student -> " << m.blood_group << endl;
				cout << "Contact Address is -> " << m.contact_address << endl;
				cout << "Roll Number -> " << m.roll_number << endl;
				cout << "Class -> " << m.classs << endl;
				cout << "Division of the student -> " << m.division << endl;
				cout << "Date of birth of the student -> " << m.date_of_birth << endl;
				cout << "Mobile Number of the Student -> " << m.telephone_number << endl;
				cout << "-------------------------------------------------------" << endl;
	}
};


int Student::total_students = 0;
// Friend Function
void access_values(Student a){
	cout << "-------------------------------------------------------" << endl;
	cout << "Hello! Currently Friend Function is working." << endl;
	cout << "Displaying Information of Student: " << endl;
	cout << "Name of the student -> " << a.name << endl;
	cout << "Blood Group of Student -> " << a.blood_group << endl;
	cout << "Contact Address is -> " << a.contact_address << endl;
	cout << "Roll Number -> " << a.roll_number << endl;
	cout << "Class -> " << a.classs << endl;
	cout << "Division of the student -> " << a.division << endl;
	cout << "Date of birth of the student -> " << a.date_of_birth << endl;
	cout << "Mobile Number of the Student -> " << a.telephone_number << endl;
	cout << "Friend Function Over" << endl;
	cout << "-------------------------------------------------------" << endl;
}

int main() {
	Student firstStudent;
	firstStudent.setValues();
	firstStudent.getValues();
	Student x = firstStudent;
	x.getValues();
	Student secondStudent;
	secondStudent.getValues();
	Student thirdStudent("Ritanshu","B+","1234566788",21212,"SE",1,"123456","987654321");
	thirdStudent.getValues();
	Student *d = new Student;
	d->setValues();
	d->getValues();
	delete d;
	Student *e = new Student("Ritanshu","B+","1234566788",21212,"SE",1,"123456","987654321");
	e->getValues();
	delete e;
	access_values(thirdStudent);
	thirdStudent.getName();
	secondStudent.getDivision();
	firstStudent.getClass();
	return 0;
}
