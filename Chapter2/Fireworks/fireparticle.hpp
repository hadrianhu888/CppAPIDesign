/**
 * @file fireparticle.hpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-09-25
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <vector>

#pragma once

#ifndef fireparticle_hpp
#define fireparticle_hpp

class FireParticle {
    public:
        FireParticle(double x, double y, double vx, double vy, double ax, double ay, double lifetime);
        double mX, mY;
        double mVX, mVY;
        double mVelocityX, mVelocityY;
        double AccelerationX, AccelerationY;
        double mLifeTime;
        void Update(float deltaTime);
        bool IsActive();
        void SetActive(bool active);
        void SetPosition(double x, double y);
        void SetVelocity(double vx, double vy);
        void SetAcceleration(double ax, double ay);
        void SetLifetime(double lifetime);
        void SetColor(int r, int g, int b);
        void draw();
        void setOrigin(double x, double y);
        void setColor(int r, int g, int b);
        void setGravity(double g);
        void setSpeed(double s);
        void setNumberOfParticles(int n);
        void Start();
        void Deactivate();
        void Stop();
        void nextFrame(float dt);
        void IsDeactivated();

    private:
        double mOriX, mOriY;
        float mRed, mGreen, mBlue;
        float mGravity;
        float mSpeed;
        bool mIsActive;
        std::vector<FireParticle *> mParticles;
};

#endif // fireparticle_hpp