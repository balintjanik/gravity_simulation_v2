#ifndef SETUPTYPE_H
#define SETUPTYPE_H

enum class PlacementType
{
    Fullscreen,
    Circular
};

// max radius of circle in case of circular setup
const int R = 400;

const double PI = 3.1415926535897932384626433832795028841971693993751058209749445923078164062;

enum class SpeedType
{
    Random,
    Angular,
    Zero,
    Central
};

#endif
