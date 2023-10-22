#include "autotimer.h"
#include <stdlib.h>
#include <time.h>

struct autotimer_struct {
  clock_t start_time;
  clock_t end_time;
};

autotimer create_autotimer() {
  autotimer timer = (autotimer)malloc(sizeof(struct autotimer_struct));
  if (timer) {
    timer->start_time = 0;
    timer->end_time = 0;
  }
  return timer;
}

void start_autotimer(autotimer timer) {
  if (timer) {
    timer->start_time = clock();
    timer->end_time = 0;
  }
}

void stop_autotimer(autotimer timer) {
  if (timer) {
    timer->end_time = clock();
  }
}

double get_elapsed_time(autotimer timer) {
  if (timer && timer->start_time && timer->end_time) {
    return ((double)(timer->end_time - timer->start_time)) / CLOCKS_PER_SEC;
  }
  return 0.0;
}

void destroy_autotimer(autotimer timer) {
  if (timer) {
    free(timer);
  }
}
