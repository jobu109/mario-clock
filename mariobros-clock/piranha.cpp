#include "piranha.h"
#include "assets.h"
Piranha::Piranha(int x, int y) {
    _x = x;
    _y = y;       // Starting position (initially hidden)
    _startY = y;  // Store the initial pipe level
    _width = 9;  // Adjust for your sprite size
    _height = 9; // Adjust for your sprite size
}

void Piranha::init() {
    _state = HIDDEN; // Start with the Piranha hidden
    currentState = 0;
}

void Piranha::update() 
{
    unsigned long currentMillis = millis();
    if (_state == HIDDEN) 
    {
        // Start growing after initialization
          if (currentMillis - _lastMillis >= _pauseDuration) 
          { // Pause for _pauseDuration seconds
            _state = GROWING;
          }
    }

    if (_state == GROWING) 
    {
       // { // Keep moving up until it reaches the max height
            if (currentMillis - _lastMillis >= 200)
             { // Update every 1000 ms (1 seconds)
                currentState += 1;
                _lastMillis = currentMillis; // Update the lastMillis
                Locator::getDisplay()->fillRect(_x, _y, _width, _height, SKY_COLOR); // Clear old position
                if (currentState == 1)
                {
                  Locator::getDisplay()->drawRGBBitmap(_x, _y+6, PIRANHA_SPRITE_TOP, _width, 3);
                }
                if (currentState == 2)
                { 
                  Locator::getDisplay()->drawRGBBitmap(_x, _y+3, PIRANHA_SPRITE_MIDDLE, _width, 6);
                } 
                if (currentState == 3)
                {
                 Locator::getDisplay()->drawRGBBitmap(_x, _y, PIRANHA_SPRITE, _width, _height); 
                } 
                if (currentState ==4)
                {
                  Locator::getDisplay()->drawRGBBitmap(_x, _y, PIRANHA_SPRITE_OPEN, _width, _height);
                }
                if (currentState ==5) 
                { 
                  Locator::getDisplay()->drawRGBBitmap(_x, _y, PIRANHA_SPRITE, _width, _height);
                }
                if (currentState ==6)
                {
                  Locator::getDisplay()->drawRGBBitmap(_x, _y, PIRANHA_SPRITE_OPEN, _width, _height);
                }
                if (currentState ==7)
                {
                  Locator::getDisplay()->drawRGBBitmap(_x, _y, PIRANHA_SPRITE, _width, _height);
                }
                if (currentState ==8)
                {
                  Locator::getDisplay()->drawRGBBitmap(_x, _y, PIRANHA_SPRITE_OPEN, _width, _height);
                }
                if (currentState ==9)
                {
                  Locator::getDisplay()->drawRGBBitmap(_x, _y, PIRANHA_SPRITE, _width, _height);
                  _state = AT_TOP;
                }
                  
            }
    }

    if (_state == AT_TOP) 
    {

        if (currentMillis - _lastMillis >= _pauseDuration) { // Pause for _pauseDuration seconds
            // Start retracting after pausing
            _state = RETRACTING;
            currentState = 4;
        }
    }

    if (_state == RETRACTING) 
    {
       // { // Keep moving down until it reaches the ground
            if (currentMillis - _lastMillis >= 200) 
            { // Update every 100 ms (0.1 seconds)
                currentState -= 1;
                Locator::getDisplay()->fillRect(_x, _y, _width, _height, SKY_COLOR); // Clear old position
                _lastMillis = currentMillis; // Update the lastMillis
                if (currentState == 3)
                {
                 Locator::getDisplay()->drawRGBBitmap(_x, _y, PIRANHA_SPRITE, _width, _height); 
                } 
                if (currentState == 2)
                { 
                  Locator::getDisplay()->drawRGBBitmap(_x, _y+3, PIRANHA_SPRITE_MIDDLE, _width, 6);
                } 
                if (currentState == 1)
                {
                  Locator::getDisplay()->drawRGBBitmap(_x, _y+6, PIRANHA_SPRITE_TOP, _width, 3);
                }
                if (currentState == 0)
                {
                  _state = HIDDEN;

                }
        }
    }
}

const char* Piranha::name() 
{
  return "Piranha";
}
