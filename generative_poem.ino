/*
 Display all the fast rendering fonts.

 This sketch uses the GLCD (font 1) and fonts 2, 4, 6, 7, 8
 
 Make sure all the display driver and pin connections are correct by
 editing the User_Setup.h file in the TFT_eSPI library folder.

 #########################################################################
 ###### DON'T FORGET TO UPDATE THE User_Setup.h FILE IN THE LIBRARY ######
 #########################################################################
*/

// Pause in milliseconds between screens, change to 0 to time font rendering
#define WAIT 100
#define NUMITEMS(arg) ((unsigned int) (sizeof (arg) / sizeof (arg [0])))
#define MAX_LINES 4

#include <TFT_eSPI.h> // Graphics and font library for ST7735 driver chip
#include <SPI.h>

#include "Free_Fonts.h"

TFT_eSPI tft = TFT_eSPI();  // Invoke library, pins defined in User_Setup.h

unsigned long targetTime = 0; // Used for testing draw times
const int screen_h = 240;
const int screen_w = 135;

String poem[] = {"_italic", "how", "is", "it", "so", "easy", "for", "you",
                "_line", "to", "be", "kind", "to", "people", "_normal", "he", "asked",
                "_stanza",
                "milk", "and", "honey", "dripped",
                "_line", "from", "my", "lips", "as", "i", "answered",
                "_stanza",
                "_italic", "cause", "people", "have", "not",
                "_line", "been", "kind", "to", "me"};

void setup(void) {
  tft.init();
  tft.setRotation(1);
}

void loop() {
  // First we test them with a background colour set
  tft.setTextSize(1);
  tft.fillScreen(TFT_BLACK);
  tft.setTextColor(TFT_WHITE);
  
  tft.setCursor(0,30); // set cursor to top
  tft.setFreeFont(FS12); //default font style is normal

  int num_lines = 1;
  
  for (int i = 0; i < NUMITEMS(poem); i++) {
    //Serial.println(poem[i]);
    if (poem[i].equals("_italic")) {
      tft.setFreeFont(FSI12); //italic
    }
    else if (poem[i].equals("_normal")) {
      tft.setFreeFont(FS12); //normal
    }
    else if (poem[i].equals("_line")) {
      tft.println(); //make a new line
      num_lines++;
      delay(WAIT);
    }
    else if (poem[i].equals("_stanza")) {
      delay(500);
      tft.fillScreen(TFT_BLACK); //clear the screen
      tft.setCursor(0,30); //reset cursor
      delay(WAIT);
    }
    else {
      tft.print(poem[i]);
      tft.print(" ");
      delay(WAIT*(poem[i].length()));
    }
  }
  delay(5000);

   
  //display one word at a time, with time increments based on how many syllables in each word
  //each line has a gap between words
  //each stanza has a new screen, orientation is now randomly determined
  //style switches are indicated with _italic or _normal
  //lines are indicated by _line, start of a new stanza is indicated by _stanza
}
