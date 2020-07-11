#include<SFML/Graphics.hpp>
#include<unistd.h>
#include"tris.hpp"
#include"graphics.hpp"

int numGRID[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};

inline void drawLine(sf::RectangleShape* lines, sf::RenderWindow* window) {for(int i = 0 ; i < 3; i++) window->draw(lines[i]);}
inline void drawNumbers(sf::Text text[3][3], sf::RenderWindow* window){for(int i = 0 ; i < 3; i++) for(int j = 0 ; j < 3; j++) window->draw(text[i][j]);}

/* Imposta la grandezza e la dimensione
    delle linee verticali */
void VlinesSet(sf::RectangleShape* lines)
{
    int x = WIDTH/3;

    for(int i = 0; i < 3; i++)
    {
        lines[i].setSize(sf::Vector2f(5, HEIGHT));
        lines[i].setPosition(sf::Vector2f(x, 0));
        lines[i].setFillColor(sf::Color::Black);
        x+=WIDTH/3;
    }
}

/* Imposta la grandezza e la dimensione
    delle linee orizzontali */
void OlinesSet(sf::RectangleShape* lines)
{
    int y = HEIGHT/3;

    for(int i = 0; i < 3; i++)
    {
        lines[i].setSize(sf::Vector2f(WIDTH, 5));
        lines[i].setPosition(sf::Vector2f(0, y));
        lines[i].setFillColor(sf::Color::Black);
        y+=HEIGHT/3;
    }
}

/* Genera i numeri da inserire nell caselle */
void TextNumbers(sf::Text text[3][3], sf::Font* font)
{
    int startX = (WIDTH/3)/2,
        startY = (HEIGHT/3)/2,
        x = startX,
        y = startY;
    char number = '1';

    font->loadFromFile("CHICKEN Pie Height.ttf");
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            text[i][j].setFont(*font);
            text[i][j].setString(number);
            text[i][j].setPosition(sf::Vector2f(x, y));
            text[i][j].setFillColor(sf::Color::Red);
            text[i][j].setCharacterSize(30);
            x+=(WIDTH/3);
            number++;
        }
        y+=(HEIGHT/3);
        x=startX;
    }
    /* text[0].setFont(*font);
    text[0].setString("ANSIA NO");
    text[0].setPosition(sf::Vector2f(200, 200));
    text[0].setFillColor(sf::Color::Red);
    text[0].setCharacterSize(20); */

}

/* Gestione della finestra */
int generateWindows()
{
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Window");
    sf::RectangleShape  background(sf::Vector2f(WIDTH, HEIGHT));
    sf::Font font;
    sf::Text text[3][3];
    int i, j;
    int move;
    char player = 'X';

    
    background.setFillColor(sf::Color::White);
    
    sf::RectangleShape Vlines[3];
    sf::RectangleShape Olines[3];

    VlinesSet(Vlines);
    OlinesSet(Olines);
    TextNumbers(text, &font);
    

    while (window.isOpen())
    {
        sf::Event closedEvent;
        

        while(window.pollEvent(closedEvent))
            if(closedEvent.type == sf::Event::Closed)
                window.close();
            
        move = keypress();
        if(move)
        {    getMovePos(move, &i, &j);
        
            if(numGRID[i][j] == 0)
                {    text[i][j].setString(player); player = (player=='X') ? 'O':'X'; numGRID[i][j] = player;}
            move = 0;
        }

        window.clear();
        window.draw(background);
        drawLine(Vlines, &window);
        drawLine(Olines, &window);
        drawNumbers(text, &window);
        window.display();
        if(win(numGRID))
        {
            player = (player=='X') ? 'O':'X';
            endGame(&window, player, text);
        }
        
    }
    
    return 0;
}

int keypress()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
        return 1;
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
        return 2;
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num3))
        return 3;
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num4))
        return 4;
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num5))
        return 5;
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num6))
        return 6;
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num7))
        return 7;
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num8))
        return 8;
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num9))
        return 9;
    else return 0;
}

void endGame(sf::RenderWindow* window, char player, sf::Text grid[3][3])
{
    sf::Event closedEvent;
    sf::Text text, text1;
    sf::Font font;
    sf::RectangleShape background(sf::Vector2f(WIDTH, HEIGHT));

    
    background.setFillColor(sf::Color::Black);
    font.loadFromFile("CHICKEN Pie Height.ttf");
    text.setString("HAI VINTO");
    text.setFont(font);
    text.setPosition(sf::Vector2f(WIDTH/2 - 50, HEIGHT/2-90));
    text1.setString(player);
    text1.setFont(font);
    text1.setPosition(sf::Vector2f(WIDTH/2, HEIGHT/2 - 125));
    text.setFillColor(sf::Color::Blue);
    text1.setFillColor(sf::Color::Blue);


   
        window->clear();
        window->draw(background);
        drawNumbers(grid, window);
        window->draw(text);
        window->draw(text1);
        window->display();

     while(window->isOpen())
    {
        while(window->pollEvent(closedEvent))
            if(closedEvent.type == sf::Event::Closed)
                window->close();
    }

}

