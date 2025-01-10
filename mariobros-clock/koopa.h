#ifndef Koopa_h
#define Koopa_h

#include "Sprite.h"
#include "Locator.h"

class Koopa : public Sprite {
private:
    enum State { LEFT,RIGHT,HIDDEN };
    State _state = RIGHT;

    unsigned long _lastMillis = 0;
    unsigned long _lastSecond = 0;
    int offset = 13;
    unsigned long _pauseDuration = 1000; // Pause at the top for 1 second
    bool currentState = false;
    int _movePace = 1;  // Moves 1 pixel per step
    //int _maxMove = 6; // Maximum distance the flower "grows" from its starting position
    int _startY;

public:
    Koopa(int x, int y);
    void init();
    void update();
    const char* name();  // Add this declaration
};

#endif
