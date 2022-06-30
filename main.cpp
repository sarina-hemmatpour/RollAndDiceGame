 #include <iostream>
#include <conio.h>
#include <time.h>
#include <string>
#include <stdlib.h>

using namespace std;
int board[10][10];

void fillBoard();
void printBoard();
void startGameBoard();
void drawLine(int , char);
void gameScore(int , int);
void playGame(int &);


int main() {

    srand((unsigned)time('\0'));

    int position1 = 0, position2 = 0;

    system("cls");

    fillBoard();
    startGameBoard();
    cout<<"\nPress any key to start playing: \n";
    getch();


    while (position1 < 100 && position2 < 100)
    {
        gameScore(position1, position2);
        drawLine(50, '-');

        cout << "\n Well, Player 1 now it's your turn... Press any key to play:\n ";
        getch();

        playGame(position1);

        if(position1 == position2)
        {
            position2=0;
        }

        cout << "\n Well, Player 2 now it's your turn... Press any key to play:\n ";
        getch();

        playGame(position2);

        if(position2 == position1)
        {
            position1=0;
        }

    }
    system("cls");
    cout << "\n\n";
    drawLine(50, '*');
    cout << "\n\n";

    gameScore(position1, position2);

    if (position1 >= 100)
        cout << "\n Player 1 won the game!!!! \n";
    else
        cout << "\n Player 2 won the game!!! \n";

    drawLine(50, '*');
    getch();
    return 0;
}

//filling the game board with numbers
void fillBoard()
{
    for(int i=0 ; i<10 ; i++ )
    {
        board[0][i]=100-i;
    }
    for (int i=0 ; i<10 ; i++)
    {
        board[1][i]=81+i;
    }
    for(int i=0 ; i<10 ; i++ )
    {
        board[2][i]=80-i;
    }
    for (int i=0 ; i<10 ; i++)
    {
        board[3][i]=61+i;
    }
    for(int i=0 ; i<10 ; i++ )
    {
        board[4][i]=60-i;
    }
    for (int i=0 ; i<10 ; i++)
    {
        board[5][i]=41+i;
    }
    for(int i=0 ; i<10 ; i++ )
    {
        board[6][i]=40-i;
    }
    for (int i=0 ; i<10 ; i++)
    {
        board[7][i]=21+i;
    }
    for(int i=0 ; i<10 ; i++ )
    {
        board[8][i]=20-i;
    }
    for (int i=0 ; i<10 ; i++)
    {
        board[9][i]=1+i;
    }
}

void printBoard()
{
    for(int i=0 ; i<10 ; i++ )
    {
        cout<<"    ";
        for(int j=0 ; j<10 ; j++ )
        {
            cout<<board[i][j]<<"  ";
            if (i>0 && j==0)
            {
                cout<<" ";
            }
            if (i==9)
            {
                cout<<" ";
            }
        }
        cout<<endl;
    }
}

//this function is for when the program runs
void startGameBoard()
{
    cout<<"\n\t <<<<<<<<<<SNAKE LADDER GAME>>>>>>>>>>\n";
    cout<<"-------------------------------------------------\n"
          "-------------------------------------------------\n";
    cout<<"    _____________\n";
    printBoard();
    cout<<"    _____________\n\n";

    cout<<"\n| Snake at Position \t|\t"<<"Ladder at Position |\n";
    cout<<"________________\n";
    cout<<  "| From 35 to 2  \t\t|\t"<<"From 1  to 21      |\n";
    cout<<  "| From 71 to 13 \t\t|\t"<<"From 8  to 27      |\n";
    cout<<  "| From 82 to 28 \t\t|\t"<<"From 10 to 49      |\n";
    cout<<  "| From 90 to 16 \t\t|\t"<<"From 17 to 55      |\n";
    cout<<  "| From 98 to 28 \t\t|\t"<<"From 20 to 93      |\n";
    cout<<  "|       -       \t\t|\t"<<"From 32 to 89      |\n";
    cout<<  "|       -       \t\t|\t"<<"From 37 to 76      |\n";
    cout<<  "|       -       \t\t|\t"<<"From 45 to 87      |\n";

}

//this function is for draw line by character
void drawLine(int number , char ch){
    for(int i=0 ; i<number ; i++)
        cout<<ch;
}

//this function is for show the location of players
void gameScore(int pos1 , int pos2){
    cout<<"\n\n";
    drawLine(50 ,'*');
    cout<<"\n Game Status :\n\n";
    drawLine(50 , '-');
    cout<<"\n player 1 is at position :" <<pos1;
    cout<<"\n player 2 is at position :" <<pos2;

    cout<<endl;
}

// this function is for start game and continue
void playGame(int & score){
    bool point=true;
    if (score == 0){
        while (point) {
            int dice;
            dice = (rand() % 6) + 1;
            cout<<"+You got "<<dice<<" point(s)\n";
            if (dice == 6) {

                dice = (rand() % 6) + 1;
                cout<<"+You got "<<dice<<" point\n";
                score += dice;
                point=false;
            }
            else {
                cout << "\nOops!!!I am sorry , you will get 6! \n";
                break;
            }
        }
    }
    if(score >=6)
    {
        int dice;
        dice=(rand()%6)+1;

        cout<<"+You got "<<dice<<" point\n";

        score += dice;

        if(dice == 6)
        {
            dice=(rand()%6)+1;
            cout<<"+You got "<<dice<<" point\n";
            score += dice;
        }
    }

    switch (score){
        case 1:
            score=21;
            break;
        case 8:
            score=27;
            break;
        case 10:
            score=49;
            break;
        case 17:
            score=55;
            break;
        case 20:
            score=93;
            break;
        case 32:
            score=89;
            break;
        case 37:
            score=76;
            break;
        case 45:
            score=87;
            break;
        case 35:
            score=2;
            break;
        case 71:
            score=13;
            break;
        case 82:
            score=28;
            break;
        case 90:
            score=16;
            break;
        case 98:
            score=28;
            break;
    }
}
