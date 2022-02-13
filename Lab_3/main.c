#include <stdio.h>
#include <string.h>
#include <stdlib.h>

FILE *filePtr;

int theArray[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
int numInput = 0;

typedef struct student
{
    int ID;
    char firstName[30];
    char lastName[30];
    float GPA;
} Student;

void ReverseArray(void);
Student* createStudent(void);
void sortGPA(Student** inputArray);
void readStudentRecords(void);

int main()
{
	
	
	
	ReverseArray();
	
	
	
	printf("\n\nEnter the number of students in the class: ");
	scanf("%d", &numInput);
	Student **arrayStudent = (Student**) malloc(numInput * sizeof(Student*));
	/*for(int i = 0; i < numInput; i++)
	{
		arrayStudent[i] = createStudent();
	}
	sortGPA(arrayStudent);
	filePtr = fopen("StudentRecords.txt", "w+");
	fprintf(filePtr, "Number of students: %d ", numInput);
	for(int i = 0; i < numInput; i++)
	{
		fprintf(filePtr, "\n\nStudent ID: %d", arrayStudent[i]->ID);
		fprintf(filePtr, "\nStudent First Name: %s", arrayStudent[i]->firstName);
		fprintf(filePtr, "\nStudent Last Name: %s", arrayStudent[i]->lastName);
		fprintf(filePtr, "\nStudent GPA: %f", arrayStudent[i]->GPA);
	}*/
	free(arrayStudent);
	readStudentRecords();
}

void ReverseArray()
{
	int reversedArray[10];
	for(int i=0; i<10; i++)
	{
		reversedArray[i] = theArray[9-i];
	}
	for(int i=0; i<10; i++)
	{
		theArray[i] = reversedArray[i];
		printf("%d ", theArray[i]);
	}
}

Student* createStudent()
{
	Student* peterPtr = (Student*) malloc(sizeof(Student));
	int id_in = 0;
	char first_in[30] = "";
	char last_in[30] = "";
	float gpa_in = 0.0;
	
	printf("\nEnter the ID of the student: ");
	scanf("%d", &id_in);
	peterPtr->ID = id_in;
	
	printf("\nEnter the first name of the student: ");
	scanf("%29s", first_in);
	strcpy(peterPtr->firstName, first_in);
	
	printf("\nEnter the last name of the student: ");
	scanf("%29s", last_in);
	strcpy(peterPtr->lastName, last_in);
	
	printf("\nEnter the GPA of the student: ");
	scanf("%f", &gpa_in);
	peterPtr->GPA = gpa_in;
	
	return peterPtr;
}

void sortGPA(Student** inputArray)
{
	for(int i = 0; i<numInput-1; i++)
	{
		for(int j = 0; j<numInput-1; j++)
		{
			if(inputArray[i]->GPA > inputArray[j]->GPA)
			{
				Student* temp = inputArray[i];
				inputArray[i] = inputArray[j];
				inputArray[j] = temp;
			}
			
		}
	}
}

void readStudentRecords()
{
	printf("=========STUDENT RECORDS=========\n");
	char first_out[30], last_out[30];
	int numOut, id_out;
	float gpa_out;
	
	filePtr = fopen("StudentRecords.txt", "r");
	fscanf(filePtr, "Number of students: %d", &numOut);
	printf("\nNumber of students: %d", numOut);

	Student** newStudentArray = (Student**) malloc(numInput * sizeof(Student*));
	for(int i=0; i<numInput; i++)
	{
		Student* piperPtr = (Student*) malloc(sizeof(Student));
		
		fscanf(filePtr, "\n\nStudent ID: %d", &id_out);
		piperPtr->ID = id_out;
		printf("\n\nStudent ID: %d", id_out);
		
		fscanf(filePtr, "\nStudent First Name: %s", first_out);
		strcpy(piperPtr->firstName, first_out);
		printf("\nStudent First Name: %s", first_out);
		
		fscanf(filePtr, "\nStudent Last Name: %s", last_out);
		strcpy(piperPtr->lastName, last_out);
		printf("\nStudent Last Name: %s", last_out);
		
		fscanf(filePtr, "\nStudent GPA: %f", &gpa_out);
		piperPtr->GPA = gpa_out;
		printf("\nStudent GPA: %f", gpa_out);
		
		newStudentArray[i] = piperPtr;
	}
	printf("\n\n=================================\n");
}

