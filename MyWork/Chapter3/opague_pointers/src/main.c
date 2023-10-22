
#include "main.h"
#include <stdio.h>

int main(int argc, char **argv) {
  // Create an autotimer
  autotimer timer = create_autotimer();

  // Start the timer
  start_autotimer(timer);

  // Simulate some time-consuming work
  for (int i = 0; i < 100000000; i++) {
    // Doing some work here
  }

  // Stop the timer
  stop_autotimer(timer);

  // Get the elapsed time and print it
  double elapsed_time = get_elapsed_time(timer);
  printf("Elapsed Time: %f seconds\n", elapsed_time);

  // Destroy the autotimer to free memory
  destroy_autotimer(timer);

  return 0;
}
