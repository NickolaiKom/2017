#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tool.h"

int main()
{
	char *hex_value = (char *) malloc(sizeof(char) * 5);
	if(hex_value == NULL)
	{
		return 1;
	}
	
	printf("Enter HEX value. Without space or anouther symbols. Max 4 symbols.\nEnter: ");
	fgets(hex_value, 5, stdin);
	printf("\nYou writen: %s\n", hex_value);
	
	int *dec_value = (int *) malloc(sizeof(int) * 4);
	if(dec_value == NULL)
	{
		free(hex_value);
		return 1;
	}
	
	int z = checkValue(hex_value, dec_value);
	if(z != 0)
	{
		printf("Uncorrect format!\n");
		free(hex_value);
		free(dec_value);
		return 1;
	}
	
	int j = 0;
	printf("Converting in decimal: ");
	
	while(j < 4 && dec_value[j] != -1)
	{
		printf("%i ", dec_value[j]);
		j++;
	}
	printf("\n");
	
	int counter = 0;
	int size = j;
	unsigned long int result = formula(dec_value, counter, size);
	
	printf("\nResult: %ld\n", result);
	
	free(hex_value);
	free(dec_value);
	
	return 0;
}
