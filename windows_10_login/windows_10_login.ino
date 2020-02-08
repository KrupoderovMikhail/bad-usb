/* Automatic password entry in Windows 10 */

#include "HID-Project.h" // Includes BootKeyboard/Mouse, Consumer, System, Gamepad, RawHID and more features.

#define PASSWORD "password" // Password to enter

int changeLang = 0; // 0 - do not change the layout,
                     // 1 - change the Alt + Shift, 
                     // 2 - change the Ctrl + Shift

int mainDelay = 0; // The delay in the computer before entering the password, in seconds.

const int MILLISECOND = 1000;

/* "Press button" and "Release" */
void pressKey (uint8_t key1, uint8_t key2, int del)
{
  Keyboard.press(key1);
  Keyboard.press(key2);
  delay(del);
  Keyboard.releaseAll();
}

/* Simulate Alt + Ctrl + Del */
void altCtrlDel ()
{
  Keyboard.press(KEY_LEFT_ALT); 
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_DELETE);
  delay(40);
  Keyboard.releaseAll();
}

/* Press and release the Enter button */
void enter ()
{
  Keyboard.press(KEY_RETURN); 
  delay(40);
  Keyboard.release(KEY_RETURN); 
}

/* The code is executed once at startup */
void setup ()
{
  Keyboard.begin();
  
  delay(1000);
  
  altCtrlDel();

  if(mainDelay != 0)
  {
    delay(mainDelay * MILLISECOND);
  }
  
  if(changeLang != 0)
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
  
  Keyboard.print(PASSWORD);
  
  enter();
}

/* This is where code loops, a required method */
void loop ()
{
  // Empty loop
}
