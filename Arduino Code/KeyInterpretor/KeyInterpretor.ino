//github.com/IAmFatAndLazy

//Pins your buttons/keys will be connected to on your board 
//can be increased/decreased as needed

int button1 = 2;
int button2 = 4;
int button3 = 5;
int button4 = 8;
int button5 = 10;
int button6 = 3;
int button7 = A5;
int button8 = A3;
int button9 = A2;
int button10 = A0;

//Time delay between sending another key press
int delayTime = 300;

void setup() {
  //sets pins as inputs will pullup resistor on
  pinMode(button1,INPUT_PULLUP);
  pinMode(button2,INPUT_PULLUP);
  pinMode(button3,INPUT_PULLUP);
  pinMode(button4,INPUT_PULLUP);
  pinMode(button5,INPUT_PULLUP);
  pinMode(button6,INPUT_PULLUP);
  pinMode(button7,INPUT_PULLUP);
  pinMode(button8,INPUT_PULLUP);
  pinMode(button9,INPUT_PULLUP);
  pinMode(button10,INPUT_PULLUP);

  //open serial connection
  Serial.begin(9600);
}

void loop() {
  // check each pin for if they have a button pressed and send the key over Serial
  //Yes this should be done cleaner but whatever
  
  if (digitalRead(button1) == LOW) {
      Serial.write("K1\n");
      delay(delayTime);
    }
   else if (digitalRead(button2) == LOW) {
      Serial.write("K2\n");
      delay(delayTime);
   }
   else if (digitalRead(button3) == LOW) {
      Serial.write("K3\n");
      delay(delayTime);
   }
   else if (digitalRead(button4) == LOW) {
      Serial.write("K4\n");
      delay(delayTime);
   }
   else if (digitalRead(button5) == LOW) {
      Serial.write("K5\n");
      delay(delayTime);
   }
   else if (digitalRead(button6) == LOW) {
      Serial.write("K6\n");
      delay(delayTime);
   }
   else if (digitalRead(button7) == LOW) {
      Serial.write("K7\n");
      delay(delayTime);
   }
   else if (digitalRead(button8) == LOW) {
      Serial.write("K8\n");
      delay(delayTime);
   }
   else if (digitalRead(button9) == LOW) {
      Serial.write("K9\n");
      delay(delayTime);
   }
   else if (digitalRead(button10) == LOW) {
      Serial.write("K10\n");
      delay(delayTime);
   }
}
