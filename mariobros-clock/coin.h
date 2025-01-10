#ifndef Coin_h
#define Coin_h

#include "Sprite.h"
#include "Locator.h"

class Coin : public Sprite {
private:
    enum State { COIN1, COIN2, COIN3, COIN4 };
    State _state = COIN1;

    unsigned long _lastMillis = 0;
    int currentState = 0;
    int _startY;

public:
    Coin(int x, int y);
    void init();
    void update();
    const char* name();  // Add this declaration
};

#endif
