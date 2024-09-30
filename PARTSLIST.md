## Essential Parts and Tools
1. Microcontroller (main board, one of),
  - Arduino Uno, Mini or Nano for basic, single-beater/instrument setup,
  - Arduino Mega 2560 or 3rd party [2560 Mega Pro Mini](https://www.aliexpress.com/item/32904052177.html) for more advanced kit design,
2. [AOD4184 MOSFETS](https://www.aosmd.com/res/datasheets/AOD4184A.pdf) or [MOSFET modules](https://lonelybinary.com/products/aod4184-40v-50a-mosfet-mos-module) (one per solenoid),
3. Pretty much any 12v solenoid of any force rating 20N or more, such as the [JF-0826B](https://www.aliexpress.com/item/32847809022.html At least one per drum and at least 3 for the hi-hats, 1 or 2 for beaters, 2 for lifting.), the 60N JF-1250B has been added to solenoids.scad to use as a template in design models,
4. 24v, 5A (for MOSFETs and solenoids) and 5v, 1A (for microcontroller) power supplies,
5. Hookup wire, light duty for microcontroller to MOSFETs, heavy duty from MOSFETS to solenoids,
6. Usual assortment of electronics bench tools, such as,
  - Breadboard,
  - Soldering station, solder and wet sponge for cleaning the iron's tip,
  - circuitboard design software (such as Fritzing),
  - multimeter to measure voltages at MOSFET outputs,
  - some sort of oscilliscope to check micro output waveforms.
