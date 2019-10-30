/*
** EPITECH PROJECT, 2018
** create_my_window.h
** File description:
** create_my_window
*/

#ifndef MY_HUNTER_H_
#define MY_HUNTER_H_

#include <stddef.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <SFML/Window/Export.h>
#include <SFML/Window/Types.h>
#include <SFML/System/Vector2.h>

void my_putchar(char c);
int my_putstr(char const *str);
sfRenderWindow *createMyWindow(unsigned int width, unsigned int height);
void rec_mouvement(sfIntRect *rec, int taille_sprite, int fin_sprite);

#endif    /* MY_HUNTER_H_ */