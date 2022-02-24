#include <Arduino.h>
#include <driver/dac.h>
#include <soc/rtc.h>
#include <soc/sens_reg.h>
#include "data-table.h"


//#define EXCEL
//#define NTP

#if defined NTP
  #include <NTPtimeESP.h>
  #include <WiFi.h>
  
  NTPtime NTPch("europe.pool.ntp.org"); // Choose your server pool
  char *ssid      = "Your SSID";        // Set you WiFi SSID
  char *password  = "Your PASS";        // Set you WiFi password
  
  int status = WL_IDLE_STATUS;
  strDateTime dateTime;
#endif //

// Change this to set the initial Time
// Now is 10:08:37 (12h)
int h=10;   //Start Hour 
int m=8;    //Start Minutes
int s=37;   //Start Seconds

//Variables
int           lastx,lasty;
unsigned long currentMillis  = 0;
unsigned long previousMillis = 0;    
int           Timeout        = 20;
const    long interval       = 990; //milliseconds, you should twick this
                                    //to get a better accuracy


void PlotTable(byte *SubTable, int SubTableSize, int skip, int opt, int offset);
inline void Dot(int x, int y);
void Line(byte x1, byte y1, byte x2, byte y2);

