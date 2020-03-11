/*****************************************************************************/
/*
 *
 *   Author : Sebastien MARCHAND 
 *            Web:www.marscaper.com 
 *            Email:sebastien@marscaper.com
 *
 *   Create : 04/03/2020
 *    
 *   Copyrights and Disclaimer :  
 *
 *      Copyright (c) 2020, seb. All rights reserved.
 *
 *      Redistribution and use in source and binary forms, with or without 
 *      modification, are permitted provided that the following conditions  
 *      are met:
 *      •Redistributions of source code must retain the above copyright notice,
 *       this list of conditions and the following disclaimer.
 *      •Redistributions in binary form must reproduce the above copyright 
 *       notice, this list of conditions and the following disclaimer in the 
 *       documentation and/or other materials provided with the distribution.
 *      •Neither the name of Sébastien Marchand nor the names of its contributors  
 *       may be used to endorse or promote products derived from this software  
 *       without specific prior written permission.
 * 
 *      THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
 *      "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
 *      LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR 
 *      A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT 
 *      OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  
 *      SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  
 *      LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, 
 *      DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY 
 *      THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
 *      (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
 *      OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *   
 */
/*****************************************************************************/


/*****************************************************************************/
/*                                                                           */
/*                          TIMER 0 MANAGEMENT                               */
/*                                                                           */
/*****************************************************************************/

long outline = 0;

void start_timer0(void)
{    
  Serial.println("start timer0");
  
  NRF_TIMER0->MODE = TIMER_MODE_MODE_Timer;              // Set the timer in Counter Mode
  NRF_TIMER0->TASKS_CLEAR = 1;                           // clear the task first to be usable for later
  NRF_TIMER0->PRESCALER   = 4;  
  NRF_TIMER0->BITMODE = TIMER_BITMODE_BITMODE_16Bit;     //Set counter to 16 bit resolution
  NRF_TIMER0->CC[0] = 32000;                             //Set value for TIMER1 compare register 0
  NRF_TIMER0->CC[1] = 0;
  NRF_TIMER0->INTENSET = (TIMER_INTENSET_COMPARE0_Enabled << TIMER_INTENSET_COMPARE0_Pos);
  NVIC_EnableIRQ(TIMER0_IRQn);
    
  NRF_TIMER0->TASKS_START = 1;               // Start TIMER1
}

void stop_timer0()
{
  Serial.println("Stop timer0");
  NRF_TIMER0->INTENCLR = TIMER_INTENCLR_COMPARE0_Clear << TIMER_INTENCLR_COMPARE0_Pos;
}

extern "C"  { void TIMER0_IRQHandler(void) { timer_pal0();  } }

void timer_pal0(void)
{ 
  NRF_TIMER0->EVENTS_COMPARE[0] = 0;         //Clear compare register 0 event 

  // Do the job for display...
  outline++;
  if( outline>9 ) outline=0;
}


/*****************************************************************************/
/*                                                                           */
/*                          TIMER 1 MANAGEMENT                               */
/*                                                                           */
/*****************************************************************************/

long progress = 0;

void start_timer1(void)
{    
  Serial.println("Start timer1");

  NRF_TIMER1->MODE = TIMER_MODE_MODE_Timer;              // Set the timer in Counter Mode
  NRF_TIMER1->TASKS_CLEAR = 1;                           // clear the task first to be usable for later
  NRF_TIMER1->PRESCALER   = 7;  
  NRF_TIMER1->BITMODE = TIMER_BITMODE_BITMODE_16Bit;     //Set counter to 16 bit resolution
  NRF_TIMER1->CC[0] = 32000;                             //Set value for TIMER1 compare register 0
  NRF_TIMER1->CC[1] = 0;
  NRF_TIMER1->INTENSET = (TIMER_INTENSET_COMPARE0_Enabled << TIMER_INTENSET_COMPARE0_Pos);
  NVIC_EnableIRQ(TIMER1_IRQn);
    
  NRF_TIMER1->TASKS_START = 1;               // Start TIMER1
}

void stop_timer1()
{
  Serial.println("Stop timer1");
  NRF_TIMER1->INTENCLR = TIMER_INTENCLR_COMPARE0_Clear << TIMER_INTENCLR_COMPARE0_Pos;
}

