#include<ctime>
#include<cstdlib>
#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<locale>
using namespace std;
int main()
{
	double pr[400][400];
	double mas1[400][400];
	double mas2[400][400];
	int i = 0, j = 0, k = 0;
	int t = clock();
	int N = 400;
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
