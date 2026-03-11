#pragma once

class Timer
{

private:

    float whiteTime;
    float blackTime;

public:

    Timer();

    void update(bool whiteTurn);
};