extern "C"  { void TIMER1_IRQHandler(void) { timer_pal1();  } }

void timer_pal1(void)
{
  NRF_TIMER1->EVENTS_COMPARE[0] = 0;         //Clear compare register 0 event 

  // Do the job for display...
  progress++;
  if( progress>2 ) progress=0;
}


/*****************************************************************************/
/*                                                                           */
/*                          TIMER 2 MANAGEMENT                               */
/*                                                                           */
/*****************************************************************************/

long fade    = 0;
int  incFade = 1;

void start_timer2(void)
{ 
  Serial.println("start timer2");

  NRF_TIMER2->MODE = TIMER_MODE_MODE_Timer;              // Set the timer in Counter Mode
  NRF_TIMER2->TASKS_CLEAR = 1;                           // clear the task first to be usable for later
  NRF_TIMER2->PRESCALER   = 4;  
  NRF_TIMER2->BITMODE = TIMER_BITMODE_BITMODE_16Bit;     //Set counter to 16 bit resolution
  NRF_TIMER2->CC[0] = 32000;                             //Set value for TIMER1 compare register 0
  NRF_TIMER2->CC[1] = 0;
  NRF_TIMER2->INTENSET = (TIMER_INTENSET_COMPARE0_Enabled << TIMER_INTENSET_COMPARE0_Pos);
  NVIC_EnableIRQ(TIMER2_IRQn);
    
  NRF_TIMER2->TASKS_START = 1;               // Start TIMER1
}

void stop_timer2()
{
  Serial.println("stop timer2");
  NRF_TIMER2->INTENCLR = TIMER_INTENCLR_COMPARE0_Clear << TIMER_INTENCLR_COMPARE0_Pos;
}

extern "C"  { void TIMER2_IRQHandler(void) { timer_pal2();  } }

void timer_pal2(void)
{
  NRF_TIMER2->EVENTS_COMPARE[0] = 0;         //Clear compare register 0 event 

  // Do the job for display...
  fade += incFade;
  if( fade>5 )
  {
    incFade = -1;
  }
  else if( fade < 0 )
  {
    incFade = 1;
    fade = 0;
  }
}

/*****************************************************************************/
/*                                                                           */
/*                        LED DISPLAY MANAGEMENT                             */
/*                                                                           */
/*****************************************************************************/

const uint8_t max_cols PROGMEM = 9;
const uint8_t max_rows PROGMEM = 3;
const uint8_t colCount PROGMEM = 5;
const uint8_t rowCount PROGMEM = 5;
const uint8_t cols[max_cols] PROGMEM = {3, 4, 10, 23, 24, 25, 9, 7, 6};
const uint8_t rows[max_rows] PROGMEM = {26, 27, 28};

typedef struct TPoint 
{
  uint8_t x;
  uint8_t y;
} LED_POINT;

const LED_POINT LED_POS[rowCount][colCount] PROGMEM =
{
  {{0, 0}, {3, 1}, {1, 0}, {4, 1}, {2, 0}},
  {{3, 2}, {4, 2}, {5, 2}, {6, 2}, {7, 2}},
  {{1, 1}, {8, 0}, {2, 1}, {8, 2}, {0, 1}},
  {{7, 0}, {6, 0}, {5, 0}, {4, 0}, {3, 0}},
  {{2, 2}, {6, 1}, {0, 2}, {5, 1}, {1, 2}}
};

const uint8_t heart[colCount] 
{
  B01010,
  B11111, 
  B11111, 
  B01110, 
  B00100
};

const LED_POINT heartOutline[10] PROGMEM = {{2, 4}, {3, 3}, {4, 2}, {4, 1}, {3, 0}, {2, 1}, {1, 0}, {0, 1}, {0, 2}, {1, 3}};
const LED_POINT progressList[3]      PROGMEM = {{1, 2}, {2, 2}, {3, 2}};

unsigned int screenArray[colCount][rowCount];

// Around 10x faster
void fastDigitalWrite( uint32_t ulPin, uint32_t ulVal )
{
  ulPin = g_ADigitalPinMap[ulPin];
  (ulVal)?NRF_GPIO->OUTSET=(1UL<<ulPin):NRF_GPIO->OUTCLR=(1UL<<ulPin);
}

