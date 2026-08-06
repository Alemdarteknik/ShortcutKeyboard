#include "USB.h"
#include "USBHIDKeyboard.h"

USBHIDKeyboard Keyboard;

int bstate[10], lbstate[10], fo1;
int keystate;

#define BO1 4
#define BO2 5
#define BO3 6
#define BO4 7
#define BO5 15
#define BO6 16
#define BO7 17
#define BO8 18
#define BO9 8

void setup()
{
  pinMode(BO1, INPUT);
  pinMode(BO2, INPUT);
  pinMode(BO3, INPUT);
  pinMode(BO4, INPUT);
  pinMode(BO5, INPUT);
  pinMode(BO6, INPUT);
  pinMode(BO7, INPUT);
  pinMode(BO8, INPUT);
  pinMode(BO9, INPUT);

  for (fo1 = 0; fo1 < 10; fo1++)
  {
    bstate[fo1] = 0;
    lbstate[fo1] = 0;
  }
  USB.begin();
  Keyboard.begin();
}

void loop()
{
  bstate[1] = digitalRead(BO1);
  bstate[2] = digitalRead(BO2);
  bstate[3] = digitalRead(BO3);
  bstate[4] = digitalRead(BO4);
  bstate[5] = digitalRead(BO5);
  bstate[6] = digitalRead(BO6);
  bstate[7] = digitalRead(BO7);
  bstate[8] = digitalRead(BO8);
  bstate[9] = digitalRead(BO9);
  keystate = 0;

  for (fo1 = 1; fo1 < 10; fo1++)
  {
    if (bstate[fo1] == 0 && lbstate[fo1] == 1)
    {
      keystate = fo1;
      fo1 = 10;
    }
  }

  if (keystate != 0)
  {

    if (keystate == 1)
    {
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.press(KEY_LEFT_ALT);
      Keyboard.press('a');
    }
    else if (keystate == 2)
    {
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.press(KEY_LEFT_ALT);
      Keyboard.press('b');
    }
    else if (keystate == 3)
    {
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.press(KEY_LEFT_ALT);
      Keyboard.press('c');
    }
    else if (keystate == 4)
    {
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.press(KEY_LEFT_ALT);
      Keyboard.press('d');
    }
    else if (keystate == 5)
    {
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.press(KEY_LEFT_ALT);
      Keyboard.press('e');
    }
    else if (keystate == 6)
    {
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.press(KEY_LEFT_ALT);
      Keyboard.press('f');
    }
    else if (keystate == 7)
    {
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.press(KEY_LEFT_ALT);
      Keyboard.press('g');
    }
    else if (keystate == 8)
    {
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.press(KEY_LEFT_ALT);
      Keyboard.press('h');
    }
    else if (keystate == 9)

    {
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.press(KEY_LEFT_ALT);
      Keyboard.press('i');
    }
    delay(10);
    Keyboard.releaseAll();
  }

  for (fo1 = 0; fo1 < 10; fo1++)
  {
    lbstate[fo1] = bstate[fo1];
  }
}