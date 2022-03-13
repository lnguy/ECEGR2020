#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

enum Department {English, Math, Philosophy, Theology, Biology, Physics, Chemistry, Engineering, Unknown};

class Student
{
private:
	int  ID;
    char* firstName;
    char* lastName;
    float GPA;
	Student* next;

public:
	Student();
	Student(int id_in, char *first_in, char *last_in, float gpa_in);
	Student(Student &init);
	~Student();
	Student& operator=(Student const &s)
	{
		this->ID = s.ID;
		this->firstName = NULL;
		this->lastName = NULL;
		setFirstName(s.firstName);
		setLastName(s.lastName);
		this->GPA = s.GPA;
		//printf("Student Assignment Operator called.\n");
		return *this;
	}
	
	// Get methods
	int getID()
	{
		return ID;
	}
	float getGPA()
	{
		return GPA;
	}
	char* getFirstName()
	{
		return firstName;
	}
	char* getLastName()
	{
		return lastName;
	}
	Student* getNext()
	{
		return next;
	}

	// Set methods
	void setID(int id_in)
	{
		ID = id_in;
	}
	void setGPA(float gpa_in)
	{
		GPA = gpa_in;
	}
	void setFirstName(char *first_in)
	{
		if(firstName == NULL)
		{
			firstName = (char*) malloc(strlen(first_in)+1);
			strcpy(firstName, first_in);
			return;
		}
		else
		{
			free(firstName);
			firstName = (char*) malloc(strlen(first_in)+1);
			strcpy(firstName, first_in);
			return;
		}
	}
	void setLastName(char *last_in)
	{
		if(lastName == NULL)
		{
			lastName = (char*) malloc(strlen(last_in)+1);
			strcpy(lastName, last_in);
			return;
		}
		else
		{
			free(lastName);
			lastName = (char*) malloc(strlen(last_in)+1);
			strcpy(lastName, last_in);
			return;
		}
	}
	void setNext(Student* next_in)
	{
		next = next_in;
	}
};

Student* firstStudent = NULL;

Student :: Student()
{
	this->ID = 9999;
	this->firstName = NULL;
	this->lastName = NULL;
	this->GPA = 0.0;
	this->next = NULL;
	//printf("Student Default Constructor called.\n");
}

Student :: Student(int id_in, char* first_in, char* last_in, float gpa_in)
{
	this->ID = id_in;
	this->firstName = (char*) malloc(strlen(first_in)+1);
	strcpy(this->firstName, first_in);
	this->lastName = (char*) malloc(strlen(last_in)+1);
	strcpy(this->lastName, last_in);
	this->GPA = gpa_in;
	this->next = NULL;
	//printf("Student Constructor called for %s %s.\n", firstName, lastName);
}

Student :: Student(Student &init)
{
	ID = init.ID;
	GPA = init.GPA;
	firstName = NULL;
	lastName = NULL;
	if(init.firstName)
	{
		setFirstName(init.firstName);
	}
	if(init.lastName)
	{
		setLastName(init.lastName);
	}
	next = init.next;
	//printf("Student Copy Constructor called.\n");
}

Student :: ~Student()
{
	//printf("Student Destructor called for %s %s.\n", firstName, lastName);
	if(firstName)
	{
		free(firstName);
	}
	if(lastName)
	{
		free(lastName);
	}
}

void insertStudentNode(Student* student_in);
void deleteStudentNode(Student* student_in);
void readStudentRecords(void);
void readList(void);
//void freeList(void);
void saveList(void);
void removeStudent(int id_in);
void updateStudent(int id_in);
void menuDisplay(void); // Displays the default menu.
void updateStudentMenu(char* first, char* last); // Displays the menu for the specific student to have their attributes updated.

