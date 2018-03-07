// Contains the game globals
#pragma once

//The direction the sprite is moving in
const int static WEST = 1;
const int static EAST = 2;
const int static NORTH = 3; // direction north
const int static SOUTH = 4;

//Fence Bounds
//Link
//X
const int FENCE_WIDTH_LEFT = 13;	//Amount of pixels from the very left of the screen and the fence
const int FENCE_WIDTH_RIGHT = 30;	//Amoint of pixels from the very right of the screen and the fence
//Y
const int FENCE_HEIGHT_TOP = 70;	//Amount of pixels from the very top of the screen and the fence
const int FENCE_HEIGHT_BOT = 40;	//Amount of pixels from the very bottom of the screen and the fence

//skeleton
//Y
const int FENCE_WIDTH_RIGHT_SKEL = 40;

const float SCREEN_WIDTH = 400;   // the size of the screen in pixels used in the game
const float SCREEN_HEIGHT = 320;

//Health
const int MAX_HEALTH = 10;