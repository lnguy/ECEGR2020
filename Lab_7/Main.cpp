#include <iostream>
#include <sstream>
#include <cstring>
#include <fstream>
#include <typeinfo>
#include <stdlib.h> 

using namespace std;

// Class comparison
template <class DstType, class SrcType>
bool instanceof(const SrcType* src)
{
  return dynamic_cast<const DstType*>(src) != nullptr;
}

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
	virtual ~Person();
	Person& operator=(Person const &p)
	{
		this->ID = p.ID;
		setFirstName(p.firstName);
		setLastName(p.lastName);
		this->next = p.next;
		//printf("Student Assignment Operator called.\n");
		return *this;
	}
	
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
	//delete this;
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
	//delete this;
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
	//delete this;
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

Professor :: Professor(Professor &init)
{
	this->setID(init.getID());
	this->setSalary(init.getSalary());
	this->setFirstName(init.getFirstName());
	this->setLastName(init.getLastName());
	this->setTenured(init.tenured);
	this->setDepartment(init.department);
	this->setNext(init.getNext());
}

Professor :: ~Professor()
{
	//delete this;
}

void readUniversityRecords(void);
void readList(void);
void saveList(void);
void insertNode(Person* person_in);
void deleteNode(Person* person_in);
void addToList();
void removeFromList(int id_in);
void updateList(int id_in);
void menuDisplay(void);
void addMenuDisplay(void);
void updateStudentMenu(string first, string last);
void updateProfessorMenu(string first, string last);
void updateEmployeeMenu(string first, string last);

int main()
{
	system("Color 0E"); // background color black, text color yellow
	int user_in = 0;
	readUniversityRecords();
	do
	{
		int userID_in;
		//Person* idCheck = firstPerson;
		
		menuDisplay();
		cout << "\nWhat would you like to do? ";
		cin >> user_in;
		
		switch(user_in)
		{
			case 1 :
			{
				readList();
				break;
			}
			case 2 :
			{
				addToList();
				break;
			}
			case 3 : 
			{
				printf("\nEnter the ID of the person you wish to delete: "); // Prompts the user to enter an input.
				cin >> userID_in; // Scans the input into the userID_in variable that was declared at the beginning of the do-while loop.
				removeFromList(userID_in);// Takes the scanned userID_in and removes a student from the linked list by searching for userID_in.
				break; // Leave the switch-case.
			}
			case 4 :
			{
				printf("\nEnter the ID of the person you wish to update: "); // Prompts the user to enter an input.
				cin >> userID_in; // Scans the input into the userID_in variable that was declared at the beginning of the do-while loop.
				updateList(userID_in); // Takes the scanned userID_in and updates the student based on the user input for any attribute of the student based on userID_in.
				break; // Leave the switch-case.
			}
			case 5 :
			{
				printf("\nExiting University Program..."); // Let the user know the program is closing.
				break; // Leave the switch-case.
			}
		}
		
	}while(user_in != 5);
	saveList();
}

void readUniversityRecords()
{
	ifstream readRecords;
	int totalPeople = 0;
	readRecords.open("UniversityRecords.txt.");
	if(!readRecords.is_open())
	{
		cerr << "Could not open file: UniversityRecords.txt" << endl;
	}
	else
	{
		string temp = "";
		readRecords >> temp;
		readRecords >> temp;
		readRecords >> temp;
		readRecords >> totalPeople;
		cout << "\nNumber of People: " << totalPeople << "\n";
		for(int i = 0; i < totalPeople; i++)
		{
			readRecords >> temp;
			if(temp == "Student")
			{
				int read_id = 0;
				string read_first = "";
				string read_last= "";
				float read_gpa = 0.0;
				readRecords >> temp;
				readRecords >> read_id;
				readRecords >> temp;
				readRecords >> temp;
				readRecords >> read_first;
				readRecords >> temp;
				readRecords >> temp;
				readRecords >> read_last;
				readRecords >> temp;
				readRecords >> read_gpa;
				
				Person* newStudent = new Student(read_id, read_first, read_last, read_gpa);
				insertNode(newStudent);
			}
			else if(temp == "Professor")
			{
				int read_id = 0;
				string read_first = "";
				string read_last= "";
				float read_salary = 0.0;
				bool read_ten = false;
				Department read_dep = Unknown;
				readRecords >> temp;
				readRecords >> read_id;
				readRecords >> temp;
				readRecords >> temp;
				readRecords >> read_first;
				readRecords >> temp;
				readRecords >> temp;
				readRecords >> read_last;
				readRecords >> temp;
				readRecords >> read_salary;
				readRecords >> temp;
				readRecords >> read_ten;
				readRecords >> temp;
				readRecords >> temp;
				if(temp == "English")
				{
					read_dep = English;
				}
				else if(temp == "Math")
				{
					read_dep = Math;
				}
				else if(temp == "Philsophy")
				{
					read_dep = Philosophy;
				}
				else if(temp == "Theology")
				{
					read_dep = Theology;
				}
				else if(temp == "Biology")
				{
					read_dep = Biology;
				}
				else if(temp == "Physics")
				{
					read_dep = Physics;
				}
				else if(temp == "Chemistry")
				{
					read_dep = Chemistry;
				}
				else if(temp == "Engineering")
				{
					read_dep = Engineering;
				}
				else
				{
					read_dep = Unknown;
				}
				
				Person* newProfesor = new Professor(read_id, read_first, read_last, read_salary, read_ten, read_dep);
				insertNode(newProfesor);
			}
			else if(temp == "Employee")
			{
				int read_id = 0;
				string read_first = "";
				string read_last= "";
				float read_salary = 0.0;
				readRecords >> temp;
				readRecords >> read_id;
				readRecords >> temp;
				readRecords >> temp;
				readRecords >> read_first;
				readRecords >> temp;
				readRecords >> temp;
				readRecords >> read_last;
				readRecords >> temp;
				readRecords >> read_salary;
				
				Person* newEmployee = new Employee(read_id, read_first, read_last, read_salary);
				insertNode(newEmployee);
			}
			else
			{
				
			}
		}
		readRecords.close();
		cout << "UniversityRecords.txt successfully scanned" << endl;
	}
}

