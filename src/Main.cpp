#include <SFML/Graphics.hpp>
#include <vector>
#include <ctime>
#include <iostream>

void drawGraphLine(sf::RenderWindow& _window, int _pos, int _height);
void iterateSortingAlgorithm(int i);

const int SCREEN_W = 640;
const int SCREEN_H = 480;

std::vector<int> vector(SCREEN_W/4);

int iteration = 0;

int main()
{
    sf::RenderWindow window(sf::VideoMode(SCREEN_W, SCREEN_H), "Sorting Algorithm Visualizer | by @PieceOfSoil");

    //Generate random int vector for visualizing
    std::srand(unsigned(std::time(nullptr)));
    std::generate(vector.begin(), vector.end(), std::rand);

    for (int i = 0; i < vector.size(); i++) {
        vector[i] = vector[i] / SCREEN_H * 3;
        std::cout << vector[i] << '\n';
    }

    //Main loop
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        
        for (int i = 0; i < vector.size(); i++) {
            drawGraphLine(window, i, vector[i]);
        }

        window.display();

        iterateSortingAlgorithm(iteration);
        iteration++;
        if (iteration == vector.size() - 1) iteration = 0;
    }

    return 0;
}

void drawGraphLine(sf::RenderWindow& _window, int _pos, int _height) {
    sf::RectangleShape line(sf::Vector2f(4, _height));
    line.setOrigin(sf::Vector2f(0, _height));
    line.setPosition(_pos * 4, SCREEN_H);
    if (iteration == _pos) line.setFillColor(sf::Color::Red);

    _window.draw(line);
}

void iterateSortingAlgorithm(int i) { //Your sorting algorithm here
    int buf = 0;
    if (vector[i] > vector[i + 1]) {
        buf = vector[i];
        vector[i] = vector[i + 1];
        vector[i + 1] = buf;
    }
}