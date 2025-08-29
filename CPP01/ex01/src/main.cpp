#include "../inc/Zombie.hpp"

int main()
{
    int N = 7;

    std::string name = "Julie";

    Zombie *horde = zombieHorde(N, name);

    if (horde)
    {
        for (int i = 0; i < N; i++)
            horde[i].announce();
        delete[] horde;
    }
}