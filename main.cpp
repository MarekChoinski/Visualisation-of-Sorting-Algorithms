#include <SFML/Graphics.hpp>
#include "SortingAlgorithm.h"

#define _SIZE 800



int main()
{
    sf::RenderWindow window(sf::VideoMode(_SIZE,_SIZE), "Sorting Visualisation", sf::Style::Close);
    window.setActive(false);

    SortingAlgorithm alg(window);
    alg.start();

    return 0;
}
