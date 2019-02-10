# Simple-Arduino-Frequency-Counter
The simplest Frequency Counter for the Arduino

I needed a frquency counter for settng up 555 timer chips,
so I came up with the simplest, fairly accurate method of
acheiving this.

This has just one variable and two lines of control code.

You can connect pin 3 of the 555 timer or any other positive
output, as long as you limit the potential difference to between
0.5 - 5 volts, to the Arduino interrupt pin D2. And gnd to gnd,
of course.

I have tested this up to about 150 kHz, using a sample time of
1000 milliseconds, but if you want a more accurate results at
low frquencies, then you will have to increase the sample times
by factors of 10 for simplicity.

At 160 kHz, the loop code becomes corrupted and as I have kept
the loop code to the bare minimum, if you add more code to the
loop the corruption threshold will lower.
