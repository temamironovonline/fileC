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
	fgets(buffer, 12, file);
	printf("%s", buffer);
	fclose(file);
	//getch();

	char* lastOne = calloc(1, sizeof(char*)+1);
	float* lastTwo = calloc(1, sizeof(float*)+1);
	for (int i = 0; i < 12; i++)
	{
		if (buffer[i] != ' ')
		{
			lastOne[i] = buffer[i];
			realloc(lastOne, (i + 2) * sizeof(char*) + 1);
		}
		/*else
		{
			break;
		}*/
	}
	printf("\n%s", lastOne);
	lastTwo[0] = strtol(lastOne, NULL, lastTwo[0]);
	printf("%f", lastTwo[0]);
	//file = fopen("1.txt", "r");
}