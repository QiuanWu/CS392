/**********************************************************************************************
 * Name        : myselect
 * Author      : Qiuan Wu, Tianbo Tan
 * Date        : 04/11/2018
 * References  : https://stackoverflow.com/questions/10463201/getch-and-arrow-codes
 *             : https://www.viget.com/articles/game-programming-in-c-with-the-ncurses-library/
 * Pledge      : I pledge my honor that I have abided by the Stevens Honor System.
 *********************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ncurses.h>
#include "my.h"

// System dependent key codes
#define ST '['
#define ARROW_UP 'A'
#define ARROW_DOWN 'B'
#define ARROW_RIGHT 'C'
#define ARROW_LEFT 'D'
#define KEY_ESC 27
#define KEY_SPACE ' '

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        my_str("\nUsage: ./myselect files\n\n");
        return 1;
    }
    
    int c, index, height, width, length, currow, currcol, underline, equcur;
    char **inputList = argv;
    int inputSize = argc - 1;
    int highlight[inputSize + 1];

    for (int i = 0; i <= inputSize; i++)
        highlight[i] = 0;

    /* Initialize the ncurses windows */
    initscr();
    //keypad(stdscr, TRUE);
    my_char('\n');
    noecho();
    if (raw() == -1) {
        my_str("Error opening windows");
    }
    length = 0;
    underline = 1;

    do
    {
        currow = 0;
        currcol = 0;
        clear();
        getmaxyx(stdscr, height, width);
        index = 1;
        while (index <= inputSize)
        {
            if (my_strlen(inputList[index]) > length)
                length = my_strlen(inputList[index]);
            if (index == underline)
                attron(A_UNDERLINE);
            equcur = length + currcol + 1;
            if (currow == height)
            {
                currcol = equcur;
                length = 0;
                currow = 0;
            }
            if (highlight[index] % 2 != 1)
                attroff(A_STANDOUT);
            else
                standout();

            mvprintw(currow, currcol, inputList[index]);
            if (currcol > width - my_strlen(inputList[index]))
            {
                clear();
                mvprintw(0, 0, "Please enlarge the window");
                break;
            }
            ++currow;
            attroff(A_UNDERLINE);   
            ++index;       
        }

        if ((c = getch()) == '\n')
            break;
        
        /* Listen to key input: Space, ESC, up, down, right, left */
        switch (c)
        {
        case KEY_SPACE:
            ++highlight[underline];
            if (highlight[underline] % 2 == 1)
            {
                if (underline == inputSize)
                    underline = 1;
                else
                    ++underline;
            }
            break;

        case KEY_ESC:
            timeout(10);
            switch (c = getch())
            {
            case -1:
                endwin();
                return 0;
                break;

            case ST:
                switch (c = getch())
                {
                case ARROW_UP:
                    if (underline == 1)
                        underline = inputSize;
                    else
                        --underline;
                    break;

                case ARROW_DOWN:
                    if (underline == inputSize)
                        underline = 1;
                    else
                        ++underline;
                    break;

                case ARROW_RIGHT:
                    if (underline + height > argc)
                        underline = inputSize;
                    else
                        underline += height;
                    break;

                case ARROW_LEFT:
                    if (underline < height + 1)
                        underline = 1;
                    else
                        underline -= height;
                    break;

                default:
                    refresh();
                    break;
                }
            }
        }
    } while (1);

    /* Close the windows and print out the selected files on the terminal */
    refresh();
    endwin();
    for (int j = 0; j <= inputSize; j++)
    {
        if (highlight[j] % 2 == 1)
        {
            my_str(inputList[j]);
            my_char(' ');
        }
        else 
            continue;
    }
    my_char('\n');
    my_char('\n');   
    return 0;

}
