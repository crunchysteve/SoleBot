## Roadmap

1. Now I'm satisfied with solenoids as beater drivers, it's time to knock my repo (and [Thingiverse entry](https://www.thingiverse.com/thing:6771931) ) for the project into shape. **done** (As much as these things ever are, anyway.)
  a  Complete a basic Arduino Uno test device with a single beater per instrument running [testTool.ino](https://github.com/crunchysteve/SoleBot/blob/main/code/testTool/) **done**
2. Begin development of a MIDI operated Uno version, still with single beaters.
   a  Initial MIDI driver Arduino code available. This is the primary working C code for the control board. **Working, in progress**
   b  Expand and generalise setup of MIDI control firmware to Arduino Mega or [Mega Pro Mini](https://www.aliexpress.com/item/32904052177.html) board for multiple beaters per instrument and greater nuance. (eg left stick, right stick.)
3. Begin development of a controller and settings memory board using [ESP32-2432S028R "Cheap Yellow Display"](https://github.com/witnessmenow/ESP32-Cheap-Yellow-Display) module and [LVGL GUI library](https://github.com/lvgl/lvgl).
4. If not burned out by then, develop robotic bass and...
5. ...robotic keys player.
6. Make more music while maintaining a more relaxed development cycle
