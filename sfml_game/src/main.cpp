#include <SFML/Graphics.hpp>
#include <sys/time.h>
#include <random>
using namespace std;
using namespace sf;

const unsigned int WIDTH  = 16 * 70;
const unsigned int HEIGHT = 9 * 70;
const int NUMBER_OF_ENEMIES = 7;
const int ENEMY_MOVEMENT_RANGE = 12;
float ENEMY_MOVEMENT_COOLDOWN = 0.005;

random_device rd;
mt19937 gen(rd());

RenderWindow window(VideoMode(WIDTH, HEIGHT), "SFML Game");
Clock frame_clock, enemy_clock, survival_clock;
float frame_time;

Font font;
Text score;
Texture football, rat;
Sprite player, enemy[NUMBER_OF_ENEMIES];

void init()
{
    player.setPosition(Vector2f(40, 40));

    score.setPosition(Vector2f(10, 10));
}

void load_textures()
{
    font.loadFromFile("assets/BebasNeue-Regular.ttf");
    score.setFont(font);
    score.setFillColor(Color::Black);

    football.loadFromFile("assets/football.png");
    rat.loadFromFile("assets/rat.png");

    player.setTexture(football);
    player.setScale(Vector2f(0.3f, 0.3f));

    for (int i = 0; i < NUMBER_OF_ENEMIES; i++)
    {
        enemy[i].setTexture(rat);
        enemy[i].setScale(Vector2f(0.22f, 0.22f));

        auto bounds = enemy[i].getLocalBounds();
        enemy[i].setOrigin(Vector2f(bounds.width / 2, bounds.height / 2));

        uniform_real_distribution<> x(150, WIDTH - 150);
        uniform_real_distribution<> y(100, HEIGHT - 100);
        enemy[i].setPosition(Vector2f(x(gen), y(gen)));
    }

    auto bounds = player.getLocalBounds();
    player.setOrigin(Vector2f(bounds.width / 2, bounds.height / 2));
}

void draw()
{
    window.draw(player);

    for (int i = 0; i < NUMBER_OF_ENEMIES; i++)
    {
        window.draw(enemy[i]);
    }

    int score_seconds = survival_clock.getElapsedTime().asSeconds();
    score.setString("Your score: " + to_string(score_seconds));
    window.draw(score);
}

void keyboard_handler()
{
    int moved = 0;
    float inc = 300.0f * frame_time;

    if (Keyboard::isKeyPressed(Keyboard::Up) /* && pos.y > 0 */)
    {
        player.move(Vector2f(0, -inc));
        moved = 1;
    }
    if (Keyboard::isKeyPressed(Keyboard::Down) /* && pos.y < HEIGHT */)
    {
        player.move(Vector2f(0, inc));
        moved = -1;
    }
    if (Keyboard::isKeyPressed(Keyboard::Right) /* && pos.x < WIDTH */)
    {
        player.move(Vector2f(inc, 0));
        moved = 1;
    }
    if (Keyboard::isKeyPressed(Keyboard::Left) /* && pos.x > 0 */)
    {
        player.move(Vector2f(-inc, 0));
        moved = -1;
    }

    if (moved) player.rotate(inc * moved);

    auto pos = player.getPosition();
    if (pos.x > WIDTH) player.setPosition(Vector2f(0, pos.y));
    if (pos.y > HEIGHT) player.setPosition(Vector2f(pos.x, 0));
    if (pos.x < 0) player.setPosition(Vector2f(WIDTH - 1, pos.y));
    if (pos.y < 0) player.setPosition(Vector2f(pos.x, HEIGHT - 1));

    for (int i = 0; i < NUMBER_OF_ENEMIES; i++)
    {
        if (enemy[i].getGlobalBounds().intersects(player.getGlobalBounds()))
        {
            window.close();
        }
    }
}

void move_enemies()
{
    for (int i = 0; i < NUMBER_OF_ENEMIES; i++)
    {
        uniform_int_distribution<> direction(1, 2);
        uniform_real_distribution<> position(-ENEMY_MOVEMENT_RANGE, ENEMY_MOVEMENT_RANGE);
        int rand_direction = direction(gen);

        if (rand_direction == 1) enemy[i].move(Vector2f(position(gen), 0));
        if (rand_direction == 2) enemy[i].move(Vector2f(0, position(gen)));

        auto pos = enemy[i].getPosition();
        if (pos.x > WIDTH) enemy[i].setPosition(Vector2f(pos.x - WIDTH, pos.y));
        if (pos.y > HEIGHT) enemy[i].setPosition(Vector2f(pos.x, pos.y - HEIGHT));
        if (pos.x < 0) enemy[i].setPosition(Vector2f(WIDTH, pos.y));
        if (pos.y < 0) enemy[i].setPosition(Vector2f(pos.y, HEIGHT));
    }
}

void display_loop()
{
    window.setFramerateLimit(60);
    init();
    load_textures();

    survival_clock.restart();
    enemy_clock.restart();
    frame_time = frame_clock.restart().asSeconds();
    while (window.isOpen())
    {
        Event event;
        while(window.pollEvent(event))
        {
            if (event.type == Event::Closed) window.close();
        }
        keyboard_handler();

        if (enemy_clock.getElapsedTime().asSeconds() >= ENEMY_MOVEMENT_COOLDOWN)
        {
            move_enemies();
            enemy_clock.restart();
        }

        window.clear(Color(211, 211, 211));
        draw();
        window.display();

        frame_time = frame_clock.restart().asSeconds();
    }
}

#ifndef GTEST_DECLARES_MAIN
int main()
{
    display_loop();
}
#endif