int main()
{
	int user_in = 0;
	readStudentRecords();
	do // Begins the do-while loop to keep the user in the program.
	{
		//
		// Declarations for placeholder variables.
		//
		int id_input;
		string temp;
		char* first_input;
		char* last_input;
		float gpa_input = 0.0;
		int userID_in; // Variable to scan for user input later for menu options 3 and 4.
		Student* idCheck = firstStudent; // Variable to use as a check for later.
		
		menuDisplay(); // Displays the default menu.
		printf("\nWhat would you like to do? "); // Prompts the user to enter an input.
		cin >> user_in; // Scans the input into the user_in variable that was declared at the beginning of the main() function.
		
		switch(user_in) // Switch-case to check which case the user desired.
		{
			case 1 : // 1) List all students
			{
				readList(); // Iterates through the linked list and prints out all the students in the linked list.
				break; // Leave the switch-case.
			}
				
			case 2 : // 2) Add Student
			{
				printf("\nEnter the ID of the student: "); // Prompts the user to enter an input.
				cin >> id_input; // Scans the input into the id_input variable that was declared at the beginning of the do-while loop.
				while(idCheck != NULL) // Iterates through the linked list.
				{
					if(id_input == idCheck->getID()) // Checks to see if the ID already exists.
					{
						printf("\nEntered ID is currently used by and existing student."); // Let the user know that this ID can't be used.
						idCheck = firstStudent; // Set the check back to the beginning of the linked list.
						printf("\nEnter the ID of the student: "); // Prompt the user to enter an input.
						cin >> id_input; // Scans the input into the id_input variable that was declared at the beginning of the do-while loop.
					}
					idCheck = idCheck->getNext(); // Iterates the current node to the next to traverse the linked list. Remember, it works like i++ in a for loop.
				}
				
				printf("\nEnter the first name of the student: "); // Prompts the user to enter an input.
				cin >> temp; // Scans the input into the temp variable that was declared at the beginning of the do-while loop.
				first_input = (char*) malloc(sizeof(strlen((temp.c_str())+1)));
				strcpy(first_input, temp.c_str());
				
				printf("\nEnter the last name of the student: "); // Prompts the user to enter an input.
				cin >> temp; // Scans the input into the temp variable that was declared at the beginning of the do-while loop.
				last_input = (char*) malloc(sizeof(strlen((temp.c_str())+1)));
				strcpy(last_input, temp.c_str());
				
				printf("\nEnter the GPA of the student: "); // Prompts the user to enter an input.
				cin >> gpa_input; // Scans the input into the gpa_input variable that was declared at the beginning of the do-while loop.
				while((gpa_input > 4.0) || (gpa_input < 1.0)) // Checks the gpa_input to see if it is within the 4.0 GPA scale.
				{
					printf("\nPlease enter a GPA in the range of 4.0 and 1.0."); // Let the user know that this GPA can't be used.
					printf("\nEnter the GPA of the student: "); // Prompt the user to enter an input.
					cin >> gpa_input; // Scans the input into the gpa_input variable that was declared at the beginning of the do-while loop.
				}
				
				Student* peterPtr = new Student(id_input, first_input, last_input, gpa_input); // Takes all the scanned inputs and creates a new student pointer from it.
				insertStudentNode(peterPtr); // Takes the new student pointer and insterts it into the linked list.
				free(first_input);
				free(last_input);
				break; // Leave the switch-case.
			}
				
				
			case 3 : // 3) Remove Student
			{
				printf("\nEnter the ID of the student you wish to delete: "); // Prompts the user to enter an input.
				scanf("%d", &userID_in); // Scans the input into the userID_in variable that was declared at the beginning of the do-while loop.
				removeStudent(userID_in);// Takes the scanned userID_in and removes a student from the linked list by searching for userID_in.
				break; // Leave the switch-case.
			}
				
				
			case 4 : // 4) Update Student
			{
				
			}
				printf("\nEnter the ID of the student you wish to update: "); // Prompts the user to enter an input.
				cin >> userID_in; // Scans the input into the userID_in variable that was declared at the beginning of the do-while loop.
				updateStudent(userID_in); // Takes the scanned userID_in and updates the student based on the user input for any attribute of the student based on userID_in.
				break; // Leave the switch-case.
			
			case 5 : // 5) Quit
			{
				
			}
				printf("\nExiting Student Program..."); // Let the user know the program is closing.
				break; // Leave the switch-case.
			
			default : // If there is an input that isn't any of the above listed cases.
				printf("\nInvalid input\n"); 
		}
	}while(user_in != 5); // Leave the do-while if option 5 is chosen.
	saveList();
	
	return 0;
}

