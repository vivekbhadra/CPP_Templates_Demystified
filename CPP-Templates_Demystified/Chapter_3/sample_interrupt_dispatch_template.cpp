#include <iostream>

// GPIO ISR handler representing a hardware abstraction layer function
void gpio_interrupt_handler() 
{
    std::cout << "GPIO edge detected: clearing interrupt flag\n";
    // Logic for clearing flags or toggling peripheral states would reside here
}

template<void (*ISR)()>
void dispatch_interrupt() 
{
    // The compiler knows the exact function address at compile time
    ISR(); 
}

int main() 
{
    // The handler is passed as a non-type template parameter
    dispatch_interrupt<gpio_interrupt_handler>();
    return 0;
}
