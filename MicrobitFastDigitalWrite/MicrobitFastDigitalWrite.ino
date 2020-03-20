const int COL1 = 3;     // Column #1 control
const int LED = 26;     // 'row 1' led

// >10x faster than original nrf functions

void setup() 
{  
  Serial.begin(9600);
  
  Serial.println("Benchmark running (Please wait)");

  // because the LEDs are multiplexed, we must ground the opposite side of the LED
  pinMode(COL1, OUTPUT);
  digitalWrite(COL1, LOW); 
   
  pinMode(LED, OUTPUT);   

  unsigned long start,stop;

  unsigned short loopCount = 0xffff;

  float std,fast;
  
  start = micros();
  for(unsigned short i=0; i<loopCount; i++)
  {
    // Unroll 128x to avoid loop cost
    
    fastDigitalWrite(LED, LOW );
    fastDigitalWrite(LED, HIGH );
    fastDigitalWrite(LED, LOW );
    fastDigitalWrite(LED, HIGH );
    fastDigitalWrite(LED, LOW );
    fastDigitalWrite(LED, HIGH );
    fastDigitalWrite(LED, LOW );
    fastDigitalWrite(LED, HIGH );

    fastDigitalWrite(LED, LOW );
    fastDigitalWrite(LED, HIGH );
    fastDigitalWrite(LED, LOW );
    fastDigitalWrite(LED, HIGH );
    fastDigitalWrite(LED, LOW );
    fastDigitalWrite(LED, HIGH );
    fastDigitalWrite(LED, LOW );
    fastDigitalWrite(LED, HIGH );

    fastDigitalWrite(LED, LOW );
    fastDigitalWrite(LED, HIGH );
    fastDigitalWrite(LED, LOW );
    fastDigitalWrite(LED, HIGH );
    fastDigitalWrite(LED, LOW );
    fastDigitalWrite(LED, HIGH );
    fastDigitalWrite(LED, LOW );
    fastDigitalWrite(LED, HIGH );

    fastDigitalWrite(LED, LOW );
    fastDigitalWrite(LED, HIGH );
    fastDigitalWrite(LED, LOW );
    fastDigitalWrite(LED, HIGH );
    fastDigitalWrite(LED, LOW );
    fastDigitalWrite(LED, HIGH );
    fastDigitalWrite(LED, LOW );
    fastDigitalWrite(LED, HIGH );

    fastDigitalWrite(LED, LOW );
    fastDigitalWrite(LED, HIGH );
    fastDigitalWrite(LED, LOW );
    fastDigitalWrite(LED, HIGH );
    fastDigitalWrite(LED, LOW );
    fastDigitalWrite(LED, HIGH );
    fastDigitalWrite(LED, LOW );
    fastDigitalWrite(LED, HIGH );

    fastDigitalWrite(LED, LOW );
    fastDigitalWrite(LED, HIGH );
    fastDigitalWrite(LED, LOW );
    fastDigitalWrite(LED, HIGH );
    fastDigitalWrite(LED, LOW );
    fastDigitalWrite(LED, HIGH );
    fastDigitalWrite(LED, LOW );
    fastDigitalWrite(LED, HIGH );

    fastDigitalWrite(LED, LOW );
    fastDigitalWrite(LED, HIGH );
    fastDigitalWrite(LED, LOW );
    fastDigitalWrite(LED, HIGH );
    fastDigitalWrite(LED, LOW );
    fastDigitalWrite(LED, HIGH );
    fastDigitalWrite(LED, LOW );
    fastDigitalWrite(LED, HIGH );

    fastDigitalWrite(LED, LOW );
    fastDigitalWrite(LED, HIGH );
    fastDigitalWrite(LED, LOW );
    fastDigitalWrite(LED, HIGH );
    fastDigitalWrite(LED, LOW );
    fastDigitalWrite(LED, HIGH );
    fastDigitalWrite(LED, LOW );
    fastDigitalWrite(LED, HIGH );

    fastDigitalWrite(LED, LOW );
    fastDigitalWrite(LED, HIGH );
    fastDigitalWrite(LED, LOW );
    fastDigitalWrite(LED, HIGH );
    fastDigitalWrite(LED, LOW );
    fastDigitalWrite(LED, HIGH );
    fastDigitalWrite(LED, LOW );
    fastDigitalWrite(LED, HIGH );

    fastDigitalWrite(LED, LOW );
    fastDigitalWrite(LED, HIGH );
    fastDigitalWrite(LED, LOW );
    fastDigitalWrite(LED, HIGH );
    fastDigitalWrite(LED, LOW );
    fastDigitalWrite(LED, HIGH );
    fastDigitalWrite(LED, LOW );
    fastDigitalWrite(LED, HIGH );

    fastDigitalWrite(LED, LOW );
    fastDigitalWrite(LED, HIGH );
    fastDigitalWrite(LED, LOW );
    fastDigitalWrite(LED, HIGH );
    fastDigitalWrite(LED, LOW );
    fastDigitalWrite(LED, HIGH );
    fastDigitalWrite(LED, LOW );
    fastDigitalWrite(LED, HIGH );

    fastDigitalWrite(LED, LOW );
    fastDigitalWrite(LED, HIGH );
    fastDigitalWrite(LED, LOW );
    fastDigitalWrite(LED, HIGH );
    fastDigitalWrite(LED, LOW );
    fastDigitalWrite(LED, HIGH );
    fastDigitalWrite(LED, LOW );
    fastDigitalWrite(LED, HIGH );

    fastDigitalWrite(LED, LOW );
    fastDigitalWrite(LED, HIGH );
    fastDigitalWrite(LED, LOW );
    fastDigitalWrite(LED, HIGH );
    fastDigitalWrite(LED, LOW );
    fastDigitalWrite(LED, HIGH );
    fastDigitalWrite(LED, LOW );
    fastDigitalWrite(LED, HIGH );

    fastDigitalWrite(LED, LOW );
    fastDigitalWrite(LED, HIGH );
    fastDigitalWrite(LED, LOW );
    fastDigitalWrite(LED, HIGH );
    fastDigitalWrite(LED, LOW );
    fastDigitalWrite(LED, HIGH );
    fastDigitalWrite(LED, LOW );
    fastDigitalWrite(LED, HIGH );

    fastDigitalWrite(LED, LOW );
    fastDigitalWrite(LED, HIGH );
    fastDigitalWrite(LED, LOW );
    fastDigitalWrite(LED, HIGH );
    fastDigitalWrite(LED, LOW );
    fastDigitalWrite(LED, HIGH );
    fastDigitalWrite(LED, LOW );
    fastDigitalWrite(LED, HIGH );

    fastDigitalWrite(LED, LOW );
    fastDigitalWrite(LED, HIGH );
    fastDigitalWrite(LED, LOW );
    fastDigitalWrite(LED, HIGH );
    fastDigitalWrite(LED, LOW );
    fastDigitalWrite(LED, HIGH );
    fastDigitalWrite(LED, LOW );
    fastDigitalWrite(LED, HIGH );
  }
  stop = micros();
  
  fast = (float)(stop-start)/(loopCount*128)*1000;
  Serial.print("Optimized fastDigitalWrite(): ");
  Serial.print(fast);
  Serial.print("ns -> ");
  Serial.print(1000/fast);
  Serial.println("MHz");

  start = micros();
  for(unsigned short i=0; i<loopCount; i++)
  {
    // Unroll 128x to avoid loop cost
    
    digitalWrite(LED, LOW );
    digitalWrite(LED, HIGH );
    digitalWrite(LED, LOW );
    digitalWrite(LED, HIGH );
    digitalWrite(LED, LOW );
    digitalWrite(LED, HIGH );
    digitalWrite(LED, LOW );
    digitalWrite(LED, HIGH );

    digitalWrite(LED, LOW );
    digitalWrite(LED, HIGH );
    digitalWrite(LED, LOW );
    digitalWrite(LED, HIGH );
    digitalWrite(LED, LOW );
    digitalWrite(LED, HIGH );
    digitalWrite(LED, LOW );
    digitalWrite(LED, HIGH );

    digitalWrite(LED, LOW );
    digitalWrite(LED, HIGH );
    digitalWrite(LED, LOW );
    digitalWrite(LED, HIGH );
    digitalWrite(LED, LOW );
    digitalWrite(LED, HIGH );
    digitalWrite(LED, LOW );
    digitalWrite(LED, HIGH );

    digitalWrite(LED, LOW );
    digitalWrite(LED, HIGH );
    digitalWrite(LED, LOW );
    digitalWrite(LED, HIGH );
    digitalWrite(LED, LOW );
    digitalWrite(LED, HIGH );
    digitalWrite(LED, LOW );
    digitalWrite(LED, HIGH );

    digitalWrite(LED, LOW );
    digitalWrite(LED, HIGH );
    digitalWrite(LED, LOW );
    digitalWrite(LED, HIGH );
    digitalWrite(LED, LOW );
    digitalWrite(LED, HIGH );
    digitalWrite(LED, LOW );
    digitalWrite(LED, HIGH );

    digitalWrite(LED, LOW );
    digitalWrite(LED, HIGH );
    digitalWrite(LED, LOW );
    digitalWrite(LED, HIGH );
    digitalWrite(LED, LOW );
    digitalWrite(LED, HIGH );
    digitalWrite(LED, LOW );
    digitalWrite(LED, HIGH );

    digitalWrite(LED, LOW );
    digitalWrite(LED, HIGH );
    digitalWrite(LED, LOW );
    digitalWrite(LED, HIGH );
    digitalWrite(LED, LOW );
    digitalWrite(LED, HIGH );
    digitalWrite(LED, LOW );
    digitalWrite(LED, HIGH );

    digitalWrite(LED, LOW );
    digitalWrite(LED, HIGH );
    digitalWrite(LED, LOW );
    digitalWrite(LED, HIGH );
    digitalWrite(LED, LOW );
    digitalWrite(LED, HIGH );
    digitalWrite(LED, LOW );
    digitalWrite(LED, HIGH );

    digitalWrite(LED, LOW );
    digitalWrite(LED, HIGH );
    digitalWrite(LED, LOW );
    digitalWrite(LED, HIGH );
    digitalWrite(LED, LOW );
    digitalWrite(LED, HIGH );
    digitalWrite(LED, LOW );
    digitalWrite(LED, HIGH );

    digitalWrite(LED, LOW );
    digitalWrite(LED, HIGH );
    digitalWrite(LED, LOW );
    digitalWrite(LED, HIGH );
    digitalWrite(LED, LOW );
    digitalWrite(LED, HIGH );
    digitalWrite(LED, LOW );
    digitalWrite(LED, HIGH );

    digitalWrite(LED, LOW );
    digitalWrite(LED, HIGH );
    digitalWrite(LED, LOW );
    digitalWrite(LED, HIGH );
    digitalWrite(LED, LOW );
    digitalWrite(LED, HIGH );
    digitalWrite(LED, LOW );
    digitalWrite(LED, HIGH );

    digitalWrite(LED, LOW );
    digitalWrite(LED, HIGH );
    digitalWrite(LED, LOW );
    digitalWrite(LED, HIGH );
    digitalWrite(LED, LOW );
    digitalWrite(LED, HIGH );
    digitalWrite(LED, LOW );
    digitalWrite(LED, HIGH );

    digitalWrite(LED, LOW );
    digitalWrite(LED, HIGH );
    digitalWrite(LED, LOW );
    digitalWrite(LED, HIGH );
    digitalWrite(LED, LOW );
    digitalWrite(LED, HIGH );
    digitalWrite(LED, LOW );
    digitalWrite(LED, HIGH );

    digitalWrite(LED, LOW );
    digitalWrite(LED, HIGH );
    digitalWrite(LED, LOW );
    digitalWrite(LED, HIGH );
    digitalWrite(LED, LOW );
    digitalWrite(LED, HIGH );
    digitalWrite(LED, LOW );
    digitalWrite(LED, HIGH );

    digitalWrite(LED, LOW );
    digitalWrite(LED, HIGH );
    digitalWrite(LED, LOW );
    digitalWrite(LED, HIGH );
    digitalWrite(LED, LOW );
    digitalWrite(LED, HIGH );
    digitalWrite(LED, LOW );
    digitalWrite(LED, HIGH );

    digitalWrite(LED, LOW );
    digitalWrite(LED, HIGH );
    digitalWrite(LED, LOW );
    digitalWrite(LED, HIGH );
    digitalWrite(LED, LOW );
    digitalWrite(LED, HIGH );
    digitalWrite(LED, LOW );
    digitalWrite(LED, HIGH );
  }
  stop = micros();

  std = (float)(stop-start)/(loopCount*128)*1000;
  Serial.print("Standard digitalWrite():  ");
  Serial.print(std);
  Serial.print("ns -> ");
  Serial.print(1000/std);
  Serial.println("MHz");

  Serial.print("Speed improvement: ");
  Serial.print(std/fast);
  Serial.println("x");

  // Turn off the light
  digitalWrite(LED, LOW );

  Serial.println("Finished");
}

void loop() {}
