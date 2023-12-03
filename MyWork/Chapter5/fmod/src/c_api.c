#include <conio.h>
#include <mmsystem.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void myFunction() {
  UINT myVariable;
  // Rest of your code...
}

void ERRCHECK(int result) {
  if (result != 0) {
    printf("Error! (%d)\n", result);
    exit(-1);
  }
}

int main() {
  int key;
  unsigned int ms = 0;
  unsigned int lenms = 0;
  int playing = 0;
  int paused = 0;
  int channelsplaying = 0;

  printf("==================================================================="
         "\n");
  printf("PlaySound Example\n");
  printf("==================================================================="
         "\n");
  printf("\n");
  printf("Press '1' to Play a mono sound using software mixing\n");
  printf("Press '2' to Play a mono sound using software mixing\n");
  printf("Press '3' to Play a stereo sound using software mixing\n");
  printf("Press 'Esc' to quit\n");
  printf("\n");

  do {
    if (_kbhit()) {
      key = _getch();
      switch (key) {
      case '1':
        printf("Playing sound 1\n");
        PlaySound(TEXT("sound1.wav"), NULL, SND_FILENAME | SND_ASYNC);
        break;
      case '2':
        printf("Playing sound 2\n");
        PlaySound(TEXT("sound2.wav"), NULL, SND_FILENAME | SND_ASYNC);
        break;
      case '3':
        printf("Playing sound 3\n");
        PlaySound(TEXT("sound3.wav"), NULL, SND_FILENAME | SND_ASYNC);
        break;
      }
    }

    // Update sound status
    ms += 10;
    lenms = 10000;       // Dummy value for sound length
    playing = 1;         // Dummy value for sound playing status
    paused = 0;          // Dummy value for sound paused status
    channelsplaying = 1; // Dummy value for number of channels playing

    printf("\rTime %02d:%02d:%02d/%02d:%02d:%02d : %s : Channels Playing %2d",
           ms / 1000 / 60, ms / 1000 % 60, ms / 10 % 100, lenms / 1000 / 60,
           lenms / 1000 % 60, lenms / 10 % 100,
           paused    ? "Paused "
           : playing ? "Playing"
                     : "Stopped",
           channelsplaying);
    fflush(stdout);

    Sleep(10);

  } while (key != 27);

  printf("\n");

  return 0;
}

