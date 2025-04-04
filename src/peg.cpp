// Copyright (c) 2024 Nathan Greenfield. All rights reserved
#include "peg.h"

// Default Constructor
Peg::Peg() 
{
    inX = 0;
    inY = 0;
    inWidth = 0;
    inHeight = 0;
    color = "BLACK";
}

// Parameterized constructor
Peg::Peg(int x, int y, int width, int height, const std::string& pegColor)
{
    inX = x;
    inY = y;
    inWidth = width;
    inHeight = height;
    color = pegColor;
}

// Setter
void Peg::setX(int newXPosition)
{
    inX = newXPosition;
}

// Setter
void Peg::setY(int newYPosition)
{
    inY = newYPosition;
}

// Adds disk to vector and adds disk to peg
void Peg::addDisk(const Disk& newDisk)
{
    // Starting position of peg is inY, size says how many disks are on peg, inY - size and height of a disk shows where to position disks on the peg
    int diskY = inY - (disks.size() * newDisk.getHeight());
    // Copies the original disk
    Disk adjustedDisk = newDisk;
    // Align disk with center of peg
    adjustedDisk.setX(inX);
    // Align disk to stack on top of other disk
    adjustedDisk.setY(diskY);
    // Adds the disk to the vector
    disks.push_back(adjustedDisk);
}

// Removes disk from peg
// should return disk here
// if empty tests fail it makes debugging more difficult
void Peg::removeDisk()
{
    if (!disks.empty())
    {
        disks.pop_back();
    }
}

// Return the top disk
Disk Peg::getTopDisk() const
{
    // See if we can get a disk off top
    if (!disks.empty())
    {
        // Return top disk with index - 1
        return disks[disks.size() - 1];
    }
    else
    {
        // Returns a default disk
        return Disk();
    }
}

// Moves top disk to a new peg
void Peg::moveDisk(Peg& diskToNewPeg)
{
    // See if we can move disk
    if (!disks.empty())
    {
        // Find top disk in index
        Disk topDisk = disks[disks.size() - 1];
        // Removes disk from vector
        disks.pop_back();
        // Puts disk on new peg
        diskToNewPeg.addDisk(topDisk);
    }
}

// Draw the peg (using GWindow)
void Peg::drawPeg(GWindow& gw)
{
    // Draws peg and sets it to black
    gw.setColor("BLACK");
    gw.fillRect(inX - inWidth / 2, inY - inHeight, inWidth, inHeight);

    // Draw disks on peg
    for (int i = 0; i < disks.size(); i++)
    {
        disks[i].drawDisk(gw);
    }
}