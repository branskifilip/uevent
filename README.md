# uevent - A very small C++ library for handling simple events.

> Note: Though it gets the job done, this library is **very** primitive and made it for my own use.

## Usage
```c++
#include "uevent.h"

// An example dummy function
void multiply(int i, float f){
  i * f;
}

// Create the event with given argument types
uevent::Event<int, float> event;

// Add the function pointer to the event
event += multiply;   // Using operator +=
event.add(multiply); // Or using the 'add' member function

// Invoke the event
event.invoke(1, 3.14);

// Remove the function pointer from the event 
event -= multiply;      // Using operator -=
event.remove(multiply); // Or using the 'remove' member function

// Get the number of event's targets
event.size();
```
