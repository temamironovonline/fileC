#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>

int main(void)
{
	FILE* file;
	char buffer[12];
	file = fopen("1.txt", "r");
	fgets(buffer, 11, file);
	printf("%s", buffer);
	fclose(file);

	char* lastOne;
	float* lastTwo = calloc(1, sizeof(float*)+1);
	int j = 0;


	lastOne = strtok(buffer, " ");
	int i = 0;
	printf("\n%p\n ", &lastOne[0]);
	for (int i = 0; i < 11; i++)
	{
		printf("%p ", &lastOne[i]);
 	}
	printf("\n%p ", &lastOne);
	while (lastOne != NULL)
	{
		printf("\n%s\n", lastOne);
		printf("\n%p\n", &lastOne);
		lastTwo[i] = atof(lastOne);
		lastOne = strtok(NULL, " ");
		i++;
		
	}

	for (int i = 0; i < 3; i++)
	{
		printf("%f ", lastTwo[i]);
	}
}