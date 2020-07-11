#include"tris.hpp"

void getMovePos(int num, int *i, int *j)
{
    int raw = 0, col = 0;

    for(int i = num; i > 1; i--)
    {
        if(col <= 2)
            col++;
        else
        {raw++; col = 1;}
    }
    *i = raw;
    *j = col;
}

int win(int arr[3][3])
{
    int player1 = 'X';
    int player2 = 'O';
    int victory1 = (verticale(arr, player1) || orizzontale(arr, player1) || diagonal(arr, player1));
    int victory2 = (verticale(arr, player2) || orizzontale(arr, player2) || diagonal(arr, player2));

    return victory1 ? victory1 : victory2;
}

int verticale(int arr[3][3], char player)
{
    for(int i = 0; i < 3; i++)
    {
        int con = 0;
        for(int j = 0; j < 3; j++)
            if(arr[j][i] == player)
                con++;
        if(con == 3)
            return player;
    }
    return 0;
}
int orizzontale(int arr[3][3], char player)
{
    for(int i = 0; i < 3; i++)
    {
        int con = 0;
        for(int j = 0; j < 3; j++)
            if(arr[i][j] == player)
                con++;
        if(con == 3)
            return player;
    }
    return 0;
}
int diagonal(int arr[3][3], char player)
{
    if(arr[0][0] == player && arr[1][1] == player && arr[2][2] == player)
        return player;
    else if(arr[2][0] == player && arr[1][1] == player && arr[0][2] == player)
        return player;
    else 
        return 0;
}