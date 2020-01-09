//
//  maze.h
//  finalProject
//
//  Created by McKenzie on 8/2/18.
//  Copyright © 2018 McKenzie. All rights reserved.
//

#ifndef maze_h
#define maze_h

#include <iostream>
#include <vector>
#include <fstream>
#include <list>

using namespace std;

class Graph{
private:
    int room;   //holds current room
    int pathLength; //hold the length of the path solution
    vector<vector<int> > mazeVec;   //hold text file input
    vector<vector<int> > adjMatrix; //holds adjacency matrix about mazeVec
    vector<int> pathSolution; //holds all rooms on mazeSolutionPath
    vector<vector<char> > mazeText; //hold solution of maze as text style
    
public:
    Graph() {room = 0; pathLength = 0;} //constructor
    void readMaze(string file);     //read maze info and set adjMatrix
    void DFS(int start, int end);   //find solution path
    void printMaze();
    void printMatrix();
    void printPathLength() {cout << "Path Length: " << pathLength << endl; }
    void findPathSolution(Graph maze, int start, int end){maze.DFS(start, end);}
};



#endif /* maze_h */
