#include "pch.h"
#include <stdio.h>

long fact(int n)
{
	long factorial = 1;

	while (n)
	{
		factorial *= n;
		--n;
	}

	return factorial;
}

long perm(int r, int n)
{
	long permutation = fact(n) / fact(n - r);
	return permutation;
}

long comb(int r, int n)
{
	long combination = perm(r, n) / fact(r);
	return combination;
}

void main()
{
	int r, n;
	printf("\nEnter r and n : ");
	scanf("%d %d", &r, &n);

	printf("\nThe number of permutation of %d objects chosen from %d is %li", r, n, perm(r, n));
	printf("\nThe number of combination of %d objects chosen from %d is %li", r, n, comb(r, n));
}