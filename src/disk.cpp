// Copyright (c) 2024 Nathan Greenfield. All rights reserved
#include "disk.h"
#include <vector>
#include <cstdlib>
#include <ctime>

// Default Constructor
Disk::Disk()
{
    inX = 0;
    inY = 0;
    inWidth = 0;
    inHeight = 0;
    setRandomColor();
}

// Parameterized constructor
// flip mx --> inx
Disk::Disk(int x, int y, int width, int height)
{
    inX = x;
    inY = y;
    inWidth = width;
    inHeight = height;
    // Adjust disks to be centered
    inX = x - inWidth / 2;
    inY = y - inHeight;
    setRandomColor();
}

// Setter
void Disk::setX(int newXPosition)
{
    // Center disks
    inX = newXPosition - inWidth / 2;
}

// Setter
void Disk::setY(int newYPosition)
{
    // Bottom centering
    inY = newYPosition - inHeight;
}

// Getter
int Disk::getHeight() const
{
    return inHeight;
}

// Draw disc function
void Disk::drawDisk(GWindow& gw)
{
    gw.setColor(color);
    gw.fillRect(inX, inY, inWidth, inHeight);
}

// Random color function
void Disk::setRandomColor()
{
    // Vector with different color options
    std::vector<std::string> colors = {"GREEN", "BLUE", "RED", "MAGENTA", "CYAN", "PURPLE", "PINK", "YELLOW", "ORANGE", "GRAY"};
    // Choose random color
    int randomIndex = rand() % colors.size() + 1;
    // Random colors are in randomIndex
    color = colors[randomIndex];
}