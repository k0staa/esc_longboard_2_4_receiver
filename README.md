# Arduino with ESC and simple toy 2,4Ghz receiver

A simple Arduino code which I use to handle the signal from the 2.4 Ghz receiver pulled out of the toy to control the signal flowing to the ESC controlling the operation of the engine connected to the Longboard.
The receiver cannot be directly connected to the ESC due to signal incompatibility.
I attach the version for Arduino Uno and Atmega8.
Because I use power from ESC which is quite high (>5V) and destabilizes the 2.4 GHz receiver, I added a few LEDs that stabilize the work.
## Dependencies
Project is very simple and uses following dependencies:
 - Servo

## Pictures
![Alt text](Photos/IMG_20190907_185642.jpg?raw=true "Schema photo 1")
![Alt text](Photos/IMG_20190907_185659.jpg?raw=true "Schema photo 2")
![Alt text](Photos/IMG_20190907_185711.jpg?raw=true "Schema photo 3")
![Alt text](Photos/receiver_proc_schema.png?raw=true "Receiver processor signal schema")
![Alt text](Photos/IMG_20191005_192845.jpg?raw=true "Schema with Atmega8")
## Licence

Project uses a MIT licence .

MIT License

Copyright (c) 2019 Michal Kostewicz

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