void insertStudentNode(Student* student_in)
{
	if(firstStudent == NULL)
	{
		firstStudent = student_in;
		return;
	}
	else if(firstStudent->getNext() == NULL)
	{
		if(firstStudent->getGPA() >= student_in->getGPA())
		{
			firstStudent->setNext(student_in);
			return;
		}
		else
		{
			Student* temp = firstStudent;
			firstStudent = student_in;
			firstStudent->setNext(temp);
			return;
		}
	}
	
	Student* node = firstStudent;
	
	while(node->getNext() != NULL)
	{
		Student* nextNode = node->getNext();
		
		if((node->getGPA() > student_in->getGPA()) && (student_in->getGPA() >= nextNode->getGPA()))
		{
			student_in->setNext(node->getNext());
			node->setNext(student_in);
			return;
		}
		else if(node->getGPA() <= student_in->getGPA())
		{
			student_in->setNext(node);
			firstStudent = student_in;
			return;
		}
		node = node->getNext();
	}
	node->setNext(student_in);
	student_in->setNext(NULL);
	return;
}

void deleteStudentNode(Student* student_in)
{
	Student* currentStudent = firstStudent;
	Student* prevStudent = NULL;
	
	if(firstStudent == student_in)
	{
		firstStudent = firstStudent->getNext();
		delete student_in;
		return;
	}
	
	while(currentStudent != NULL && currentStudent != student_in) // Iterates through the list until the desired student is found.
	{
		prevStudent = currentStudent; // The present becomes the past.
		currentStudent = currentStudent->getNext(); // The future becomes the present.
	}
	
	if(currentStudent != NULL)
	{
		prevStudent->setNext(currentStudent->getNext());
	}
	
	delete student_in;
}

void readStudentRecords() // Reads the StudentRecords.txt file and writes it into a linked list.
{
	ifstream readRecords;
	int totalStudents = 0;
	readRecords.open("StudentRecords.txt");
	if(!readRecords.is_open())
	{
		cerr << "Could not open file: StudentRecords.txt" << endl;
	}
	else
	{
		string temp = "";
		readRecords >> temp;
		readRecords >> temp;
		readRecords >> temp;
		readRecords >> totalStudents;
		cout << "\nNumber of Students: " << totalStudents << "\n";
		for(int i = 0; i < totalStudents; i++)
		{
			int read_id = 0;
			char* read_first = NULL;
			char* read_last = NULL;
			float read_gpa = 0.0;
			readRecords >> temp;
			readRecords >> temp;
			readRecords >> read_id;
			readRecords >> temp;
			readRecords >> temp;
			readRecords >> temp;
			readRecords >> temp;
			
			read_first = (char*) malloc(strlen((temp.c_str())+1));
			strcpy(read_first, temp.c_str());
			
			readRecords >> temp;
			readRecords >> temp;
			readRecords >> temp;
			readRecords >> temp;
			read_last = (char*) malloc(strlen((temp.c_str())+1));
			strcpy(read_last, temp.c_str());
			
			readRecords >> temp;
			readRecords >> temp;
			readRecords >> read_gpa;
			
			Student* newStudent = new Student(read_id, read_first, read_last, read_gpa);
			insertStudentNode(newStudent);
			
			free(read_first);
			free(read_last);
		}
		readRecords.close();
		printf("StudentRecords.txt successfully scanned\n"); // Let user know the function worked.
	}
}

void readList() // Iterates through the linked list and prints out all the students in the linked list.
{
	Student* node = firstStudent; // Creates a new student pointer to keep track of the current node (aka student). Sets the pointer at the start of the linked list.
	printf("\n==========STUDENT LINKED LIST=========="); // Formatting.
	while(node != NULL) // While loop to iterate through the linked list.
	{
		//
		// Print the attributes of each student in the linked list.
		//
		printf("\n\nStudent ID: %d", node->getID());
		printf("\nStudent First Name: %s", node->getFirstName());
		printf("\nStudent Last Name: %s", node->getLastName());
		printf("\nStudent GPA: %f", node->getGPA());
		node = node->getNext(); // i++
	}
	printf("\n\n=======================================\n"); // Formatting.
}