void readList()
{
	Person* node = firstPerson;
	printf("\n==========ZOOM UNIVERSITY RECORDS==========");
	while(node != NULL) // While loop to iterate through the linked list.
	{
		//
		// Print the attributes of each student in the linked list.
		//
		if(instanceof<Student>(node))
		{
			Student* tempStudent = (Student*) node;
			cout << "\n\nStudent";
			cout << "\nID: " << tempStudent->getID();
			cout << "\nFirst Name: " << tempStudent->getFirstName();
			cout << "\nLast Name: " << tempStudent->getLastName();
			cout << "\nGPA: " << tempStudent->getGPA();
			//delete tempStudent;
		}
		else if(instanceof<Professor>(node))
		{
			Professor* tempProfessor = (Professor*) node;
			cout << "\n\nProfessor";
			cout << "\nID: " << tempProfessor->getID();
			cout << "\nFirst Name: " << tempProfessor->getFirstName();
			cout << "\nLast Name: " << tempProfessor->getLastName();
			cout << "\nSalary: " << tempProfessor->getSalary();
			if(tempProfessor->getTenured())
			{
				cout << "\nTenured: Yes";
			}
			else
			{
				cout << "\nTenured: No";
			}
			 tempProfessor->getTenured();
			if(tempProfessor->getDepartment() == English)
			{
				cout << "\nDepartment: English";
			}
			else if(tempProfessor->getDepartment() == Math)
			{
				cout << "\nDepartment: Math";
			}
			else if(tempProfessor->getDepartment() == Philosophy)
			{
				cout << "\nDepartment: Philosophy";
			}
			else if(tempProfessor->getDepartment() == Theology)
			{
				cout << "\nDepartment: Theology";
			}
			else if(tempProfessor->getDepartment() == Biology)
			{
				cout << "\nDepartment: Biology";
			}
			else if(tempProfessor->getDepartment() == Physics)
			{
				cout << "\nDepartment: Physics";
			}
			else if(tempProfessor->getDepartment() == Chemistry)
			{
				cout << "\nDepartment: Chemistry";
			}
			else if(tempProfessor->getDepartment() == Engineering)
			{
				cout << "\nDepartment: Engineering";
			}
			else
			{
				cout << "\nDepartment: Unknown";
			}
			//delete tempProfessor;
		}
		else if(instanceof<Employee>(node))
		{
			Employee* tempEmployee = (Employee*) node;
			cout << "\n\nEmployee";
			cout << "\nID: " << tempEmployee->getID();
			cout << "\nFirst Name: " << tempEmployee->getFirstName();
			cout << "\nLast Name: " << tempEmployee->getLastName();
			cout << "\nSalary: " << tempEmployee->getSalary();
			//delete tempEmployee;
		}
		node = node->getNext(); // i++
	}
	printf("\n\n===========================================\n");
}

