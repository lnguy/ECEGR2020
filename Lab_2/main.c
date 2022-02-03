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
		scanf(" %ld", &num3);
		HighestBitSet(num3);
	}
	
	//ReverseIt and ReverseItAgain Test
	ReverseIt();
	ReverseItAgain();
	
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
	while(count != 0)
	{
		ans *= 10;
		temp = count%10;
		ans += temp;
		count /= 10;
	}
	return ans == value;
}

//HighestBitSet Function
int HighestBitSet(int value)
{
	int count = 0;
	while (pow((double) 2, (double) count) <= value)
	{
		count++;
	}
	(int) --count;
	
	int temp = value;
	int binary[count];
	for(int i = 0; temp>0; i++)
	{
		binary[i] = temp % 2;
		temp /= 2;
	}
	printf("Value: %d Binary: ", value);
	for(int i = count; i>=0; --i)
	{
		printf("%d", binary[i]);
	}
	printf(" Highest Bit Set: %d\n\n", count);
	return count;
}

void ReverseIt(void)
{
	float nums[5];
	for(int i=0; i<5; i++)
	{
		float num;
		printf("%d. Enter a number\n", i+1);
		scanf(" %f", &num);
		nums[i] = num;
	}
	
	filePtr = fopen("ReverseIt.txt", "w+");
	for(int i=4; i>=0; i--)
	{
		fprintf(filePtr, "%f ", nums[i]);
	}
	
}

void ReverseItAgain(void)
{
	//float nums[5];
	filePtr = fopen("ReverseIt.txt", "r");
	float temp0, temp1, temp2, num0, num1, num2, num3, num4;
	fscanf(filePtr, "%f %f %f %f %f %f %f %f", &temp0, &temp1, &temp2, &num0, &num1, &num2, &num3, &num4);
	printf("%f %f %f %f %f", num0, num1, num2, num3, num4);
}

void Pyramid(int lines)
{
	int temp = lines;
	int line = 1;
	for(int i=line;i<=lines;i++)
	{
		for(int j=lines-i;j>0;j--)
		{
			printf(" ");
		}
		printf("*");
		for(int j=i-1;j>0;j--)
		{
			printf("*");
			printf("*");
		}
		printf("\n");
	}
	
	filePtr = fopen("Pyramid.txt", "w+");
	for(int i=line;i<=lines;i++)
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