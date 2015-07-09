/* Sweeping
 * 
 * This program makes the light of the diodes sweep, and use four 
 * buttons to control the speed, pause and or invert the lights.  
 */

int leds[] = {11, 10, 9, 6, 5, 3};
int counter = 0;
int ledNr = 0;
int strength = 0;

void setup() {
  // Declare pins as output and make sure they are off
  for (int i;i<7;i++) {
    pinMode(leds[i], OUTPUT);
    digitalWrite(leds[i], LOW);
  }
}

void loop() {
  // Makes the leds pulse from right to left
  while (counter <= 255*6) {
    ledNr = getLedNr(counter);
    strength = getLedStrength(counter);
    analogWrite(leds[ledNr], strength);
    
    if (counter > 255) {
      analogWrite(leds[ledNr-1], 255-strength);
    }
    counter += 5;
    delay(10);
  }
  
  // Makes the leds pulse from left to right
  while (counter >= 0) {
    ledNr = getLedNr(counter);
    strength = getLedStrength(counter);
    if (counter > 255) {
      analogWrite(leds[ledNr-1], 255-strength);
    }
    
    analogWrite(leds[ledNr], strength);
    
    counter -= 5;
    delay(10);
  }
}

int getLedNr(int counter) {
  return counter/255;
}

int getLedStrength(int counter) {
  return counter%255;
}

