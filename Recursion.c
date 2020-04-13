//Recursion.c: This file contains the definitions of all the functions in recursion.h. Tail recursion implementations preferred
#include <stdio.h>

//Factorial
//Actual factorial calculation
int fact_actual(int n, int res) {
	if (n == 0) {
		return res;
	}
	return fact_actual(n - 1, res * n);
}
//Wrapper for factorial
int factorial(int n) {
	if (n < 0) {
		return -1;
	}
	return fact_actual(n, 1);
}

//Digit Sum
//Actual digit sum calculation
int digSum_actual(int n, int sum) {
	if (n == 0) {
		return sum;
	}
	sum += n % 10;
	return digSum_actual(n/10,sum);
}
//Wrapper for digit sum
int digitSum(int n) {
	return digSum_actual(n, 0);
}

//Print string in reverse
void reversePrint(char* str) {
	if (str == NULL || str[0] == '\0') {
		return;
	}
	reversePrint(str + 1);
	printf("%c", str[0]);
}

//Check whether a string is a palidrome
//Actual palindrome check
char* palindrome_actual(char* str, int length, int position) {
	if (position > length / 2) {
		return "true";
	}
	if (str[position] != str[length - 1 - position]) {
		return "false";
	}
	return palindrome_actual(str, length, position + 1);
}
//Wrapper for palindrome check
char* checkPalindrome(char* str) {
	int length;
	for (length = 0; str[length] != '\0'; ++length);
	char* result;
	if (length == 0) {
		result = "false";
	} else {
		result = palindrome_actual(str, length, 0);
	}

	return result;
}

//Check if string 1 is a subsequence of string 2
char* checkSubsequence(char* str1, char* str2) {
	//possible return values
	char* TRUE = "true";
	char* FALSE = "false";

	//Length of each string
	int len1;
	int len2;
	for (len1 = 0; str1[len1] != '\0'; ++len1);
	for (len2 = 0; str2[len2] != '\0'; ++len2);

	//If string 1 is longer than string 2, it cannot be a subsequence of string 2
	if (len1 > len2) {
		return FALSE;
	}
	//if string 1 is of 0 length, it is a subsequence of string 2
	if (len1 == 0) {
		return TRUE;
	}
	
	char first = str1[0];

	int skip;
	for (skip = 0; (skip < len2) && (str2[skip] != first); ++skip);
	return checkSubsequence(str1 + 1, str2 + 1 + skip);
}