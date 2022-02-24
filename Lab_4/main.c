#include <stdio.h>
#include <string.h>
#include <stdlib.h>

FILE *filePtr;

typedef struct student
{
    int ID;
    char firstName[30];
    char lastName[30];
    float GPA;
	struct student* next;
} Student;

Student* firstStudent = NULL;

Student* createStudentNode(int id_in, char first_in[30], char last_in[30], float gpa_in)
{
	Student* newStudent = NULL;
	
	newStudent = (Student*) malloc(sizeof(Student));
	if(newStudent != NULL)
	{
		newStudent->ID = id_in;
		strcpy(newStudent->firstName, first_in);
		strcpy(newStudent->lastName, last_in);
		newStudent->GPA = gpa_in;
		newStudent->next = NULL;
	}
	
	return newStudent;
}

void addStudentNode(Student* newStudent)
{
	Student* currentStudent = firstStudent;
	
	if(firstStudent == NULL)
	{
		firstStudent = newStudent;
		return;
	}
	
	while(currentStudent->next != NULL)
	{
		currentStudent = currentStudent->next;
	}
	currentStudent->next = newStudent;
	newStudent->next = NULL;
}

void instertStudentNode(Student* newStudent)
{
	Student* node = firstStudent;
	while(node != NULL)
	{
		Student* nextNode = node->next;
		if((node->GPA > newStudent->GPA) && (newStudent->GPA >= nextNode->GPA))
		{
			newStudent->next = node->next;
			node->next = newStudent;
			return;
		}
		else if(node->GPA <= newStudent->GPA)
		{
			newStudent->next = node;
			firstStudent = newStudent;
			return;
		}
		else if((node->GPA >= newStudent->GPA) && (nextNode == NULL))
		{
			node->next = newStudent;
			newStudent->next = NULL;
			return;
		}
		node = node->next;
	}
	
	
}

void deleteStudentNode(Student* delStudent)
{
	Student* currentStudent = firstStudent;
	Student* prevSudent = NULL;
	
	if(firstStudent == delStudent)
	{
		firstStudent = firstStudent->next;
		free(delStudent);
		return;
	}
	
	while(currentStudent != NULL && currentStudent != delStudent)
	{
		prevSudent = currentStudent;
		currentStudent = currentStudent->next;
	}
	
	if(currentStudent != NULL)
	{
		prevSudent->next = currentStudent->next;
	}
	
	free(delStudent);
}

void readStudentRecords(void);
void readList(void);
void freeList(void);
void saveList(void);
void removeStudent(int id_in);
void updateStudent(int id_in);
//void sortGPA(void);
void menuDisplay(void);
void updateStudentMenu(void);

int main()
{
	int user_in;
	
	readStudentRecords();
	do
	{
		int id_input = 0;
		char first_input[30] = "";
		char last_input[30] = "";
		float gpa_input = 0.0;
		int userID_in;
		
		menuDisplay();
		printf("\nWhat would you like to do? ");
		scanf("%d", &user_in);
		switch(user_in)
		{
			case 1 :
				readList();
				break;
			case 2 :
				printf("\nEnter the ID of the student: ");
				scanf("%d", &id_input);
				
				printf("\nEnter the first name of the student: ");
				scanf("%29s", first_input);
				
				printf("\nEnter the last name of the student: ");
				scanf("%29s", last_input);
				
				printf("\nEnter the GPA of the student: ");
				scanf("%f", &gpa_input);
				while((gpa_input > 4.0) || (gpa_input < 1.0))
				{
					printf("\nPlease enter a GPA in the range of 4.0 and 1.0.");
					printf("\nEnter the GPA of the student: ");
					scanf("%f", &gpa_input);
				}
				
				Student* peterPtr = createStudentNode(id_input, first_input, last_input, gpa_input);
				instertStudentNode(peterPtr);
				break;
			case 3 :
				printf("\nEnter the ID of the student you wish to delete: ");
				scanf("%d", &userID_in);
				removeStudent(userID_in);
				break;
			case 4 :
				printf("\nEnter the ID of the student you wish to update: ");
				scanf("%d", &userID_in);
				updateStudent(userID_in);
				break;
			
			case 5 :
				printf("\nExiting Student Program...");
				break;
			
			default :
				printf("\nInvalid input\n");
		}
	}while(user_in != 5);
	saveList();
	freeList();
}

void readStudentRecords()
{
	//printf("=========STUDENT RECORDS=========\n");
	char first_out[30], last_out[30];
	int numOut, id_out;
	float gpa_out;
	
	filePtr = fopen("StudentRecords.txt", "r");
	fscanf(filePtr, "Number of students: %d", &numOut);
	//printf("\nNumber of students: %d", numOut);
	
	for(int i=0; i<numOut; i++)
	{
		fscanf(filePtr, "\n\nStudent ID: %d", &id_out);
		fscanf(filePtr, "\nStudent First Name: %s", first_out);
		fscanf(filePtr, "\nStudent Last Name: %s", last_out);
		fscanf(filePtr, "\nStudent GPA: %f", &gpa_out);
		
		Student* piperPtr = createStudentNode(id_out, first_out, last_out, gpa_out);
		addStudentNode(piperPtr);
	}
	
	printf("StudentRecords.txt successfully scanned\n");
}

