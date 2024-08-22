#include <iostream>
#include <string>
#include <cmath>
using namespace std;

static void NumSys_Calculator(string &expression, int &radix_from, int &radix_to)
{
	bool IncorrectDigit = false;
	bool Flag_from = (radix_from >= 2 && radix_from <= 10 || radix_from == 16);
	bool Flag_to = (radix_to >= 2 && radix_to <= 10 || radix_to == 16);
	if (expression[0] == ' ') { cout << "Error: Please, enter the expression without spaces!" << endl; }
	else if (expression[0] == '-') { cout << "Error: Please, enter a non-negative expression!" << endl; }
	else if (Flag_from == false) { cout << "Error: "; cout << "Incorrect radix: " << radix_from <<
		".\n       It can be: [2; 10], {16}." << endl; }
	else if (Flag_to == false) { cout << "Error: "; cout << "Incorrect radix: " << radix_to <<
		".\n       It can be: [2; 10], {16}." << endl; }
	else
	{ 
		for (int i = 0; i < expression.size(); i++)
		{
			(expression[i] - '0' >= radix_from) ? IncorrectDigit = true : IncorrectDigit = false;
		}
		if (IncorrectDigit == true && radix_from != 16) 
		{ 
			cout << "Error: Error input! \nPlease, try to enter the expression again!" << endl;
		}
		else
		{
			int decimal_number = 0;
			for (int i = 0; i < expression.size(); i++)
			{
				int digit = expression[i] - '0';
				if (digit >= 0 && digit <= 9)
				{
					decimal_number += digit * pow(radix_from, expression.size() - i - 1);
				}
				else if (digit >= 17 && digit <= 22)
				{
					switch (expression[i])
					{
					case 'A':
						digit = 10;
						break;
					case 'B':
						digit = 11;
						break;
					case 'C':
						digit = 12;
						break;
					case 'D':
						digit = 13;
						break;
					case 'E':
						digit = 14;
						break;
					case 'F':
						digit = 15;
						break;
					}
					decimal_number += digit * pow(radix_from, expression.size() - i - 1);
				}
				else {
					decimal_number = 0; cout <<
						"Error: Error input! \nPlease, try to enter the expression again!" << endl; return;
				}
			}
			int number = decimal_number;
			////////////////////////////
			cout << "Result: ";
			int size = 1;
			int number_size = number;
			while (number_size >= radix_to)
			{
				number_size /= radix_to;
				size++;
			}
			int *arr = new int[size];
			for (int i = 0; i < size; i++)
			{
				arr[i] = number % radix_to;
				int divider = number / radix_to;
				number = divider;
			}
			for (int i = 0; i < size; i++)
			{
				if (arr[size - i - 1] < 10)
				{
					cout << arr[size - i - 1];
				}
				else
				{
					switch (arr[size - i - 1])
					{
					case 10:
						cout << "A";
						break;
					case 11:
						cout << "B";
						break;
					case 12:
						cout << "C";
						break;
					case 13:
						cout << "D";
						break;
					case 14:
						cout << "E";
						break;
					default:
						cout << "F";
						break;
					}
				}
			}
			cout << endl;
			delete[] arr;
			arr = nullptr;
		}
	}
}

int main()
{
	string expression;
	int radix_from, radix_to;


	cout << endl;
	cout << "-<====================================================||CALCULATOR||==================================================>-" << endl;
	cout << endl << endl;
	cout << "|===============================================================<>" << endl;
	cout << "|===============================================================<>" << endl;
	cout << endl;
	cout << "enter an expression: ";
	getline(cin, expression);
	cout << endl;
	cout << "|===============================================================<>" << endl;
	cout << "|===============================================================<>" << endl;
	cout << endl;
	cout << "|---------------------------->>from<<----------------------------|" << endl;
	cout << "enter the radix of your expression: ";
	cin >> radix_from;
	cout << endl << endl;
	cout << "|----------------------------->>to<<-----------------------------|" << endl;
    cout << "enter a radix of number system: ";
	cin >> radix_to;
	cout << endl;
	cout << "|===============================================================<>" << endl;
	cout << "|===============================================================<>" << endl;
	cout << endl;
	NumSys_Calculator(expression, radix_from, radix_to);
	cout << endl;
	cout << "|===============================================================<>" << endl;
	cout << "|===============================================================<>" << endl;
	cout << endl << endl;
	cout << "-<===================================================||CALCULATOR||===================================================>-" << endl;
	cout << endl;
}
