#ifndef Mario_h
#define Mario_h


#include "Game.h"
#include "Locator.h"
#include "EventBus.h"
#include "assets.h"


const uint8_t MARIO_PACE = 3;
const uint8_t MARIO_JUMP_HEIGHT = 14;


class Mario: public Sprite, public EventTask {
  private:

    enum State {
      IDLE,
      WALKING,
      JUMPING
    };

    Direction direction;

    int _lastX;
    int _lastY;

    const unsigned short* _sprite;
    unsigned long lastMillis = 0;
    State _state = IDLE; 
    State _lastState = IDLE; 
    
    void idle();

  public:
    enum PublicState {
        PUBLIC_IDLE,
        PUBLIC_WALKING,
        PUBLIC_JUMPING
    };
    Mario(int x, int y);
    PublicState getState() const { return static_cast<PublicState>(_state); }
    //bool isJumping() const { return _state == JUMPING; }  // Public method to check state
    void init();
    void move(Direction dir, int times);
    void jump();
    void update();
    const char* name();
    void execute(EventType event, Sprite* caller);
    
};


#endif