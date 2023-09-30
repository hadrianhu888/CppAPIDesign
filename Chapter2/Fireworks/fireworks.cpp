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
#include <cstdlib>

/*#include "fireparticle.hpp"
#include "fireworks.hpp"*/ 

class FireParticle {
public:
    double mX, mY;
    double mVelocityX, mVelocityY;
    double AccelerationX, AccelerationY;
    int mRed, mGreen, mBlue;
};

class Firework {
public:
    Firework();

    void setOrigin(double x, double y);
    void setColor(int r, int g, int b);
    void setGravity(double g);
    void setSpeed(double s);
    void setNumberOfParticles(int n);
    void Start();
    void Stop();
    void nextFrame(float dt);

    std::vector<FireParticle *> mParticles;

private:
    double mOriX, mOriY;
    int mRed, mGreen, mBlue;
    double mGravity;
    double mSpeed;
    bool mIsActive;
};

Firework::Firework() : mOriX(0), mOriY(0), mRed(0), mGreen(0), mBlue(0), mGravity(9.81), mSpeed(1.0), mIsActive(false) {}

void Firework::setOrigin(double x, double y) {
    mOriX = x;
    mOriY = y;
}

void Firework::setColor(int r, int g, int b) {
    mRed = r;
    mGreen = g;
    mBlue = b;
}

void Firework::setGravity(double g) { mGravity = g; }

void Firework::setSpeed(double s) { mSpeed = s; }

void Firework::setNumberOfParticles(int n) {
    mParticles.resize(n);
    for (int i = 0; i < n; ++i) {
        FireParticle *particle = new FireParticle();
        particle->mX = mOriX;
        particle->mY = mOriY;
        particle->mVelocityX = (rand() % 100 - 50) / 10.0;
        particle->mVelocityY = (rand() % 100 - 50) / 10.0;
        particle->mRed = mRed;
        particle->mGreen = mGreen;
        particle->mBlue = mBlue;
        mParticles[i] = particle;
    }
}

void Firework::Start() { mIsActive = true; }

void Firework::Stop() { mIsActive = false; }

void Firework::nextFrame(float dt) {
    if (mIsActive) {
        for (FireParticle *particle : mParticles) {
            particle->AccelerationX = 0;  // Changed from -mGravity
            particle->AccelerationY = -mGravity;  // Changed from += mGravity
            particle->mVelocityX += particle->AccelerationX * dt;
            particle->mVelocityY += particle->AccelerationY * dt;
            particle->mX += particle->mVelocityX * dt;
            particle->mY += particle->mVelocityY * dt;
        }
    }
}

int main(int argc, char **argv) {
    Firework firework;
    firework.setOrigin(100, 100);
    firework.setColor(255, 100, 0);
    firework.setGravity(9.81);
    firework.setSpeed(5);
    firework.setNumberOfParticles(100);

    firework.Start();

    float dt = 0.01f;
    for (int i = 0; i < 30; ++i) {
        firework.nextFrame(dt);

        for (FireParticle *particle : firework.mParticles) {
            std::cout << particle->mX << ", " << particle->mY << std::endl;
        }
    }

    firework.Stop();

    return 0;
}
