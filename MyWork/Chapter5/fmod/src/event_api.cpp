#include <iostream>
#include <conio.h>
#include <windows.h>

const float UPDATE_INTERVAL = 100.0f;

void ERRCHECK(bool condition)
{
    if (!condition)
    {
        std::cout << "Error occurred!" << std::endl;
        exit(-1);
    }
}

int main(int argc, char* argv[])
{
    float param00_val, param00_min, param00_max, param00_increment;
    int key;

    std::cout << "======================================================================\n";
    std::cout << "Effects Example.  Copyright (c) Firelight Technologies 2004-2009.\n";
    std::cout << "==============================-------=================================\n";
    std::cout << "This demonstrates the use of FMOD event effects. It simply plays an\n";
    std::cout << "event with effects applied and allows the user to adjust the parameters.\n";
    std::cout << "======================================================================\n\n";

    param00_min = 0.0f;
    param00_max = 1.0f;
    param00_val = 0.0f;
    param00_increment = (param00_max - param00_min) / UPDATE_INTERVAL;

    std::cout << "======================================================================\n";
    std::cout << "Press '<' or ',' to decrease param00\n";
    std::cout << "Press '>' or '.' to increase param00\n";
    std::cout << "Press ESC        to quit\n";
    std::cout << "======================================================================\n";

    key = 0;
    do
    {
        if (_kbhit())
        {
            key = _getch();

            if (key == '<' || key == ',')
            {
                param00_val -= param00_increment;
                if (param00_val < param00_min)
                {
                    param00_val = param00_min;
                }
            }
            else if (key == '>' || key == '.')
            {
                param00_val += param00_increment;
                if (param00_val > param00_max)
                {
                    param00_val = param00_max;
                }
            }
        }

        Sleep(15);

        std::cout << "param00 = " << param00_val << "         \r";
        std::cout.flush();

    } while (key != 27);

    return 0;
}
