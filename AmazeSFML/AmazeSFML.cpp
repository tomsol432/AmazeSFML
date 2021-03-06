
#include "pch.h"
#include <iostream>
#include <SFML\Graphics.hpp>
#include <SFML\OpenGL.hpp>
#include <SFML\Window.hpp>
#include <SFML\System.hpp>
#ifndef GL_SRGB8_ALPHA8
#define GL_SRGB8_ALPHA8 0x8C43
#endif

using namespace sf;
using namespace std;
int main()
{
	ContextSettings contextSettings;
	contextSettings.depthBits = 24;

	RenderWindow window(VideoMode(1600, 900), "OpenGL", sf::Style::Default, sf::ContextSettings(32));

	window.setFramerateLimit(60);
	window.setVerticalSyncEnabled(true);
	window.setActive(true);


	Event event;
	glViewport(0, 0, window.getSize().x, window.getSize().y);
	

	float step = 0.001f;
	
	while (true)
	{
		window.pollEvent(event);
		if (event.type == Event::Closed)
		{
			window.close();
			break;
		}

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glLoadIdentity();
		glPointSize(3.0f);
		glOrtho(-32, 32, -16, 16, -1, 1);
		glRotatef(0.001f+step, 1, 0,0);
		step++;
		glClearColor(0, 0, 0, 0);

		glBegin(GL_LINES);
		//glVertex goes here
		
		glEnd();

		window.display();



	}


}
