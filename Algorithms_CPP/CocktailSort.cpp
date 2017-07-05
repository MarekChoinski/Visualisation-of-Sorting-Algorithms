#include "CocktailSort.hpp"

CocktailSort::CocktailSort(sf::RenderWindow& win, int i_sort_delay) : SortingAlgorithm::SortingAlgorithm(win, i_sort_delay)
{
}

void CocktailSort::sorting()
{
    bool notSorted = true;
	while( notSorted )
	{
	    notSorted = false;
            for( int a = 0; a < m_amount - 1; a++ )
            {
                if( number[a] < number[a + 1] )
                {
                    std::swap( number[a], number[a + 1] );
                    notSorted = true;
                }
            }

	    if( !notSorted ) break;

	    notSorted = false;

            for( int a = m_amount - 1; a > 0; a-- )
            {
                if( number[a - 1] < number[a] )
                {
                    std::swap( number[a], number[a - 1] );
                    notSorted = true;
                }
            }
	    sf::sleep(sf::milliseconds(m_sort_delay));
	}
	sorted();

}