void saveList() // Iterates through the linked list and writes all the student details in the same format into the StudentRecords.txt file.
{
	ofstream openRecords;
	openRecords.open("UniversityRecords.txt");
	Person* node = firstPerson; // Creates a new student pointer to keep track of the current node (aka student). Sets the pointer at the start of the linked list.
	int personCount = 0; // New variable to count the total students in the linked list.
	while(node != NULL) // While loop to iterate through the linked list.
	{
		personCount++; // For every node in the list, add 1 to count. End result should be the total amont of nodes in the list.
		node = node->getNext(); // Iterate.
	}
	if (!openRecords.is_open())
	{
		cout << "Unable to write file\n";
	}
	else
	{
		openRecords << "Number of people: " << personCount; // Print in the same format as the file was scanned for consistency.
		node = firstPerson; // Reset the node to the beginning of the list.
		while(node != NULL) // While loop to iterate through the linked list.
		{
			//
			// Printing the ID, first and last name, and GPA of each student.
			//
			if(instanceof<Student>(node))
			{
				Student* tempStudent = (Student*) node;
				openRecords << "\n\nStudent";
				openRecords << "\nID: " << tempStudent->getID();
				openRecords << "\nFirst Name: " << tempStudent->getFirstName();
				openRecords << "\nLast Name: " << tempStudent->getLastName();
				openRecords << "\nGPA: " << tempStudent->getGPA();
				//delete tempStudent;
			}
			else if(instanceof<Professor>(node))
			{
				Professor* tempProfessor = (Professor*) node;
				openRecords << "\n\nProfessor";
				openRecords << "\nID: " << tempProfessor->getID();
				openRecords << "\nFirst Name: " << tempProfessor->getFirstName();
				openRecords << "\nLast Name: " << tempProfessor->getLastName();
				openRecords << "\nSalary: " << tempProfessor->getSalary();
				openRecords << "\nTenured: " << tempProfessor->getTenured();
				if(tempProfessor->getDepartment() == English)
				{
					openRecords << "\nDepartment: English";
				}
				else if(tempProfessor->getDepartment() == Math)
				{
					openRecords << "\nDepartment: Math";
				}
				else if(tempProfessor->getDepartment() == Philosophy)
				{
					openRecords << "\nDepartment: Philosophy";
				}
				else if(tempProfessor->getDepartment() == Theology)
				{
					openRecords << "\nDepartment: Theology";
				}
				else if(tempProfessor->getDepartment() == Biology)
				{
					openRecords << "\nDepartment: Biology";
				}
				else if(tempProfessor->getDepartment() == Physics)
				{
					openRecords << "\nDepartment: Physics";
				}
				else if(tempProfessor->getDepartment() == Chemistry)
				{
					openRecords << "\nDepartment: Chemistry";
				}
				else if(tempProfessor->getDepartment() == Engineering)
				{
					openRecords << "\nDepartment: Engineering";
				}
				else
				{
					openRecords << "\nDepartment: Unknown";
				}
				
				//delete tempProfessor;
			}
			else if(instanceof<Employee>(node))
			{
				Employee* tempEmployee = (Employee*) node;
				openRecords << "\n\nEmployee";
				openRecords << "\nID: " << tempEmployee->getID();
				openRecords << "\nFirst Name: " << tempEmployee->getFirstName();
				openRecords << "\nLast Name: " << tempEmployee->getLastName();
				openRecords << "\nSalary: " << tempEmployee->getSalary();
				//delete tempEmployee;
			}
			
			node = node->getNext(); // Iterate.
		}
		openRecords.close(); // Close the file.
	}
}

void insertNode(Person* person_in)
{
	if(firstPerson == NULL)
	{
		firstPerson = person_in;
		return;
	}
	else if(firstPerson->getNext() == NULL)
	{
		if(firstPerson->getID() >= person_in->getID())
		{
			firstPerson->setNext(person_in);
			return;
		}
		else
		{
			Person* temp = firstPerson;
			firstPerson = person_in;
			firstPerson->setNext(temp);
			return;
		}
	}
	
	Person* node = firstPerson;
	
	while(node->getNext() != NULL)
	{
		Person* nextNode = node->getNext();
		
		if((node->getID() > person_in->getID()) && (person_in->getID() >= nextNode->getID()))
		{
			person_in->setNext(node->getNext());
			node->setNext(person_in);
			return;
		}
		else if(node->getID() <= person_in->getID())
		{
			person_in->setNext(node);
			firstPerson = person_in;
			return;
		}
		node = node->getNext();
	}
	node->setNext(person_in);
	person_in->setNext(NULL);
	return;
}

void deleteNode(Person* person_in)
{
	Person* currentPerson = firstPerson;
	Person* prevPerson = NULL;
	
	if(firstPerson == person_in)
	{
		firstPerson = firstPerson->getNext();
		delete person_in;
		return;
	}
	
	while(currentPerson != NULL && currentPerson != person_in) // Iterates through the list until the desired student is found.
	{
		prevPerson = currentPerson; // The present becomes the past.
		currentPerson = currentPerson->getNext(); // The future becomes the present.
	}
	
	if(currentPerson != NULL)
	{
		prevPerson->setNext(currentPerson->getNext());
	}
	
	delete person_in;
}

