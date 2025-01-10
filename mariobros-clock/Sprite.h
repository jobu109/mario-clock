
#ifndef Sprite_h
#define Sprite_h

#include <Arduino.h>

class Sprite {

  protected:
    uint8_t _x;
    uint8_t _y;
    uint8_t _width;
    uint8_t _height;

  public:
    uint8_t get_x() const { return _x; }  // Getter method
    boolean collidedWith(Sprite* sprite);
    void logPosition();
    virtual const char* name();
};


#endif
