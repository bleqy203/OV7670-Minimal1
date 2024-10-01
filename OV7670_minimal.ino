//INPUTS
#define  d0 A0    //pixel data pins
#define  d1 A1
#define  d2 A2
#define  d3 A3
#define  d4 4
#define  d5 5
#define  d6 6
#define  d7 7
#define  vsync 2    //new frame
#define  pckl 12    //Pixel clock is necessary for knowing the exact time when to read pixel data.
//OUTPUTS
#define  xckl 3     //XCLK is the input clock that makes the camera run.

#include<Wire.h>;
int c = 0;
int r[11];

void setup() {
  Serial.begin(115200); Wire.begin();
//  pinMode(d0, INPUT); pinMode(d1, INPUT);  pinMode(d2, INPUT); pinMode(d3, INPUT);  pinMode(vsync, INPUT);
//  pinMode(d4, INPUT); pinMode(d5, INPUT);  pinMode(d6, INPUT); pinMode(d7, INPUT); pinMode(pckl, INPUT);
//  pinMode(xckl, OUTPUT);
  DDRD = B00001010;
  DDRB = B01000000;
  DDRC = B00110000;
  
  TCCR2A = _BV(COM2B1) | _BV(WGM21) | _BV(WGM20); //set timer on pin3
  TCCR2B = _BV(WGM22) | _BV(CS20);
  OCR2A = 1;
  OCR2B = 0; delay(100);

  wr(0x12, 0x80); delay(10);    // Perform a soft reset
  wr(0x12, 0x00); delay(10);    // Bring out of reset
  wr(0x12, 0x0C); delay(10);    // selecting mode RGB and format QCIF

}

void loop() {
  r[0] = digitalRead(d0); r[1] = digitalRead(d1); r[2] = digitalRead(d2);  r[3] = digitalRead(d3);

  r[4] = digitalRead(d4);  r[5] = digitalRead(d5); r[6] = digitalRead(d6); r[7] = digitalRead(d7);

  r[8] = digitalRead(vsync); r[9] = digitalRead(pckl);

  // for (int i = 0; i < 8; i++)
  for (int i = 0; i < 10; i++)
  {
    Serial.print(r[i] + i); Serial.print(",");
  }
  Serial.println();
}
bool wr(uint8_t addr, uint8_t val) {    //write camera register
  Wire.beginTransmission(0x21);         //0x21 is camera adress
  Wire.write(addr);
  Wire.write(val);
  return Wire.endTransmission();        // if return value is 0 => everything is OK
}
