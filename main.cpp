#include <iostream>
#include <windows.h>
#include <time.h>
#include <cstdlib>
using namespace std;
bool wygrana,blad;
int a,losowa,remis,pkt1,pkt2,numer;
char l[9],tura='X';
void menu();
void pvsb();
void bot();
void reset()
{
    for(int i=0; i<9; i++)
    {
        l[i]=' ';
    }
}
void bot_los()
{

    srand(time(NULL));
    losowa=rand()%9;
}
void gramenu()
{
    cout<<"  "<<l[0]<<" | "<<l[1]<<" | "<<l[2]<<endl;
    cout<<" -----------"<<endl;
    cout<<"  "<<l[3]<<" | "<<l[4]<<" | "<<l[5]<<endl;
    cout<<" -----------"<<endl;
    cout<<"  "<<l[6]<<" | "<<l[7]<<" | "<<l[8]<<endl;
    cout<<"gracz X: "<<pkt1<<endl;
    cout<<"gracz O: "<<pkt2<<endl<<"10. Exit"<<endl;
}
void win()
{
    if (((l[0] == l[1]) && (l[1] == l[2]) && ((l[0] == 'X') || (l[0] == 'O'))) ||
            ((l[3] == l[4]) && (l[4] == l[5]) && ((l[3] == 'X') || (l[3] == 'O'))) ||
            ((l[6] == l[7]) && (l[7] == l[8]) && ((l[6] == 'X') || (l[6] == 'O'))) ||
            ((l[0] == l[3]) && (l[3] == l[6]) && ((l[0] == 'X') || (l[0] == 'O'))) ||
            ((l[1] == l[4]) && (l[4] == l[7]) && ((l[1] == 'X') || (l[1] == 'O'))) ||
            ((l[2] == l[5]) && (l[5] == l[8]) && ((l[2] == 'X') || (l[2] == 'O'))) ||
            ((l[0] == l[4]) && (l[4] == l[8]) && ((l[0] == 'X') || (l[0] == 'O'))) ||
            ((l[2] == l[4]) && (l[4] == l[6]) && ((l[2] == 'X') || (l[2] == 'O'))))
    {
        wygrana=true;
    }
}
void pvp()
{
    reset();
    system("cls");
    gramenu();
    do
    {
        cout << "Tura gracza " << tura << "." << endl;
        do
        {
            cout << "Wstaw " << tura << ": ";
            cin >> numer;
            if(numer==10)
            {
                pkt1=0;
                pkt2=0;
                menu();
            }
            blad = cin.fail();
            if (blad == 1)
            {
                cin.clear();
                cin.ignore(999, '\n');
            }
        }
        while ((blad == 1) || (numer < 1) || (numer > 9) || (l[numer - 1] == 'X') || (l[numer - 1] == 'O'));
        l[numer - 1] = tura;
        system("cls");
        gramenu();
        if (tura == 'X')
            tura = 'O';
        else if (tura == 'O')
            tura = 'X';
        win();
        remis++;
    }
    while ((wygrana == 0) && (remis != 9));
    if (wygrana==1)
    {
        if (tura == 'X')
        {
            tura = 'O';
            pkt2++;
        }
        else if (tura == 'O')
        {
            tura = 'X';
            pkt1++;
        }
        cout << "Wygrywa: "<<tura<<endl;
    }
    else if (remis==9)
    {
        cout << "Remis!" << endl;
    }
    system("pause");
    pvp();
}
pvb()
{
    reset();
    system("cls");
    gramenu();
    do
    {
        cout << "Tura gracza " << tura << "." << endl;
        do
        {
            cout << "Wstaw " << tura << ": ";
            cin >> numer;
            if(numer==10)
            {
                pkt1=0;
                pkt2=0;
                menu();
            }
            blad = cin.fail();
            if (blad == 1)
            {
                cin.clear();
                cin.ignore(999, '\n');
            }
        }
        while ((blad == 1) || (numer < 1) || (numer > 9) || (l[numer - 1] == 'X') || (l[numer - 1] == 'O'));
        l[numer - 1] = tura;
        system("cls");
        gramenu();
        win();
        remis++;
        if (wygrana == 1)
        {
            cout << "Wygrywasz!" << endl;
            pkt1++;
            break;
        }
        else if (remis == 9)
        {
            cout << "Remis!" << endl;
            system("pause");
            break;
        }
        bot();
        system("cls");
        gramenu();
        win();
        remis++;
        if (wygrana == 1)
        {
            Sleep(1000);
            cout << "Przegrywasz!" << endl;
            pkt2++;
        }
    }
    while (wygrana == 0);
    system("pause");
    system("cls");
    pvb();
}


