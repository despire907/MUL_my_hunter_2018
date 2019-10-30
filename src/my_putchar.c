/*
** EPITECH PROJECT, 2018
** put_char
** File description:
** put_char
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}
