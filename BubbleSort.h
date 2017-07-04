#ifndef BUBBLESORT_H
#define BUBBLESORT_H

#include "SortingAlgorithm.h"


class BubbleSort : public SortingAlgorithm
{
    public:
        BubbleSort(sf::RenderWindow& win, int i_sort_delay=50);

        virtual void sorting() override;

    private:
};

#endif // BUBBLESORT_H
