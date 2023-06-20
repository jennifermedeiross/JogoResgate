#ifndef TECLADO_HPP
#define TECLADO_HPP

#include <iostream>

#ifdef _WIN32
    #include <conio.h>

#elif __linux__
    #include <unistd.h>
    #include <termios.h>
    
#endif

class Teclado
{
    public:
        char getChar(){
            char ch;
            #ifdef _WIN32
                ch = _getch();
            #elif __linux__
                ch = getch();
            #endif
            
            return ch;
        }

        char getch(){
            char buf = 0;
            #ifdef __linux__
                    struct termios old = {0};

                    if (tcgetattr(0, &old) < 0)
                        perror("tcsetattr()");

                    old.c_lflag &= ~ICANON;
                    old.c_lflag &= ~ECHO;
                    old.c_cc[VMIN] = 1;
                    old.c_cc[VTIME] = 0;

                    if (tcsetattr(0, TCSANOW, &old) < 0)
                        perror("tcsetattr ICANON");

                    if (read(0, &buf, 1) < 0)
                        perror("read()");

                    old.c_lflag |= ICANON;
                    old.c_lflag |= ECHO;

                    if (tcsetattr(0, TCSADRAIN, &old) < 0)
                        perror("tcsetattr ~ICANON");
            #endif
            
            return buf;
        }
};

#endif