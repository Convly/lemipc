#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <sys/types.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <string.h>
#include <stddef.h>
#include <iostream>
#include "lemipc.h"

int			get_shm(char *path)
{
    key_t			key;
    int			shm_id;

    key = ftok(path, 0);
    shm_id = shmget(key, sizeof(t_game), SHM_R | SHM_W);
    if (shm_id == -1)
    {
        std::cout << "no current map hosted here" << std::endl;
        exit(0);
    }
    return (shm_id);
}

sf::Color			ctc(int team)
{
    sf::Color		colorlu;

    srand(team);
    colorlu.a = 255;
    colorlu.r = rand() % 255;
    colorlu.g = rand() % 255;
    colorlu.b = rand() % 255;
    return (colorlu);
}

int main(int ac, char **av) {
    if (ac != 2)
        return (0);
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "interface lemIPC CPP");
    sf::RectangleShape Shape(sf::Vector2f(100.f, 100.f));
    Shape.setFillColor(sf::Color::Green);
    t_game *ctx = (t_game *)shmat(get_shm(av[1]), NULL, SHM_R | SHM_W);
    sf::Vector2f s(0, 0);
    sf::Vector2f place(0, 0);
    sf::Vector2u winsize(window.getSize());

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear(sf::Color::White);
        s.x = -1;
        while (++s.x < ctx->mapWidth)
        {
            s.y = -1;
            while (++s.y < ctx->mapHeight)
            {
                Shape.setPosition(sf::Vector2f((winsize.x / ctx->mapWidth) * s.x, (winsize.y / ctx->mapHeight) * s.y));
                Shape.setFillColor(ctc(ctx->map[(int)s.y * ctx->mapWidth + (int)s.x]));
                window.draw(Shape);
            }
        }
        window.display();
    }
}