#include <iostream>
#include <SFML/Graphics.hpp>
#include "gameLogic.h"
#include <SFML/Audio.hpp>
#include <thread>

int main(){
    gameLogic chess(sf::Color::White, sf::Color::Black);

    RenderWindow window(sf::VideoMode(768,512), "Satran�", sf::Style::Titlebar | sf::Style::Close);
    window.setVerticalSyncEnabled(true);
    SoundBuffer buffer;
    SoundBuffer buffer2;
	Sound sound;
    sound.setPitch(2);
    if (!buffer.loadFromFile("sound.wav"))
	{
	   cout<<"Please Chech the Sound";
	}   

    if (!buffer2.loadFromFile("sound2.wav"))
	{
	   cout<<"Please Chech the Sound";
	}

    while(window.isOpen()){
        
        sf::Event event;

        while(window.pollEvent(event)){

            if (event.type == sf::Event::Closed){
                window.close();
}
			else if(chess.gameOver){
				chrono::seconds cooldownDuration(2);
            	this_thread::sleep_for(cooldownDuration);
                window.close();
			}
            if(event.type == sf::Event::MouseButtonPressed){
                if(event.mouseButton.button == sf::Mouse::Left){
                    if((0 <= event.mouseButton.x) && (event.mouseButton.x <= 512) && (0 <= event.mouseButton.y) && (event.mouseButton.y <= 512)){
                        unsigned int buttonPos{(event.mouseButton.x/64) + ((event.mouseButton.y/64) * 8)};
                                                
                        if(!chess.getSelected())
                            chess.selectPiece(buttonPos);
                        else
                            chess.moveSelected(buttonPos);
                            sound.setBuffer(buffer);
                            sound.play();
                    }
                    else if((517 <= event.mouseButton.x) && (event.mouseButton.x <= 763) && (5 <= event.mouseButton.y) && (event.mouseButton.y <= 45)){
                        chess.restart();
                            sound.setBuffer(buffer2);
							sound.play();
                    }
                    else if((517 <= event.mouseButton.x) && (event.mouseButton.x <= 763) && (45 <= event.mouseButton.y) && (event.mouseButton.y <= 95)){
                            sound.setBuffer(buffer2);
							sound.play();
							window.close();
                    }
                }
            }
        }
        window.draw(chess);
        window.display();
    }

    return 0;
}
