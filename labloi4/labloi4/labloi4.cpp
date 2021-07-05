#include <iostream>
using namespace std;

int m, i, j, sch;
int** mas1 = new int* [m];
int* num = new int[m];

void dfs(int v)
{
    num[v] = true;
    cout << v;
    for (int i = 0; i < m; i++)
    {
        if ((mas1[v][i] == 1) && (num[i] == false))
        {
            dfs(i);
        }
    }
}

int main()
{

    cout << "Enter m: ";
    cin >> m;
    cout << "\n";

    for (i = 0; i < m; i++)
    {
        num[i] = false;
    }

    for (i = 0; i < m; i++)
    {
        mas1[i] = new int[m];
        for (int j = 0; j < m; j++)
        {
            mas1[i][j] = rand() % 2;
        }
    }

    for (i = 0; i < m; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (sch == m)
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
    while (v < m)
    {
        cout << "\n";
        dfs(v);
        for (i = 0; i < m; i++)
        {
            num[i] = false;
        }
        v = v + 1;
    }
 }