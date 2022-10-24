#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>
#include <math.h>

float* getСoefficients();
void decisionCompleteEquation(float, float, float);
void decisionIncompleteEquation(float, float, float);

int main(void)
{
	system("chcp 1251>n");
	float* coefficients = getСoefficients();
	float coefficientA = coefficients[0], coefficientB = coefficients[1], coefficientC = coefficients[2];
	printf("a = %f, b = %f, c = %f\n", coefficientA, coefficientB, coefficientC);

	if (coefficients[0] == 0) printf("Уравнение не является квадратным, т.к. a == 0");
	else if (coefficients[1] != 0 && coefficients[2] != 0) decisionCompleteEquation(coefficientA, coefficientB, coefficientC);
	else decisionIncompleteEquation(coefficientA, coefficientB, coefficientC);
}

float* getСoefficients()
{
	FILE* file;
	char textFromFile[11];
	file = fopen("1.txt", "r");
	fgets(textFromFile, 11, file);
	printf("%s", textFromFile);
	printf("\n");
	fclose(file);

	char* SplitTextFromFile;
	float* coefficientsFromFile = calloc(3, sizeof(float*) + 1);
	SplitTextFromFile = strtok(textFromFile, " ");

	for (int i = 0; SplitTextFromFile != NULL; i++)
	{
		printf("%s\n", SplitTextFromFile);
		coefficientsFromFile[i] = atof(SplitTextFromFile);
		SplitTextFromFile = strtok(NULL, " ");
	}
	return coefficientsFromFile;
}

void decisionCompleteEquation(float forCoefficientA, float forCoefficientB, float forCoefficientC)
{
	float discriminant;
	float x1, x2;
	
	discriminant = pow(forCoefficientB, 2) - 4 * forCoefficientA * forCoefficientC;
	if (discriminant > 0)
	{
		x1 = (-forCoefficientB + sqrt(discriminant)) / (2 * forCoefficientA);
		x2 = (-forCoefficientB - sqrt(discriminant)) / (2 * forCoefficientA);
		printf("%f %f", x1, x2); //Отправить в новый файл
	}
	else if (discriminant == 0)
	{
		x1 = (-forCoefficientB + sqrt(discriminant)) / (2 * forCoefficientA);
		printf("%f", x1);
	}
	else printf("Корней нет!");
}

void decisionIncompleteEquation(float forCoefficientA, float forCoefficientB, float forCoefficientC)
{
	float x1, x2;
	if (forCoefficientC == 0 && forCoefficientB != 0)
	{
		if (-(forCoefficientC / forCoefficientA) >= 0)
		{
			x1 = sqrt(-(forCoefficientC / forCoefficientA));
			x2 = -x1;
			printf("%f %f", x1, x2);
		}
		else printf("Нет корней, т.к. -(c/a) < 0");
	}
	else if (forCoefficientB == 0 && forCoefficientC != 0)
	{
		x1 = 0;
		x2 = -(forCoefficientB / forCoefficientA);
		printf("%f %f", x1, x2);
	}
	else 
	{
		x1 = 0;
		printf("%f", x1);
	}
}