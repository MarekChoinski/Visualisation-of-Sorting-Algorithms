#include "SortingAlgorithm.h"

SortingAlgorithm::SortingAlgorithm(sf::RenderWindow& win, int i_sort_delay) : m_window(&win), m_sort_delay(i_sort_delay)
{
    //resize arrays with size depending on window size
    piksel.resize(m_window->getSize().x);
    number.resize(m_window->getSize().x);

    //amount depends on window size
    m_amount = m_window->getSize().x;

    //inicialize array with ascendinh numbers
    std::iota(number.rbegin(), number.rend(), 0);
    //randomize array
    std::shuffle(number.begin(), number.end(), std::mt19937{std::random_device{}()});

    int j=0;
    for (auto& i : piksel)
    {
        i =  sf::Vertex(sf::Vector2f(j, number[j]), sf::Color::White);
        j++;
    }
}


void SortingAlgorithm::setPostionOfPixels()
{
    int j=0;
    for (auto& i : piksel)
    {
        i.position.y = number[j];//i =  sf::Vertex(sf::Vector2f(j, number[j]), sf::Color::White);
        j++;
    }
}


void SortingAlgorithm::drawing()
{

    while (m_window->isOpen()) {
            m_window->setActive(true);

            m_window->clear(sf::Color::Black);

        setPostionOfPixels();

        for(const auto p: piksel)
            m_window->draw(&p, 1, sf::Points);


            m_window->display();

    sf::sleep(sf::milliseconds(m_display_delay));

  }
}


void SortingAlgorithm::sorted()
{
    for(int i=m_amount; i>0; i--)
    {
        piksel[i].color = sf::Color::Green;
        sf::sleep(sf::milliseconds(m_already_sorted_delay));
    }
    sf::sleep(sf::milliseconds(1000));
    m_window->close();
}


void SortingAlgorithm::start()
{
    std::thread thr_d([=]{drawing();});
        thr_d.detach();

    std::thread thr_s([=]{sorting();});
        thr_s.detach();

    while (m_window->isOpen())
    {
        sf::Event event;
        while (m_window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                m_window->close();
        }

            sf::sleep(sf::milliseconds(m_event_delay));
    }
}
