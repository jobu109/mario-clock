#ifndef Piranha_h
#define Piranha_h

#include "Sprite.h"
#include "Locator.h"

class Piranha : public Sprite {
private:
    enum State { HIDDEN, GROWING, AT_TOP, RETRACTING };
    State _state = HIDDEN;

    unsigned long _lastMillis = 0;
    unsigned long _pauseDuration = 1500; // Pause at the top for 1 second
    int currentState = 0;
    int _movePace = 2;  // Moves 2 pixels per step
    int _maxHeight = 6; // Maximum distance the Piranha "grows" from its starting position
    int _startY;

public:
    Piranha(int x, int y);
    void init();
    void update();
    const char* name();  // Add this declaration
};

#endif
