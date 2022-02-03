#include <stdio.h>
#include <math.h>

FILE *filePtr;

long Factorial(long num);
int IsPalidrome(long value);
int HighestBitSet(int value);
void ReverseIt(void);
void ReverseItAgain(void);
void Pyramid(int lines);

int main()
{
	//Factorial Test
	long num1;
	for(int i=0;i<5;i++) // For loop to interate the test 5 times
	{
		printf("Enter a number\n");
		scanf(" %ld", &num1);
		printf("the factorial of %ld is %ld\n\n", num1, Factorial(num1));
	}
	
	//IsPalindrome Test
	long num2;
	for(int i=0;i<5;i++) // For loop to interate the test 5 times
	{
		printf("Enter a number\n");
		scanf(" %ld", &num2);
		if(IsPalidrome(num2))
		{
			printf("%ld is a palidrome\n\n", num2);
		}
		else
		{
			printf("%ld is not a palidrome\n\n", num2);
		}
	}
	
	//HighestBitSet Test
	int num3;
	for(int i=0;i<5;i++) // For loop to interate the test 5 times
	{
		printf("Enter a number\n");
		scanf(" %d", &num3);
		HighestBitSet(num3);
	}
	
	//ReverseIt and ReverseItAgain Test
	ReverseIt(); // run individually 
	ReverseItAgain(); // doesn't write the file when both are ran like this
	
	//Pyramid Test
	int lineNum;
	printf("Enter a number\n");
	scanf(" %d", &lineNum);
	Pyramid(lineNum);
}

//Factorial Function
long Factorial(long num)
{
	long product = 1; // product variable to keep track of the final product value
	for(int i = 1;i<=num;i++) // For loop that iterates from 1 to num incramenting i by 1
	{
		product *= i; // multiplies the current i against the final product
	}
	return product; // returns the final product (the factorial)
}

//IsPalindrome Function
int IsPalidrome(long value)
{
	long count = value;
	long temp = 0; 
	long ans = 0;
	while(count != 0) // reverses the given value
	{
		ans *= 10;
		temp = count%10;
		ans += temp;
		count /= 10;
	}
	return ans == value; // checks if the reverse is the same as the original value
}

//HighestBitSet Function
int HighestBitSet(int value)
{
	int count = 0;
	while (pow((double) 2, (double) count) <= value) // checks if 2 to the power of count is <= value, since bits in binary represent 2^n numbers
	{
		count++; // incraments count to check what power of 2 would be the number
	}
	(int) --count; // decrement count since index starts at 0 for the highest bit set
	
	int temp = value;
	int binary[count]; // using an array to keep track of 1's and 0's in the right order for binary conversion
	for(int i = 0; temp>0; i++) // same way to reverse a number using integer division
	{
		binary[i] = temp % 2;
		temp /= 2;
	}
	printf("Value: %d Binary: ", value); 
	for(int i = count; i>=0; --i) // prints out the number in binary
	{
		printf("%d", binary[i]);
	}
	printf(" Highest Bit Set: %d\n\n", count); // prints out the highest bit set
	return count;
}

void ReverseIt(void)
{
	float nums[5]; // 5 numbers as input
	for(int i=0; i<5; i++) // for loop to take the inputs and put them into the float array
	{
		float num;
		printf("%d. Enter a number:", i+1);
		scanf(" %f\n", &num);
		nums[i] = num;
	}
	
	filePtr = fopen("ReverseIt.txt", "w+"); // opens the file for read/write
	for(int i=0; i<5; i++) // for loop to print to file in original order
	{
		fprintf(filePtr, "%f ", nums[i]);
	}
	for(int i=4; i>=0; i--) // for loop to print to file in reverse order
	{
		fprintf(filePtr, "%f ", nums[i]);
	}
	
}

void ReverseItAgain(void)
{
	// no for loops, just read the file and print it
	filePtr = fopen("ReverseIt.txt", "r");
	float num0, num1, num2, num3, num4, num5, num6, num7, num8, num9;
	fscanf(filePtr,"%f %f %f %f %f %f %f %f %f %f", &num0, &num1, &num2, &num3, &num4, &num5, &num6, &num7, &num8, &num9);
	printf("%f %f %f %f %f %f %f %f %f %f\n", num0, num1, num2, num3, num4, num5, num6, num7, num8, num9);
}

void Pyramid(int lines)
{
	int temp = lines;
	int line = 1;
	for(int i=line;i<=lines;i++) // top for loop that iterates for every level/line of the pyramid
	{
		for(int j=lines-i;j>0;j--) // spaces determined by the input lines and how many lines hae been made
		{
			printf(" ");
		}
		printf("*");
		for(int j=i-1;j>0;j--) // two more stars are added per level, determined how many stars are added based on what level/line it is on
		{
			printf("*");
			printf("*");
		}
		printf("\n"); // new line for next level
	}
	
	filePtr = fopen("Pyramid.txt", "w+");
	for(int i=line;i<=lines;i++) // same thing as last set of nested for loops, but to write into a file
	{
		for(int j=lines-i;j>0;j--)
		{
			fprintf(filePtr, " ");
		}
		fprintf(filePtr, "*");
		for(int j=i-1;j>0;j--)
		{
			fprintf(filePtr, "*");
			fprintf(filePtr, "*");
		}
		fprintf(filePtr, "\n");
	}
}