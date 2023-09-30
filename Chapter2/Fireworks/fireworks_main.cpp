#include "fireworks.hpp"
#include "fireparticle.hpp"

int main(int argc, char **argv) {
    std::cout << "Fireworks API Example\n";

        Firework firework;
        firework.setOrigin(0, 0);
        firework.setColor(255, 0, 0);
        firework.setGravity(9.81);
        firework.setSpeed(1.0);
        firework.setNumberOfParticles(100);
        firework.Start();

        return 0;
}

