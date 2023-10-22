#ifndef AUTOTIMER_H
#define AUTOTIMER_H

typedef struct autotimer_struct *autotimer;

autotimer create_autotimer();
void start_autotimer(autotimer timer);
void stop_autotimer(autotimer timer);
double get_elapsed_time(autotimer timer);
void destroy_autotimer(autotimer timer);

#endif // AUTOTIMER_H
