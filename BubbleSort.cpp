#include "BubbleSort.h"

BubbleSort::BubbleSort(sf::RenderWindow& win, int i_sort_delay) : SortingAlgorithm::SortingAlgorithm(win, i_sort_delay)
{
}

void BubbleSort::sorting()
{
    for(int i=0;i<m_amount;i++)
    {
        for(int j=0;j<m_amount;j++)
        if(number[j]<number[j+1])
            std::swap( number[j], number[j+1] );

     sf::sleep(sf::milliseconds(m_sort_delay));

    }
    sorted();

}
