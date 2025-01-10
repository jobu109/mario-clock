#include "goomba.h"
#include "assets.h"
#include "Mario.h"  // Ensure Mario's class is accessible

extern Mario mario;  // Reference to the Mario instance

Goomba::Goomba(int x, int y) {
    _x = x;
    _y = y;       // Starting position
    _startY = y;  // Store the initial position
    _width = 13;  // Adjust for your sprite size
    _height = 13; // Adjust for your sprite size
    _state = RIGHT;  // Start moving right
}

void Goomba::init() {
    Locator::getDisplay()->drawRGBBitmap(_x, _y, GOOMBA_RIGHT, _width, _height);
}

void Goomba::setState(State state)
{
  _state = state;
}

void Goomba::update() 
{
    unsigned long currentMillis = millis();

    if (_state == SMASHED) 
    {
        // Stay in SMASHED state for ~4 seconds
        if (currentMillis - _lastMillis < 4237)  // Use 5000 ms instead of seconds
        {
            Locator::getDisplay()->drawRGBBitmap(_x, _y, GOOMBA_SMASH, _width, _height);
            return;  // Exit early to maintain the smashed state
        } 
        else 
        {
            _state = LEFT;  // After 4 seconds, revert to LEFT
        }
    }

    // Movement and animation logic
    if (currentMillis - _lastMillis >= 213) 
    {
        currentState = !currentState;  // Toggle animation state

        // Clear old position
        Locator::getDisplay()->fillRect(_x, _y, _width, _height, SKY_COLOR);

        // Move Goomba
        if (_state == RIGHT) 
        {
            _x += _movePace;
            if (collidedWith(&mario)) 
            {
                if (mario.getState() == Mario::PUBLIC_JUMPING)
                {
                    _state = SMASHED;  // Set state to SMASHED
                    _lastMillis = currentMillis;  // Reset the timer for the SMASHED state
                    return;
                } 
                else
                {
                    _state = LEFT;  
                }
            }
        } 
        else if (_state == LEFT) 
        {
            _x -= _movePace;
            if (_x <= 0) 
            {
                _state = RIGHT;
            }
        }

        // Draw the Goomba at the new position
        Locator::getDisplay()->drawRGBBitmap(
            _x, _y, 
            (currentState) ? GOOMBA_RIGHT : GOOMBA_LEFT, 
            _width, _height
        );

        _lastMillis = currentMillis;  // Update the lastMillis
    }
}


const char* Goomba::name() {
    return "GOOMBA";
}
