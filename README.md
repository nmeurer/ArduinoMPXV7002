# ArduinoMPXV7002

This sketch reads the voltage level of an MPXV7002 pressure difference sensor and converts it to pascal (Pa).
The calculation may not be 100% accurate due to various factors. You can improve the accuracy by using the MPXV7002
with it's recommended components (e.g. the ceramic capacitors mentioned in it's datasheet) and taking multiple measurements
to calculate a more percise average.
Remember that this sensor requires a 5V input! Using a 1:2 voltage divider will make this work properly with 3.3V-Boards!
Released under the MIT license 2020 by Noah Meurer
http://nmeurer.de
