// Copyright (c) 2024 Nathan Greenfield. All rights reserved
#include "towers.h"
// Finish comments here

int Towers::promptForDisks()
{
    // Int to hold the number of disks that the user wants on the peg
    int numDisks;
    // Do while loop to prompt the user for the correct input, gets user input
    do
    {
        std::cout << "How many disks would you like to play with? (2-10): ";
        std::cin >> numDisks;
        if (numDisks < minimumDisks || numDisks > maximumDisks)
        {
            std::cout << "Wrong number of disks! You can only play with 2-10 disks!" << std::endl;
        }
    }
    while (numDisks < minimumDisks || numDisks > maximumDisks);
    return numDisks;
}

void Towers::promptForPegs(int& startingPeg, int& endingPeg)
{
    // Do while loop to prompt the user for the correct input, gets user input for pegs
    do
    {
        std::cout << "What Peg would you like to start on? (1, 2, 3): ";
        std::cin >> startingPeg;
        if (startingPeg == endingPeg || startingPeg < minimumPegs || startingPeg > maximumPegs)
        {
            std::cout << "Wrong choice of peg! Starting peg must be between 1-3." << std::endl;
        }
        else
        {
            std::cout << "What Peg would you like to end on? (1, 2, 3): ";
            std::cin >> endingPeg;
            if (startingPeg == endingPeg || endingPeg < minimumPegs || endingPeg > maximumPegs)
            {
                std::cout << "Wrong choice of pegs! The Starting peg and ending peg have to be different and between 1-3." << std::endl;
            }
        }
    }
    while (startingPeg == endingPeg || startingPeg < minimumPegs || startingPeg > maximumPegs || endingPeg < minimumPegs || endingPeg > maximumPegs);
}

int Towers::promptForPause()
{
    // Variable to hold pause time that the user inputs into the program
    int pauseTime;
    // Do while loop to prompt the user for the correct input, gets user input for pause time
    do
    {
        std::cout << "How many milliseconds do you want to pause between image animation? (1-1000000): ";
        std::cin >> pauseTime;
        if (pauseTime < minimumPause || pauseTime > maximumPause)
        {
            std::cout << "Wrong pause time! Pause time has to be between 1 and 1000000 milliseconds." << std::endl;
        }
    }
    while (pauseTime < minimumPause || pauseTime > maximumPause);
    return pauseTime;
}

void Towers::promptForWindowSize(int& width, int& height)
{
    // Do while loop to prompt the user for the correct input, gets user input for window width and the window height
    do
    {
        std::cout << "How wide do you want the window? (800-3840): ";
        std::cin >> width;
        std::cout << "How tall do you want the window? (600-2160): ";
        std::cin >> height;
        
        if (width < minimumWindowWidth || width > maximumWindowWidth || height < minimumWindowHeight || height > maximumWindowHeight)
        {
            std::cout << "Wrong window size! Window must follow these size guidlines: 800-3840 Wide and 600-2160 Tall! " << std::endl;
        }
    }
    while (width < minimumWindowWidth || width > maximumWindowWidth || height < minimumWindowHeight || height > maximumWindowHeight);
}

void Towers::draw(GWindow& gw, std::vector<Peg>& pegs, int pauseTime)
{
    // Clears the window
    gw.clear();
    // Draws pegs and disks in the window
    for (int i = 0; i < pegs.size(); i++)
    {
        pegs[i].drawPeg(gw);
    }
    // Pause for the users desired time
    pause(pauseTime);
}

// this shouldnt be a function in peg
void Towers::moveDisk(GWindow& gw, std::vector<Peg>& pegs, int start, int end, int pauseTime)
{
    // Uses the moveDisk function from the Peg class to move the disk
    pegs[start].moveDisk(pegs[end]);
    // Draws window after moving the disk
    draw(gw, pegs, pauseTime);
}

void Towers::towerSolver(GWindow& gw, std::vector<Peg>& pegs, int start, int end, int n, int pauseTime)
{
    // Base case if no disks can be moved return
    if (n == 0)
    {
        return;
    }

    // Figure out the temp peg to use
    int temp = 3 - start - end;

    // Moves n-1 disks from start to temp
    towerSolver(gw, pegs, start, temp, n - 1, pauseTime);

    // Moves the nth disk from start to end
    moveDisk(gw, pegs, start, end, pauseTime);

    // Moves the n-1 disks from temp to end
    towerSolver(gw, pegs, temp, end, n - 1, pauseTime);
}

void Towers::towerRun(GWindow& gw, std::vector<Peg>& pegs, int pauseTime, int numDisks, int startingPeg, int endingPeg)
{
    // Adjust peg numbers 1-3 to vector because pegs are stored from index 0-2
    int startIndex = startingPeg - 1;
    int endIndex = endingPeg - 1;

    // Start recursive solution.
    towerSolver(gw, pegs, startIndex, endIndex, numDisks, pauseTime);
}