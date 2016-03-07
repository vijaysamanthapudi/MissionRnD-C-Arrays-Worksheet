/*
OVERVIEW:  given an array that has duplicate values remove all duplicate values.
E.g.: input: [1, 1, 2, 2, 3, 3], output [1, 2, 3]

Ex 2: [4,4,2,2,1,5] output : [4,2,1,5]

INPUTS: Integer array and length of the array .

OUTPUT: Update input array by removing duplicate values and return the final array length

ERROR CASES: Return -1 for invalid inputs.

NOTES: Don't create new array, try to change the input array.
*/

#include <stdio.h>
int  shift(int a[], int pos, int len);
int removeArrayDuplicates(int *Arr, int len)
{
	int i, j;

	if (Arr == NULL || len <= 0)
	{
		return -1;
	}
	else
	{
		for (i = 0; i < len - 1; i++)
		{
			for (j = i + 1; j < len; j++)
			{
				if (Arr[i] == Arr[j])
				{
					len = shift(Arr, j, len);
				}
			}
		}
	}
	return len;
}

int  shift(int Arr[], int pos, int len)
{
	int i;
	for (i = pos; i < len; i++)
	{
		Arr[i] = Arr[i + 1];

	}
	len--;
	return len;
}