/*void freeList()
{
	Student* node = firstStudent;
	Student* nextNode = firstStudent->getNext();
	while(node != NULL)
	{
		delete node;
		node = nextNode;
		nextNode = nextNode->getNext();
	}
}*/

void saveList() // Iterates through the linked list and writes all the student details in the same format into the StudentRecords.txt file.
{
	ofstream openRecords;
	openRecords.open("StudentRecords.txt");
	Student* node = firstStudent; // Creates a new student pointer to keep track of the current node (aka student). Sets the pointer at the start of the linked list.
	int studentCount = 0; // New variable to count the total students in the linked list.
	while(node != NULL) // While loop to iterate through the linked list.
	{
		studentCount++; // For every node in the list, add 1 to count. End result should be the total amont of nodes in the list.
		node = node->getNext(); // Iterate.
	}
	if (!openRecords.is_open())
	{
		cout << "Unable to write file\n";
	}
	else
	{
		openRecords << "Number of students: " << studentCount; // Print in the same format as the file was scanned for consistency.
		node = firstStudent; // Reset the node to the beginning of the list.
		while(node != NULL) // While loop to iterate through the linked list.
		{
			//
			// Printing the ID, first and last name, and GPA of each student.
			//
			openRecords << "\n\nStudent ID: " << node->getID();
			openRecords << "\nStudent First Name: " << node->getFirstName();
			openRecords << "\nStudent Last Name: " << node->getLastName();
			openRecords << "\nStudent GPA: " << node->getGPA();
			node = node->getNext(); // Iterate.
		}
		openRecords.close(); // Close the file.
	}
}

void removeStudent(int id_in) // Removes a student from the linked list by searching for their specific ID.
{
	Student* node = firstStudent; // Creates a new student pointer to keep track of the current node (aka student). Sets the pointer at the start of the linked list.
	int check = 0; // Initialzed a variable to check if the ID was found or not. 0 if not found, 1 if found.
	while(node != NULL) // While loop to iterate through the linked list.
	{
		if(id_in == node->getID()) // Check if the current node in the list shares the ID of the resired input ID.
		{
			char* first;
			first = (char*) malloc(strlen(node->getFirstName()+1));
			char* last;
			last = (char*) malloc(strlen(node->getLastName()+1));
			strcpy(first, node->getFirstName());
			strcpy(last, node->getLastName());
			deleteStudentNode(node); // Remove and free the node from the list.
			check = 1; // Iterate check so that the ID was found.
			printf("\n%s %s was successfully deleted.", first, last); // Success message for the user.
			free(first);
			free(last);
			return; // Leave the function.
		}
		node = node->getNext(); // Iterate.
	}
	if(check == 0) // If the ID was not found.
	{
		printf("\nThere is no student associated with the given ID."); // Let the user know that the ID was invalid.
		return; // Leave the function.
	}
	return; // Leave the function.
}

