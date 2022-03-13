#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

enum Department {English, Math, Philosophy, Theology, Biology, Physics, Chemistry, Engineering, Unknown};

class Person
{
private:
	int ID;
    string firstName;
    string lastName;
	Person* next;
	
public:
	Person();
	Person(int id_in, string first_in, string last_in);
	Person(Person &init);
	~Person();
	// getters
	int getID()
	{
		return ID;
	}
	string getFirstName()
	{
		return firstName;
	}
	string getLastName()
	{
		return lastName;
	}
	Person* getNext()
	{
		return next;
	}
	
	// setters
	void setID(int id_in)
	{
		ID = id_in;
	}
	void setFirstName(string first_in)
	{
		this->firstName = first_in;
	}
	void setLastName(string last_in)
	{
		this->lastName = last_in;
	}
	void setNext(Person* next_in)
	{
		next = next_in;
	}
};

Person* firstPerson = NULL;

Person :: Person()
{
	this->ID = 9999;
	this->firstName = "(null)";
	this->lastName = "(null)";
	this->next = NULL;
}

Person :: Person(int id_in, string first_in, string last_in)
{
	this->ID = id_in;
	this->firstName = first_in;
	this->lastName = last_in;
	this->next = NULL;
}

Person :: Person(Person &init)
{
	this->ID = init.ID;
	this->firstName = "";
	this->lastName = "";
	setFirstName(init.firstName);
	setLastName(init.lastName);
	this->next = init.next;
}

Person :: ~Person()
{
	//idk
}

class Student: public Person
{
private:
	float GPA;
	
public:
	Student();
	Student(int id_in, string first_in, string last_in, float gpa_in);
	Student(Student &init);
	~Student();
	float getGPA()
	{
		return GPA;
	}
	
	void setGPA(float gpa_in)
	{
		GPA = gpa_in;
	}
};

Student :: Student()
{
	this->setID(9999);
	this->setFirstName("(null)");
	this->setLastName("(null)");
	this->GPA = 0.0;
	this->setNext(NULL);
	//printf("Student Default Constructor called.\n");
}

Student :: Student(int id_in, string first_in, string last_in, float gpa_in)
{
	setID(id_in);
	setFirstName(first_in);
	setLastName(last_in);
	this->GPA = gpa_in;
	this->setNext(NULL);
	//printf("Student Constructor called for %s %s.\n", firstName, lastName);
}

Student :: Student(Student &init)
{
	this->setID(init.getID());
	this->setGPA(init.GPA);
	this->setFirstName(init.getFirstName());
	this->setLastName(init.getLastName());
	this->setNext(init.getNext());
	//printf("Student Copy Constructor called.\n");
}

Student :: ~Student()
{
	
}

class Employee: public Person
{
private:
	float salary;
	
public:
	Employee();
	Employee(int id_in, string first_in, string last_in, float salary_in);
	Employee(Employee &init);
	~Employee();
	float getSalary()
	{
		return salary;
	}
	
	void setSalary(float salary_in)
	{
		salary = salary_in;
	}
};

Employee :: Employee()
{
	this->setID(9999);
	this->setFirstName("(null)");
	this->setLastName("(null)");
	this->salary = 0.0;
	this->setNext(NULL);
}

Employee :: Employee(int id_in, string first_in, string last_in, float salary_in)
{
	setID(id_in);
	setFirstName(first_in);
	setLastName(last_in);
	this->salary = salary_in;
	this->setNext(NULL);
}

Employee :: Employee(Employee &init)
{
	this->setID(init.getID());
	this->setSalary(init.salary);
	this->setFirstName(init.getFirstName());
	this->setLastName(init.getLastName());
	this->setNext(init.getNext());
}

Employee :: ~Employee()
{
	
}

class Professor: public Employee
{
private:
	bool tenured;
	Department department;
	
public:
	Professor();
	Professor(int id_in, string first_in, string last_in, float salary_in, bool ten_in, Department dep_in);
	Professor(Professor &init);
	~Professor();
	bool getTenured()
	{
		return tenured;
	}
	Department getDepartment()
	{
		return department;
	}
	
	void setTenured(bool ten_in)
	{
		tenured = ten_in;
	}
	void setDepartment(Department dep_in)
	{
		department = dep_in;
	}
};

Professor :: Professor()
{
	this->setID(9999);
	this->setFirstName("(null)");
	this->setLastName("(null)");
	this->setSalary(0.0);
	this->tenured = false;
	this->department = Unknown;
	this->setNext(NULL);
}

Professor :: Professor(int id_in, string first_in, string last_in, float salary_in, bool ten_in, Department dep_in)
{
	setID(id_in);
	setFirstName(first_in);
	setLastName(last_in);
	setSalary(salary_in);
	this->tenured = ten_in;
	this->department = dep_in;
	this->setNext(NULL);
}