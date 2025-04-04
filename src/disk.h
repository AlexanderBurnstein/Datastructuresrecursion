// Copyright (c) 2024 Nathan Greenfield. All rights reserved
#pragma once
// onlky .cpp time stuff
#include "gwindow.h"
#include <string>
#include <cstdlib>
#include <ctime>

class Disk
{
    private:
    // Disk member variables
    // use m to indicate membervariables
    int inX;
    int inY;
    int inWidth;
    int inHeight;
    std::string color;

    public:
    // Default constructor
    Disk();
    // Parameterized constructor
    Disk(int x, int y, int width, int height);

    // Setters
    void setX(int newXPosition);
    void setY(int newYPosition);

    // Getters
    int getHeight() const;

    // Name: 
    //		drawDisk
    // Input:
    //		1. gw for graphics window passed by reference
    // Output: 
    //		None
    // Side effects: 
    //		Draws a filled rectangle(disk) in the graphics window
    // Summary:
    //		Creates a Disk(filled rectangle) in our gwindow
    //          1. Draws disk in the gwindow at x, y, width, height
    void drawDisk(GWindow& gw);

    // Name: 
    //		setRandomColor
    // Input:
    //		1. None
    // Output: 
    //		None
    // Side effects: 
    //		Randomize the color of the disks
    // Summary:
    //		Randomizes the colors of the disks generated
    //          1. Randomizes the colors of the disks generated uses vector and string colors to do so.
    //          2. Used by drawDisk function to assign random colors to random disks
    void setRandomColor();
};

