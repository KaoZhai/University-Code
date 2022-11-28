#include "maze.h"

// read the maze and store it
void Maze::read_maze(const int height, const int width)
{
    for(int i = 0 ; i < height ; i++)
    {
        string line;
        getline(cin, line);
        vector<char> tmp;
        for(int j = 0 ; j < width ; j++)
            tmp.push_back(line[j]);
        body.push_back(tmp);
    }
}

// print the whole maze
void Maze::print_maze() const
{
    for(int i = 0 ; i < body.size() ; i++)
    {
        for(int j = 0 ; j < body[i].size() ; j++)
            cout << body[i][j];
        cout << endl;
    }
}

// return the maze object by x, y
char Maze::check_maze(const int x, const int y) const
{
    if(y < body.size() && x < body[y].size())
        return body[y][x];
    else
        return 0;
}

// return the robot's origin position
const pair<int, int> Maze::find_robot_in_origin_maze() const
{
    for(int i = 0 ; i < body.size() ; i++)
    {
        for(int j = 0 ; j < body[i].size() ; j++)
        {
            if(body[i][j] == 'O')
                return make_pair(j, i);
        }
    }
}