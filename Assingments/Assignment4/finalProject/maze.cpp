//
//  maze2.cpp
//  finalProject
//
//  Created by McKenzie on 8/6/18.
//  Copyright © 2018 McKenzie. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cctype>
#include <stack>
#include <cmath>
#include "maze.h"

//reads maze info from terminal input
void Graph::readMaze(string file){
    
    ifstream maze;
    string mazeFile;
    mazeFile = file;
    maze.open(mazeFile.c_str());
    
    int val_read = 0;
    room = 0;
    for(int i = 0; !maze.eof(); i++){
        vector<int> row;
        for(int j =0; (j<4) && !maze.eof(); j++){
            maze >> val_read;
            row.push_back(val_read);
        }
        mazeVec.push_back(row);
        room++;
    }
    maze.close();
    
    cout << "mazeVec: \n";
    for(int i =0; i < mazeVec.size(); i++){
        cout << i << ": ";
        for(int j = 0; j < mazeVec[i].size(); j++){
            cout << mazeVec[i][j] << " ";
        }
        cout << endl;
    }

    //intialize adjMatrix with 0
    int size = mazeVec.size();
    for(int i = 0; i < size; i++){
        vector<int> matrixR;
        for(int j = 0; j < size; j++)
            matrixR.push_back(0);
        adjMatrix.push_back(matrixR);
    }
    
    //populate adjMatrix with txt file input
    for(int i = 0; i < size; i++){
        if(mazeVec[i][0] == 1)
            adjMatrix[i][i - sqrt(size)] = 1;
        if(mazeVec[i][1] == 1)
            adjMatrix[i][i + 1] = 1;
        if(mazeVec[i][2] == 1)
            adjMatrix[i][i + sqrt(size)] = 1;
        if(mazeVec[i][3] == 1)
            adjMatrix[i][i - 1] = 1;
    }
}

void Graph::printMatrix(){
    for(int i =0; i < adjMatrix.size(); i++){
        for(int j = 0; j < adjMatrix[i].size(); j++){
            cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }
}

//depth-first search using stack
void Graph::DFS(int start, int end){
    vector<bool> visit(room, false);
    stack<int> stack;
    
    stack.push(start);
    
    //if end is found stop
    while(!stack.empty() && start != end){
        start = stack.top();
        pathSolution.push_back(start);
        pathLength++;
        stack.pop();
        
        if(!visit[start]){
            cout << start << " ";
            visit[start] = true;
        }
        
        for(int i = 0; i != adjMatrix[start].size(); i++)
            if(visit[i] == false && adjMatrix[start][i] == 1)
                stack.push(i);
    }

}


void Graph::printMaze(){
    int size = mazeVec.size();
    //initialize output char vector
    vector<vector<int> > temp;
    for(int i = 0; i < sqrt(size); i++){
        vector<char> mazeR;
        vector<int> tempR;
        for(int j = 0; j < sqrt(size); j++){
            mazeR.push_back('x');
            tempR.push_back(0);
        }
        mazeText.push_back(mazeR);
        temp.push_back(tempR);
    }
    
    //if room on maze path then change char to 'o'
    int room = 0;
    for(int i = 0; i < sqrt(size); i++){
        for(int j = 0; j < sqrt(size); j++){
            temp[i][j] = room;
            for(int z = 0; z < pathSolution.size(); z++){
                if(room == pathSolution[z])
                    mazeText[i][j] = 'o';
            }
            room++;
        }
    }
    
    cout << "\nMaze Solution:\n";
    for(int i = 0; i < mazeText.size(); i++){
        for(int j = 0; j < mazeText[i].size(); j++){
            cout << mazeText[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    Graph m;
    cout << "Enter name of maze file: ";
    string file;
    cin >> file;
    
    m.readMaze(file);
    cout << endl;
    cout << "DFS: ";
    m.DFS(0,15);
    cout << endl;
    m.printMaze();
    cout << endl << endl;
    bool exit = false;
    int menu;
    do{
        cout << endl << endl;
        cout << "Enter '0' to see adjacency matrix\n";
        cout << "Enter '1' to see rooms in the solution path\n";
        cout << "Enter '2' to see the length of the solution path\n";
        cout << "Enter '3' to exit\n";
        cout << "\nYour choice: ";
        cin >> menu;
        cout << endl << endl;
        
        switch (menu) {
            case 0:
                cout << "Matrix\n";
                m.printMatrix();
                break;

            case 1:
                cout << "Path Solution: ";
                m.findPathSolution(m, 0, 15);
                break;

            case 2:
                m.printPathLength();
                break;
                
            case 3:
                cout << "EXITING\n";
                exit = true;
                break;

            default:
                cout << "invalid input ... please try again\n";
                break;
        }
    }while(!exit);
    return 0;
}
