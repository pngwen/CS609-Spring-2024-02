    #include <SFML/Graphics.hpp>

    int main()
    {
        // Create a window with the size of 800x600 pixels
        sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Circle");

        // Create a circle with a radius of 100 pixels
        sf::CircleShape circle(100);
        circle.setFillColor(sf::Color::Green); // Set the circle's color
        circle.setPosition(350, 250); // Set the position of the circle

        // Main loop that continue.s until the window is closed
        while (window.isOpen())
        {
            sf::Event event;
            while (window.pollEvent(event
            {
                // "Close requested" event: we close the window
                if (event.type == sf::Event::Closed)
                    window.close();
            }

            // Clear the whole window before rendering a new frame
            window.clear();

            // Draw the circle
            window.draw(circle);

            // End the current frame and display its contents on screen
            window.display();
        }

        return 0;
    }
