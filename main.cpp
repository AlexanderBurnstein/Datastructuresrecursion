// Copyright (c) 2024 Nathan Greenfield. All rights reserved
#include <iostream>
#include <vector>
#include "gwindow.h"
#include "disk.h"
#include "peg.h"
#include "towers.h"

// remove peg 123 and and move code from main and call tower run in main in my tower run 
// dont need if statements in peg.cpp

int main(int argc, const char* argv[])
{
	// Create Tower object
	Towers towers;

	// Random number generator for random colored disks
    std::srand(std::time(0));
	
	// Ask number of disks, starting and ending pegs, pause time, and window size
	int numDisks = towers.promptForDisks();
	int startingPeg, endingPeg;
	towers.promptForPegs(startingPeg, endingPeg);
	int pauseTime = towers.promptForPause();
	int width, height;
	towers.promptForWindowSize(width, height);

	// Create the gw with users width and height
	GWindow gw(width, height);

	// Adjust peg size depending on gw dimensions
	int pegWidth = width / 100;
	int pegHeight = height - 100;

	// Adjust disk size depending on window size
	int maxDiskWidth = width / 4;
	int maxDiskHeight = height / 12;

	// Adjust certain pegs axis added to math below
	int pegAdjust = 60;

	// Create vector of pegs and position them based on the window size
	std::vector<Peg> pegs;
	pegs.push_back(Peg(width / 4 - pegAdjust, height - 50, pegWidth, pegHeight, "BLACK"));
	pegs.push_back(Peg(width / 2, height - 50, pegWidth, pegHeight, "BLACK"));
	pegs.push_back(Peg(3 * width / 4 + pegAdjust, height - 50, pegWidth, pegHeight, "BLACK"));

	// Create the disks and add them to the starting peg largest disk first to smallest
	for (int i = numDisks; i > 0; --i)
	{
		// Scale the disk width and height based on i and window size
		// Disk width gets smaller with each disk added
		int diskWidth = maxDiskWidth * i / numDisks;
		// Disk height is fixed, can possibly scale later
		int diskHeight = maxDiskHeight;
		// Center X axis to peg for disk
		int diskX = 0;
		// Y position added when peg is added
		int diskY = 0;
		// Create a newDisk with updated dimensions
		Disk newDisk(diskX, diskY, diskWidth, diskHeight);
		// Add disk to peg
		pegs[startingPeg - 1].addDisk(newDisk);
	}

	// Draws the pegs, disks, and pauseTime
	towers.draw(gw, pegs, pauseTime);
	
	// Moves disks from starting peg to ending peg using recursion
	towers.towerRun(gw, pegs, pauseTime, numDisks, startingPeg, endingPeg);

	// Pause to help gw and viewing time
	pause(3000);
    
	/* // Disk draw test code & Peg draw test code
	// Added pauses as per Lucas to help the gwindow create
	pause(100);
	pause(120);

	// Random number generator for random colored disks
    std::srand(std::time(0));

	// Create Window
	GWindow gw(1000, 800);

	// Make a silly label
	gw.setColor("BLACK");
	gw.drawLabel("TOWER OF HANOI", 500, 30);

	pause(2000);

	// Draw Pegs
	Peg testPeg1 = Peg(200, 750, 15, 680);
	Peg testPeg2 = Peg(500, 750, 15, 680);
	Peg testPeg3 = Peg(800, 750, 15, 680);

	// Draw Disks
	// Add them biggest to smallest to peg
	Disk testDisk1 = Disk(0, 0, 250, 100);
	Disk testDisk2 = Disk(0, 0, 200, 100);
	Disk testDisk3 = Disk(0, 0, 150, 100);
	Disk testDisk4 = Disk(0, 0, 100, 100);
	Disk testDisk5 = Disk(0, 0, 50, 100);

	// Draw Pegs with disks
	testPeg1.addDisk(testDisk1);
	testPeg1.addDisk(testDisk2);
	testPeg1.addDisk(testDisk3);
	testPeg1.addDisk(testDisk4);
	testPeg1.addDisk(testDisk5);

	// Draw Pegs
    testPeg1.drawPeg(gw);
    testPeg2.drawPeg(gw);
    testPeg3.drawPeg(gw);

	// Pause to see setup
	pause(1000);
	pause(500);

	// Remove disks one by one and redraw Pegs, clear window and redraw the updated pegs
	testPeg1.removeDisk();
	testPeg2.addDisk(testDisk5);
	gw.clear();
	gw.setColor("BLACK");
	gw.drawLabel("TOWER OF HANOI", 500, 30);
	// Draw pegs and disks but updated and adds removed disk to new peg
	testPeg1.drawPeg(gw);
	testPeg2.drawPeg(gw);
    testPeg3.drawPeg(gw);
	pause(1000);

	testPeg1.removeDisk();
	testPeg2.addDisk(testDisk4);
	gw.clear();
	gw.setColor("BLACK");
	gw.drawLabel("TOWER OF HANOI", 500, 30);
	testPeg1.drawPeg(gw);
	testPeg2.drawPeg(gw);
    testPeg3.drawPeg(gw);
	pause(1000);

	testPeg1.removeDisk();
	testPeg2.addDisk(testDisk3);
	gw.clear();
	gw.setColor("BLACK");
	gw.drawLabel("TOWER OF HANOI", 500, 30);
	testPeg1.drawPeg(gw);
	testPeg2.drawPeg(gw);
    testPeg3.drawPeg(gw);
	pause(1000); */

	/* // Test Disks
	testDisk1.drawDisk(window);
	testDisk2.drawDisk(window);
	testDisk3.drawDisk(window); */

	/* gw.drawLabel("Hanoi", gw.getWidth() / 2, gw.getHeight() + 20); */

	// Pause for window display
	pause(100);
	pause(5000);

	return 0;
}
