/* 
 * Automatic login to most sites
 * 
 * author Krupoderov Mikhail
 * version 1.0
*/

#include "HID-Project.h" // Includes BootKeyboard/Mouse, Consumer, System, Gamepad, RawHID and more features.

#define LOGIN "test@gmail.com" // Login or email
#define PASSWORD "mypass123" // Password

int changeLang = 0;  // 0 - do not change the layout,
                     // 1 - change the Alt + Shift, 
                     // 2 - change the Ctrl + Shift

/* "Press button" and "Release" */
void pressKey (uint8_t key, int del)
{
  Keyboard.press(key);
  delay(del);
  Keyboard.release(key);
}

/* "Press button" and "Release" */
void pressKey (uint8_t key1, uint8_t key2, int del)
{
  Keyboard.press(key1);
  Keyboard.press(key2);
  delay(del);
  Keyboard.releaseAll();
}

/* Press and release the Enter button */
void enter ()
{
  pressKey(KEY_RETURN, 40);
}

/* The code is executed once at startup */
void setup ()
{
  Keyboard.begin();

  if (changeLang != 0)
  {
    delay(1000);
    if(changeLang == 1)
    {
      pressKey(KEY_LEFT_ALT, KEY_LEFT_SHIFT, 500);
    }
    else if(changeLang == 2)
      {
        pressKey(KEY_LEFT_CTRL, KEY_LEFT_SHIFT, 500);
      }
  }  
  
  delay(500);
  
  Keyboard.print(LOGIN);
  Keyboard.press(KEY_TAB); 
  Keyboard.print(PASSWORD);
  delay(100);
  
  enter();
}

/* This is where code loops, a required method */
void loop ()
{
  // Empty loop
}
