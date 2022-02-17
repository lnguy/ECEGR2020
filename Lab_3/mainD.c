#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define length 100

char str_in[length];

void vowelCount(void);
void consCount(void);
void goUpper(void);
void goLower(void);
void strDisplay(void);
void strReplace(void);
void strReverse(void);
void menuDisplay(void);

int main()
{
	printf("Enter a string: ");
	gets(str_in);
	menuDisplay();
	char user_in;
	printf("\nWhat would you like to do? ");
	do
	{
		user_in = getchar();
		char junk = getchar();
		switch (user_in)
		{
			case 'A' :
				vowelCount();
				break;
			case 'a' :
				vowelCount();
				break;
			case 'B' :
				consCount();
				break;
			case 'b' :
				consCount();
				break;
			case 'C' :
				goUpper();
				break;
			case 'c' :
				goUpper();
				break;
			case 'D' :
				goLower();
				break;
			case 'd' :
				goLower();
				break;
			case 'E':
				strDisplay();
				break;
			case 'e':
				strDisplay();
				break;
			case 'F' :
				strReplace();
				break;
			case 'f' :
				strReplace();
				break;
			case 'R' :
				strReverse();
				break;
			case 'r' :
				strReverse();
				break;
			
			case 'M' :
				menuDisplay();
				break;
			case 'm' :
				menuDisplay();
				break;
			case 'X' :
				printf("\nExiting String Program...");
				break;
			case 'x' :
				printf("\nExiting String Program...");
				break;
				
			default :
				printf("\nInvalid input\n");
		}
	}while((user_in != 'X') && (user_in != 'x'));
}

void vowelCount()
{
	int count = 0;
	for(int i = 0; i < strlen(str_in); i++)
	{
		if(str_in[i] == 'a' || str_in[i] == 'A' ||
		   str_in[i] == 'e' || str_in[i] == 'E' ||
		   str_in[i] == 'i' || str_in[i] == 'I' ||
		   str_in[i] == 'o' || str_in[i] == 'O' ||
		   str_in[i] == 'u' || str_in[i] == 'U')
		{
			count++;
		}
	}
	printf("\nThere are %d vowels in the string\n\n", count);
}

void consCount()
{
	int count = 0;
	for(int i = 0; i < strlen(str_in); i++)
	{
		if(str_in[i] <= 90 && str_in[i] >= 65)
		{
			if(!(str_in[i] == 'A' ||
				 str_in[i] == 'E' ||
				 str_in[i] == 'I' ||
				 str_in[i] == 'O' ||
				 str_in[i] == 'U'))
			{
				count++;
			}
		}
		else if(str_in[i] >= 97 && str_in[i] <= 122)
		{
			if(!(str_in[i] == 'a' ||
			   str_in[i] == 'e' ||
			   str_in[i] == 'i' ||
			   str_in[i] == 'o' ||
			   str_in[i] == 'u'))
			{
			   count++;
			}
		
		}
	}
	printf("\nThere are %d consonants in the string\n\n", count);
}

void goUpper()
{
	for(int i = 0; i < (int) strlen(str_in); i++)
	{
		str_in[i] = (char) toupper(str_in[i]);
	}
}

void goLower()
{
	for(int i = 0; i < (int) strlen(str_in); i++)
	{
		str_in[i] = (char) tolower(str_in[i]);
	}
}

void strDisplay()
{
	printf("\n\n%s\n\n", str_in);
}

void strReplace()
{
	printf("\n\nEnter a string: ");
	gets(str_in);
}

void strReverse()
{
	char strRev[length];
	int lenIndex = strlen(str_in)-1;
	for(int i = lenIndex; i >= 0; i--)
	{
		strRev[(lenIndex)-i] = str_in[i];
	}
	for(int i = 0; i <= lenIndex; i++)
	{
		str_in[i] = strRev[i];
	}
}

void menuDisplay()
{
	printf("====================STRING MENU====================");
	
	printf("\n\n[A] Count the number of vowels in the string");
	printf("\n[B] Count the number of consonants in the string");
	printf("\n[C] Convert the string to uppercase");
	printf("\n[D] Convert the string to lowercase");
	printf("\n[E] Display the current string");
	printf("\n[F] Enter another string");
	printf("\n[R] Reverse words in string");
	
	printf("\n\n[M] Display this menu");
	printf("\n[X] Exit this program");
	printf("\n\n===================================================");
	printf("\n\n");
}