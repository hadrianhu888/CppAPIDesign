/**
 * @file fireworks.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-09-25
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <math.h>

#ifndef fireworks_hpp
#define fireworks_hpp

class Firework {
    public:
        void setOrigin(double x, double y);
        void setColor(int r, int g, int b);
        void setGravity(double g);
        void setSpeed(double s);
        void setNumberOfParticles(int n);
        void Start();
        void Stop();
        void nextFrame(float dt);

    private:
    
};

#endif // fireworks_hpp