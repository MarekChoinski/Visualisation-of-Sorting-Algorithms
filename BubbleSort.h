#ifndef BUBBLESORT_H
#define BUBBLESORT_H

#include "SortingAlgorithm.h"


class BubbleSort : public SortingAlgorithm
{
    public:
        explicit BubbleSort(sf::RenderWindow& win);
        virtual void sorting() override;

    private:
};

#endif // BUBBLESORT_H
