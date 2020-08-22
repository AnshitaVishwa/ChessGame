#include<bits/stdc++.h>
#include <SFML/Graphics.hpp>
// Including the header file for the class
#include"class.h"
using namespace std;

int main()
{
    sf::RenderWindow window(sf::VideoMode(600, 600), "Chess Game");

        Chess C;
        sf :: RectangleShape rectangle[8][8];
        sf::Texture texture;
        texture.loadFromFile("image1.jpg");
        sf::Sprite sprite;
        sprite.setTexture(texture);
        int firstClick = 1;

        while (window.isOpen())
        {
            int ux, uy, vx, vy, Ux, Uy, Vx, Vy;
            char* board = C.getBoard();

            sf::Event event;
            while (window.pollEvent(event))
            {
                switch (event.type)
                {
                    case sf :: Event :: EventType :: Closed :
                        window.close();
                        break;
                }
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                    {
                        sf :: Vector2i position = sf::Mouse::getPosition(window);
                        if (firstClick % 2 == 1) {
                            ux = position.x, uy = position.y;
                            ++firstClick;
                        } else {
                            vx =  position.x, vy = position.y;
                            ++firstClick;
                        }
                        // cout << ux << " " << uy << " " << vx << " " << vy << " " << firstClick << endl;
                    }
            }
            window.clear();
            int x = 0, y = 0;
            for (int i = 0; i < 8; ++i) {
                x = 0;
                for (int j = 0; j < 8; ++j) {
                    rectangle[i][j].setSize(sf::Vector2f(75, 75));
                    rectangle[i][j].setOutlineColor(sf::Color::Blue);
                    rectangle[i][j].setOutlineThickness(2);
                    rectangle[i][j].setPosition(x, y);
                    if (i % 2 == 0 and j % 2 == 0) rectangle[i][j].setFillColor(sf::Color::Blue);
                    if (i % 2 == 1 and j % 2 == 1) rectangle[i][j].setFillColor(sf::Color::Blue);
                    if (i % 2 == 0 and j % 2 == 1) rectangle[i][j].setFillColor(sf::Color::White);
                    if (i % 2 == 1 and j % 2 == 0) rectangle[i][j].setFillColor(sf::Color::White);
                    window.draw(rectangle[i][j]);
                    x += 75;
                }
                y += 75;
            }
            x = 0, y = 0;
            for (int i = 0; i < 8; ++i) {
                x = 0;
                for (int j = 0; j < 8; ++j) {
                    sprite.setPosition(x, y);
                    if (board[i*8 + j] == 'P') {
                        sprite.setTextureRect(sf::IntRect(0, 450, 75, 75));
                        if (i % 2 == 0 and j % 2 == 0) sprite.setColor(sf::Color::Blue);
                        if (i % 2 == 1 and j % 2 == 1) sprite.setColor(sf::Color::Blue);
                        if (i % 2 == 0 and j % 2 == 1) sprite.setColor(sf::Color::White);
                        if (i % 2 == 1 and j % 2 == 0) sprite.setColor(sf::Color::White);
                        window.draw(sprite);
                    } else if (board[i*8 + j] == 'p') {
                        sprite.setTextureRect(sf::IntRect(75, 75, 75, 75));
                        if (i % 2 == 0 and j % 2 == 0) sprite.setColor(sf::Color::Blue);
                        if (i % 2 == 1 and j % 2 == 1) sprite.setColor(sf::Color::Blue);
                        if (i % 2 == 0 and j % 2 == 1) sprite.setColor(sf::Color::White);
                        if (i % 2 == 1 and j % 2 == 0) sprite.setColor(sf::Color::White);
                        window.draw(sprite);
                    } else if (board[i*8 + j] == 'K') {
                        sprite.setTextureRect(sf::IntRect(225, 525, 75, 75));
                        if (i % 2 == 0 and j % 2 == 0) sprite.setColor(sf::Color::Blue);
                        if (i % 2 == 1 and j % 2 == 1) sprite.setColor(sf::Color::Blue);
                        if (i % 2 == 0 and j % 2 == 1) sprite.setColor(sf::Color::White);
                        if (i % 2 == 1 and j % 2 == 0) sprite.setColor(sf::Color::White);
                        window.draw(sprite);
                    } else if (board[i*8 + j] == 'k') {
                        sprite.setTextureRect(sf::IntRect(300, 0, 75, 75));
                        if (i % 2 == 0 and j % 2 == 0) sprite.setColor(sf::Color::Blue);
                        if (i % 2 == 1 and j % 2 == 1) sprite.setColor(sf::Color::Blue);
                        if (i % 2 == 0 and j % 2 == 1) sprite.setColor(sf::Color::White);
                        if (i % 2 == 1 and j % 2 == 0) sprite.setColor(sf::Color::White);
                        window.draw(sprite);
                    } else if (board[i*8 + j] == 'Q') {
                        sprite.setTextureRect(sf::IntRect(300, 525, 75, 75));
                        if (i % 2 == 0 and j % 2 == 0) sprite.setColor(sf::Color::Blue);
                        if (i % 2 == 1 and j % 2 == 1) sprite.setColor(sf::Color::Blue);
                        if (i % 2 == 0 and j % 2 == 1) sprite.setColor(sf::Color::White);
                        if (i % 2 == 1 and j % 2 == 0) sprite.setColor(sf::Color::White);
                        window.draw(sprite);
                    } else if (board[i*8 + j] == 'q') {
                        sprite.setTextureRect(sf::IntRect(225, 0, 75, 75));
                        if (i % 2 == 0 and j % 2 == 0) sprite.setColor(sf::Color::Blue);
                        if (i % 2 == 1 and j % 2 == 1) sprite.setColor(sf::Color::Blue);
                        if (i % 2 == 0 and j % 2 == 1) sprite.setColor(sf::Color::White);
                        if (i % 2 == 1 and j % 2 == 0) sprite.setColor(sf::Color::White);
                        window.draw(sprite);
                    } else if (board[i*8 + j] == 'N') {
                        sprite.setTextureRect(sf::IntRect(75, 525, 75, 75));
                        if (i % 2 == 0 and j % 2 == 0) sprite.setColor(sf::Color::Blue);
                        if (i % 2 == 1 and j % 2 == 1) sprite.setColor(sf::Color::Blue);
                        if (i % 2 == 0 and j % 2 == 1) sprite.setColor(sf::Color::White);
                        if (i % 2 == 1 and j % 2 == 0) sprite.setColor(sf::Color::White);
                        window.draw(sprite);
                    } else if (board[i*8 + j] == 'n') {
                        sprite.setTextureRect(sf::IntRect(450, 0, 75, 75));
                        if (i % 2 == 0 and j % 2 == 0) sprite.setColor(sf::Color::Blue);
                        if (i % 2 == 1 and j % 2 == 1) sprite.setColor(sf::Color::Blue);
                        if (i % 2 == 0 and j % 2 == 1) sprite.setColor(sf::Color::White);
                        if (i % 2 == 1 and j % 2 == 0) sprite.setColor(sf::Color::White);
                        window.draw(sprite);
                    } else if (board[i*8 + j] == 'B') {
                        sprite.setTextureRect(sf::IntRect(375, 525, 75, 75));
                        if (i % 2 == 0 and j % 2 == 0) sprite.setColor(sf::Color::Blue);
                        if (i % 2 == 1 and j % 2 == 1) sprite.setColor(sf::Color::Blue);
                        if (i % 2 == 0 and j % 2 == 1) sprite.setColor(sf::Color::White);
                        if (i % 2 == 1 and j % 2 == 0) sprite.setColor(sf::Color::White);
                        window.draw(sprite);
                    } else if (board[i*8 + j] == 'b') {
                        sprite.setTextureRect(sf::IntRect(150, 0, 75, 75));
                        if (i % 2 == 0 and j % 2 == 0) sprite.setColor(sf::Color::Blue);
                        if (i % 2 == 1 and j % 2 == 1) sprite.setColor(sf::Color::Blue);
                        if (i % 2 == 0 and j % 2 == 1) sprite.setColor(sf::Color::White);
                        if (i % 2 == 1 and j % 2 == 0) sprite.setColor(sf::Color::White);
                        window.draw(sprite);
                    } else if (board[i*8 + j] == 'R') {
                        sprite.setTextureRect(sf::IntRect(525, 525, 75, 75));
                        if (i % 2 == 0 and j % 2 == 0) sprite.setColor(sf::Color::Blue);
                        if (i % 2 == 1 and j % 2 == 1) sprite.setColor(sf::Color::Blue);
                        if (i % 2 == 0 and j % 2 == 1) sprite.setColor(sf::Color::White);
                        if (i % 2 == 1 and j % 2 == 0) sprite.setColor(sf::Color::White);
                        window.draw(sprite);
                    } else if (board[i*8 + j] == 'r') {
                        sprite.setTextureRect(sf::IntRect(0, 0, 75, 75));
                        if (i % 2 == 0 and j % 2 == 0) sprite.setColor(sf::Color::Blue);
                        if (i % 2 == 1 and j % 2 == 1) sprite.setColor(sf::Color::Blue);
                        if (i % 2 == 0 and j % 2 == 1) sprite.setColor(sf::Color::White);
                        if (i % 2 == 1 and j % 2 == 0) sprite.setColor(sf::Color::White);
                        window.draw(sprite);
                    }
                    x += 75;
                }
                y += 75;
            }
            x = 0, y = 0;
            for (int i = 0; i < 8; ++i) {
                x = 0;
                for (int j = 0; j < 8; ++j) {
                    if (ux >= x and ux < x + 75 and uy >= y and uy < y + 75) {
                        Ux = i, Uy = j;
                    }
                    if (vx >= x and vx < x + 75 and vy >= y and vy < y + 75) {
                        Vx = i, Vy = j;
                    }
                    x += 75;
                }
                y += 75;
            }
            // object
            // cout << Ux << " " << Uy << " " << Vx << " " << Vy << " " << firstClick << endl;
            C.getMouseCoordinates(Ux, Uy, Vx, Vy);
            C.initializer();
            window.display();
        }
    return 0;
}