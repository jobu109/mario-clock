# Mario Bros. Clock
************************************************************************

This is based off of jnthas original mario bros clock project. I have just modified/added some code to spruce things up a little for my own preferences. 

- removed the hill and bush objects
- added a pipe object
- adjusted cloud positioning
- added goomba sprite with animation
- added koopa sprite with animation
- added piranha sprite with animation
- added 2 coin sprites with animation
- added collision detection with animation betweeen mario landing and goomba squishing
- added collision detection from blocks to make koopa hide

*************************************************************************

Super Mario World on the SNES was probably one of the games my brother and I played the most in our lives. So the emotional connection with the plumbers starts there. The first games of the franchise, still on the NES, were revolutionary and represented a great relief for the gaming industry that was going through a bad phase in the first half of the 80's. This article guides you to create an animated Mario clock that can be a retro decorative object for any environment.

One-click firmware flashing is available on [https://jnthas.github.io/mariobros-clock/](https://jnthas.github.io/mariobros-clock/).

The complete tutorial can be seen on [Instructables](https://www.instructables.com/Mario-Bros-Clock/).

# Compiling with ESP-IDF
You can use the [official Esspressif IoT Development Framekwork (aka esp-idf)](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/) to build and upload this project to an ESP32 device, including the [ESP32-Trinity board](https://esp32trinity.com/).

### Install esp-idf
Follow the [Step By Step installation instructions](https://docs.espressif.com/projects/esp-idf/en/stable/esp32/get-started/#installation-step-by-step).

### Setup the environment variables
Follow the [instructions here](https://docs.espressif.com/projects/esp-idf/en/stable/esp32/get-started/#step-4-set-up-the-environment-variables).

### Clone and build this project
* `git clone --recurse-submodules https://github.com/jnthas/mariobros-clock.git`
* `idf.py reconfigure`
* `idf.py flash`
* `idf.py monitor`
