#include <iostream>
#include <chrono>
#include <typeinfo>

using namespace std;

/*
 *		Bitwise Operators:
 *			-'>>' = shift a single bit left
 *			-'<<' = shift a single bit right
 *			-'&' = bitwise AND
 *			-'|' = bitwise OR
 *			-'^' = bitwise XOR
 *			-'~' = bitwise compliment
 **/
int multiplyBitwiseNumber(int, int); // Args: num1, num2
int multiplyNumber(int, int); // Args: num1, num2
bool determineEvenNum(int); // Args: number
int twoCompliment(int); // Args: number
int multiplyBy2(int); // Args: number1
int divideBy2(int); // Args: number2
string createFormat(int); // Args: numOfSpaces
int checkSmallNumSpaces(int, int=0); // Args: num1, num2
string createEqualBar(int);

int main()
{
	int num1 = 45, num2 = 12;
	int product;

	cout << "Enter value for number 1-> ";
	cin >> num1;
	cout << "\nEnter Value for number 2-> ";
	cin >> num2;

	cout << "Regular Multiplication and Division\n"
		 << "-----------------------------------\n\n";

	auto start = chrono::high_resolution_clock::now();
	product = multiplyNumber(num1, num2);
	auto stop = chrono::high_resolution_clock::now();
	auto elapsed = chrono::duration_cast<chrono::nanoseconds>(stop - start);

	cout << "        -----\n"
		 << "         " << product << endl << endl
		 << "Ran in " << elapsed.count() << " nanoseconds."
		 << "          Bitwise Operators        \n"
		 << "-----------------------------------\n\n";

	start = chrono::high_resolution_clock::now();
	product = multiplyBitwiseNumber(num1, num2);
	stop = chrono::high_resolution_clock::now();
	elapsed = chrono::duration_cast<chrono::nanoseconds>(stop - start);
	cout << "        -----\n"
		 << "         " << product << endl << endl
		 << "Ran in " << elapsed.count() << " nanoseconds.";

	return 0;

}

int multiplyNumber( int num1, int num2 )
{
	int product = 0;
	bool convertNum1, convertNum2;
	convertNum1 = convertNum2 = false;

	if ( num1 < 0 )
		convertNum1 = true;
	if ( num2 < 0 )
		convertNum2 = true;

	while (( num1 != 0 ) && ( num2 != 0 ))
	{
		bool even = true;
		int prev[2] = { num1, num2 };

		if ( num1 % 2 != 0 )
		{
			product += num2;
			even = false;
		}

		num1 /= 2;
		num2 *= 2;

		if ( !even )
			cout << prev[0] << "   " << prev[1] << "   " << prev[1] << endl;
		else
			cout << prev[0] << "   " << prev[1] << "   " << "***" << endl;
		
	}

	if ( convertNum1 && convertNum2 )
		product *= -1;
	
	return product;
}


bool determineEvenNum( int number )
{
	return ( number & 1 );
}

int twoCompliment( int number )
{
	number = ~number;
	return ( number ^ 1 );
}

int multiplyBy2( int number1 )
{
	number1 = number1 << 1;
	return number1;
}

int divideBy2( int number2 )
{
	number2 = number2 >> 1;
	return number2;
}

int checkSmallNumSpaces( int num1, int prevGaps )
{
	int smallNum, totalZeros = 1;

	if ( num1 < 0 )
	{
		num1 = num1 * (-1);
		totalZeros++;
	}

	while ( num1 != 0 )
	{
		num1 /= 10;
		totalZeros++;
	}

	if (( totalZeros + 2 <= prevGaps ))
		return prevGaps + 1;

	return totalZeros;
}

string createFormat( int smallNum )
{
	string space = " ";

	for ( int i = 0; i < smallNum; i++ )
		space = space + '_';

	return space;
}

int multiplyBitwiseNumber( int num1, int num2 )
{
	int product = 0;
	int totalSpaces = 0;
	bool convertNum1, convertNum2;
	convertNum1 = convertNum2 = false;

	if ( num1 < 0 )
		convertNum1 = true;
	if ( num2 < 0 )
		convertNum2 = true;


	while (( num1 != 0 ) & ( num2 != 0 ))
	{
		bool even = false;
		int prev[2] = { num1, num2 };

		even = determineEvenNum(num1);
		if ( even )
			product = product + num2;

		num2 = multiplyBy2(num2);
		num1 = divideBy2(num1);

		if ( even )
			cout << "   " << prev[0] << "   " << prev[1] << "   " << prev[1] << endl;
		else
			cout << "   " << prev[0] << "   " << prev[1] << "   ***" << endl;
	}

	return product;
}
