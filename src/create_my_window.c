/*
** EPITECH PROJECT, 2018
** task01
** File description:
** task01
*/

#include "../include/hunter.h"

sfRenderWindow *createMyWindow(unsigned int width, unsigned int height)
{
    sfRenderWindow *window;
    sfVideoMode video_mode;

    video_mode.width = width;
    video_mode.height = height;
    video_mode.bitsPerPixel = 32;
    window = sfRenderWindow_create(video_mode, "My hunter",
            sfDefaultStyle, NULL);
    return (window);
}