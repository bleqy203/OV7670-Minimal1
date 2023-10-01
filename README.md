# OV7670-Minimal1
This arduino code controls the OV7670 camera module with probably least amount of code. It outputs in Serial monitor the pixel data.
I used Arduino nano. It is best used with Serial Plotter. The output is in raw bits so additional conversion may be required.

You will need 1 x 4.7 Kohm and 3 x 10Kohm resistors

Conections:  
Camera pin - Arduino pin
        d0 A0  
        d1 A1
        d2 A2
        d3 A3
        SCL A5    connect: A5 - 10K - 3.3
        SDA A4    connect: A4 - 10K - 3.3
        d4 4
        d5 5
        d6 6
        d7 7
        pckl 12
        xckl 3 ; sometimes is mclk
        VS 2  ; voltage divider is needed. GND - 10K - VS - 4,7K - pin2
        3.3 3.3
        RST 3.3
        GND GND
        PWDN GND
             
