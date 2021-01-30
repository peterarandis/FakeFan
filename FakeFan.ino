/*
 * Peter Hansson 2021-01-30
 * Frequency double to lower fan speed
 * With treshold where id will bypas fan speed as normal at high load
 * Uses ATtiny85
 */
 
#define IN 4
#define UT 1

unsigned long tid,t,changed;
unsigned long z,x,last_len;
bool dubbla_fq = true;
bool i;

void setup() {
 
  pinMode (1, OUTPUT);   // Pin 5 To motherboard
  pinMode (4, INPUT);    // Pin 3 from FAN pulse output
}

void loop() {
  
  tid = millis(); // measure period time

  if (dubbla_fq) { // Doubling the frequency to make MB thinks fan spins faster 
      z=0;
      pinMode(UT, LOW);
      while (!digitalRead(IN)) {
          z++;  // Mät puls längd
          if (z>last_len) pinMode(UT, HIGH);
          }

      pinMode(UT, LOW);
      z=0;
      while (digitalRead(IN)) {
          z++;  // Mät puls längd
          if (z>last_len) pinMode(UT, HIGH);
        }
      
     }
  else
     {
      // Bypass, Non dubling, FAN speed = MB Speed
      pinMode(UT, HIGH);  while (digitalRead(IN)) {}
      pinMode(UT, LOW);   while (!digitalRead(IN)){}
     }
  
  last_len=z/2; // Calc for freq doubling

  t = millis()-tid; // ms for one period
  
  if (millis() - changed > 1000 && dubbla_fq == true  && t < 12 ) {dubbla_fq = false;changed = millis(); } // Treshold to switch to bypass (ca80Hz)
  if (millis() - changed > 1000 && dubbla_fq == false && t > 12 ) {dubbla_fq = true;changed = millis(); } // Treshold to switch to Freq doubling. (ca80Hz)


  
   
}
