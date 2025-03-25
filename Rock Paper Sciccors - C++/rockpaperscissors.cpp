#include <iostream>  // Input and output (std::cout and std::cin)
#include <vector>    // List with choices (std::vector)
#include <cstdlib>   // Random number generator for computerchoice (std::srand and std::rand)
#include <algorithm> // Input into uppercase (std::transform)
#include <string>    // std::string type
#include <ctime>     // Seed generator for random numbers (std::time)

int main()
{
    std::srand(std::time(0));
    std::cout << "============ Rock - Paper - Scissors Game ============";

    while (true)
    {
        std::string userinput = "";
        std::cout << "\nGive your choice: ";
        std::cin >> userinput;
        std::transform(userinput.begin(), userinput.end(), userinput.begin(), ::toupper);

        if (userinput == "Q")
        {
            std::cout << "\nThanks for playing! Hope to see you again soon!";
            break;
        }

        std::vector<std::string> choices = {"ROCK", "PAPER", "SCISSORS"};

        if (std::find(choices.begin(), choices.end(), userinput) == choices.end())
        {
            std::cout << "Wrong input. Try again.";
            continue;
        }

        int compchoicenumber = std::rand() % 3;
        std::string compchoice = choices[compchoicenumber];

        if (userinput == compchoice)
        {
            std::cout << "Draw.";
            continue;
        }
        else if (userinput == "ROCK" && compchoice == "SCISSORS")
        {
            std::cout << "Congratulations, you win!";
            continue;
        }
        else if (userinput == "PAPER" && compchoice == "ROCK")
        {
            std::cout << "Congratulations, you win!";
            continue;
        }
        else if (userinput == "SCISSORS" && compchoice == "PAPER")
        {
            std::cout << "Congratulations, you win!";
            continue;
        }
        else
        {
            std::cout << "Too bad, you lose.";
        }
    }

    std::cout << "\n======================================================";
    return 0;
}