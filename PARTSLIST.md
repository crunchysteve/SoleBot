## Essential Parts and Tools
1. Microcontroller (main board, one of),
  - Arduino Uno, Mini or Nano for basic, single-beater/instrument setup,
  - Arduino Mega 2560 or 3rd party [2560 Mega Pro Mini](https://www.aliexpress.com/item/32904052177.html) for more advanced kit design,
2. [AOD4184 MOSFETS](https://www.aosmd.com/res/datasheets/AOD4184A.pdf) or [MOSFET modules](https://lonelybinary.com/products/aod4184-40v-50a-mosfet-mos-module) (one per solenoid),
3. [Adafruit MIDI Featherwing Kit](https://learn.adafruit.com/adafruit-midi-featherwing/overview): At this stage, I'm going to just use an off-the-shelf, external Serial-MIDI interface and the one that's available to use without headers pre-soldered, allowing for wiring as an external module, is this kit. It's designed for 3V, but maybe feed it from the 3V pin of the Nano on the motherboard or put 3 rectifier diodes in series between your 5V supply and the MIDI Featherwing 3V pin. The kit comes with DIN midi jacks and header pins, but has holes for adding 3.5mm TRS jacks in type A configuration. This is the pinout diagram...
![Adafruit MIDI Feather wing](./immages/adafruit_products_MIDI_FW_pinouts_bottom.jpg)
(Note: once I have a working prototype, I'll start refining the motherboard to have its own built-in MIDI interface.)
4. Pretty much any 12v solenoid of any force rating of 20N or more, such as the [JF-0826B](https://www.aliexpress.com/item/32847809022.html At least one per drum and at least 3 for the hi-hats, 1 or 2 for beaters, 2 for lifting.), the 60N JF-1250B has been added to solenoids.scad to use as a template in design models. Hi-hat closing solenoid probably requires the JF-1250B at a minimum,
4. 24v, 5A (for MOSFETs and solenoids) and 5v, 1A (for microcontroller) power supplies,
6. Hookup wire, light duty for microcontroller to MOSFETs, heavy duty from MOSFETS to solenoids,
7. Usual assortment of electronics bench tools, such as,
  - Breadboard,
  - Soldering station, solder and wet sponge for cleaning the iron's tip,
  - circuitboard design software (such as Fritzing),
  - multimeter to measure voltages at MOSFET outputs,
  - some sort of oscilliscope to check micro output waveforms.

As always, this is an open project. If you can see a better way to do any part of this, post a feature request in the discussions, raise an issue, or offer your code with a pull request.