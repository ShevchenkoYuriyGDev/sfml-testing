#include <SFML\Graphics.hpp>

#define W_PIX 480
#define H_PIX 600

static void MainWindowDrawing()
{ 
	sf::RenderWindow mainWindow(sf::VideoMode(H_PIX, W_PIX), "Text"); 
	sf::Event mainWindowEvent;
	sf::CircleShape circle;;

	circle.setFillColor        (sf::Color::Blue);
	circle.setOutlineColor     (sf::Color::Green);
	circle.setRadius           (50);
	circle.setPosition         (1.f, 1.f);
	circle.setOutlineThickness (2.f);
	
	while (mainWindow.isOpen())
	{
		while (mainWindow.pollEvent(mainWindowEvent));   
		{
			if (mainWindowEvent.type == sf::Event::Closed) { mainWindow.close(); }
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))    { circle.move(0, -0.05); }
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))  { circle.move(0, 0.05);  }
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))  { circle.move(-0.05, 0); }
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) { circle.move(0.05, 0);  }
		}
		mainWindow.clear   ();
		mainWindow.draw    (circle);
		mainWindow.display ();
	}
}

int main()
{
	MainWindowDrawing();
	return 0;
}