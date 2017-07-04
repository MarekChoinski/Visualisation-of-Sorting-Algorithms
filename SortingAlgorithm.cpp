#include "SortingAlgorithm.h"

SortingAlgorithm::SortingAlgorithm(sf::RenderWindow& win) : m_window(&win)
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

    //make image used later as a texture
    im_texture.create(1,1,sf::Color::White);
    im_texture_sorted.create(1,1,sf::Color::Green);

    //make texture (1x1 white pixel)
    texture.loadFromImage(im_texture);

    //set texture to pixels (1x1 white pixel)
    //pixels are sprites
    for (auto& i : piksel)
    i.setTexture(texture);
}

//set position of pixels depending of numbers
void SortingAlgorithm::setPostionOfPixels()
{
    int j=0;
    for (auto& i : piksel)
    {
        i.setPosition(j, number[j]);
        j++;
    }
}


void SortingAlgorithm::drawing()//sf::RenderWindow& window
{

    while (m_window->isOpen()) {

            m_window->setActive(true);
            m_window->clear(sf::Color::Black);

                setPostionOfPixels();

                for (auto& i : piksel)
                    m_window->draw(i);




            m_window->display();





    sf::sleep(sf::milliseconds(m_display_delay));

  }
}



void SortingAlgorithm::sorted()
{
    for(int i=m_amount; i>0; i--)
    {
        piksel[i].setColor(sf::Color::Green);
        sf::sleep(sf::milliseconds(m_already_sorted_delay));
    }
}


void SortingAlgorithm::start()
{
    std::thread thr_d([=]{drawing();});//, &window
        thr_d.detach();

    std::thread thr_s([=]{sorting();});//, &window
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

