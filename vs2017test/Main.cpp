#include "glut.h"
#include <iostream>
#include <time.h>

#include "cell/Cell.h"
#include "maze/Maze.h"
#include "algorithms/SearchingMethod.h"
#include "algorithms/bfs/BFS.h"
#include "algorithms/dfs/DFS.h"
#include "algorithms/bi_bfs/BiDirectionalBFS.h"
#include "algorithms/best_first_search/BestFirstSearch.h"
#include "algorithms/a_star/AStar.h"
#include <chrono> 

using namespace std::chrono;

SearchingMethod* pathFinder;
Maze* maze;
steady_clock::time_point startTime;
steady_clock::time_point endTime;
bool flag = false;
string chosenMethod = "";

void init() {
	glClearColor(0.8, 0.7, 0.5, 0); // color of window background
	glOrtho(-1, 1, -1, 1, 1, -1);
	srand(time(0));
	maze = new Maze();
}

void drawMaze() {
	int i, j;
	double sx, sy; // cell size
	double x, y;
	sx = 2.0 / MSZ;
	sy = 2.0 / MSZ;
	for (i = 0; i < MSZ; i++) {
		for (j = 0; j < MSZ; j++) {
			switch (maze->get(i, j)) {
			case SPACE:
				glColor3d(1, 1, 1);   // white
				break;
			case WALL:
				glColor3d(0.7, 0.4, 0);   // dark-orange
				break;
			case SOURCE:
				glColor3d(0, 0.2, 0.5);   // cyan
				break;
			case TARGET:
				glColor3d(0, 0.5, 1);   // ??
				break;
			case SOURCE_GRAY:
				glColor3d(1, 1, 0);   // yellow
				break;
			case SOURCE_BLACK:
				glColor3d(0.8, 1, 0.8);   // green
				break;
			case SOURCE_PATH:
				glColor3d(0.8, 0.4, 1);   // magenta
				break;
			case TARGET_GRAY:
				glColor3d(1, 0.2, 0);   // ??
				break;
			case TARGET_BLACK:
				glColor3d(0.8, 0, 0.8);   // ??
				break;
			case TARGET_PATH:
				glColor3d(0.8, 0, 0.5);   // ??
				break;
			}
			// draw square maze[i][j]
			x = 2 * (j / (double)MSZ) - 1;
			y = 2 * (i / (double)MSZ) - 1;
			glBegin(GL_POLYGON);  // fill up
			glVertex2d(x, y);
			glVertex2d(x, y + sy);
			glVertex2d(x + sx, y + sy);
			glVertex2d(x + sx, y);
			glEnd();
			glColor3d(0, 0, 0);
		}
	}
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT); // clean frame buffer
	drawMaze();
	glutSwapBuffers(); // show all
}

void idle() {
	if (pathFinder != nullptr) {
		if (pathFinder->isOn()) {
			flag = true;
			pathFinder->iteration();
		}
		else if (flag && !chosenMethod.empty()) {
			endTime = steady_clock::now();
			double elapsedMillis = (double)duration_cast<microseconds>(endTime - startTime).count() / 1000;
			std::cout << chosenMethod << " elapsed " << elapsedMillis << " [millisecond]." << std::endl;
			flag = false;
		}
	}
	glutPostRedisplay(); // indirect call to display
}

void menu(int choice) {
	if (pathFinder != nullptr) {
		pathFinder->clear();
	}
	switch (choice) {
	case INIT_BFS: // BFS
		pathFinder = new BFS(maze);
		chosenMethod = "BFS";
		break;
	case INIT_BI_BFS: // Bi-Directional BFS
		pathFinder = new BiDirectionalBFS(maze);
		chosenMethod = "Bi Directional BFS";
		break;
	case INIT_DFS:  // DFS
		pathFinder = new DFS(maze);
		chosenMethod = "DFS";
		break;
	case INIT_BEST_FIRST_SEARCH:
		pathFinder = new BestFirstSearch(maze);
		chosenMethod = "Best First Search";
		break;
	case INIT_A_STAR:
		pathFinder = new AStar(maze);
		chosenMethod = "A*";
		break;
	case CLEAR_MAZE: // Clear maze from previous runs
		pathFinder->clear();
		break;
	case CHANGE_TARGET_CELL: // Change target cell location in maze
		maze->setTargetCell();
		break;
	case SHUFFLE_MAZE: // Reset maze
		maze = new Maze();
		break;
	}
	startTime = steady_clock::now();
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(600, 0);
	glutCreateWindow("Maze");

	glutDisplayFunc(display);
	glutIdleFunc(idle);
	// menu
	glutCreateMenu(menu);
	glutAddMenuEntry("BFS", INIT_BFS);
	glutAddMenuEntry("Bi-Directional BFS", INIT_BI_BFS);
	glutAddMenuEntry("DFS", INIT_DFS);
	glutAddMenuEntry("Best First Search", INIT_BEST_FIRST_SEARCH);
	glutAddMenuEntry("A*", INIT_A_STAR);
	glutAddMenuEntry("Clear Maze", CLEAR_MAZE);
	glutAddMenuEntry("Change Target", CHANGE_TARGET_CELL);
	glutAddMenuEntry("Shuffle Maze", SHUFFLE_MAZE);

	glutAttachMenu(GLUT_RIGHT_BUTTON);

	init();

	glutMainLoop();
}