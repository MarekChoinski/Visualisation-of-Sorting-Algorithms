#include <SFML/Graphics.hpp>
#include "SortingAlgorithm.h"
#include "BubbleSort.h"

#define _SIZE 800



int main()
{
    sf::RenderWindow window(sf::VideoMode(_SIZE,_SIZE), "Sorting Visualisation", sf::Style::Close);
    window.setActive(false);


    BubbleSort bubbleAlg(window, 5);
    bubbleAlg.start();


    return 0;
}
