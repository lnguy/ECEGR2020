#include<stdio.h>

void SizeOfVariables(void);
int IsLeapYear(int aYear);
int IsVowel(char aLetter);
void ReverseNumber(long aNumber);

int main()
{
	//Testing Function 1
	SizeOfVariables();
	
	//Testing Function 2 with 10 different years
	if(IsLeapYear(2000))
	{
		printf("2000 is a leap year\n");
	}
	else
	{
		printf("2000 is not a leap year\n");
	}
	if(IsLeapYear(1900))
	{
		printf("1900 is a leap year\n");
	}
	else
	{
		printf("1900 is not a leap year\n");
	}
	if(IsLeapYear(1800))
	{
		printf("1800 is a leap year\n");
	}
	else
	{
		printf("1800 is not a leap year\n");
	}
	if(IsLeapYear(1904))
	{
		printf("1904 is a leap year\n");
	}
	else
	{
		printf("1904 is not a leap year\n");
	}
	if(IsLeapYear(1908))
	{
		printf("1908 is a leap year\n");
	}
	else
	{
		printf("1908 is not a leap year\n");
	}
	if(IsLeapYear(1700))
	{
		printf("1700 is a leap year\n");
	}
	else
	{
		printf("1700 is not a leap year\n");
	}
	if(IsLeapYear(200))
	{
		printf("200 is a leap year\n");
	}
	else
	{
		printf("200 is not a leap year\n");
	}
	if(IsLeapYear(2005))
	{
		printf("2005 is a leap year\n");
	}
	else
	{
		printf("2005 is not a leap year\n");
	}
	if(IsLeapYear(2007))
	{
		printf("2007 is a leap year\n");
	}
	else
	{
		printf("2007 is not a leap year\n");
	}
	if(IsLeapYear(2018))
	{
		printf("2018 is a leap year\n");
	}
	else
	{
		printf("2018 is not a leap year\n");
	}
	
	printf("\n");
	
	//Testing function 3 will different inputs
	if(IsVowel('a'))
		printf("a is a vowel\n");
	if(IsVowel('b'))
		printf("b is a vowel\n");
	if(IsVowel('c'))
		printf("c is a vowel\n");
	if(IsVowel('3'))
		printf("3 is a vowel\n");
	if(IsVowel('I'))
		printf("I is a vowel\n");
	if(IsVowel('!'))
		printf("! is a vowel\n");
	if(IsVowel('H'))
		printf("H is a vowel\n");
	
	//Testing Function 4
	ReverseNumber(1523);
	ReverseNumber(640495);
	ReverseNumber(123456789);
	
	printf("\n\n");
	
    int num1, num2;  
    float fraction;     
    char character;
    char str[50];   // char array of size 50

    printf("Enter two numbers\n");
    
    // Taking integer as input from user
    scanf(" %d%i", &num1, &num2);
    printf("\n\nThe two numbers You have entered are %d and %i\n\n", num1, num2);

    // Taking float or fraction as input from the user
    printf("\n\nEnter a Decimal number\n");
    scanf(" %f", &fraction); 
    printf("\n\nThe float or fraction that you have entered is %f", fraction);

    // Taking Character as input from the user
    printf("\n\nEnter a Character\n");
    scanf(" %c",&character);
    printf("\n\nThe character that you have entered is %c and the ASCII number is %d", character, character);
    getchar();

    printf("\n\nEnter your complete name:\n\n\n");

    gets(str);
    printf("\n\nWelcome to ECEGR 2020  %s\n\n\n", str);

    printf("\n\n\t\t\tCoding is Fun !\n\n\n");
    
    printf("Press Enter to quit");
    scanf("%c",&character);
    return 0;
}

void SizeOfVariables(void)
{
	char c;  
	short s;  
	int i;  
	unsigned int ui;  
	unsigned long int ul; 
	float f;
	double d;  
	long double ld;
	void *ptr;
	
	//all the %llu was %d at one point but it started causing errors after reopening
	printf("Variable c type char is %llu bytes", sizeof(c));
	printf("\nVariable s type short is %llu bytes", sizeof(s));
	printf("\nVariable i type int is %llu bytes", sizeof(i));
	printf("\nVariable ui type unsigned int is %llu bytes", sizeof(ui));
	printf("\nVariable ul type unsigned long int is %llu bytes", sizeof(ul));
	printf("\nVariable f type float is %llu bytes", sizeof(f));
	printf("\nVariable d type double is %llu bytes", sizeof(d));
	printf("\nVariable ld type long double is %llu bytes", sizeof(ld));
	printf("\nVariable *ptr type void is %llu bytes\n\n", sizeof(*ptr));
}

int IsLeapYear(int aYear)
{
	if(aYear < 1752)
	{
		//printf("%d is not a leap year (there were no leap years beefore 1752).", aYear);
		return 0;
	}
	else
	{
		if((aYear % 400) == 0)
		{
			return 1;
		}
		else if((aYear % 100) == 0)
		{
			return 0;
		}
		else if((aYear % 4) == 0)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
}

int IsVowel(char aLetter)
{
	if(aLetter >= 65 && aLetter <= 90)
	{
		if(aLetter == 'A' ||
		   aLetter == 'E' ||
		   aLetter == 'I' ||
		   aLetter == 'O' ||
		   aLetter == 'U')
		   {
			   return 1;
		   }
		else
		   {
			   printf("%c is not a vowel\n", aLetter);
			   return 0;
		   }
	}
	else if(aLetter >= 97 && aLetter <= 122)
	{
		if(aLetter == 'a' ||
		   aLetter == 'e' ||
		   aLetter == 'i' ||
		   aLetter == 'o' ||
		   aLetter == 'u')
		   {
			   return 1;
		   }
		else
		   {
			   printf("%c is not a vowel\n", aLetter);
			   return 0;
		   }
	}
	else
	{
		printf("%c is not an ASCII Letter\n", aLetter);
		return 0;
	}
	/*if (aLetter == 'a' ||
	    aLetter == 'e' ||
	    aLetter == 'i' ||
	    aLetter == 'o' ||
	    aLetter == 'u')
	{
		return 1;
	}
	else if (aLetter == 'b' ||
			 aLetter == 'c' ||
			 aLetter == 'd' ||
			 aLetter == 'f' ||
			 aLetter == 'g' ||
			 aLetter == 'h' ||
			 aLetter == 'j' ||
			 aLetter == 'k' ||
			 aLetter == 'l' ||
			 aLetter == 'm' ||
			 aLetter == 'n' ||
			 aLetter == 'p' ||
			 aLetter == 'q' ||
			 aLetter == 'r' ||
			 aLetter == 's' ||
			 aLetter == 't' ||
			 aLetter == 'v' ||
			 aLetter == 'w' ||
			 aLetter == 'x' ||
			 aLetter == 'y' ||
			 aLetter == 'z')
	{
		return 0;
	}
	else
	{
		printf("%c is not an ASCII Letter", aLetter);
	}*/
}

void ReverseNumber(long aNumber)
{
	long count = aNumber;
	long temp = 0;
	long ans = 0;
	while(count != 0)
	{
		ans *= 10;
		temp = count%10;
		ans += temp;
		count /= 10;
	}
	printf("\n%ld was reversed to %ld", aNumber, ans);
}