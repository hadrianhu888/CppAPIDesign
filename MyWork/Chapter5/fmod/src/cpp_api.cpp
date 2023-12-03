/// -*- tab-width: 4; c-basic-offset: 4; indent-tabs-mode: t -*-
/*===============================================================================================
 PlaySound Example
 Copyright (c), Firelight Technologies Pty, Ltd 2004-2009.

 This example shows how to simply load and play multiple sounds.  This is about
the simplest use of FMOD. This makes FMOD decode the into memory when it loads.
If the sounds are big and possibly take up a lot of ram, then it would be better
to use the FMOD_CREATESTREAM flag so that it is streamed in realtime as it
plays.
/*===============================================================================================
 PlaySound Example
 Copyright (c), Firelight Technologies Pty, Ltd 2004-2009.

 This example shows how to simply load and play multiple sounds.  This is about
the simplest use of FMOD. This makes FMOD decode the into memory when it loads.
If the sounds are big and possibly take up a lot of ram, then it would be better
to use the FMOD_CREATESTREAM flag so that it is streamed in realtime as it
plays.
===============================================================================================*/

#include <Windows.h>
#include <conio.h>
#include <mmsystem.h>
#include <stdio.h>
#include <thread>

#pragma comment(lib, "winmm.lib")

void ERRCHECK(int result) {
  if (result != 0) {
    printf("Error! (%d)\n", result);
    exit(-1);
  }
}

int main(int argc, char *argv[]) {
  int key;
  unsigned int version;

  printf(
      "===================================================================\n");
  printf(
      "PlaySound Example.  Copyright (c) Firelight Technologies 2004-2009.\n");
  printf(
      "===================================================================\n");
  printf("\n");
  printf("Press '1' to Play a mono sound using software mixing\n");
  printf("Press '2' to Play a mono sound using software mixing\n");
  printf("Press '3' to Play a stereo sound using software mixing\n");
  printf("Press 'Esc' to quit\n");
  printf("\n");

  /*
      Main loop.
  */
  do {
    if (kbhit()) {
      key = getch();

      switch (key) {
      case '1': {
        ERRCHECK(
            PlaySound("../media/drumloop.wav", NULL, SND_FILENAME | SND_ASYNC));
        break;
      }
      case '2': {
        ERRCHECK(
            PlaySound("../media/jaguar.wav", NULL, SND_FILENAME | SND_ASYNC));
        break;
      }
      case '3': {
        ERRCHECK(
            PlaySound("../media/swish.wav", NULL, SND_FILENAME | SND_ASYNC));
        break;
      }
      }
    }
#include <thread>
    std::this_thread::sleep_for(std::chrono::milliseconds(10));

  } while (key != 27);

  printf("\n");

  return 0;
}
