#include "coin.h"
#include "assets.h"

Coin::Coin(int x, int y) {
    _x = x;
    _y = y;       // Starting position (initially hidden)
    _startY = y;  // Store the initial pipe level
    _width = 8;  // Adjust for your sprite size
    _height = 11; // Adjust for your sprite size
}

void Coin::init() 
{
    _state = COIN1; // Start with the coin visible
    currentState = 0;
    //Locator::getDisplay()->fillRect(_x, _y, _width, _height, SKY_COLOR); // Clear flower area
}

void Coin::update() 
{
    unsigned long currentMillis = millis();
    const uint16_t* _sprite;
    if (currentMillis - _lastMillis >= 250) 
    {
        _lastMillis = currentMillis; // Update the lastMillis here to avoid repetition

        currentState = (currentState + 1) % 4; // Cycle through 0, 1, 2, 3

        // Set the corresponding state based on currentState
        switch (currentState) 
        {
            case 0: _sprite = COIN_1; break;
            case 1: _sprite = COIN_2; break;
            case 2: _sprite = COIN_3; break;
            case 3: _sprite = COIN_4; break;
        }

        // Clear old position and draw the new state
        Locator::getDisplay()->fillRect(_x, _y, _width, _height, SKY_COLOR);
        Locator::getDisplay()->drawRGBBitmap(_x, _y, _sprite, _width, _height);
    }
}

const char* Coin::name() 
{
  return "COIN";
}
