/**
 * @file vector.cpp
 * @brief Implementation of VectorCustom class
 * @version 0.1
 * @date 2023-09-24
 */

#include <iostream>
#include <string>
#include <vector>

class VectorCustom
{
private:
    double x;
    double y;
    double z;
public:
    double GetX() const;
    double GetY() const;
    double GetZ() const;
    void SetX(double x);
    void SetY(double y);
    void SetZ(double z);
    VectorCustom(double x, double y, double z); // added semicolon here
}; // added semicolon here

VectorCustom::VectorCustom(double x, double y, double z)
{
    SetX(x);
    SetY(y);
    SetZ(z);
}

double VectorCustom::GetX() const { return x; }

double VectorCustom::GetY() const { return y; }

double VectorCustom::GetZ() const { return z; }

void VectorCustom::SetX(double x) { this->x = x; }

void VectorCustom::SetY(double y) { this->y = y; }

void VectorCustom::SetZ(double z) { this->z = z; }

int main(int argc, char **argv)
{
    VectorCustom vector(1, 2, 3);
    std::cout << "Vector: " << vector.GetX() << ", " << vector.GetY() << ", " << vector.GetZ() << std::endl;
    return 0;
}