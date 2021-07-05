#include<ctime>
#include<cstdlib>
#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<locale>
using namespace std;
int main()
{
	double pr[100][100];
	double mas1[100][100];
	double mas2[100][100];
	int i = 0, j = 0, k = 0;
	clock_t t = clock();
	int N = 100;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			mas1[i][j] = rand() % 100 + 1;
		}
	}
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			mas2[i][j] = rand() % 100 + 1;
		}
	}
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			for (k = 0; k < N; k++)
			{
				pr[i][j] += mas1[i][k] * mas2[k][j];
			}
		}
	}
	cout << "vremya: " << t;
}
