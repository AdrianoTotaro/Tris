#include<SFML/Graphics.hpp>
const int  WIDTH = 800;
const int  HEIGHT = 600;

int generateWindows();
void VlinesSet(sf::RectangleShape *);
void OlinesSet(sf::RectangleShape*);
void TextNumbers(sf::Text**, sf::Font*);
inline void drawLinesO(sf::RectangleShape* , sf::RenderWindow*);
inline void drawNumbers(sf::Text**, sf::RenderWindow*);
void endGame(sf::RenderWindow*, char, sf::Text grid[3][3]);
int keypress();