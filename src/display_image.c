/*
** EPITECH PROJECT, 2018
** MUL_my_hunter_2018
** File description:
** my_hunter
*/

#include "../include/hunter.h"

void rec_mouvement(sfIntRect *rec, int taille_sprite, int fin_sprite)
{
    rec->left = rec->left + taille_sprite;
    if (rec->left >= fin_sprite)
        rec->left = 0;
}

int main(void) {
    sfRenderWindow *window;
    sfTexture *texture;
    sfSprite *sprite;
    sfSprite *aim;
    sfTexture *text_aim;
    sfEvent event;
    sfSprite *bird;
    sfTexture *text_bird;
    sfSprite *game_over;
    sfTexture *text_game_over;
    sfSprite *exit;
    sfTexture *text_exit;
    sfFont *font;
    sfText *text;
    sfText *exitt;
    sfIntRect rect;
    sfIntRect rect2;
    sfTime time;
    float second;
    int t = 0;
    int miss = 3;
    sfClock *clock = sfClock_create();
    sfVector2i Mouse1;
    sfVector2i Mouse2;
    sfVector2i Mouse3;
    sfVector2f game3 = {0, 0};
    sfVector2f game = {1920 / 2.7, 1080 / 3.5};
    sfVector2f game2 = {830, 535};
    sfVector2f game4 = {75, 230};

    float pos_x = -110.0;
    float pos_y = rand() % (1080);
    sfVector2f vector = {pos_x, pos_y};
    sfVector2f dep = {2, 0};

    rect.top = 0;
    rect.left = 0;
    rect.width = 110;
    rect.height = 110;

    rect2.top = 0;
    rect2.left = 0;
    rect2.width = 256;
    rect2.height = 256;

    window = createMyWindow(1920, 1080);
    sfRenderWindow_setFramerateLimit(window, 500);
    texture = sfTexture_createFromFile("image/forest.png", NULL);
    sprite = sfSprite_create();
    text_aim = sfTexture_createFromFile("image/aim.png", NULL);
    aim = sfSprite_create();
    text_bird = sfTexture_createFromFile("image/Bird.png", NULL);
    bird = sfSprite_create();
    text_game_over = sfTexture_createFromFile("image/game_over.png", NULL);
    game_over = sfSprite_create();
    text_exit = sfTexture_createFromFile("image/exit.png", NULL);
    exit = sfSprite_create();
    font = sfFont_createFromFile("image/BebasNeue.otf");

    while (sfRenderWindow_isOpen(window)) {
        sfSprite_setTexture(sprite, texture, sfTrue);
        sfSprite_setTexture(aim, text_aim, sfTrue);
        sfSprite_setTexture(bird, text_bird, sfTrue);
        sfSprite_setTexture(game_over, text_game_over, sfTrue);
        sfSprite_setTexture(exit, text_exit, sfTrue);
        sfRenderWindow_drawSprite(window, aim, NULL);
        sfRenderWindow_drawSprite(window, bird, NULL);
        sfSprite_setPosition(bird, vector);

        while (miss != 0) {
            while (sfRenderWindow_pollEvent(window, &event)) {
                if (event.type == sfEvtClosed)
                    sfRenderWindow_close(window);
            }

            Mouse2 = sfMouse_getPositionRenderWindow(window);
            sfVector2f voc = {Mouse2.x - (150 / 2), Mouse2.y - (113 / 2)};
            sfSprite_setPosition(aim, voc);

            t++;
            sfVector2f vec = {pos_x, rand() % (920)};
            if (event.type == sfEvtMouseButtonPressed) {
                Mouse1 = sfMouse_getPositionRenderWindow(window);
                if (Mouse1.x > vector.x && Mouse1.x < (vector.x + rect.width) &&
                        Mouse1.y > vector.y &&
                    Mouse1.y < (vector.y + rect.height)) {
                    sfSprite_setPosition(bird, vec);
                    dep.x = dep.x + 0.1;
                }
            }

            time = sfClock_getElapsedTime(clock);
            second = time.microseconds / 10000.0;
            if (second > 1) {
                if (t % 75 == 0) {
                    rec_mouvement(&rect, 111, 333);
                }
                sfSprite_setTextureRect(bird, rect);
                sfSprite_move(bird, dep);
                vector = sfSprite_getPosition(bird);

                if (vector.x > 1920) {
                    dep.x = dep.x + 0.2;
                    pos_x = -500;
                    pos_y = rand() % (900);
                    vector.x = pos_x;
                    vector.y = pos_y;
                    sfSprite_setPosition(bird, vector);
                    miss--;
                }
                sfRenderWindow_drawSprite(window, sprite, NULL);
                sfRenderWindow_drawSprite(window, aim, NULL);
                sfRenderWindow_drawSprite(window, bird, NULL);
                sfRenderWindow_display(window);
            }
        }
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawSprite(window, sprite, NULL);
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
        }
        sfRenderWindow_setMouseCursorVisible(window, sfTrue);
        sfRenderWindow_drawSprite(window, game_over, NULL);
        sfSprite_setPosition(game_over, game);
        sfRenderWindow_drawSprite(window, exit, NULL);
        text = sfText_create();
        sfText_setString(text, "Click to retry !");
        sfText_setFont(text, font);
        sfText_setCharacterSize(text, 25);
        sfText_setPosition(text, game2);
        sfRenderWindow_drawText(window, text, NULL);
        exitt = sfText_create();
        sfText_setString(exitt, "Exit !");
        sfText_setFont(exitt, font);
        sfText_setCharacterSize(exitt, 40);
        sfText_setPosition(exitt, game4);
        sfRenderWindow_drawText(window, exitt, NULL);
        if (event.type == sfEvtMouseButtonPressed) {
            Mouse3 = sfMouse_getPositionRenderWindow(window);
            if (Mouse3.x > game3.x && Mouse3.x < (game3.x + rect2.width) &&
                    Mouse3.y > game3.y &&
                Mouse3.y < (game3.y + rect2.height))
                sfRenderWindow_close(window);
            else {
                miss = 3;
                dep.x = 0.5;
                sfRenderWindow_setMouseCursorVisible(window, sfFalse);
            }
        }
        sfRenderWindow_display(window);
    }
    sfSprite_destroy(aim);
    sfSprite_destroy(bird);
    sfTexture_destroy(text_aim);
    sfTexture_destroy(text_bird);
    sfRenderWindow_destroy(window);
    return (0);
}