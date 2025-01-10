
#include "Clockface.h"
#include "piranha.h"
#include "goomba.h"
#include "koopa.h"
#include "mario.h"
#include "object.h"
#include "coin.h"

extern Mario mario;

EventBus eventBus;

const char* FORMAT_TWO_DIGITS = "%02d";

// Graphical
Tile ground(GROUND, 8, 8); 

//Object bush(BUSH, 13, 15);
Object pipeObj(PIPE, 13, 15);
Object cloud1(CLOUD1, 13, 12);
Object cloud2(CLOUD2, 13, 12);
//Object hill(HILL, 20, 22);

Mario mario(30, 40);
Block hourBlock(13, 14);
Block minuteBlock(32, 14);
Piranha piranha(52, 32);
Goomba goomba(2,43);
Koopa koopa(11,1);
Coin coin1(2,6);
Coin coin2(54,17);

unsigned long lastMillis = 0;


Clockface::Clockface(Adafruit_GFX* display) {
  _display = display;

  Locator::provide(display);
  Locator::provide(&eventBus);
}

void Clockface::setup(CWDateTime *dateTime) {
  _dateTime = dateTime;

  Locator::getDisplay()->setFont(&Super_Mario_Bros__24pt7b);
  Locator::getDisplay()->fillRect(0, 0, 64, 64, SKY_COLOR);

  ground.fillRow(DISPLAY_HEIGHT - ground._height);

  pipeObj.draw(50, 41);
 // hill.draw(0, 34);
  cloud1.draw(0, 28);
  cloud2.draw(51, 2);

  updateTime();

  koopa.init();
  hourBlock.init();
  minuteBlock.init();
  goomba.init();
  mario.init();  // Mario initialized here
  piranha.init();
  mario.jump();
  coin1.init();
  coin2.init();
}


void Clockface::update() 
{
  coin1.update();
  coin2.update();
  hourBlock.update();
  minuteBlock.update();
  mario.update();  // Ensure Mario is always updated
  piranha.update();
  goomba.update();
  koopa.update();

  if (_dateTime->getSecond() == 0 && millis() - lastMillis > 1000) {
    mario.jump();  // Only make Mario jump on an event
    updateTime();
    lastMillis = millis();

    Serial.println(_dateTime->getFormattedTime());
  }
}



void Clockface::externalEvent(int type) {
  if (type == 0) {  //TODO create an enum
    mario.jump();
    updateTime();
  }
}

void Clockface::updateTime() {
  hourBlock.setText(String(_dateTime->getHour()));
  minuteBlock.setText(String(_dateTime->getMinute(FORMAT_TWO_DIGITS)));
}