void menu()
{
    cout<<"-----------------------------------"
        <<endl<<"           TIC-TAC-TOE             "
        <<endl<<"-----------------------------------"
        <<endl<<"1.  2 GRACZY"
        <<endl<<"2. GRACZ VS SI"
        <<endl<<"Co wybierasz?  ";
    cin>>a;
    switch(a)
    {

    case 1:
        pvp();
        break;
    case 2:
        pvb();
        break;
    }
}
int main()
{
    menu();
    return 0;
}
void bot()
{
    if		((l[0] == l[1]) && (l[0] == 'O') && (l[2] != 'X') && (l[2] != 'O'))
        l[2] = 'O';
    else if ((l[3] == l[4]) && (l[3] == 'O') && (l[5] != 'X') && (l[5] != 'O'))
        l[5] = 'O';
    else if ((l[7] == l[6]) && (l[7] == 'O') && (l[8] != 'X') && (l[8] != 'O'))
        l[8] = 'O';
    else if ((l[1] == l[2]) && (l[1] == 'O') && (l[0] != 'X') && (l[0] != 'O'))
        l[0] = 'O';
    else if ((l[4] == l[5]) && (l[4] == 'O') && (l[3] != 'X') && (l[3] != 'O'))
        l[3] = 'O';
    else if ((l[7] == l[8]) && (l[7] == 'O') && (l[6] != 'X') && (l[6] != 'O'))
        l[6] = 'O';
    else if ((l[0] == l[3]) && (l[0] == 'O') && (l[6] != 'X') && (l[6] != 'O'))
        l[6] = 'O';
    else if ((l[1] == l[4]) && (l[1] == 'O') && (l[7] != 'X') && (l[7] != 'O'))
        l[7] = 'O';
    else if ((l[2] == l[5]) && (l[2] == 'O') && (l[8] != 'X') && (l[8] != 'O'))
        l[8] = 'O';
    else if ((l[6] == l[3]) && (l[6] == 'O') && (l[0] != 'X') && (l[0] != 'O'))
        l[0] = 'O';
    else if ((l[7] == l[4]) && (l[7] == 'O') && (l[1] != 'X') && (l[1] != 'O'))
        l[1] = 'O';
    else if ((l[8] == l[5]) && (l[8] == 'O') && (l[2] != 'X') && (l[2] != 'O'))
        l[2] = 'O';
    else if ((l[0] == l[4]) && (l[0] == 'O') && (l[8] != 'X') && (l[8] != 'O'))
        l[8] = 'O';
    else if ((l[2] == l[4]) && (l[2] == 'O') && (l[6] != 'X') && (l[6] != 'O'))
        l[6] = 'O';
    else if ((l[6] == l[4]) && (l[6] == 'O') && (l[2] != 'X') && (l[2] != 'O'))
        l[2] = 'O';
    else if ((l[8] == l[4]) && (l[8] == 'O') && (l[0] != 'X') && (l[0] != 'O'))
        l[0] = 'O';
    else if ((l[0] == l[6]) && (l[0] == 'O') && (l[3] != 'X') && (l[3] != 'O'))
        l[3] = 'O';
    else if ((l[1] == l[7]) && (l[1] == 'O') && (l[4] != 'X') && (l[4] != 'O'))
        l[4] = 'O';
    else if ((l[2] == l[8]) && (l[2] == 'O') && (l[5] != 'X') && (l[5] != 'O'))
        l[5] = 'O';
    else if ((l[0] == l[2]) && (l[0] == 'O') && (l[1] != 'X') && (l[1] != 'O'))
        l[1] = 'O';
    else if ((l[3] == l[5]) && (l[3] == 'O') && (l[4] != 'X') && (l[4] != 'O'))
        l[4] = 'O';
    else if ((l[6] == l[8]) && (l[6] == 'O') && (l[7] != 'X') && (l[7] != 'O'))
        l[7] = 'O';
    else if ((l[0] == l[8]) && (l[0] == 'O') && (l[4] != 'X') && (l[4] != 'O'))
        l[4] = 'O';
    else if ((l[2] == l[6]) && (l[2] == 'O') && (l[4] != 'X') && (l[4] != 'O'))
        l[4] = 'O';
    //-------------------------------------------------------------------------------------
    else if ((l[0] == l[1]) && (l[0] == 'X') && (l[2] != 'X') && (l[2] != 'O'))
        l[2] = 'O';
    else if ((l[3] == l[4]) && (l[3] == 'X') && (l[5] != 'X') && (l[5] != 'O'))
        l[5] = 'O';
    else if ((l[7] == l[6]) && (l[7] == 'X') && (l[8] != 'X') && (l[8] != 'O'))
        l[8] = 'O';
    else if ((l[1] == l[2]) && (l[1] == 'X') && (l[0] != 'X') && (l[0] != 'O'))
        l[0] = 'O';
    else if ((l[4] == l[5]) && (l[4] == 'X') && (l[3] != 'X') && (l[3] != 'O'))
        l[3] = 'O';
    else if ((l[7] == l[8]) && (l[7] == 'X') && (l[6] != 'X') && (l[6] != 'O'))
        l[6] = 'O';
    else if ((l[0] == l[3]) && (l[0] == 'X') && (l[6] != 'X') && (l[6] != 'O'))
        l[6] = 'O';
    else if ((l[1] == l[4]) && (l[1] == 'X') && (l[7] != 'X') && (l[7] != 'O'))
        l[7] = 'O';
    else if ((l[2] == l[5]) && (l[2] == 'X') && (l[8] != 'X') && (l[8] != 'O'))
        l[8] = 'O';
    else if ((l[6] == l[3]) && (l[6] == 'X') && (l[0] != 'X') && (l[0] != 'O'))
        l[0] = 'O';
    else if ((l[7] == l[4]) && (l[7] == 'X') && (l[1] != 'X') && (l[1] != 'O'))
        l[1] = 'O';
    else if ((l[8] == l[5]) && (l[8] == 'X') && (l[2] != 'X') && (l[2] != 'O'))
        l[2] = 'O';
    else if ((l[0] == l[4]) && (l[0] == 'X') && (l[8] != 'X') && (l[8] != 'O'))
        l[8] = 'O';
    else if ((l[2] == l[4]) && (l[2] == 'X') && (l[6] != 'X') && (l[6] != 'O'))
        l[6] = 'O';
    else if ((l[6] == l[4]) && (l[6] == 'X') && (l[2] != 'X') && (l[2] != 'O'))
        l[2] = 'O';
    else if ((l[8] == l[4]) && (l[8] == 'X') && (l[0] != 'X') && (l[0] != 'O'))
        l[0] = 'O';
    else if ((l[0] == l[6]) && (l[0] == 'X') && (l[3] != 'X') && (l[3] != 'O'))
        l[3] = 'O';
    else if ((l[1] == l[7]) && (l[1] == 'X') && (l[4] != 'X') && (l[4] != 'O'))
        l[4] = 'O';
    else if ((l[2] == l[8]) && (l[2] == 'X') && (l[5] != 'X') && (l[5] != 'O'))
        l[5] = 'O';
    else if ((l[0] == l[2]) && (l[0] == 'X') && (l[1] != 'X') && (l[1] != 'O'))
        l[1] = 'O';
    else if ((l[3] == l[5]) && (l[3] == 'X') && (l[4] != 'X') && (l[4] != 'O'))
        l[4] = 'O';
    else if ((l[6] == l[8]) && (l[6] == 'X') && (l[7] != 'X') && (l[7] != 'O'))
        l[7] = 'O';
    else if ((l[0] == l[8]) && (l[0] == 'X') && (l[4] != 'X') && (l[4] != 'O'))
        l[4] = 'O';
    else if ((l[2] == l[6]) && (l[2] == 'X') && (l[4] != 'X') && (l[4] != 'O'))
        l[4] = 'O';
    else
    {
        for (;;)
        {
            bot_los();
            if ((l[losowa] != 'X') && (l[losowa] != 'O'))
            {
                l[losowa] = 'O';
            }
            break;

        }
    }
    system("cls");
}
