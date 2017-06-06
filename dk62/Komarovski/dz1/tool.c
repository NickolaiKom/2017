#include <math.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int checkValue(char *hex_value, int *dec_value)
{
	if(hex_value != NULL && dec_value != NULL)
	{
		for(int i = 0; i < 4; i++)
		{
			if((isdigit(hex_value[i]) != 0) || (hex_value[i] >= 'A' && hex_value[i] <= 'F') || (hex_value[i] >= 'a' && hex_value[i] <= 'f'))
			{
				switch(hex_value[i])
				{
					case '0':
						dec_value[i] = 0;
						break;
					case '1':
						dec_value[i] = 1;
						break;
					case '2':
						dec_value[i] = 2;
						break;
					case '3':
						dec_value[i] = 3;
						break;
					case '4':
						dec_value[i] = 4;
						break;
					case '5':
						dec_value[i] = 5;
						break;
					case '6':
						dec_value[i] = 6;
						break;
					case '7':
						dec_value[i] = 7;
						break;
					case '8':
						dec_value[i] = 8;
						break;
					case '9':
						dec_value[i] = 9;
						break;
					case 'a':
					case 'A':
						dec_value[i] = 10;
						break;
					case 'b':
					case 'B':
						dec_value[i] = 11;
						break;
					case 'c':
					case 'C':
						dec_value[i] = 12;
						break;
					case 'd':
					case 'D':
						dec_value[i] = 13;
						break;
					case 'e':
					case 'E':
						dec_value[i] = 14;
						break;
					case 'f':
					case 'F':
						dec_value[i] = 15;
						break;
				}
			}
			else if(hex_value[i] == '\n')
			{
				dec_value[i] = -1;
				return 0;
			}
			else
				return 1;
		}
	}
	return 0;
}

unsigned long int formula(int *dec_value, int a, int size)
{
	if(size != 0 && dec_value != NULL)
	{
		//int tmp = pow(16, size - 1) * dec_value[a];
		//a++;
		//size--;
		//return tmp + formula(dec_value, a, size);
		return pow(16, size - 1) * dec_value[a] + formula(dec_value, a + 1, size - 1);
	}
	else
		return 0;
}
