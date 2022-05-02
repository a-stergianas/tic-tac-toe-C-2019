#include <stdio.h>
#include <stdlib.h>
int wins,ties,loses,size,win1,win2;
char name[20]="";
void menu(int x)
{
    system("cls");
    switch(x)
    {
        case 1:
            printf("\n\n\tWelcome to Tic-Tac-Toe\n\n");
            printf("\t» ONE PLAYER\n");
            printf("\t  TWO PLAYERS\n");
            printf("\t  STATISTICS\n");
            printf("\t  EXIT\n");
            break;
        case 2:
            printf("\n\n\tWelcome to Tic-Tac-Toe\n\n");
            printf("\t  ONE PLAYER\n");
            printf("\t» TWO PLAYERS\n");
            printf("\t  STATISTICS\n");
            printf("\t  EXIT\n");
            break;
        case 3:
            printf("\n\n\tWelcome to Tic-Tac-Toe\n\n");
            printf("\t  ONE PLAYER\n");
            printf("\t  TWO PLAYERS\n");
            printf("\t» STATISTICS\n");
            printf("\t  EXIT\n");
            break;
        case 4:
            printf("\n\n\tWelcome to Tic-Tac-Toe\n\n");
            printf("\t  ONE PLAYER\n");
            printf("\t  TWO PLAYERS\n");
            printf("\t  STATISTICS\n");
            printf("\t» EXIT\n");
            break;
    }
}
int epilogi()
{
    int ch1,ch2;
    ch1=getch();
    ch2=0;
    if (ch1==224)
    {
        ch2 = getch();
        if(ch2==72)
            return -1;
        if(ch2==80)
            return 1;
    }
    else if (ch1==13)
        return 0;
}
void arxikopoihsh(char A[9])
{
    A[0]='1';
    A[1]='2';
    A[2]='3';
    A[3]='4';
    A[4]='5';
    A[5]='6';
    A[6]='7';
    A[7]='8';
    A[8]='9';
}
int checkwin(char A[9])
{
    int x=11;

    for(int i=0;i<9;i=i+3)
    {
        if(A[i]==A[i+1] && A[i]==A[i+2])
            x=i;
    }
    for(int i=0;i<3;i++)
    {
        if(A[i]==A[i+3] && A[i]==A[i+6])
            x=i;
    }
    if(A[0]==A[4] && A[0]==A[8])
        x=4;
    else if(A[2]==A[4] && A[2]==A[6])
        x=4;

    if(x!=11)
    {
        if(A[x]=='X')
            return 1;
        else
            return 2;
    }
    return 0;
}
void xrhsths(char A[9],int z,int p)
{
    int y,error=0;
    char x;
    x=getch();
    y=(int)x;
    while(A[y-49]!=x || y-49<0 || y-49>8)
    {
        if(y-49<0 || y-49>8)
        {
            if(error!=1)
            {
                pinakas(z,A);
                printf("\t Player %d turn\n",p);
                printf("    This isn't a valid block\n");
            }
            x=getch();
            y=(int)x;
            error=1;
        }
        else
        {
            if(error!=2)
            {
                pinakas(z,A);
                printf("\t Player %d turn\n",p);
                printf("      This block is taken\n");
            }
            x=getch();
            y=(int)x;
            error=2;
        }
    }
    error=0;
    if(z==1)
    {
        A[y-49]='X';
        pinakas(z,A);
    }
    else
    {
        if(p==1)
        {
            A[y-49]='X';
            pinakas(z,A);
        }
        else
        {
            A[y-49]='O';
            pinakas(z,A);
        }
    }
}
void cpu(char A[9],int i,int r)
{
    int x=11,m;
    char y='X';
    if(i==5)
    {
        for(int k=0;k<9;k++)
        {
            if(A[1]!='X' && A[1]!='O')
            x=1;
        }
    }
    else if(i==1)
    {
        if(r==2)
        {
            do
            {
                srand(time(NULL));
                m=rand()%5+1;
                if(m==1)
                    x=0;
                else if(m==2)
                    x=2;
                else if(m==3)
                    x=6;
                else if(m==4)
                    x=8;
                else
                    x=4;
            }while(A[x]=='X');
        }
        else
        {
            srand(time(NULL));
            m=rand()%2+1;
            if(m==1 && A[4]!='X')
                x=4;
            else
            {
                if(A[0]=='X')
                    x=8;
                else if(A[2]=='X')
                    x=6;
                else if(A[6]=='X')
                    x=2;
                else if(A[8]=='X')
                    x=0;
            }
        }
    }
    else
    {
        for(int i=0;i<9;i=i+3)
        {
            if(A[i]==A[i+1] && A[i+2]!='X' && A[i+2]!='O' && A[i]=='O')
                x=i+2;
            else if(A[i+1]==A[i+2] && A[i]!='X' && A[i]!='O' && A[i+1]=='O')
                x=i;
            else if(A[i]==A[i+2] && A[i+1]!='X' && A[i+1]!='O' && A[i]=='O')
                x=i+1;
        }
        for(int i=0;i<3;i++)
        {
            if(A[i]==A[i+3] && A[i+6]!='X' && A[i+6]!='O' && A[i]=='O')
                x=i+6;
            else if(A[i]==A[i+6] && A[i+3]!='X' && A[i+3]!='O' && A[i]=='O')
                x=i+3;
            else if(A[i+3]==A[i+6] && A[i]!='X' && A[i]!='O' && A[i+3]=='O')
                x=i;
        }
        if(A[0]==A[4] && A[8]!='X' && A[8]!='O' && A[0]=='O')
            x=8;
        else if(A[0]==A[8] && A[4]!='X' && A[4]!='O' && A[0]=='O')
            x=4;
        else if(A[4]==A[8] && A[0]!='X' && A[0]!='O' && A[4]=='O')
            x=0;
        if(A[2]==A[4] && A[6]!='X' && A[6]!='O' && A[2]=='O')
            x=6;
        else if(A[4]==A[6] && A[2]!='X' && A[2]!='O' && A[4]=='O')
            x=2;
        else if(A[2]==A[6] && A[4]!='X' && A[4]!='O' && A[2]=='O')
            x=4;

        if(x==11)
        {
            for(int i=0;i<9;i=i+3)
            {
                if(A[i]==A[i+1] && A[i+2]!='X' && A[i+2]!='O' && A[i]=='X')
                    x=i+2;
                else if(A[i+1]==A[i+2] && A[i]!='X' && A[i]!='O' && A[i+1]=='X')
                    x=i;
                else if(A[i]==A[i+2] && A[i+1]!='X' && A[i+1]!='O' && A[i]=='X')
                    x=i+1;
            }

            for(int i=0;i<3;i++)
            {
                if(A[i]==A[i+3] && A[i+6]!='X' && A[i+6]!='O' && A[i]=='X')
                    x=i+6;
                else if(A[i]==A[i+6] && A[i+3]!='X' && A[i+3]!='O' && A[i]=='X')
                    x=i+3;
                else if(A[i+3]==A[i+6] && A[i]!='X' && A[i]!='O' && A[i+3]=='X')
                    x=i;
            }

            if(A[0]==A[4] && A[8]!='X' && A[8]!='O' && A[0]=='X')
                x=8;
            else if(A[0]==A[8] && A[4]!='X' && A[4]!='O' && A[0]=='X')
                x=4;
            else if(A[4]==A[8] && A[0]!='X' && A[0]!='O' && A[4]=='X')
                x=0;

            if(A[2]==A[4] && A[6]!='X' && A[6]!='O' && A[2]=='X')
                x=6;
            else if(A[4]==A[6] && A[2]!='X' && A[2]!='O' && A[4]=='X')
                x=2;
            else if(A[2]==A[6] && A[4]!='X' && A[4]!='O' && A[2]=='X')
                x=4;
        }

        if(x==11)
        {
            do
            {
                srand(time(NULL));
                x=rand()%9;
            }
            while(A[x]=='X' || A[x]=='O');
        }
    }

    A[x]='O';
    pinakas(1,A);
}
void menu_telous(int winner,char A[9],int x,int z)
{
    pinakas(z,A);
    if(winner==0)
        printf("\t  IT'S A DRAW\n\n");
    else if(winner==1 && z==2)
        printf("\tWINNER PLAYER 1\n\n");
    else if(winner==2 && z==2)
        printf("\tWINNER PLAYER 2\n\n");
    else if(winner==1 && z==1)
        printf("\t    YOU WON\n\n");
    else if(winner==2 && z==1)
        printf("\t   WINNER CPU\n\n");

    switch(x)
    {

        case 1:
            printf("\t» PLAY AGAIN\n");
            printf("\t  BACK TO MENU\n");
            break;
        case 2:
            printf("\t  PLAY AGAIN\n");
            printf("\t» BACK TO MENU\n");
            break;
    }
}
void oneplayer()
{
    char A[9];
    int r,winner;
    srand(time(NULL));
    r=rand()%2+1;
    arxikopoihsh(A);
    pinakas(1,A);
    for(int i=1;i<=5;i++)
    {
        if(r==1)
        {
            printf("\t It's your turn\n");
            xrhsths(A,1,1);
        }
        else
        {
            printf("\t  CPU's turn\n");
            printf("\t (please wait)\n");
            cpu(A,i,r);
        }
        if(i>=3)
        {
            winner=checkwin(A);
            if(winner!=0)
                break;
        }
        if(i!=5)
        {
            if(r==1)
            {
                printf("\t  CPU's turn\n");
                printf("\t (please wait)\n");
                cpu(A,i,r);
            }
            else
            {
                printf("\t It's your turn\n");
                xrhsths(A,1,1);
            }
        }
        if(i>=3)
        {
            winner=checkwin(A);
            if(winner!=0)
                break;
        }
    }

    if(winner==1)
        wins++;
    else if(winner==2)
        loses++;
    else
        ties++;

    int x=1,y=1;
    while(y!=0)
    {
        menu_telous(winner,A,x,1);
        y=epilogi();
        x=x+y;
        if (x<1)
            x=2;
        if(x>2)
            x=1;
    }

    switch(x)
    {
        case 1:
            oneplayer();
            break;
        case 2:
            printf("\n\tGive a name: ");
            gets(name);
            size=strlen(name);
            while(size>20)
            {
                menu_telous(winner,A,x,1);
                printf("\n     (max 20 characters)");
                printf("\n\tGive a name: ");
                gets(name);
                size=strlen(name);
            }
            write_stats();
            main();
            break;
    }
}
void twoplayers()
{
    char A[9];
    int r,winner;
    srand(time(NULL));
    r=rand()%2+1;
    arxikopoihsh(A);
    pinakas(2,A);
    for(int i=1;i<=5;i++)
    {
        if(i!=5)
        {
            printf("\t Player %d turn\n",r);
            xrhsths(A,2,r);
        }
        else
        {
            if(r==1)
            {
                printf("\t Player 2 turn\n");
                xrhsths(A,2,2);
            }
            else
            {
                printf("\t Player 1 turn\n");
                xrhsths(A,2,1);
            }
        }
        if(i>=3)
        {
            winner=checkwin(A);
            if(winner!=0)
                break;
        }
        if(i!=5)
        {
            if(r==1)
            {
                printf("\t Player 2 turn\n");
                xrhsths(A,2,2);
            }
            else
            {
                printf("\t Player 1 turn\n");
                xrhsths(A,2,1);
            }
        }
        if(i>=3)
        {
            winner=checkwin(A);
            if(winner!=0)
                break;
        }
    }

    if(winner==1)
        win1++;
    else if(winner==2)
        win2++;

    int x=1,y=1;
    while(y!=0)
    {
        menu_telous(winner,A,x,2);
        y=epilogi();
        x=x+y;
        if (x<1)
            x=2;
        if(x>2)
            x=1;
    }
    switch(x)
    {
        case 1:
            twoplayers();
            break;
        case 2:
            main();
            break;
    }
}
void write_stats()
{
    FILE *fp;
    if ((fp = fopen("stats.txt","a+"))!=NULL)
    {
        fprintf(fp,"%d ",size);
        fputs(name,fp);
        fprintf(fp," %d %d %d\n",wins,ties,loses);
        fclose(fp);
    }
    else
    {
        system("cls");
        printf("Error opening file\n");
    }
}
void show_stats()
{
    int x=1,y=1;
    while(y!=0)
    {
        FILE *fp;
        if ((fp = fopen("stats.txt","r"))!=NULL)
        {
            fseek(fp, 0, SEEK_END);
            unsigned long size = (unsigned long)ftell(fp);
            fclose(fp);
            if(size==0)
            {
                system("cls");
                printf("\n\tNo stats available yet.\n\n ");
            }
            else
            {
                FILE *fp;
                if ((fp = fopen("stats.txt","r"))!=NULL)
                {
                    system("cls");
                    printf("\n\t    STATISTICS\n\n");
                    printf("  NAME \t\t\t W - D - L\n");
                    printf(" ----------------------------------\n");
                    while(fscanf(fp,"%d ",&size)==1)
                    {
                        fgets(name,size+1,fp);
                        fscanf(fp,"%d %d %d",&wins,&ties,&loses);
                        if(size<=4)
                            printf("  %s \t\t\t %d - %d - %d\n",name,wins,ties,loses);
                        else if(size<=12)
                            printf("  %s \t\t %d - %d - %d\n",name,wins,ties,loses);
                        else
                            printf("  %s \t %d - %d - %d\n",name,wins,ties,loses);
                    }
                    fclose(fp);
                }
                else
                {
                    system("cls");
                    printf("Error opening file\n");
                }
            }
        }
        else
        {
            system("cls");
            printf("Error opening file\n");
        }
        switch(x)
        {
            case 1:
                printf("\n\t» DELETE HISTORY\n");
                printf("\t  BACK TO MENU\n");
                break;
            case 2:
                printf("\n\t  DELETE HISTORY\n");
                printf("\t» BACK TO MENU\n");
                break;
        }
        y=epilogi();
        x=x+y;
        if (x<1)
            x=2;
        if(x>2)
            x=1;
    }
    FILE *fp;
    switch(x)
    {
        case 1:
            if ((fp = fopen("stats.txt","w"))!=NULL)
                show_stats();
            else
            {
                system("cls");
                printf("Error opening file\n");
            }
            break;
        case 2:
            main();
            break;
    }
}
void pinakas(int x,char A[9])
{
    system("cls");
    printf("\n\n          Tic Tac Toe\n\n");

    if(x==1)
        printf("   Player (X)  -  CPU (O)\n\n");
    else
        printf("Player 1 (X) %d - %d Player 2 (O)\n\n",win1,win2);

    printf("            |     |     \n");
    printf("         %c  |  %c  |  %c \n", A[6], A[7], A[8]);
    printf("       _____|_____|_____\n");
    printf("            |     |     \n");
    printf("         %c  |  %c  |  %c \n", A[3], A[4], A[5]);
    printf("       _____|_____|_____\n");
    printf("            |     |     \n");
    printf("         %c  |  %c  |  %c \n", A[0], A[1], A[2]);
    printf("            |     |     \n\n");
    return 0;
}
int main()
{
    FILE *fp;
    fp = fopen("stats.txt","a");
    fclose(fp);
    int x=1,y=1;
    while(y!=0)
    {
        menu(x);
        y=epilogi();
        x=x+y;
        if (x<1)
            x=4;
        if(x>4)
            x=1;
    }
    switch(x)
    {
        case 1:
            wins=0;
            ties=0;
            loses=0;
            oneplayer();
            break;
        case 2:
            win1=0;
            win2=0;
            twoplayers();
            break;
        case 3:
            show_stats();
            break;
        case 4:
            system("cls");
            printf("\n\n\tTHANKS FOR PLAYING.\n\n");
            exit(0);
    }
}
