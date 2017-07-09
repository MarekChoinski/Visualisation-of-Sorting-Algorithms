#include <SFML/Graphics.hpp>
#include "SortingAlgorithm.h"

#include "BubbleSort.h"
#include "CocktailSort.hpp"
#include "CombSort.h"

#define _CHOOSE 3
#define _DELAY 5



int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "Sorting Visualisation", sf::Style::Close);
    window.setActive(false);

    BubbleSort bubbleAlg(window, _DELAY);
    CocktailSort cocktailAlg(window, _DELAY);
    CombSort combAlg(window, _DELAY);

    switch(_CHOOSE)
    {
        case 1:
            bubbleAlg.start();
        break;

        case 2:
            cocktailAlg.start();
        break;

        case 3:
            combAlg.start();
        break;
    }



    return 0;
}
