#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include "maze.h"
#include "robot.h"

using namespace std;

int main()
{
    // read width and height
    int width, height;
    cin >> width >> height; cin.ignore();
    
    // read how many steps
    long long steps;
    cin >> steps; cin.ignore();

    // read maze
    Maze maze;
    maze.read_maze(height, width);

    // init robot
    Robot robot;
    robot.init(maze.find_robot_in_origin_maze());

    // flag for checked the loop or not
    bool loop_flag = false;
    while(steps--)
    {
        robot.move(maze);

        if(!loop_flag)
        {
            long long loop_steps = robot.check_loop();
            if(loop_steps)
            {
                steps %= loop_steps;
                loop_flag = true;
            }
        }
    }

    pair<int, int> answer = robot.pos();
    cout << answer.first << " " << answer.second << endl;
}