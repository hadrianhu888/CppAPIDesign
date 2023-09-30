/**
 * @file fireparticles.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-09-29
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <vector>
#include <iostream>
#include <random>
#include "fireparticle.hpp"

/**
 * @brief class FireParticle {
    public:
        double mX, mY;
        double mVX, mVY;
        double mVelocityX, mVelocityY;
        double AccelerationX, AccelerationY;
        double mLifeTime;

    private:
        double mOriX, mOriY;
        float mRed, mGreen, mBlue;
        float mGravity;
        float mSpeed;
        bool mIsActive;
        std::vector<FireParticle *> mParticles;

    };
 *
 */

/**
 * @brief Implement the above class here
 *
 */

FireParticle::FireParticle(double x, double y, double vx, double vy, double ax, double ay, double lifetime) {
    mX = x;
    mY = y;
    mVX = vx;
    mVY = vy;
    AccelerationX = ax;
    AccelerationY = ay;
    mLifeTime = lifetime;
    mVelocityX = mVX;
    mVelocityY = mVY;
    mRed = 255;
    mGreen = 0;
    mBlue = 0;
    mOriX = 0;
    mOriY = 0;
    mGravity = 9.81;
    mSpeed = 1.0;
    mIsActive = true;
}

void FireParticle::Update(float deltaTime) {
    if (mIsActive) {
        mLifeTime -= deltaTime;
        if (mLifeTime <= 0) {
            mIsActive = false;
        }
        else {
            mX += mVelocityX * deltaTime;
            mY += mVelocityY * deltaTime;
            mVelocityX += AccelerationX * deltaTime;
            mVelocityY += AccelerationY * deltaTime;
            mVelocityY += mGravity * deltaTime;
        }
    }
}

bool FireParticle::IsActive() { return mIsActive; }

void FireParticle::SetActive(bool active) { mIsActive = active; }

void FireParticle::SetPosition(double x, double y) {
    mX = x;
    mY = y;
}

void FireParticle::SetVelocity(double vx, double vy) {
    mVX = vx;
    mVY = vy;
}

void FireParticle::SetAcceleration(double ax, double ay) {
    AccelerationX = ax;
    AccelerationY = ay;
}

void FireParticle::SetLifetime(double lifetime) { mLifeTime = lifetime; }

void FireParticle::SetColor(int r, int g, int b) {
    mRed = r;
    mGreen = g;
    mBlue = b;
}

void FireParticle::draw() {
    std::cout << "Drawing a particle at (" << mX << ", " << mY << ")" << std::endl;
}

void FireParticle::setOrigin(double x, double y) {
    mOriX = x;
    mOriY = y;
}

void FireParticle::setColor(int r, int g, int b) {
    mRed = r;
    mGreen = g;
    mBlue = b;
}

void FireParticle::setGravity(double g) { mGravity = g; }

void FireParticle::setSpeed(double s) { mSpeed = s; }

void FireParticle::setNumberOfParticles(int n) { mParticles.resize(n); }

void FireParticle::Start() {
    std::cout << "Starting a particle" << std::endl;
    mIsActive = true;
    mLifeTime = 1.0;
    mVelocityX = mVX;
    mVelocityY = mVY;
    mVelocityY += mGravity * mLifeTime;
    mX = mOriX;
    mY = mOriY;
    std::cout << "Particle started" << std::endl;
    std::cout << "Particle position is (" << mX << ", " << mY << ")"
              << std::endl;
    std::cout << "Particle velocity is (" << mVX << ", " << mVY << ")"
              << std::endl;
    std::cout << "Particle acceleration is (" << AccelerationX << ", "
              << AccelerationY << ")" << std::endl;
    std::cout << "Particle lifetime is " << mLifeTime << std::endl;
    std::cout << "Particle color is (" << mRed << ", " << mGreen << ", "
              << mBlue << ")" << std::endl;
    std::cout << "Particle origin is (" << mOriX << ", " << mOriY << ")"
              << std::endl;
    std::cout << "Particle gravity is " << mGravity << std::endl;
    std::cout << "Particle speed is " << mSpeed << std::endl;
    std::cout << "Particle is active " << std::boolalpha << mIsActive
              << std::endl;
    std::cout << "Particle has " << mParticles.size() << " particles"
              << std::endl;
    std::cout << "Particle has " << mParticles.capacity() << " particles"
              << std::endl;
    std::cout << "Particle has " << mParticles.max_size() << " particles"
              << std::endl;
}

void FireParticle::Deactivate() { mIsActive = false; }

void FireParticle::IsDeactivated() {mIsActive = false;}

void FireParticle::Stop() {
    std::cout << "Stopping a particle" << std::endl;
    mIsActive = false;
    mLifeTime = 0;
    mVelocityX = 0;
    mVelocityY = 0;
    mX = 0;
    mY = 0;
    std::cout << "Particle stopped" << std::endl;
    std::cout << "Particle position is (" << mX << ", " << mY << ")"
              << std::endl;
    std::cout << "Particle velocity is (" << mVX << ", " << mVY << ")"
              << std::endl;
    std::cout << "Particle acceleration is (" << AccelerationX << ", "
              << AccelerationY << ")" << std::endl;
    std::cout << "Particle lifetime is " << mLifeTime << std::endl;
    std::cout << "Particle color is (" << mRed << ", " << mGreen << ", "
              << mBlue << ")" << std::endl;
    std::cout << "Particle origin is (" << mOriX << ", " << mOriY << ")"
              << std::endl;
    std::cout << "Particle gravity is " << mGravity << std::endl;
}

void FireParticle::nextFrame(float dt) {
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








