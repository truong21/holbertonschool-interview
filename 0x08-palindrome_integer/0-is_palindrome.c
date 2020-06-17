#include "palindrome.h"
/**
 * is_palindrome - Determine if number is a palindrome
 * @n: Unsigned long integer
 * Return: 1 if n is a palindrome; 0 otherwise
 */
int is_palindrome(unsigned long int n)
{
	unsigned long int origin = n;
	unsigned long int reverse = 0;
	unsigned long int remain = 0;
	int check = 0;

	while (n > 0)
	{
		remain = n % 10;
		n = (n - remain) / 10;
		reverse = reverse * 10 + remain;
	}
	if (reverse == origin)
		check = 1;

	return (check);
}
