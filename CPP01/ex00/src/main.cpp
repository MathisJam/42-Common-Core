#include "../inc/Zombie.hpp"

int main()
{
    Zombie *Heap = newZombie("Heap");
    Heap->announce();
    
    randomChump("Stack");

    delete Heap;
}