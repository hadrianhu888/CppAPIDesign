#include <iostream>
#include "DateTimeAPI.h"

int main(int argc, char **argv) {
    std::cout << "DateTime API Example\n";
    
    Date date(2023, 9, 28);
    date.print();

    Time1 time(2023, 9, 28, 12, 30, 0);
    time.print();
    
    return 0;
}
