#include"classes.hpp"
#include<iostream>

Tris::tris::tris()
{
    cell.resize(9);
    for(char &i:cell)
        i = '0';
}

void Tris::tris::changePlayer()
{
    if(player == 'X')
        player = 'O';
    else
        player = 'X';
}

void Tris::tris::Move()
{
    int move;
    std::cout << "Player : " << player << " fai la tua mossa : " << std::endl;
    std::cin >> move;
}