void updateStudent(int id_in) // Updates a function based on the user input for any attribute of the student based on their specific ID.
{
	Student* node = firstStudent; // Creates a new student pointer to keep track of the current node (aka student). Sets the pointer at the start of the linked list.
	Student* prevNode = node; // Creates a new student pointer to keep track of the previous node (aka student). Sets the pointer at the start of the linked list.
	int check = 0; // Initialzed a variable to check if the ID was found or not. 0 if not found, 1 if found.
	int user_input = 0; // Declares a new variable to scan for user input later.
	while(node != NULL) // While loop to iterate through the linked list.
	{
		if(id_in == node->getID()) // Check if the current node in the list shares the ID of the resired input ID.
		{
			do // Begins the do-while loop to keep the user in the update student system.
			{
				updateStudentMenu(node->getFirstName(), node->getLastName()); // Display the update student menu for the specific student desired.
				cin >> user_input; // Scans the input into the user_input variable that was declared at the beginning of the updateStudent() function.
				//
				// Declarations for placeholder variables.
				//
				int new_id, old_id = 0;
				char* new_first = NULL;
				char* old_first = NULL;
				char* new_last = NULL;
				char* old_last = NULL;
				string temp = "";
				float new_gpa, old_gpa = 0.0;
				Student* idCheck = firstStudent;
				
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
								idCheck = firstStudent; // Set the check back to the beginning of the linked list.
								printf("\nEnter the ID of the student: "); // Prompt the user to enter an input.
								scanf("%d", &new_id); // Scans the input into the new_id variable that was declared at the beginning of the do-while loop.
							}
							idCheck = idCheck->getNext(); // Iterates the current node to the next to traverse the linked list. Remember, it works like i++ in a for loop.
						}
						old_id = node->getID(); // Formatting.
						node->setID(new_id); // Change the ID.
						printf("\n%d was sucessfully updated to %d", old_id, new_id); // Success message for the user.
						break; // Leave the switch-case.
					case 2 : // 2) Update First Name
						printf("\nEnter the new first name: "); // Prompts the user to enter an input.
						cin >> temp; // Scans the input into the new_first variable that was declared at the beginning of the do-while loop.
						new_first = (char*) malloc(strlen(temp.c_str()+1));
						strcpy(new_first, temp.c_str());
						old_first = (char*) malloc(strlen(node->getFirstName()+1));
						strcpy(old_first, node->getFirstName()); // Formatting.
						node->setFirstName(new_first); // Change the first name.
						printf("\n%s was sucessfully updated to %s", old_first, new_first); // Success message for the user.
						free(new_first);
						free(old_first);
						break; // Leave the switch-case.
					case 3 : // 3) Update Last Name
						printf("\nEnter the new last name: "); // Prompts the user to enter an input.
						cin >> temp; // Scans the input into the new_last variable that was declared at the beginning of the do-while loop.
						new_last = (char*) malloc(strlen(temp.c_str()+1));
						strcpy(new_last, temp.c_str());
						old_last = (char*) malloc(strlen(node->getLastName()+1));
						strcpy(old_last, node->getLastName()); // Formatting.
						node->setLastName(new_last); // Change the last name.
						printf("\n%s was sucessfully updated to %s", old_last, new_last); // Success message for the user.
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
						old_gpa = node->getGPA(); // Formatting.
						node->setGPA(new_gpa); // Change the GPA.
						if(prevNode == node) // Checks if this is the first node in the list.
						{
							node->setNext(NULL); // If so, unlink the current node from the list.
							insertStudentNode(node); // Re-insert the node so the list is still sorted by GPA.
						}
						else // At any other part of the list...
						{
							prevNode->setNext(node->getNext()); // Unlink the current node by linking the node before it to the node in front of it.
							insertStudentNode(node); // Re-insert the node so the list is still sorted by GPA.
						}
						printf("\n%f was sucessfully updated to %f", old_gpa, new_gpa); // Success message for the user.
						break; // Leave the switch-case.
					
					case 5 : // 5) Quit
						break; // Leave the switch-case.
					
					default : // If there is an input that isn't any of the above listed cases.
						printf("\nInvalid input\n");
				}
			} while(user_input != 5); // Leave the do-while if option 5 is chosen.
			return; // Leave the function.
		}
		prevNode = node; // Makes sure prevNode is 1 iteratoin behind node.
		node = node->getNext(); // Iterate node
	}
	if(check == 0) // If the ID was not found.
	{
		printf("\nThere is no student associated with the given ID."); // Let the user know that the ID was invalid.
		return; // Leave the function.
	}
}

void menuDisplay() // Displays the default menu.
{
	printf("\n====================STUDENT MENU====================");
	
	printf("\n\n[1] List All Students");
	printf("\n[2] Add Student");
	printf("\n[3] Remove Student");
	printf("\n[4] Update Student");
	
	printf("\n\n[5] Quit");
	printf("\n\n====================================================");
	printf("\n\n");
}

void updateStudentMenu(char* first, char* last) // Displays the menu for the specific student to have their attributes updated.
{
	printf("\n====================UPDATE STUDENT MENU====================");
	printf("\nWhat would you like to update about %s %s?", first, last);
	printf("\n\n[1] ID");
	printf("\n[2] First Name");
	printf("\n[3] Last Name");
	printf("\n[4] GPA");
	
	printf("\n\n[5] Quit");
	printf("\n\n===========================================================");
	printf("\n\n");
}
