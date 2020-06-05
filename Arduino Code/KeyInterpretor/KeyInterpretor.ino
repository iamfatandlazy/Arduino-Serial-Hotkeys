//github.com/IAmFatAndLazy

//adjust these variables to suit your configuration
//number of buttons in the array
const int num_buttons = 10;
//actual pins of each button
const int buttons[num_buttons] = {2,4,5,8,10,3,A5,A3,A2,A0};

void setup() {
  // set all buttons to inputs with pullup
  for (int i=0;i<num_buttons;i++) {
     pinMode(buttons[i],INPUT_PULLUP);
  }
  //begins Serial connection
  Serial.begin(9600);
}

void loop() {
//loop through each button checking if its set low (pressed)
for (int i=0;i<num_buttons;i++) {
     if (digitalRead(buttons[i])==LOW) {
      //if pressed, write out which key is pressed to the serial connection
      String outputString = String("K")+String(i+1)+String("\n");
      Serial.write(outputString.c_str());
      delay(300);
     }
  }
}
