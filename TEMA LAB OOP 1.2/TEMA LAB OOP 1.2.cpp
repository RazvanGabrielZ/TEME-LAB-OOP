#include <iostream>

#define USE_HEADER1 1  // Change this to 0 to use header2.h

#if USE_HEADER1
#include "Header1.h"
#else
#include "Header2.h"
#endif

int main() {
    f();  // Call the function f()
    return 0;
}