void addToList()
{
	int user_input = 0;
	do
	{
		int id_input;
		string first_input, last_input;
		float gpa_input, salary_input;
		bool ten_input;
		Department dep_input;
		string temp;
		Person* idCheck = firstPerson;
		
		addMenuDisplay();
		cout << "\nWho would you like to add? ";
		cin >> user_input;
		
		switch(user_input)
		{
			case 1 :
			{
				printf("\nEnter the ID of the student: "); // Prompts the user to enter an input.
				cin >> id_input; // Scans the input into the id_input variable that was declared at the beginning of the do-while loop.
				while(idCheck != NULL) // Iterates through the linked list.
				{
					if(id_input == idCheck->getID()) // Checks to see if the ID already exists.
					{
						printf("\nEntered ID is currently used by and existing person."); // Let the user know that this ID can't be used.
						idCheck = firstPerson; // Set the check back to the beginning of the linked list.
						printf("\nEnter the ID of the student: "); // Prompt the user to enter an input.
						cin >> id_input; // Scans the input into the id_input variable that was declared at the beginning of the do-while loop.
					}
					idCheck = idCheck->getNext(); // Iterates the current node to the next to traverse the linked list. Remember, it works like i++ in a for loop.
				}
				
				printf("\nEnter the first name of the student: "); // Prompts the user to enter an input.
				cin >> first_input;
				
				printf("\nEnter the last name of the student: "); // Prompts the user to enter an input.
				cin >> last_input;
				
				printf("\nEnter the GPA of the student: "); // Prompts the user to enter an input.
				cin >> gpa_input; // Scans the input into the gpa_input variable that was declared at the beginning of the do-while loop.
				while((gpa_input > 4.0) || (gpa_input < 1.0)) // Checks the gpa_input to see if it is within the 4.0 GPA scale.
				{
					printf("\nPlease enter a GPA in the range of 4.0 and 1.0."); // Let the user know that this GPA can't be used.
					printf("\nEnter the GPA of the student: "); // Prompt the user to enter an input.
					cin >> gpa_input; // Scans the input into the gpa_input variable that was declared at the beginning of the do-while loop.
				}
				
				Person* peterPtr = new Student(id_input, first_input, last_input, gpa_input);
				insertNode(peterPtr);
				break;
			}
			case 2 :
			{
				printf("\nEnter the ID of the professor: "); // Prompts the user to enter an input.
				cin >> id_input; // Scans the input into the id_input variable that was declared at the beginning of the do-while loop.
				while(idCheck != NULL) // Iterates through the linked list.
				{
					if(id_input == idCheck->getID()) // Checks to see if the ID already exists.
					{
						printf("\nEntered ID is currently used by an existing person."); // Let the user know that this ID can't be used.
						idCheck = firstPerson; // Set the check back to the beginning of the linked list.
						printf("\nEnter the ID of the professor: "); // Prompt the user to enter an input.
						cin >> id_input; // Scans the input into the id_input variable that was declared at the beginning of the do-while loop.
					}
					idCheck = idCheck->getNext(); // Iterates the current node to the next to traverse the linked list. Remember, it works like i++ in a for loop.
				}
				
				printf("\nEnter the first name of the professor: "); // Prompts the user to enter an input.
				cin >> first_input;
				
				printf("\nEnter the last name of the professor: "); // Prompts the user to enter an input.
				cin >> last_input;
				
				printf("\nEnter the salary of the professor: "); // Prompts the user to enter an input.
				cin >> salary_input;
				
				cout << "\nAre they tenured? (yes/no) ";
				cin >> temp;
				string yes = "yes";
				string no = "no";
				if(strcasecmp(yes.c_str(), temp.c_str()) == 0)
					ten_input = true;
				else if(strcasecmp(no.c_str(), temp.c_str()) == 0)
					ten_input = false;
				else
				{
					bool check = true;
					while(check)
					{
						cout << "\nPlease indicate yes or no: ";
						cin >> temp;
						if(strcasecmp(yes.c_str(), temp.c_str()) == 0)
						{
							ten_input = true;
							check = false;
						}
							
						else if(strcasecmp(no.c_str(), temp.c_str()) == 0)
						{
							ten_input = false;
							check = false;
						}
					}
				}
				
				cout << "\nEnter the department of the professor: ";
				cin >> temp;
				
				if(temp == "English"){dep_input = English;}
				else if(temp == "Math"){dep_input = Math;}
				else if(temp == "Philsophy"){dep_input = Philosophy;}
				else if(temp == "Theology"){dep_input = Theology;}
				else if(temp == "Biology"){dep_input = Biology;}
				else if(temp == "Physics"){dep_input = Physics;}
				else if(temp == "Chemistry"){dep_input = Chemistry;}
				else if(temp == "Engineering"){dep_input = Engineering;}
				else{dep_input = Unknown;}
				
				Person* peterPtr = new Professor(id_input, first_input, last_input, salary_input, ten_input, dep_input);
				insertNode(peterPtr);
				break;
			}
			case 3 :
			{
				printf("\nEnter the ID of the employee: "); // Prompts the user to enter an input.
				cin >> id_input; // Scans the input into the id_input variable that was declared at the beginning of the do-while loop.
				while(idCheck != NULL) // Iterates through the linked list.
				{
					if(id_input == idCheck->getID()) // Checks to see if the ID already exists.
					{
						printf("\nEntered ID is currently used by an existing person."); // Let the user know that this ID can't be used.
						idCheck = firstPerson; // Set the check back to the beginning of the linked list.
						printf("\nEnter the ID of the employee: "); // Prompt the user to enter an input.
						cin >> id_input; // Scans the input into the id_input variable that was declared at the beginning of the do-while loop.
					}
					idCheck = idCheck->getNext(); // Iterates the current node to the next to traverse the linked list. Remember, it works like i++ in a for loop.
				}
				
				printf("\nEnter the first name of the employee: "); // Prompts the user to enter an input.
				cin >> first_input;
				
				printf("\nEnter the last name of the employee: "); // Prompts the user to enter an input.
				cin >> last_input;
				
				printf("\nEnter the salary of the employee: "); // Prompts the user to enter an input.
				cin >> salary_input;
				
				Person* peterPtr = new Employee(id_input, first_input, last_input, salary_input);
				insertNode(peterPtr);
				break;
			}
			
			case 4 : // 5) Quit
				break; // Leave the switch-case.
				
			default : // If there is an input that isn't any of the above listed cases.
				printf("\nInvalid input\n"); 
		}
	}while(user_input != 4);
}

