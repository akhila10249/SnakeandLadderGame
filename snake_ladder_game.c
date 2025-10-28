#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int roolldie() // function for roll a die
{
    return rand() % 6 + 1;
}
int player1 = 0, player2 = 0; // players with global variables
void gameboard(int player1,int player2)              // function for game board display
{
    int board[101];
    for (int i = 1; i <= 100; i++)
    {
        board[i] = i;
    }
    int alt = 0;
    int iterlr = 101;
    int iterrl = 80;
    int val = 100;
    while (val--)
    {
        if (alt == 0)
        {
            iterlr--;
            if (iterlr == player1)
            {
                printf(" @p1 ");
            }
            else if(iterlr == player2)
            {
                printf(" @p2 ");
            }
            else
            {
                printf("%5d", board[iterlr]);
            }
            if (iterlr % 10 == 1)
            {
                printf("\n\n");
                alt = 1;
                iterlr -= 10;
            }
        }
        else
        {
            iterrl++;
            if (iterrl == player1)
            {
                printf(" @p1  ");
            }
            else if(iterrl == player2)
            {
                printf(" @p2  ");
            }
            else
            {
                printf("%5d", board[iterrl]);
            }
            if (iterrl % 10 == 0)
            {
                printf("\n\n");
                alt = 0;
                iterrl -= 30;
            }
        }
        if (iterrl == 10)
            break;
    }
    printf("\n");
}
int moveplayer(int currentplayer, int roll)
{
    int newposition = currentplayer + roll;
    int snakesandladders[101];
    for (int i = 0; i <= 100; i++)
    {
        snakesandladders[i] = 0;
    }
    snakesandladders[6] = 40;
    snakesandladders[23] = -10;
    snakesandladders[45] = -7;
    snakesandladders[61] = -18;
    snakesandladders[65] = -8;
    snakesandladders[77] = 5;
    snakesandladders[98] = -10;
    int newsquare = newposition + snakesandladders[newposition];
    if (newsquare > 100)
    {
        newsquare=100;
        
    }
    return newsquare;
}
// main function
int main()
{
    srand(time(0));
    int currentplayer = 1;
    int won = 0;
    printf("snake and ladder game\n");
     while (!won)
    {
        printf("\nplayer %d press enter  to roll the die:",currentplayer);
         getchar();
    int roll = roolldie();
    printf("you rolled a %d.\n", roll);
    if (currentplayer == 1)
    {
        player1 = moveplayer(player1, roll);
        printf("player1 is now at square %d\n", player1);
        gameboard(player1,player2);
        if (player1 == 100)
        {
            printf("player1 wins!\n");
            won = 1;
        }
    }
    else
    {
        player2 = moveplayer(player2, roll);
        printf("player2 is now at square %d.\n", player2);
        gameboard(player1,player2);
        if (player2 == 100)
        {
            printf("player2 wins!\n");
            won = 1;
        }
    }
    currentplayer = (currentplayer == 1) ? 2 : 1;
}
return 0;
}
