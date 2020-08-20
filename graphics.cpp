#include<bits/stdc++.h>
#include <SFML/Graphics.hpp>
using namespace std;

void makeBoard(int board[8][8]) {
    // Initially the board is empty
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            board[i][j] = ' ';
        }
    }
    // The white pawns are made on the top denoted by 'W'
    for (int i = 0; i < 8; ++i) {
        board[1][i] = 'P';
    }
    // The Black pawns are made on the top denoted by 'B'
    for (int i = 0; i < 8; ++i) {
        board[6][i] = 'p';
    }
    // The white rook denoted by 'R'
    board[0][0] = 'R', board[0][7] = 'R';
    // the black rook denoted by 'r'
    board[7][0] = 'r', board[7][7] = 'r';
    // the white knight denoted by 'N'
    board[0][1] = 'N', board[0][6] = 'N';
    // the black knight denoted by 'n'
    board[7][1] = 'n', board[7][6] = 'n';
    // the white king denoted by 'K'
    board[0][3] = 'K';
    // the black king denoted by 'k'
    board[7][3] = 'k';
    // the white bishop denoted by 'B'
    board[0][2] = 'B', board[0][5] = 'B';
    // the black bishop denoted by 'b'
    board[7][2] = 'b', board[7][5] = 'b';
    // the white Queen denoted by 'Q'
    board[0][4] = 'Q';
    // the black Queen denoted by 'q'
    board[7][4] = 'q';
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(600, 600), "Chess Game");
        sf :: RectangleShape rectangle[8][8];
        int board[8][8];
        makeBoard(board);
        // Load the image
        sf::Texture texture;
        texture.loadFromFile("image1.jpg");
        sf::Sprite sprite;
        sprite.setTexture(texture);

        while (window.isOpen())
        {
            sf::Event event;
            while (window.pollEvent(event))
            {
                switch (event.type)
                {
                case sf :: Event :: EventType :: Closed :
                    window.close();
                    break;
                        break;
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
                    if (board[i][j] == 'P') {
                        sprite.setTextureRect(sf::IntRect(0, 450, 75, 75));
                        if (i % 2 == 0 and j % 2 == 0) sprite.setColor(sf::Color::Blue);
                        if (i % 2 == 1 and j % 2 == 1) sprite.setColor(sf::Color::Blue);
                        if (i % 2 == 0 and j % 2 == 1) sprite.setColor(sf::Color::White);
                        if (i % 2 == 1 and j % 2 == 0) sprite.setColor(sf::Color::White);
                        window.draw(sprite);
                    } else if (board[i][j] == 'p') {
                        sprite.setTextureRect(sf::IntRect(75, 75, 75, 75));
                        if (i % 2 == 0 and j % 2 == 0) sprite.setColor(sf::Color::Blue);
                        if (i % 2 == 1 and j % 2 == 1) sprite.setColor(sf::Color::Blue);
                        if (i % 2 == 0 and j % 2 == 1) sprite.setColor(sf::Color::White);
                        if (i % 2 == 1 and j % 2 == 0) sprite.setColor(sf::Color::White);
                        window.draw(sprite);
                    } else if (board[i][j] == 'K') {
                        sprite.setTextureRect(sf::IntRect(225, 525, 75, 75));
                        if (i % 2 == 0 and j % 2 == 0) sprite.setColor(sf::Color::Blue);
                        if (i % 2 == 1 and j % 2 == 1) sprite.setColor(sf::Color::Blue);
                        if (i % 2 == 0 and j % 2 == 1) sprite.setColor(sf::Color::White);
                        if (i % 2 == 1 and j % 2 == 0) sprite.setColor(sf::Color::White);
                        window.draw(sprite);
                    } else if (board[i][j] == 'k') {
                        sprite.setTextureRect(sf::IntRect(300, 0, 75, 75));
                        if (i % 2 == 0 and j % 2 == 0) sprite.setColor(sf::Color::Blue);
                        if (i % 2 == 1 and j % 2 == 1) sprite.setColor(sf::Color::Blue);
                        if (i % 2 == 0 and j % 2 == 1) sprite.setColor(sf::Color::White);
                        if (i % 2 == 1 and j % 2 == 0) sprite.setColor(sf::Color::White);
                        window.draw(sprite);
                    } else if (board[i][j] == 'Q') {
                        sprite.setTextureRect(sf::IntRect(300, 525, 75, 75));
                        if (i % 2 == 0 and j % 2 == 0) sprite.setColor(sf::Color::Blue);
                        if (i % 2 == 1 and j % 2 == 1) sprite.setColor(sf::Color::Blue);
                        if (i % 2 == 0 and j % 2 == 1) sprite.setColor(sf::Color::White);
                        if (i % 2 == 1 and j % 2 == 0) sprite.setColor(sf::Color::White);
                        window.draw(sprite);
                    } else if (board[i][j] == 'q') {
                        sprite.setTextureRect(sf::IntRect(225, 0, 75, 75));
                        if (i % 2 == 0 and j % 2 == 0) sprite.setColor(sf::Color::Blue);
                        if (i % 2 == 1 and j % 2 == 1) sprite.setColor(sf::Color::Blue);
                        if (i % 2 == 0 and j % 2 == 1) sprite.setColor(sf::Color::White);
                        if (i % 2 == 1 and j % 2 == 0) sprite.setColor(sf::Color::White);
                        window.draw(sprite);
                    } else if (board[i][j] == 'N') {
                        sprite.setTextureRect(sf::IntRect(75, 525, 75, 75));
                        if (i % 2 == 0 and j % 2 == 0) sprite.setColor(sf::Color::Blue);
                        if (i % 2 == 1 and j % 2 == 1) sprite.setColor(sf::Color::Blue);
                        if (i % 2 == 0 and j % 2 == 1) sprite.setColor(sf::Color::White);
                        if (i % 2 == 1 and j % 2 == 0) sprite.setColor(sf::Color::White);
                        window.draw(sprite);
                    } else if (board[i][j] == 'n') {
                        sprite.setTextureRect(sf::IntRect(450, 0, 75, 75));
                        if (i % 2 == 0 and j % 2 == 0) sprite.setColor(sf::Color::Blue);
                        if (i % 2 == 1 and j % 2 == 1) sprite.setColor(sf::Color::Blue);
                        if (i % 2 == 0 and j % 2 == 1) sprite.setColor(sf::Color::White);
                        if (i % 2 == 1 and j % 2 == 0) sprite.setColor(sf::Color::White);
                        window.draw(sprite);
                    } else if (board[i][j] == 'B') {
                        sprite.setTextureRect(sf::IntRect(375, 525, 75, 75));
                        if (i % 2 == 0 and j % 2 == 0) sprite.setColor(sf::Color::Blue);
                        if (i % 2 == 1 and j % 2 == 1) sprite.setColor(sf::Color::Blue);
                        if (i % 2 == 0 and j % 2 == 1) sprite.setColor(sf::Color::White);
                        if (i % 2 == 1 and j % 2 == 0) sprite.setColor(sf::Color::White);
                        window.draw(sprite);
                    } else if (board[i][j] == 'b') {
                        sprite.setTextureRect(sf::IntRect(150, 0, 75, 75));
                        if (i % 2 == 0 and j % 2 == 0) sprite.setColor(sf::Color::Blue);
                        if (i % 2 == 1 and j % 2 == 1) sprite.setColor(sf::Color::Blue);
                        if (i % 2 == 0 and j % 2 == 1) sprite.setColor(sf::Color::White);
                        if (i % 2 == 1 and j % 2 == 0) sprite.setColor(sf::Color::White);
                        window.draw(sprite);
                    } else if (board[i][j] == 'R') {
                        sprite.setTextureRect(sf::IntRect(525, 525, 75, 75));
                        if (i % 2 == 0 and j % 2 == 0) sprite.setColor(sf::Color::Blue);
                        if (i % 2 == 1 and j % 2 == 1) sprite.setColor(sf::Color::Blue);
                        if (i % 2 == 0 and j % 2 == 1) sprite.setColor(sf::Color::White);
                        if (i % 2 == 1 and j % 2 == 0) sprite.setColor(sf::Color::White);
                        window.draw(sprite);
                    } else if (board[i][j] == 'r') {
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
            window.display();
        }
    return 0;
}