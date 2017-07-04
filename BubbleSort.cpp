#include "BubbleSort.h"

BubbleSort::BubbleSort(sf::RenderWindow& win) : SortingAlgorithm::SortingAlgorithm(win)
{
    start();
}

void BubbleSort::sorting()//sf::RenderWindow& window
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
