#include "U8glib.h"
 
U8GLIB_NHD_C12864 u8g(13, 11, 10, 9, 8);    // SPI Com: SCK = 13, MOSI = 11, CS = 10, CD = 9, RST = 8
 

void draw1(void) {
  // graphic commands to redraw the complete screen should be placed here 
  u8g.setFont(u8g_font_unifont);
  //u8g.setFont(u8g_font_osb21);
  u8g.drawStr( 0, 20, "Current Saving");
  u8g.drawStr( 40, 40, "10000");
}

void draw2(void) {
  int saving = 20000;
  u8g.setFont(u8g_font_unifont);
  char buf[9];
  sprintf (buf, "%d", saving);
  u8g.drawStr(60, 40, buf);
  u8g.drawStr( 0, 20, "Current Saving" );
}

void draw3(void) {    // Menu
  u8g.setFont(u8g_font_unifont);
  u8g.drawStr(0, 20, "Menu");
  u8g.drawStr(0, 40, "1. OPEN");
  u8g.drawStr(0, 60, "2. EXIT");
}

void draw4(void) {    // Menu
  u8g.setFont(u8g_font_unifont);
  u8g.drawStr(0, 40, "ERROR");
}
 
void setup(void) {
  Serial.begin(9600);
  u8g.setContrast(0); // Config the contrast to the best effect
  u8g.setRot180();// rotate screen, if required
  // set SPI backup if required
  //u8g.setHardwareBackup(u8g_backup_avr_spi);
 
  // assign default color value
  if ( u8g.getMode() == U8G_MODE_R3G3B2 ) {
    u8g.setColorIndex(255);     // white
  }
  else if ( u8g.getMode() == U8G_MODE_GRAY2BIT ) {
    u8g.setColorIndex(3);         // max intensity
  }
  else if ( u8g.getMode() == U8G_MODE_BW ) {
    u8g.setColorIndex(1);         // pixel on
  }
  else if ( u8g.getMode() == U8G_MODE_HICOLOR ) {
    u8g.setHiColorByRGB(255,255,255);
  }
}

void loop(void) {

  u8g.firstPage(); 
  do {
    draw2();
  } while( u8g.nextPage() );
  delay(10); 

  if(Serial.parseInt()) {
    u8g.firstPage(); 
    do {
      draw3();
    } while( u8g.nextPage() );
    
    Serial.setTimeout(8000);
    int i = Serial.parseInt();
    if(i == 1) {
      u8g.firstPage(); 
      do {
        draw1();
      } while( u8g.nextPage() );
      delay(2000);
    }
    else if(i == 2){
      u8g.firstPage(); 
      do {
        draw1();
      } while( u8g.nextPage() );
      delay(2000);
    }
    else {
      u8g.firstPage();
      do {
        draw4();
      } while( u8g.nextPage() );
      delay(2000);
    }
    Serial.setTimeout(10);
  }
  
//  u8g.firstPage(); 
//  do {
//    draw2();
//  } while( u8g.nextPage() );
//  delay(1000); 
}
