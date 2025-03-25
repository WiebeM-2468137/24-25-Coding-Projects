#include "rpggameheader.hpp"
#include <iostream> // Input and output
#include <string>   // std::string
#include <vector>   // std::vector
#include <cstdlib>
#include <ctime>

int main()
{
    std::srand(std::time(0));
    std::cout << "================ Welcome To Wiebe's RPG Game ================";

    std::string name;
    std::cout << "\nGeef de naam van uw karakter: ";
    std::cin >> name;

    Character Player = Character(name, 200, 44, 34);
    Enemy Goblin = Enemy("Goblin", 160, 56, 12);

    while (Player.IsAlive() && Goblin.IsAlive())
    {
        // Start of Round
        // Show Stats
        Player.ShowStats();
        Goblin.ShowStats();
        std::cout << "\n";

        // Player Action
        int playeraction;
        std::cout << "\nActies:\n1. Aanval\n2. Heling\nJouw actie: ";
        std::cin >> playeraction;

        if (playeraction == 1)
        {
            Player.Attack(Goblin);
        }
        else if (playeraction == 2)
        {
            Player.Heal();
        }

        // Enemy Action
        if (Goblin.IsAlive())
        {
            Goblin.EnemyTurn(Player);
        }
    }

    // Result
    if (Player.IsAlive())
    {
        std::cout << "\nCongrats, you win!";
    }
    else
    {
        std::cout << "\nYou lose, try again.";
    }

    std::cout << "\n=============================================================";
    return 0;
}