void pixelSet(const uint8_t x, const uint8_t y, uint8_t brightness) 
{
  if( brightness )
  {
    if( brightness > 100) brightness=100;
    
    LED_POINT position = LED_POS[y][x];

    fastDigitalWrite(cols[position.x], LOW );
    fastDigitalWrite(rows[position.y], HIGH);
   
    nrf_delay_us(brightness);
    
    fastDigitalWrite(cols[position.x], HIGH);
    fastDigitalWrite(rows[position.y], LOW );

    nrf_delay_us(25);
  }
}

void enableScreen() 
{
  for (uint8_t i = 0; i < max_cols; i++)
    pinMode(cols[i], OUTPUT);
  for (uint8_t i = 0; i < max_rows; i++)
    pinMode(rows[i], OUTPUT);
}

void showData(const uint8_t *DataArray) 
{
  
  for (uint8_t x = 0; x < colCount; x++) 
  {
    uint8_t data = DataArray[x];
    
    for (uint8_t y = 0; y < rowCount; y++) 
    {
      if ((data & 1) ) 
      {
        screenArray[y][x] = 50;
      }

      data >>= 1;
    }
  }
}


/*****************************************************************************/
/*                                                                           */
/*                        A/B BUTTONS MANAGEMENTS                            */
/*                                                                           */
/*****************************************************************************/

const uint8_t buttonA = 5;  
const uint8_t buttonB = 11;

bool AButtonPushed()
{
  static bool _AButtonState = 0;
  bool newState = !digitalRead(buttonA);

  if( _AButtonState == 0 && newState == 1 )
  {
    _AButtonState = 1;
    newState = 1;
  }
  else if( _AButtonState == 1 && newState == 0 )
  {
    _AButtonState = 0;
    newState = 0;
  }
  else
  {
    newState = false;
  }
  
  return newState;
}

bool BButtonPushed()
{
  static bool _BButtonState = 0;
  bool newState = !digitalRead(buttonB);

  if( _BButtonState == 0 && newState == 1 )
  {
    _BButtonState = 1;
    newState = 1;
  }
  else if( _BButtonState == 1 && newState == 0 )
  {
    _BButtonState = 0;
    newState = 0;
  }
  else
  {
    newState = false;
  }
  
  return newState;
}

void refresh()
{
  // Display background (Timer2)
  for (uint8_t x = 0; x < colCount; x++) 
  {
      for (uint8_t y = 0; y < rowCount; y++) 
      {
          screenArray[x][y] = fade;
      }
  }

  // Display heart
  showData(heart);

  // Display heart outline (Timer0)
  LED_POINT point = heartOutline[outline];
  screenArray[point.x][point.y] += 50;

  // Display progress line (Timer1)
  point = progressList[progress];
  screenArray[point.x][point.y] += 50;

  for (uint8_t x = 0; x < colCount; x++) 
  {
      for (uint8_t y = 0; y < rowCount; y++) 
      {
        pixelSet(x, y, screenArray[x][y]);
      }
  }
}


/*****************************************************************************/
/*                                                                           */
/*                               MAIN CODE                                   */
/*                                                                           */
/*****************************************************************************/

int timerIndex = 0;

void setup() 
{  
  Serial.begin(115200);
  Serial.println("microbit is ready!");

  pinMode(buttonA, INPUT);
  pinMode(buttonB, INPUT);

  enableScreen();

  Serial.println("Press A to launch timers and B to stop timers.");
}

void loop()
{ 
  // A Button pushed?
  if( AButtonPushed() )
  { 
    switch(timerIndex)
    {
      case 0:
        start_timer0();
      break;

      case 1:
        start_timer1();
      break;

      case 2:
        start_timer2();
      break;
    }

    timerIndex++;
    if( timerIndex>3)
    {
      timerIndex=3;
      Serial.println("All timers are already running");
    } 
  }

  // B Button pushed?
  if( BButtonPushed() )
  {    
    timerIndex--;
    if( timerIndex<0) 
    {
      timerIndex=0;
      Serial.println("No timer launched");
    }
    else
    {
      switch(timerIndex)
      {
        case 0:
          stop_timer0();
        break;
  
        case 1:
          stop_timer1();
        break;
  
        case 2:
          stop_timer2();
        break;
      }
    }
  }

  // Refresh display
  refresh();
}
