#include <iostream>
using namespace std;

int mas1[7][7];
int num[7] = { false,false,false,false,false,false,false };

void dfs(int v)
{
    num[v] = true;
    cout << v;
    for (int i = 0; i < 7; i++)
    {
        if ((mas1[v][i] == 1) && (num[i] == false))
        {
            dfs(i);
        }
    }
}

int main()
{
    int i = 0, j = 0, sch = 0;
    for (i = 0; i < 7; i++)
    {
        for (j = i; j < 7; j++)
        {
            if (i == j)
            {
                mas1[i][j] = 0;
            }
            else
            {
                mas1[i][j] = rand() % 2;
                mas1[j][i] = mas1[i][j];
            }
        }
    }

    for (i = 0; i < 7; i++)
    {
        for (j = 0; j < 7; j++)
        {
            if (sch == 7)
            {
                cout << "\n";
                sch = 0;
            }
            cout << mas1[i][j];
            sch = sch + 1;
        }
    }

    int v = 0;
    cout << "\n";
    while (v != 7)
    {
        cout << "\n";
        dfs(v);
        for (i = 0; i < 7; i++)
        {
            num[i] = false;
        }
        v = v + 1;
    }
 }