#ifndef COCKTAILSORT_HPP
#define COCKTAILSORT_HPP

#include "SortingAlgorithm.h"


class CocktailSort : public SortingAlgorithm
{
    public:
        CocktailSort(sf::RenderWindow& win, int i_sort_delay=50);

        virtual void sorting() override;

    private:
};

#endif //COCKTAILSORT_HPP