void removeFromList(int id_in)
{
	Person* node = firstPerson;
	while(node != NULL) // While loop to iterate through the linked list.
	{
		if(id_in == node->getID()) // Check if the current node in the list shares the ID of the resired input ID.
		{
			string first = node->getFirstName();
			string last =  node->getLastName();
			deleteNode(node); // Remove and free the node from the list.
			cout << "\n" << first << " " << last << " was successfully deleted."; // Success message for the user.
			return; // Leave the function.
		}
		node = node->getNext(); // Iterate.
	}
	cout << "\nThere is no student associated with the given ID.";
}

void updateList(int id_in)
{
	Person* node = firstPerson;
	Person* prevNode = node;
	int user_input = 0;
	while(node != NULL)
	{
		if(id_in == node->getID())
		{
			if(instanceof<Student>(node))
			{
				do
				{
					updateStudentMenu(node->getFirstName(), node->getLastName()); // Display the update student menu for the specific student desired.
					cin >> user_input; // Scans the input into the user_input variable that was declared at the beginning of the updateStudent() function.
					//
					// Declarations for placeholder variables.
					//
					int new_id, old_id = 0;
					string new_first = "";
					string old_first = "";
					string new_last = "";
					string old_last = "";
					string temp = "";
					float new_gpa, old_gpa = 0.0;
					Person* idCheck = firstPerson;
					Student* tempStudent = (Student*) node;
					
					switch(user_input) // Switch-case to check which case the user desired.
					{
						case 1 : // 1) Update ID
							cout << "\nEnter the new ID: "; // Prompts the user to enter an input.
							cin >> new_id; // Scans the input into the new_id variable that was declared at the beginning of the do-while loop.
							while(idCheck != NULL) // Iterates through the linked list.
							{
								if(new_id == idCheck->getID()) // Checks to see if the ID already exists.
								{
									printf("\nEntered ID is currently used by and existing student."); // Let the user know that this ID can't be used.
									idCheck = firstPerson; // Set the check back to the beginning of the linked list.
									printf("\nEnter the ID of the student: "); // Prompt the user to enter an input.
									scanf("%d", &new_id); // Scans the input into the new_id variable that was declared at the beginning of the do-while loop.
								}
								idCheck = idCheck->getNext(); // Iterates the current node to the next to traverse the linked list. Remember, it works like i++ in a for loop.
							}
							old_id = tempStudent->getID(); // Formatting.
							tempStudent->setID(new_id); // Change the ID.
							node = tempStudent;
							if(prevNode == node) // Checks if this is the first node in the list.
							{
								node->setNext(NULL); // If so, unlink the current node from the list.
								insertNode(node); // Re-insert the node so the list is still sorted by GPA.
							}
							else // At any other part of the list...
							{
								prevNode->setNext(node->getNext()); // Unlink the current node by linking the node before it to the node in front of it.
								insertNode(node); // Re-insert the node so the list is still sorted by GPA.
							}
							printf("\n%d was sucessfully updated to %d", old_id, new_id); // Success message for the user.
							break; // Leave the switch-case.
						case 2 : // 2) Update First Name
							printf("\nEnter the new first name: "); // Prompts the user to enter an input.
							cin >> new_first;
							old_first = tempStudent->getFirstName(); // Formatting.
							tempStudent->setFirstName(new_first); // Change the first name.
							cout << "\n" << old_first << " was sucessfully updated to " << new_first;// Success message for the user.
							node = tempStudent;
							break; // Leave the switch-case.
						case 3 : // 3) Update Last Name
							printf("\nEnter the new last name: "); // Prompts the user to enter an input.
							cin >> new_last;
							old_last = tempStudent->getLastName(); // Formatting.
							tempStudent->setLastName(new_last); // Change the last name.
							cout << "\n" << old_last<< " was sucessfully updated to " << new_last; // Success message for the user.
							node = tempStudent;
							break; // Leave the switch-case.
						case 4 : // 4) Update GPA
							printf("\nEnter the new GPA: "); // Prompts the user to enter an input.
							scanf("%f", &new_gpa); // Scans the input into the new_gpa variable that was declared at the beginning of the do-while loop.
							while((new_gpa > 4.0) || (new_gpa < 1.0)) // Checks the gpa_input to see if it is within the 4.0 GPA scale.
							{
								printf("\nPlease enter a GPA in the range of 4.0 and 1.0."); // Let the user know that this GPA can't be used.
								printf("\nEnter the GPA of the student: "); // Prompts the user to enter an input.
								scanf("%f", &new_gpa); // Scans the input into the new_gpa variable that was declared at the beginning of the do-while loop.
							}
							old_gpa = tempStudent->getGPA(); // Formatting.
							tempStudent->setGPA(new_gpa); // Change the GPA.
							node = tempStudent;
							printf("\n%f was sucessfully updated to %f", old_gpa, new_gpa); // Success message for the user.
							break; // Leave the switch-case.
						
						case 5 : // 5) Quit
							break; // Leave the switch-case.
						
						default : // If there is an input that isn't any of the above listed cases.
							printf("\nInvalid input\n");
					}
				}while(user_input != 5);
				return;
			}
			else if(instanceof<Professor>(node))
			{
				do
				{
					updateProfessorMenu(node->getFirstName(), node->getLastName()); // Display the update student menu for the specific student desired.
					cin >> user_input; // Scans the input into the user_input variable that was declared at the beginning of the updateStudent() function.
					//
					// Declarations for placeholder variables.
					//
					int new_id, old_id = 0;
					string new_first = "";
					string old_first = "";
					string new_last = "";
					string old_last = "";
					string temp, temp2 = "";
					float new_salary, old_salary = 0.0;
					bool new_ten, old_ten = false;
					Department new_dep;
					Person* idCheck = firstPerson;
					Professor* tempProfessor = (Professor*) node;
					
					switch(user_input) // Switch-case to check which case the user desired.
					{
						case 1 : // 1) Update ID
						{
							cout << "\nEnter the new ID: "; // Prompts the user to enter an input.
							cin >> new_id; // Scans the input into the new_id variable that was declared at the beginning of the do-while loop.
							while(idCheck != NULL) // Iterates through the linked list.
							{
								if(new_id == idCheck->getID()) // Checks to see if the ID already exists.
								{
									printf("\nEntered ID is currently used by and existing student."); // Let the user know that this ID can't be used.
									idCheck = firstPerson; // Set the check back to the beginning of the linked list.
									printf("\nEnter the ID of the student: "); // Prompt the user to enter an input.
									scanf("%d", &new_id); // Scans the input into the new_id variable that was declared at the beginning of the do-while loop.
								}
								idCheck = idCheck->getNext(); // Iterates the current node to the next to traverse the linked list. Remember, it works like i++ in a for loop.
							}
							old_id = tempProfessor->getID(); // Formatting.
							tempProfessor->setID(new_id); // Change the ID.
							node = tempProfessor;
							if(prevNode == node) // Checks if this is the first node in the list.
							{
								node->setNext(NULL); // If so, unlink the current node from the list.
								insertNode(node); // Re-insert the node so the list is still sorted by GPA.
							}
							else // At any other part of the list...
							{
								prevNode->setNext(node->getNext()); // Unlink the current node by linking the node before it to the node in front of it.
								insertNode(node); // Re-insert the node so the list is still sorted by GPA.
							}
							printf("\n%d was sucessfully updated to %d", old_id, new_id); // Success message for the user.
							break; // Leave the switch-case.
						}

						case 2 : // 2) Update First Name
						{
							printf("\nEnter the new first name: "); // Prompts the user to enter an input.
							cin >> new_first;
							old_first = tempProfessor->getFirstName(); // Formatting.
							tempProfessor->setFirstName(new_first); // Change the first name.
							cout << "\n" << old_first << " was sucessfully updated to " << new_first;// Success message for the user.
							node = tempProfessor;
							break; // Leave the switch-case.
						}

						case 3 : // 3) Update Last Name
						{
							printf("\nEnter the new last name: "); // Prompts the user to enter an input.
							cin >> new_last;
							old_last = tempProfessor->getLastName(); // Formatting.
							tempProfessor->setLastName(new_last); // Change the last name.
							cout << "\n" << old_last<< " was sucessfully updated to " << new_last; // Success message for the user.
							node = tempProfessor;
							break; // Leave the switch-case.
						}
						case 4 : // 4) Update GPA
						{
							printf("\nEnter the new Salary: "); // Prompts the user to enter an input.
							scanf("%f", &new_salary); // Scans the input into the new_gpa variable that was declared at the beginning of the do-while loop.
							old_salary = tempProfessor->getSalary(); // Formatting.
							tempProfessor->setSalary(new_salary); // Change the GPA.
							node = tempProfessor;
							printf("\n%f was sucessfully updated to %f", old_salary, new_salary); // Success message for the user.
							break; // Leave the switch-case.
						}
						
						case 5 : 
						{
							cout << "\nAre they tenured? (yes/no) ";
							cin >> temp;
							string yes = "yes";
							string no = "no";
							if(strcasecmp(yes.c_str(), temp.c_str()) == 0)
								new_ten = true;
							else if(strcasecmp(no.c_str(), temp.c_str()) == 0)
								new_ten = false;
							else
							{
								bool check = true;
								while(check)
								{
									cout << "\nPlease indicate yes or no: ";
									cin >> temp;
									if(strcasecmp(yes.c_str(), temp.c_str()) == 0)
									{
										new_ten = true;
										check = false;
									}
										
									else if(strcasecmp(no.c_str(), temp.c_str()) == 0)
									{
										new_ten = false;
										check = false;
									}
								}
							}
							old_ten = tempProfessor->getTenured();
							tempProfessor->setTenured(new_ten);
							node = tempProfessor;
							if(new_ten == old_ten)
								cout << "\nNo change was made (value entered was the same as the current value)";
							else
								cout << "\nTenured was updated";
							break;
						}
						
						case 6 :
						{
							cout << "\nEnter the department of the professor: ";
							cin >> temp;
							
							if(temp == "English"){new_dep = English;}
							else if(temp == "Math"){new_dep = Math;}
							else if(temp == "Philsophy"){new_dep = Philosophy;}
							else if(temp == "Theology"){new_dep = Theology;}
							else if(temp == "Biology"){new_dep = Biology;}
							else if(temp == "Physics"){new_dep = Physics;}
							else if(temp == "Chemistry"){new_dep = Chemistry;}
							else if(temp == "Engineering"){new_dep = Engineering;}
							else{new_dep = Unknown;}
							
							if(tempProfessor->getDepartment() == English)
							{
								temp2 = "English";
							}
							else if(tempProfessor->getDepartment() == Math)
							{
								temp2 = "Math";
							}
							else if(tempProfessor->getDepartment() == Philosophy)
							{
								temp2 = "Philosophy";
							}
							else if(tempProfessor->getDepartment() == Theology)
							{
								temp2 = "Theology";
							}
							else if(tempProfessor->getDepartment() == Biology)
							{
								temp2 = "Biology";
							}
							else if(tempProfessor->getDepartment() == Physics)
							{
								temp2 = "Physics";
							}
							else if(tempProfessor->getDepartment() == Chemistry)
							{
								temp2 = "Chemistry";
							}
							else if(tempProfessor->getDepartment() == Engineering)
							{
								temp2 = "Engineering";
							}
							else
							{
								temp2 = "Unknown";
							}
							tempProfessor->setDepartment(new_dep);
							node = tempProfessor;
							cout << "\n" << temp2 << " was successfully updated to " << temp;
							break;
						}
						
						case 7 :
						{
							break;
						}
						
						default : // If there is an input that isn't any of the above listed cases.
							printf("\nInvalid input\n");
					}
				}while(user_input != 7);
				return;
			}
			else if(instanceof<Employee>(node))
			{
				do
				{
					updateEmployeeMenu(node->getFirstName(), node->getLastName()); // Display the update student menu for the specific student desired.
					cin >> user_input; // Scans the input into the user_input variable that was declared at the beginning of the updateStudent() function.
					//
					// Declarations for placeholder variables.
					//
					int new_id, old_id = 0;
					string new_first = "";
					string old_first = "";
					string new_last = "";
					string old_last = "";
					string temp = "";
					float new_salary, old_salary = 0.0;
					Person* idCheck = firstPerson;
					Employee* tempStudent = (Employee*) node;
					
					switch(user_input) // Switch-case to check which case the user desired.
					{
						case 1 : // 1) Update ID
							cout << "\nEnter the new ID: "; // Prompts the user to enter an input.
							cin >> new_id; // Scans the input into the new_id variable that was declared at the beginning of the do-while loop.
							while(idCheck != NULL) // Iterates through the linked list.
							{
								if(new_id == idCheck->getID()) // Checks to see if the ID already exists.
								{
									printf("\nEntered ID is currently used by and existing student."); // Let the user know that this ID can't be used.
									idCheck = firstPerson; // Set the check back to the beginning of the linked list.
									printf("\nEnter the ID of the student: "); // Prompt the user to enter an input.
									scanf("%d", &new_id); // Scans the input into the new_id variable that was declared at the beginning of the do-while loop.
								}
								idCheck = idCheck->getNext(); // Iterates the current node to the next to traverse the linked list. Remember, it works like i++ in a for loop.
							}
							old_id = tempStudent->getID(); // Formatting.
							tempStudent->setID(new_id); // Change the ID.
							node = tempStudent;
							if(prevNode == node) // Checks if this is the first node in the list.
							{
								node->setNext(NULL); // If so, unlink the current node from the list.
								insertNode(node); // Re-insert the node so the list is still sorted by GPA.
							}
							else // At any other part of the list...
							{
								prevNode->setNext(node->getNext()); // Unlink the current node by linking the node before it to the node in front of it.
								insertNode(node); // Re-insert the node so the list is still sorted by GPA.
							}
							printf("\n%d was sucessfully updated to %d", old_id, new_id); // Success message for the user.
							break; // Leave the switch-case.
						case 2 : // 2) Update First Name
							printf("\nEnter the new first name: "); // Prompts the user to enter an input.
							cin >> new_first;
							old_first = tempStudent->getFirstName(); // Formatting.
							tempStudent->setFirstName(new_first); // Change the first name.
							cout << "\n" << old_first << " was sucessfully updated to " << new_first;// Success message for the user.
							node = tempStudent;
							break; // Leave the switch-case.
						case 3 : // 3) Update Last Name
							printf("\nEnter the new last name: "); // Prompts the user to enter an input.
							cin >> new_last;
							old_last = tempStudent->getLastName(); // Formatting.
							tempStudent->setLastName(new_last); // Change the last name.
							cout << "\n" << old_last<< " was sucessfully updated to " << new_last; // Success message for the user.
							node = tempStudent;
							break; // Leave the switch-case.
						case 4 : // 4) Update GPA
							printf("\nEnter the new Salary: "); // Prompts the user to enter an input.
							scanf("%f", &new_salary); // Scans the input into the new_gpa variable that was declared at the beginning of the do-while loop.
							
							old_salary = tempStudent->getSalary(); // Formatting.
							tempStudent->setSalary(new_salary); // Change the GPA.
							node = tempStudent;
							printf("\n%f was sucessfully updated to %f", old_salary, new_salary); // Success message for the user.
							break; // Leave the switch-case.
						
						case 5 : // 5) Quit
							break; // Leave the switch-case.
						
						default : // If there is an input that isn't any of the above listed cases.
							printf("\nInvalid input\n");
					}
				}while(user_input != 5);
				return;
			}
		}
		node = node->getNext();
	}
	cout << "\nThere is no student associated with the given ID.";
}

