#include <LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);
const int switchPin = 6;
int switchState = 0;
int prevSwitchState = 0;
int reply;
 byte heart[8] = {
  0b00000,
  0b01010,
  0b11111,
  0b11111,
  0b11111,
  0b01110,
  0b00100,
  0b00000
};


byte smiley[8] = { // one cell is 8 height and 5 width
  0b00000,
  0b00000,
  0b01010,
  0b00000,
  0b00000,
  0b10001,
  0b01110,
  0b00000
};


byte frownie[8] = {
  0b00000,
  0b00000,
  0b01010,
  0b00000,
  0b00000,
  0b00000,
  0b01110,
  0b10001
};


byte armsDown[8] = {
  0b00100,
  0b01010,
  0b00100,
  0b00100,
  0b01110,
  0b10101,
  0b00100,
  0b01010
};
byte walking[8] = {
  0b00100,
  0b01010,
  0b00100,
  0b00100,
  0b01110,
  0b10101,
  0b01010,
  0b01001
};
byte walking[8] = {
  0b00100,
  0b01010,
  0b00100,
  0b00100,
  0b01110,
  0b10101,
  0b01010,
  0b01001
};


byte armsUp[8] = {
  0b00100,
  0b01010,
  0b00100,
  0b10101,
  0b01110,
  0b00100,
  0b00100,
  0b01010
};

void setup() {
  // custom characters for screen
 
// create a new character

  lcd.createChar(0, heart);

  // create a new character

  lcd.createChar(1, smiley);

  // create a new character

  lcd.createChar(2, frownie);

  // create a new character

  lcd.createChar(3, armsDown);

  // create a new character
  lcd.createChar(5, walking);

  lcd.createChar(4, armsUp);
  lcd.begin(16,2);
  pinMode(switchPin, INPUT);
  lcd.print("I ");

  lcd.write(byte(0)); // when calling lcd.write() '0' must be cast as a byte

  lcd.print(" Elina! ");

  lcd.write((byte)1);

  Serial.begin(9600);
}

void loop() {
  switchState = digitalRead(switchPin);
  Serial.println(switchState);
  if(switchState != prevSwitchState){

  
    if(switchState == LOW){
       // return randomn number between 0-7
      lcd.clear(); // clear screen
      lcd.setCursor(0,0);
      

      lcd.print("Hello World"); // has limit of 40 characters per line
      for (int positionCounter = 0; positionCounter<13; positionCounter++){
        delay(300);
        lcd.scrollDisplayLeft();

        
      }
      for (int positionCounter = 0; positionCounter < 29; positionCounter++) {

        // scroll one position right:

        lcd.scrollDisplayRight();

        // wait a bit:

        delay(300);

      }
      for (int positionCounter = 0; positionCounter < 16; positionCounter++) {

    // scroll one position left:
    lcd.scrollDisplayLeft();
    // wait a bit:
    delay(150);

  }


  // delay at the end of the full loop:

  delay(2000);
  lcd.setCursor(4, 1);

  // draw the little man, arms down:

  lcd.write(3);

  delay(1000);

  lcd.setCursor(4, 1);

  // draw him arms up:

  lcd.write(4);
  delay(500);
  lcd.write(5);
    }
    
  }
  prevSwitchState = switchState;
}
