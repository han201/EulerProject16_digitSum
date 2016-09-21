// Sum of the digits of pow(2, 1000)

// This is challenge, since 2^1000 is a really large number!!

#include <iostream>
#include <vector>
#include <cmath>
// #include "utils.h"
using namespace std;

int main() {
	int DIGITS = 1000;
	vector <int> number(DIGITS, 0);   // define a vector of 1000 zero's
	
	number[DIGITS - 1] = 1;               //initial value
	
	/*
	for (auto c : number) 
	   cout << c << ' ';
	*/

	for (int i = 0;i < DIGITS;i++) {
		int carry = 0;          // initial number to carry
		for (int j = DIGITS - 1;j >= 0; j--) {
			if ((2 * number[j] + carry) > 9) {
				number[j] = (2 * number[j] + carry) % 10;
				carry = 1;
			}
			else {
				number[j] = 2 * number[j] + carry;
				carry = 0;                          // since carry from the previous digit was added to the new digit, reset carry
			}
			// cout << j << ":" << number[j] << endl;
		}
	}
	
	int sum = 0;
	for (int i = 0;i < DIGITS;i++) {
		sum += number[i];
	}
	cout << "The sum of the digits of 2 to the power of " << DIGITS << " is " << sum << endl;
	system("pause");
	return 0;

}

/*
The algorithm is from the discussion forum:
Spent a few hours writing a function to multiply large numbers only to find out that I can, 
starting from the least significant to most significant digit, 
multiply each digit by 2 and then bringing the carry over to the next significant digit. 
But hey at least I learnt something.
*/