void menuDisplay() // Displays the default menu.
{
	printf("\n====================UNIVERSITY MENU====================");
	
	printf("\n\n[1] List");
	printf("\n[2] Add");
	printf("\n[3] Remove");
	printf("\n[4] Update");
	
	printf("\n\n[5] Quit");
	printf("\n\n=======================================================");
	printf("\n\n");
}

void addMenuDisplay() // Displays the default menu.
{
	printf("\n======================ADD MENU======================");
	
	printf("\n\n[1] Student");
	printf("\n[2] Professor");
	printf("\n[3] Employee");
	
	printf("\n\n[4] Quit");
	printf("\n\n====================================================");
	printf("\n\n");
}

void updateStudentMenu(string first, string last) // Displays the menu for the specific student to have their attributes updated.
{
	printf("\n====================UPDATE STUDENT MENU====================");
	cout << "\nWhat would you like to update about " << first << " " << last << "?";
	printf("\n\n[1] ID");
	printf("\n[2] First Name");
	printf("\n[3] Last Name");
	printf("\n[4] GPA");
	
	printf("\n\n[5] Quit");
	printf("\n\n===========================================================");
	printf("\n\n");
}

void updateProfessorMenu(string first, string last) // Displays the menu for the specific student to have their attributes updated.
{
	printf("\n====================UPDATE PROFESSOR MENU====================");
	cout << "\nWhat would you like to update about " << first << " " << last << "?";
	printf("\n\n[1] ID");
	printf("\n[2] First Name");
	printf("\n[3] Last Name");
	printf("\n[4] Salary");
	printf("\n[5] Tenured");
	printf("\n[6] Department");
	
	printf("\n\n[7] Quit");
	printf("\n\n=============================================================");
	printf("\n\n");
}

void updateEmployeeMenu(string first, string last) // Displays the menu for the specific student to have their attributes updated.
{
	printf("\n====================UPDATE EMPLOYEE MENU====================");
	cout << "\nWhat would you like to update about " << first << " " << last << "?";
	printf("\n\n[1] ID");
	printf("\n[2] First Name");
	printf("\n[3] Last Name");
	printf("\n[4] Salary");
	
	printf("\n\n[5] Quit");
	printf("\n\n============================================================");
	printf("\n\n");
}