#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <windows.h>

using namespace std;

int mas1[7][7], mas2[8][8];
int button, sch, i, j, a, b, u1, u2, v;

void menu()
{
    cout << "\nF1 - отождествление\nF2 - Расщепление\nF5 - Вывод mas1\nF6 - Вывод mas2\nF7 - Коньюнкция\nF8 - Дизьюнкция\nF9 - Кольцевая сумма\nF10 - Выход\n";
}

void mas1vyvod()
{
    sch = 0;
    for (i = 0; i < 7; i++)
    {
        for (j = 0; j < 7; j++)
        {
            if (sch == 7)
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
    for (i = 0; i < 8; i++)
    {
        for (j = 0; j < 8; j++)
        {
            if (sch == 8)
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

void otozhd()
{
    cout << "Введите u1: ";
    cin >> u1;
    cout << "Введите u2: ";
    cin >> u2;
    for (i = 0; i < 7; i++)
    {
        b = 0;
        if ((i == u1) || (i == u2)) continue;
        for (j = 0; j < 7; j++)
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
    if ((v == 0) || (v < 0) || (v > 8))
    { 
        cout << "\nНевозможное значение\n";
        menu();
        return;
    }
    else
    {
        v = v - 1;
    }
    for (i = 0; i < 7; i++)
    {
        for (j = 1; j < 7; j++)
        {
            mas2[i][j] = mas1[i][j];
            if (j == v)
            {
                mas2[7][j] = mas1[i][j];
                mas2[i][7] = mas1[i][j];
            }
        }
    }
    mas2[7][v] = 1;
    mas2[v][7] = 1;
    cout << "\n";
    menu();
}

void kon()
{
    for (i = 0; i < 7; i++)
    {
        for (j = 0; j < 7; j++)
        {
            mas1[i][j] and mas2[i][j];
        }
    }
    cout << "\nПересечение графов завершено\n";
    menu();
}

void diz()
{
    for (i = 0; i < 7; i++)
    {
        for (j = 0; j < 7; j++)
        {
            mas1[i][j] or mas2[i][j];
        }
    }
    cout << "\nОбьединение графов завершено\n";
    menu();
}

void xili()
{
    for (i = 0; i < 7; i++)
    {
        for (j = 0; j < 7; j++)
        {
            mas1[i][j] xor mas2[i][j];
        }
    }
    cout << "\nКольцевая сумма графов создана\n";
    menu();
}

int main()
{

    setlocale(LC_ALL, "Rus");

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

        case 63:
            mas1vyvod();
            break;

        case 64:
            mas2vyvod();
            break;

        case 65:
            kon();
            break;

        case 66:
            diz();
            break;

        case 67:
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