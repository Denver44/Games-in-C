#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define HEIGHT 20
#define WIDTH 20

int X, Y, gameover, score, flag;
char FRUITX, FRUITY, O;
int tailX[100];
int tailY[100];
int Counttail = 0;
void draw();
void setup();
void input();
void makelogic();

int main()
{
    char c;
    score = 0;
label7:
    setup();
    while (!gameover)
    {
        draw();
        input();
        makelogic();
        for (int m = 0; m < 1000; m++)
        {
            for (int n = 0; n < 10000; n++)
            {
            }
        }
    }
    printf("\n PRESS Y TO CONTINUE\n");
    
    scanf("%c", &c);
    if (c == 'y' || c == 'Y')
    {
        goto label7;
    }

    return 0;
}

void draw()
{
    system("CLS");
    printf("\t\t\t\t\t\t       WELCOME TO SNAKE GAME  \t\t YOUR SCORE [%d] \n\n\n", score);
    //printf("\n\n\n\t\t\t  current score  %d \n", score);
    for (int i = 0; i < HEIGHT; i++)
    {
        printf("\t\t\t\t\t\t");

        for (int j = 0; j < WIDTH; j++)
        {
            if (i == 0 || i == HEIGHT - 1 || j == 0 || j == WIDTH - 1)
            {
                printf("#");
            }
            else
            {
                if (i == X && j == Y)
                {
                    printf("O");
                }
                else if (i == FRUITX && j == FRUITX)
                {
                    printf("F");
                }
                else
                {
                    int ch = 0;
                    for (int k = 0; k < Counttail; k++)
                    {
                        if (i == tailX[k] && j == tailY[k])
                        {
                            printf("o");
                            ch = 1;
                        }
                    }
                    if (ch == 0)
                    {
                        printf(" ");
                    }
                }
            }
        }
        printf("\n");
    }
}
void setup()
{

    X = HEIGHT / 2;
    Y = WIDTH / 2;

label1:
    FRUITX = rand() % 20;
    if (FRUITX == 0)
    {
        goto label1;
    }

label2:
    FRUITY = rand() % 20;
    if (FRUITY == 0)
    {
        goto label2;
    }
}
void input()
{

    if (kbhit)
    {

        switch (getch())
        {
        case 'a':
            flag = 1;
            break;
        case 's':
            flag = 2;
            break;
        case 'w':
            flag = 3;
            break;
        case 'd':
            flag = 4;
            break;
        case 'x':
            gameover = 1;
            break;
        }
    }
}
void makelogic()
{
    int i;
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X;
    int prev2Y;
    tailX[0] = X;
    tailY[0] = Y;
    for (i = 0; i < Counttail; i++)
    {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }

    switch (flag)
    {
    case 1:
        Y--;
        break;
    case 2:
        X++;
        break;
    case 3:
        X--;
        break;
    case 4:
        Y++;
        break;
    }

    if (X <= 0 || X >= HEIGHT || Y <= 0 || Y >= WIDTH)
    {
        gameover = 1;
        printf("\n\t\t\t *********************** GAME OVER **********************");
    }
    for (i = 0; i < Counttail; i++)
    {
        if (X == tailX[i] && Y == tailY[i])
        {
            gameover = 1;
            printf("\n\t\t\t *********************** GAME OVER **********************");
        }
    }

    if (X == FRUITX && Y == FRUITX)
    {
    label3:
        FRUITX = rand() % 20;
        if (FRUITX == 0)
            goto label3;
    label4:
        FRUITY = rand() % 20;
        if (FRUITY == 0)
            goto label4;
        score += 10;
        Counttail++;
    }
}