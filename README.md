Arduino program created with PlatformIO for my sim racing setup. It handles all 3 devices at once - one board to rule them all ;)

- Adapter for Logitech H-Shifter [Idea + base Arduino sketch](https://www.youtube.com/watch?v=dLpWEu8kCec)
- Custom Handbrake DIY [Idea + base Ardunio sketch](https://www.youtube.com/watch?v=dLpWEu8kCec)
- Custom sequential shifter [Base model](https://www.thingiverse.com/thing:2924658), [Base Arduino sketch](https://www.thingiverse.com/thing:4557771)

Program uses [ArduinoJoystickLibrary](https://github.com/MHeironimus/ArduinoJoystickLibrary), so just ATmega32u4 boards are supported (tested only with Ardunio Leonardo for now by myself).

Base sketches have been modified (simple pure C code replaced by class-based C++), to be easier to manage and modify.
It seems to work pretty nice.

All mounts and some parts had also been modified to meet my needs and printed then by my fearless Ender 3.

![Devices](https://raw.githubusercontent.com/szczeliniak/sim-racing-devices/readme/readme.jpg)
