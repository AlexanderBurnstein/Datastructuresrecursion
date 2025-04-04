// Copyright (c) 2024 Nathan Greenfield. All rights reserved
#pragma once

#include "gwindow.h"
#include <string>
#include <vector>
#include "disk.h"

class Peg
{
    private:
    // Vector to store disks
    std::vector<Disk> disks;
    // Peg member variables
    int inX;
    int inY;
    int inWidth;
    int inHeight;
    std::string color;

    public:
    // Default constructor
    Peg();

    // Parameterized constructor
    Peg(int x, int y, int width, int height, const std::string& pegColor = "BLACK");

    // Setters
    void setX(int newXPosition);
    void setY(int newYPosition);

    // Name:
    //      addDisk
    // Input:
    //      1. newDisk - The disk to be added to the peg passed by reference
    // Output:
    //      None
    // Side effects: 
    //      Adds a disk to the peg and changes disks position
    // Summary:
    //      Creates a disk and places it on the peg
    //          1. Gets y-position of the disk based on the number of disks already on the peg
    //          2. Aligns the disk with the center of the peg
    //          3. Adds the disk to the vector that holds the disks on the peg
    void addDisk(const Disk& newDisk);

    // Name:
    //      removeDisk
    // Input:
    //      None
    // Output:
    //      None
    // Side effects: 
    //      Removes the top disk from the peg
    // Summary:
    //      Removes the last disk on the peg
    //          1. Checks if there are disks on the peg
    //          2. Removes the top disk from the vector
    void removeDisk();

    // Name:
    //      getTopDisk
    // Input:
    //      None
    // Output:
    //      Returns the top disk from the peg
    // Side effects:
    //      None
    // Summary:
    //      Gets the disk at top of the peg without removing it
    //          1. Check if the peg has disks
    //          2. Return the top disk
    //          3. Return a default disk if there are no disks on peg
    Disk getTopDisk() const;

    // Name:
    //      moveDisk
    // Input:
    //      1. diskToNewPeg passed by reference
    // Output:
    //      None
    // Side effects:
    //      Moves the top disk from one peg to another
    // Summary:
    //      Moves top disk from one peg to another
    //          1. Check if there is a disk to move
    //          2. Gets and removes the top disk from the peg
    //          3. Adds the disk to a new peg
    void moveDisk(Peg& diskToNewPeg);

    // Name: 
    //      drawPeg
    // Input:
    //      1. window - Graphics window where stuff is drawn passed by reference
    // Output: 
    //      None
    // Side effects: 
    //      Draws the pegs and disks
    // Summary:
    //      Draws the pegs and disks
    //          1. Draws the pegs
    //          2. Loops through vector of disks and draws the disks on pegs
    void drawPeg(GWindow& gw);
};
