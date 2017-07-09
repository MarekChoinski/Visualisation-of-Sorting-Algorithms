#ifndef COMBSORT_H
#define COMBSORT_H

#include "SortingAlgorithm.h"


class CombSort : public SortingAlgorithm
{
    public:
        CombSort(sf::RenderWindow& win, int i_sort_delay=50);

        virtual void sorting() override;

    private:
};

#endif // COMBSORT_H
