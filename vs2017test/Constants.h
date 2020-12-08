#pragma once

/*Commonly used constants for maze definition and coloring.*/
	
const int INIT_BFS = 100;
const int INIT_BI_BFS = 101;
const int INIT_DFS = 102;
const int INIT_BEST_FIRST_SEARCH = 103;
const int INIT_A_STAR = 104;
const int CLEAR_MAZE = 105;
const int CHANGE_TARGET_CELL = 106;
const int SHUFFLE_MAZE = 107;

const int MSZ = 100;
const int SOURCE_X = MSZ / 2;
const int SOURCE_Y = MSZ / 2;

const int SPACE = 0;
const int WALL = 1;

const int SOURCE = 2;
const int TARGET = 3;

const int SOURCE_BLACK = 4;
const int SOURCE_GRAY = 5;
const int SOURCE_PATH = 6;

const int TARGET_BLACK = 7;
const int TARGET_GRAY = 8;
const int TARGET_PATH = 9;