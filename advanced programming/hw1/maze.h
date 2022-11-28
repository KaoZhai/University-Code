#ifndef MAZE_H
#define MAZE_H
#include <utility>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Maze
{
public:
    // read the maze and store it
    void read_maze(const int height, const int width);

    // print the whole maze
    void print_maze() const;

    // return the maze object by x, y
    char check_maze(const int x, const int y) const;

    // return the robot's origin position
    const pair<int, int> find_robot_in_origin_maze() const;

private:
    vector<vector<char>> body;
};

#endif