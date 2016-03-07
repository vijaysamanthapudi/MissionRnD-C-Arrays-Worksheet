/*
OVERVIEW: Given a sorted array, insert a given number into the array at appropriate position.
E.g.: Arr = [2, 4, 6], num = 5 final Arr = [2, 4, 5, 6]. 5 is inserted at 2nd index.

INPUTS: Integer	Array pointer, length of the array, number to be inserted.

OUTPUT: Array pointer after inserting number.

ERROR CASES: Return NULL for invalid inputs.

NOTES: Use realloc to allocate memory.
*/

#include <stdio.h>
#include <malloc.h> 

int * sortedArrayInsertNumber(int *Arr, int len, int num)
{
	int i, y, pos;
	if (Arr == NULL || len <= 0)
	{
		return NULL;
	}
	else
	{
		Arr = (int *)realloc(Arr, (len + 1)*sizeof(int));
		if (num < Arr[0])
		{
			for (i = len; i >= 0; i--)
			{
				Arr[i] = Arr[i - 1];
			}
			Arr[0] = num;
		}
		else
		{
			for (i = 0; i < len; i++)
			{
				// if it lies between the  first and last element
				if ((Arr[i] == num))									// and it equal to any one of the elememt
				{
					pos = i;
					y = len;
					while (y >= i)
					{
						Arr[y] = Arr[y - 1];
						y--;

					}
					Arr[pos] = num;
					break;
				}


				if (num >= Arr[len - 1])
				{															// if number is greater than the last element
					Arr[len] = num;
				}

				if (Arr[i] < num &&num < Arr[i + 1])					 // if it lies between the  first and last element
					//all the distict elements
				{
					pos = i;
					y = len;
					while (y > i)
					{
						Arr[y] = Arr[y - 1];
						y--;

					}
					Arr[pos + 1] = num;
					break;

				}


			}
		}


	}
	return Arr;
}


