#ifndef Goomba_h
#define Goomba_h

#include "Sprite.h"
#include "Locator.h"

class Goomba : public Sprite {
private:
    unsigned long _lastMillis = 0;
    unsigned long _lastSecond = 0;
    unsigned long _pauseDuration = 3000; // Pause at the top for 1 second
    bool currentState = false;
    int _movePace = 1;  // Moves 1 pixel per step
    int _startY;

public:
    Goomba(int x, int y);
    enum State { LEFT,RIGHT,SMASHED };
    State _state = LEFT;
    void init();
    void update();
    void setState(State state);
    const char* name();  // Add this declaration
};

#endif
