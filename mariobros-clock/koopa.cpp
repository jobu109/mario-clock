#include "koopa.h"
#include "assets.h"
#include "block.h"  // Ensure Block's class is accessible

extern Block hourBlock;
extern Block minuteBlock;   // Reference to the block instances

Koopa::Koopa(int x, int y) {
    _x = x;
    _y = y;       // Starting position
    _startY = y;  // Store the initial position
    _width = 10;  // Adjust for your sprite size
    _height = 13; // Adjust for your sprite size
    _state = RIGHT;  // Start moving right
}

void Koopa::init() {
    Locator::getDisplay()->drawRGBBitmap(_x, _y, KOOPA_RIGHT_OPEN, _width, _height);
}

void Koopa::update() 
{
    unsigned long currentMillis = millis();
    unsigned long currentSecond = millis() / 1000;

    if (currentMillis - _lastMillis >= 200) 
    {
        Locator::getDisplay()->fillRect(_x, _y, _width, _height, SKY_COLOR);
        currentState = !currentState;

        if (_state == HIDDEN) 
        {
            Locator::getDisplay()->drawRGBBitmap(_x, _y, KOOPA_HIDE, _width, _height);
            // Stay hidden for 3 seconds
            if (currentSecond - _lastSecond < 3) {
                Locator::getDisplay()->drawRGBBitmap(_x, _y, KOOPA_HIDE, _width, _height);
                _lastMillis = currentMillis;  // Prevent further updates in this period
                return;
            }

            // After 3 seconds, start animation sequence
            if (currentSecond - _lastSecond == 4) {
                Locator::getDisplay()->drawRGBBitmap(_x, _y, KOOPA_RIGHT_OPEN, _width, _height);
            } 
            else if (currentSecond - _lastSecond == 5) {
                Locator::getDisplay()->drawRGBBitmap(_x, _y, KOOPA_LEFT_OPEN, _width, _height);
            } 
            else if (currentSecond - _lastSecond == 6) {
                Locator::getDisplay()->drawRGBBitmap(_x, _y, KOOPA_RIGHT_OPEN, _width, _height);
            } 
            else if (currentSecond - _lastSecond == 7) {
                Locator::getDisplay()->drawRGBBitmap(_x, _y, KOOPA_LEFT_OPEN, _width, _height);
                _state = RIGHT;  // Return to normal movement
                _lastSecond = currentSecond;  // Reset for future use
            }

            _lastMillis = currentMillis;  // Update lastMillis for smooth timing
            return;
        }

        // Movement logic for RIGHT and LEFT states
        if (_state == RIGHT) {
            _x += _movePace;
            Locator::getDisplay()->drawRGBBitmap(_x, _y, (currentState) ? KOOPA_RIGHT_OPEN : KOOPA_RIGHT_CLOSED,_width, _height);
           // Locator::getDisplay()->drawRGBBitmap(_x, _y, KOOPA_RIGHT, _width, _height);

            if (collidedWith(&minuteBlock) || collidedWith(&hourBlock)) {
                _state = HIDDEN;
                _lastSecond = currentSecond;  // Start hidden timer
                Locator::getDisplay()->drawRGBBitmap(_x, _y, KOOPA_HIDE, _width, _height);
            } else if (_x >= hourBlock.get_x() + minuteBlock.get_x() - 4) {
                _state = LEFT;
            }
        } 
        else if (_state == LEFT) {
            _x -= _movePace;
            Locator::getDisplay()->drawRGBBitmap(_x, _y, (currentState) ? KOOPA_LEFT_OPEN : KOOPA_LEFT_CLOSED,_width, _height);
           // Locator::getDisplay()->drawRGBBitmap(_x, _y, KOOPA_LEFT, _width, _height);

            if (collidedWith(&minuteBlock) || collidedWith(&hourBlock)) {
                _state = HIDDEN;
                _lastSecond = currentSecond;  // Start hidden timer
                Locator::getDisplay()->drawRGBBitmap(_x, _y, KOOPA_HIDE, _width, _height);
            } else if (_x <= offset) {
                _state = RIGHT;
            }
        }

        _lastMillis = currentMillis;  // Update movement timer
    }
}



const char* Koopa::name() {
    return "KOOPA";
}