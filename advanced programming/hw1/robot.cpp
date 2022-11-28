#include "robot.h"

// initial robot's start position and face direction
void Robot::init(const pair<int, int> in)
{
    loc = in;
    dir = North;
}

// return robot's position
const pair<int, int> Robot::pos() const
{
    return loc;
}

// move robot
void Robot::move(const Maze maze)
{
    // add journey
    journey.push_back(make_pair(loc, dir));

    int target_x, target_y;
    // turn to right direction
    while(1)
    {
        //get target x, y
        if(dir == North)     
        { 
            target_x = loc.first;
            target_y = loc.second - 1;
        }
        else if(dir == East)
        {
            target_x = loc.first + 1;
            target_y = loc.second;
        }
        else if(dir == West) 
        {
            target_x = loc.first - 1;
            target_y = loc.second;
        }
        else if(dir == South)
        {
            target_x = loc.first;
            target_y = loc.second + 1;
        }

        if(maze.check_maze(target_x, target_y) == '#') turn();
        else                                           break;
    }
    loc = make_pair(target_x, target_y);
}

// return loop steps
const long long Robot::check_loop()
{
    for(int i = journey.size() - 1 ; i >= 0 ; i--)
    {
        if(journey[i].first == loc && journey[i].second == dir)
            return journey.size() - i;
    }
    return 0;
}

// robot turn right
void Robot::turn()
{
    if(dir == North)      dir = East;
    else if(dir == South) dir = West;
    else if(dir == West)  dir = North;
    else                  dir = South;
}