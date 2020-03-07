#include <iostream>
#include<cstring>
#include<time.h>
#include<random>

using namespace std;

char squareNum[] = "012345678";

// in the array X = 88 && O = 79 //
int squareArr[3][3] =                
{
    {0,1,2},
    {3,4,5},
    {6,7,8}
};


///////////////////////////////////////////////////// FUNCTIONS USED /////////////////////////////////////////////////////
                                                                                                                         
void square();              // draw the square //

int CheckWin();

int GameIsDraw();           

bool validity(int);         //wheter the move is valid or not

int checkForDouble(char);       // give the exact number where to do the next move if the player has 2 consecutive symbol //

int start();                //random system to chose whatewer the player or the computer starts//

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



int main()
{
    srand(time(NULL));
    int i, j, k;
    int win = 0;
    
    int player = start(),
        movePosition;

    char movePlayer = (player == 1) ? 'X' : 'O',
        movePc = (player == 1) ? 'O' : 'X';

    char move = 'X';

    do
    {
        
        //player have to decide a position//
        if(player)
        {
            do
            {
                square();
                
                cout << "Do your move: ";
                cin >> movePosition;

            }while(validity(movePosition) == false);

        }
        else
        {
            //if the player has two consecutives symbol it blocks the player victory//
            movePosition = checkForDouble(movePlayer);

            // if chackDouble does not return any positive value it does a random move always check for validity //
            while(validity(movePosition) == false)
                movePosition = rand()%8;            
        }

        // insert the move in the square and in the array //
        squareNum[movePosition] = move;
        for(i = 0; i < 3; i++)
            for( j = 0; j < 3; j++)
                if(squareArr[i][j] == movePosition)
                    squareArr[i][j] = move;

        //chehck victory//
        win = CheckWin();

        switch (win)
        {
        case 1:
            system("clear");
            square();
            cout << "\e[0;31m"  << ((player == 1) ? "Player":"Pc") <<  " won" << endl;
            break;
        case -1:
            system("clear");
            square();
            cout <<"\e[0;31m" << "Is draw" << endl;
            break;
        default:
            break;
        }

        // change turn //
        player = (player == 1) ? 0 : 1;
        move = (move == 'X') ? 'O':'X';

        

    }while(win == 0);
    
    
    
    

    return 0;

}


// draw the grid //
void square()
{
    int i , j;
    system("clear");
    

    cout << "\t Tic Tac Toe \t\t" << endl;

    cout<<"\t" << "     |     |    " << endl;
    cout<<"\t" << "  "<<squareNum[0]<<"  |  "<<squareNum[1]<<"  |  "<< squareNum[2] << endl;
    cout<<"\t" << "_____|_____|_____" << endl;
    cout<<"\t" << "     |     |    " << endl;
    cout<<"\t" << "  "<<squareNum[3]<<"  |  "<<squareNum[4]<<"  |  "<< squareNum[5] << endl;
    cout<<"\t" << "_____|_____|_____" << endl;
    cout<<"\t" << "     |     |    " << endl;
    cout<<"\t" << "  "<<squareNum[6]<<"  |  "<<squareNum[7]<<"  |  "<< squareNum[8] << endl;
    cout<<"\t" << "     |     |    " << endl;


    cout << endl;

    for(i = 0; i < 3; i++)
        {
            for(j = 0; j < 3; j++)
                cout << squareArr[i][j];
            cout << endl;
        }
    

}

// decide who starts randomly //
int start()
{
    srand(time(NULL));

    return rand()%2;
}

// check the validity of the pos chosen //
bool validity(int position)
{
    bool valid = true;

    if(position < 0 || position > 8)
        valid = false;
    else if(squareNum[position] > '8')
        valid = false;

    return valid;
}


// check for victory //
int CheckWin()
{
    int i, j, k, q;
    int win = 0;

    int CountVertical,
        CountOrizz,
        CountDiagonal,
        CountDiagonalDownUp;

    for(i = 0; i < 3; i++)
    {
            CountDiagonal = 0;
            CountDiagonalDownUp = 0;

        for(j = 0; j < 3; j++)
        {
            // orizzontal check //
            CountOrizz = 0;
            for(k = 0; k < 3; k++)
                if(squareArr[i][j] == squareArr[i][k])
                    CountOrizz++;
            
            if(CountOrizz == 3)
                win = 1;

            // vertical check //
            CountVertical = 0;
            for(k = 0; k < 3; k++)
                if(squareArr[j][i]  == squareArr[k][i])
                    CountVertical++;

            if(CountVertical == 3)
                win = 1;

            // diagonal Check //
            if(squareArr[i][i] == squareArr[j][j])
                CountDiagonal++;
            
            if(CountDiagonal == 3)
                win = 1;

            
            // diagonal Down Up check //
            for(k = 0; k < 3; k++)
            {
                CountDiagonalDownUp = 0;
                
                for(q = 0; q < 3; q++)
                {   
                    if(squareArr[2-k][k] == squareArr[2-q][q])
                        {CountDiagonalDownUp++;cout << "\e[0;31m" << CountDiagonalDownUp << "\e[0m";}

                    if(CountDiagonalDownUp == 3)
                        win = 1;
                }
            }
            
            
        }
    }

    if(!win)
        win = GameIsDraw();
    
    return win;
}


// A draw return -1//
int GameIsDraw()
{
    int isDraw;
    int i, j,
        validPosition = 0;
    
    for(i = 0; i < 3; i++)
        for(j = 0; j < 3; j++)
            if(squareArr[i][i] >= 0 && squareArr[i][j] <= 8)
                validPosition++;

    isDraw = (validPosition == 0) ? -1 : 0;
    
    return isDraw;
}

// if the player has 2 consecutive symbol the functions
// return the position to block
// player victory
int checkForDouble(char PlayerSymbol)
{
    int i, j, k, counter;
    
    int movePos = -1;

    for(i = 0; i < 3; i++)
    {   
        counter = 0;

        // orizzontal //
        for(j = 0; j < 3; j++)
            if(squareArr[i][j] == PlayerSymbol)
                counter++;

        if(counter == 2)
            for(j = 0; j < 3; j++)
                if(squareArr[i][j] != PlayerSymbol)
                    movePos = squareArr[i][j];
        
        // vertical //
        counter = 0;

        for(j = 0; j < 3; j++)
            if(squareArr[j][i] == PlayerSymbol)
                counter++;

        if(counter == 2)
            for(j = 0; j < 3; j++)
                if(squareArr[j][i] != PlayerSymbol)
                    movePos = squareArr[j][i];
        
        // Diagonal Up down //
        counter = 0;

        for(j = 0; j < 3; j++)
            if(squareArr[j][j] == PlayerSymbol)
                counter++;
        
        if(counter == 2)
            for(j = 0; j < 3; j++)
                if(squareArr[j][j] != PlayerSymbol)
                    movePos = squareArr[j][j];
        
        // Diagonal Down Up //
        counter = 0;

        for(j = 0; j < 3; j++)
            if(squareArr[2-j][j] == PlayerSymbol)
                counter++;
        
        if(counter == 2)
            for(j = 0; j < 3; j++)
                if(squareArr[2-j][2-j] != PlayerSymbol)
                    movePos = squareArr[2-j][j];

    }

    return movePos;
}
