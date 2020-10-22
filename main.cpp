#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <fstream>

using namespace std;

void arrayShuffle(int var, int* array)
{
	int random;

	for (int i = 0; i < var; i++)
	{
		random = rand() % var;
		swap(array[i], array[random]);
	}
}

void arrayInit(int var, int *array)
{
	for (int i = 0; i < var; i++)
		array[i] = i;
}

void printArray(int var, int* array)
{
	for (int i = 0; i < var; i++)
		cout << array[i] << " ";
}

float sortPercentage(int var, int* array)
{
	int numberOfCorrectElements = 0;

	for (int i = 0; i < var; i++)
		if (array[i] == i)
			numberOfCorrectElements++;

	return (numberOfCorrectElements / float(var)) * 100;
}

int main()
{
	srand(time(NULL));

	int start, finish;

	float percentage;
	float percentageMax;

	cout << "Number of variables to start with: "; cin >> start;
	cout << "Number of variables to end on: "; cin >> finish;

	for (int var = start; var <= finish; var++)
	{
		int* array = new int[var];
		arrayInit(var, array);

		percentageMax = 0;

		cout << var << " variables: ";

		do
		{
			arrayShuffle(var, array);
			//printArray(var, array);
			percentage = sortPercentage(var, array);

			if (percentage > percentageMax)
			{
				percentageMax = percentage;
				cout << percentage << "% ";
			}
		} while (percentage < 99.5f);

		cout << endl;
	}
}