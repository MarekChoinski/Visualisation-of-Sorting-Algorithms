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
        //Constructor taking RenderWindow reference and sorting delay
        SortingAlgorithm(sf::RenderWindow& win, int i_sort_delay=50);
        //function starts drawing, sorting and handling window events
        void start();

    protected:
        virtual void sorting()=0;
        //pointer to main window
        sf::RenderWindow* m_window;
        //array of numbers
        std::vector < int > number;
        //amount of numbers in array
        int m_amount;
        //delay of sorting algorithm
        //less means faster sorting
        int m_sort_delay;
        //coloring sorted line to green color
        void sorted();

    private:
        //setting position of pixels depending on numbers
        void setPostionOfPixels();
        //function used in thread drawing content on window
        void drawing();



        //one-pixel vertex representing numbers
        std::vector<sf::Vertex> piksel;

        //DELAYS ARE FOR OPTIMALIZATION AND SPEED OF ANIMATION
        //delay of displaying pixels (something like FPS)
        const int m_display_delay=0;
        //delay of green animation
        const int m_already_sorted_delay=5;
        //delay of system events like closing window etc.
        const int m_event_delay=500;


};

#endif // SORTINGALGORITHM_H

//TODO
//verify if all includes are necessary
//virtual class for sorting
