#ifndef SORTINGALGORITHM_H
#define SORTINGALGORITHM_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <algorithm>
#include <random>
#include <vector>
#include <thread>
#include <Windows.h>

class SortingAlgorithm
{
    public:
        SortingAlgorithm(sf::RenderWindow& win);
        void start();

    private:
        void setPostionOfPixels();
        void drawing();
        void sorting();
        void sorted();

        sf::RenderWindow* m_window;

        std::vector<sf::Sprite> piksel;
        std::vector < int > number;

        sf::Image im_texture;
        sf::Image im_texture_sorted;

        sf::Texture texture;

        //amount of numbers in array
        int m_amount;

        //DELAYS ARE FOR OPTIMALIZATION AND SPEED OF ANIMATION
        //delay of displaying pixels (something like FPS)
        const int m_display_delay=100;
        //delay of sorting algorithm
        //less means faster sorting
        const int m_sort_delay=50;
        //delay of green animation
        const int m_already_sorted_delay=5;
        //delay of system events like closing window etc.
        const int m_event_delay=500;


};

#endif // SORTINGALGORITHM_H
