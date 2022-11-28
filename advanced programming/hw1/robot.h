#ifndef ROBOT_H
#define ROBOT_H
#include <utility>
#include <vector>
#include "maze.h"

using namespace std;

// enumerate four directions
enum Dir
{
    North,
    South,
    West,
    East
};

class Robot
{
public:
    // initial robot's start position and face direction
    void init(const pair<int, int> in);

    // return robot's position
    const pair<int, int> pos() const;

    // move robot
    void move(const Maze maze);

    // return loop steps
    const long long check_loop();

private:
    // robot's location
    pair<int, int> loc;
    // robot's face direction
    Dir dir = North;
    // robot's journey
    vector<pair<pair<int, int>, Dir>> journey;
    // robot turn right
    void turn();
};

#endif