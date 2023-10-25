const int PIN_RED = 10;
const int PIN_GREEN = 11;
const int PIN_BLUE = 12;
int red;
int green;
int blue;

int incomingByte;      // a variable to read incoming serial data into


void setColor(int R, int G, int B){
analogWrite(PIN_RED, R);
analogWrite(PIN_GREEN, G);
analogWrite(PIN_BLUE, B);
  }

void setup() {
  // initialize serial communication:
  Serial.begin(9600);
  // initialize the LED pin as an output:
  pinMode(PIN_RED, OUTPUT);
  pinMode(PIN_GREEN, OUTPUT);
  pinMode(PIN_BLUE, OUTPUT);
}

void loop() {
  // see if there's incoming serial data:
  
  if (Serial.available() > 0) {
    // read the oldest byte in the serial buffer:
    incomingByte = Serial.read();
    // if it's a capital H (ASCII 72), turn on the LED:
    if (incomingByte == 'R') {
      setColor(255,0,0);
    }
    // if it's an L (ASCII 76) turn off the LED:
    if (incomingByte == 'G') {
      setColor(0,255,0);
    }

    if(incomingByte == 'B'){
      setColor(0,0,255);
      } 
    if (incomingByte == 'W'){
      setColor(0,0,0);
        }
  }
}
