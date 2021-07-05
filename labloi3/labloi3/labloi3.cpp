#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <windows.h>

using namespace std;

int m, n, i, j;
int button, sch, a, b, u1, u2, v;

int** mas1 = new int* [m];
int** mas2 = new int* [n];
int** masrez = new int* [n];

void menu()
{
    cout << "\nF1 - отождествление\nF2 - Расщепление\nF3 - Вывод mas1\nF4 - Вывод mas2\nF5 - Вывод masrez\nF6 - Коньюнкция\nF7 - Дизьюнкция\nF8 - Кольцевая сумма\nF10 - Выход\n";
}

void mas1vyvod()
{
    sch = 0;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (sch == m)
            {
                cout << "\n";
                sch = 0;
            }
            cout << mas1[i][j] << "  ";
            sch = sch + 1;
        }
    }
    cout << "\n";
    menu();
}

void mas2vyvod()
{
    sch = 0;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (sch == n)
            {
                cout << "\n";
                sch = 0;
            }
            cout << mas2[i][j] << "  ";
            sch = sch + 1;
        }
    }
    cout << "\n";
    menu();
}

void masrezvyvod()
{
    sch = 0;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (sch == n)
            {
                cout << "\n";
                sch = 0;
            }
            cout << masrez[i][j] << "  ";
            sch = sch + 1;
        }
    }
    cout << "\n";
    menu();
}

void otozhd()
{
    cout << "Введите u1: ";
    cin >> u1;
    cout << "Введите u2: ";
    cin >> u2;
    for (i = 0; i < m; i++)
    {
        b = 0;
        if ((i == u1) || (i == u2)) continue;
        for (j = 0; j < m; j++)
        {
            if ((j == u1) || (j == u2)) continue;
            mas2[a][b] = mas1[i][j];
            b++;
        }
        mas2[a][b] = mas1[u1][j] | mas1[u2][j];
        mas2[b][a] = mas2[a][b];
        a++;
    }
    menu();
}

void ras()
{
    cout << "Введите v: ";
    cin >> v;
    if ((v == 0) || (v < 0) || (v > n))
    {
        cout << "\nНевозможное значение\n";
        menu();
        return;
    }
    else
    {
        v = v - 1;
    }
    for (i = 0; i < m; i++)
    {
        for (j = 1; j < m; j++)
        {
            mas2[i][j] = mas1[i][j];
            if (j == v)
            {
                mas2[m][j] = mas1[i][j];
                mas2[i][m] = mas1[i][j];
            }
        }
    }
    mas2[m][v] = 1;
    mas2[v][m] = 1;
    cout << "\n";
    menu();
}

void kon()
{
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < m; j++)
        {
          masrez[i][j] =  mas1[i][j] and mas2[i][j];
        }
    }
    cout << "\nПересечение графов завершено\n";
    menu();
}

void diz()
{
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < m; j++)
        {
           mas2[i][j] = mas1[i][j] or mas2[i][j];
        }
    }
    cout << "\nОбьединение графов завершено\n";
    menu();
}

void xili()
{
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < m; j++)
        {
            masrez[i][j] = mas1[i][j] xor mas2[i][j];
        }
    }
    cout << "\nКольцевая сумма графов создана\n";
    menu();
}

int main()
{

    setlocale(LC_ALL, "Rus");

    cout << "Укажите размерность массива mas1: ";
    cin >> m;
    cout << "\n";
    
    cout << "Укажите размерность массива mas2: ";
    cin >> n;
    cout << "\n";

    for (i = 0; i < m; i++)
    {
        mas1[i] = new int[m];
        for (int j = 0; j < m; j++)
        {
            mas1[i][j] = rand() % 2;
        }
    }

    for (i = 0; i < n; i++)
    {
        mas2[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            mas2[i][j] = rand() % 2;
        }
    }

    for (i = 0; i < n; i++)
    {
        masrez[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            masrez[i][j] = 0;
        }
    }

    menu();
    while ((button != 89) || (button != 121))
    {
        switch (button = _getch())
        {
            menu();

        case 59:
            otozhd();
            break;

        case 60:
            ras();
            break;

        case 61:
            mas1vyvod();
            break;

        case 62:
            mas2vyvod();
            break;
        
        case 63:
            masrezvyvod();
            break;

        case 64:
            kon();
            break;

        case 65:
            diz();
            break;

        case 66:
            xili();
            break;

        case 68: //ВЫХОД
            cout << "\nВы точно хотите выйти из программы?\nДа - Y\nНет - N\n";
            button = _getch();
            if ((button == 89) || (button == 121))
            {
                exit(0);
            }
            else
            {
                if ((button == 78) || (button == 110))
                {
                    menu();
                    break;
                }
            }
        }
    }
}