#include "CombSort.h"

CombSort::CombSort(sf::RenderWindow& win, int i_sort_delay) : SortingAlgorithm::SortingAlgorithm(win, i_sort_delay, "Comb Sorting")
{
}

void CombSort::sorting()
{
    int swapped = 1;
    int i, j;

  int gap = m_amount;
  while (gap > 1 || swapped == 1)
  {
    //gap = gap * 10 / 13;
    gap = gap / 1.24733;//more efficient

    if (gap == 9 || gap == 10) gap = 11; //it is for optimalization (Combsort11)

    if (gap < 1) gap = 1;//gap is minimum 1

    swapped = 0;
    for (i = 0, j = gap; j < m_amount; i++, j++)
    {
      if (number[i] < number[j])
      {
		std::swap(number[i], number[j]);
        swapped = 1;
      }
      sf::sleep(sf::milliseconds(m_sort_delay/5));
    }

  }
  sorted();
}



