// Author: Batuto
// GitHub: github.com/batuto
// This code was designed using an Arduino Mega as reference.
// take this in mind when porting to another device.

// This program takes two 3-bit inputs and make simple operations with these inputs.
// An extra pin is used to handle the negative sign in the subtraction

int value_a, value_b;


void setup(){
  DDRA = 255;
  DDRB = 248;
  DDRG = 248;
  DDRF = 252;
pinMode(21, OUTPUT);
}

void loop(){
  value_a = int(PINB);  // The port B is used as first operand
  value_b = int(PING);  // The port G is used as second operand
  switch(int(PINF)){
    case 0:
        PORTA = value_a + value_b;  // Assignation of the addition operation
        break;
    case 1:
        if(value_a < value_b){
          PORTA = -(value_a - value_b);
          digitalWrite(21, HIGH);
      }  // Assignation of the subtraction --- Cases for negative and positive outputs
        else{
          PORTA = value_a - value_b;
          digitalWrite(21, LOW);
        }
        break;
    case 2:
        PORTA = value_a * value_b;  // Assignation of the multiplication
        break;
    case 3:
        PORTA = value_a / value_b;  // Assignation of the division
        break;
  }
}
