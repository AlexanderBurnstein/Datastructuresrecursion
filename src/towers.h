// Copyright (c) 2024 Nathan Greenfield. All rights reserved
#pragma once

#include <iostream>
#include <vector>
#include "peg.h"
#include "disk.h"
#include "gwindow.h"

// make private
const int minimumDisks = 2;
const int maximumDisks = 10;
const int minimumPegs = 1;
const int maximumPegs = 3;
const int minimumPause = 1;
const int maximumPause = 1000000;
const int minimumWindowWidth = 800;
const int maximumWindowWidth = 3840;
const int minimumWindowHeight = 600;
const int maximumWindowHeight = 2160;

class Towers
{
private:
    // Tower pegs
    Peg peg1;
    Peg peg2;
    Peg peg3;

    // Number of disks user chooses, goes to n then n is changed to numDisks
    int numDisks;

    // Starting and ending pegs user chooses
    int startingPeg;
    int endingPeg;

public:
    // Name: 
    //      promptForDisks
    // Input:
    //      None
    // Output: 
    //      Returns an int that is the number of disks the user inputs
    // Side effects: 
    //      Asks user for the number of disks between 2-10
    // Summary:
    //      Asks the user for the number of disks to play with and asks for more input if the input is wrong
    int promptForDisks();

    // Name: 
    //      promptForPegs
    // Input:
    //      1. int& startingPeg which is starting peg 1, 2, or 3 passed by reference
    //      2. int& endingPeg which is ending peg 1, 2, or 3
    // Output: 
    //      None
    // Side effects: 
    //      Asks the user for the starting and ending pegs if input is wrong based on parameters, asks again
    // Summary:
    //      Asks the user for starting and ending pegs, makes sure input is correct
    void promptForPegs(int& startingPeg, int& endingPeg);

    // Name: 
    //      promptForPause
    // Input:
    //      None
    // Output: 
    //      Returns a int that is the number of milliseconds to pause between animations
    // Side effects: 
    //      Asks the user for the pause time between 1 and 1000000 makes sure its within these bounds
    // Summary:
    //      Asks the user for the pause time between 1 and 1000000 makes sure its within these bounds
    int promptForPause();

    // Name: 
    //      promptForWindowSize
    // Input:
    //      1. int& width which is width of window passed by reference
    //      2. int& height which is height of the window passed by reference
    // Output: 
    //      None
    // Side effects: 
    //      Asks user for the window size, between 800 and 3840 for width, 600 and 2160 for height
    // Summary:
    //      Asks user for window size and makes sure it's between the specified parameters
    void promptForWindowSize(int& width, int& height);

    // Name: 
    //      draw
    // Input:
    //      1. GWindow& gw which is the graphics window passed by reference
    //      2. std::vector<Peg>& pegs which is a vector of pegs to draw passed by reference
    //      3. int pauseTime which is the time to pause between drawing each animation
    // Output: 
    //      None
    // Side effects: 
    //      Clears the graphics window, draws pegs and disks, does the animation with the pause
    // Summary:
    //      Clears the graphics window, draws pegs and disks, does the animation with the desired pause
    void draw(GWindow& gw, std::vector<Peg>& pegs, int pauseTime);

    // Name: moveDisk
    // Input: 
    //      1. GWindow& gw which is the graphics window passed by reference
    //      2. std::vector<Peg>& pegs which is a vector of pegs to draw passed by reference
    //      3. int start which is the index of the starting peg
    //      4. int end which is the index of the ending peg
    //      5. int pauseTime which is the time to pause between drawing each animation
    // Output: None
    // Side effects: Moves the top disk from the start peg to end peg and redraws the window
    // Summary: Moves disk and updates the window
    void moveDisk(GWindow& gw, std::vector<Peg>& pegs, int start, int end, int pauseTime);

    // Name: towerSolver
    // Input: 
    //      1. GWindow& gw which is the graphics window passed by reference
    //      2. std::vector<Peg>& pegs which is a vector of pegs to draw passed by reference
    //      3. int start which is the index of the starting peg
    //      4. int end which is the index of the ending peg
    //      5. int n which is the number of disks to move
    //      6. int pauseTime which is the time to pause between drawing each animation
    // Output: None
    // Side effects: Recursively moves disks from the start peg to end peg
    // Summary: Recursively solve the problem by moving n-1 disks, moving the nth disk, and then moving n-1 disks again
    void towerSolver(GWindow& gw, std::vector<Peg>& pegs, int start, int end, int n, int pauseTime);

    // Name: towerRun
    // Input: 
    //      1. GWindow& gw which is the graphics window passed by reference
    //      2. std::vector<Peg>& pegs which is a vector of pegs to draw passed by reference
    //      3. int pauseTime which is the time to pause between drawing each animation
    //      4. int numDisks - total number of disks
    //      5. int startingPeg which is the start peg
    //      6. int endingPeg which is end peg
    // Output: None
    // Side effects: Moves disks between pegs and starts hanoi solution
    // Summary: Gets start and end peg and moves disks between pegs
    void towerRun(GWindow& gw, std::vector<Peg>& pegs, int pauseTime, int numDisks, int startingPeg, int endingPeg);
};