void readList()
{
	Student* node = firstStudent;
	printf("\n==========STUDENT LINKED LIST==========");
	while(node != NULL)
	{
		printf("\n\nStudent ID: %d", node->ID);
		printf("\nStudent First Name: %s", node->firstName);
		printf("\nStudent Last Name: %s", node->lastName);
		printf("\nStudent GPA: %f", node->GPA);
		node = node->next;
	}
	printf("\n\n=======================================");
}

void freeList()
{
	Student* node = firstStudent;
	Student* nextNode = firstStudent->next;
	while(node != NULL)
	{
		deleteStudentNode(node);
		node = nextNode;
		nextNode = nextNode->next;
	}
}

void saveList()
{
	filePtr = fopen("StudentRecords.txt", "w+");
	Student* node = firstStudent;
	int studentCount = 0;
	while(node != NULL)
	{
		studentCount++;
		node = node->next;
	}
	
	fprintf(filePtr, "Number of students: %d ", studentCount);
	node = firstStudent;
	while(node != NULL)
	{
		fprintf(filePtr, "\n\nStudent ID: %d", node->ID);
		fprintf(filePtr, "\nStudent First Name: %s", node->firstName);
		fprintf(filePtr, "\nStudent Last Name: %s", node->lastName);
		fprintf(filePtr, "\nStudent GPA: %f", node->GPA);
		node = node->next;
	}
	fclose(filePtr);
}

/*void sortGPA()
{
	Student* node = firstStudent;
	while(node != NULL)
	{
		Student* nextNode = node->next;
		Student* beforeNextNode = nextNode;
		while(nextNode != NULL)
		{
			if(node->GPA > nextNode->GPA)
			{
				Student* temp = node;
				node->next = nextNode->next;
				nextNode->next = temp->next
			}
			beforeNextNode = nextNode;
			nextNode = nextNode->next;
		}
	}
}*/

void removeStudent(int id_in)
{
	Student* node = firstStudent;
	int check = 0;
	while(node != NULL)
	{
		if(id_in == node->ID)
		{
			char first[30];
			char last[30];
			strcpy(first, node->firstName);
			strcpy(last, node->lastName);
			deleteStudentNode(node);
			check = 1;
			printf("\n%s %s was successfully deleted.", first, last);
			return;
		}
		node = node->next;
	}
	if(check == 0)
	{
		printf("\nThere is no student associated with the given ID.");
		return;
	}
	return;
}

void updateStudent(int id_in)
{
	Student* node = firstStudent;
	Student* prevNode = node;
	int check = 0;
	int user_input = 0;
	updateStudentMenu();
	while(node != NULL)
	{
		if(id_in == node->ID)
		{
			do
			{
				updateStudentMenu();
				scanf("%d", &user_input);
				
				int new_id, old_id;
				char new_first[30], old_first[30];
				char new_last[30], old_last[30];
				float new_gpa, old_gpa;
				//Student* temp = node;
				
				switch(user_input)
				{
					case 1 :
						printf("\nEnter the new ID: ");
						scanf("%d", &new_id);
						old_id = node->ID;
						node->ID = new_id;
						printf("\n%d was sucessfully updated to %d", old_id, new_id);
						break;
					case 2 :
						printf("\nEnter the new first name: ");
						scanf("%29s", new_first);
						strcpy(old_first, node->firstName);
						strcpy(node->firstName, new_first);
						printf("\n%s was sucessfully updated to %s", old_first, new_first);
						//updateStudentMenu();
						break;
					case 3 :
						printf("\nEnter the new last name: ");
						scanf("%29s", new_last);
						strcpy(old_last, node->lastName);
						strcpy(node->lastName, new_last);
						printf("\n%s was sucessfully updated to %s", old_last, new_last);
						//updateStudentMenu();
						break;
					case 4 :
						printf("\nEnter the new GPA: ");
						scanf("%f", &new_gpa);
						old_gpa = node->GPA;
						node->GPA = new_gpa;
						prevNode->next = node->next;
						instertStudentNode(node);
						printf("\n%f was sucessfully updated to %f", old_gpa, new_gpa);
						//updateStudentMenu();
						break;
					
					case 5 :
						menuDisplay();
						break;
					
					default :
						printf("\nInvalid input\n");
						//updateStudentMenu();
				}
			} while(user_input != 5);
			return;
		}
		prevNode = node;
		node = node->next;
	}
	if(check == 0)
	{
		printf("\nThere is no student associated with the given ID.");
		return;
	}
}

void menuDisplay()
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

void updateStudentMenu()
{
	printf("\n====================STUDENT MENU====================");
	printf("\nWhat would you like to update about this student?");
	printf("\n\n[1] ID");
	printf("\n[2] First Name");
	printf("\n[3] Last Name");
	printf("\n[4] GPA");
	
	printf("\n\n[5] Quit");
	printf("\n\n====================================================");
	printf("\n\n");
}
