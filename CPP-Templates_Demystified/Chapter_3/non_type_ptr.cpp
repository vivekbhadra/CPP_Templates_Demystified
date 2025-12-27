/*************************************************************************\
*                  Copyright (C) Vivek Bhadra, 2021.                      *
*                                                                         *
* This program is free software. You may use, modify, and redistribute it *
* under the terms of the GNU General Public License as published by the   *
* Free Software Foundation, either version 3 or (at your option) any      *
* later version. This program is distributed without any warranty.  See   *
* the file COPYING.gpl-v3 for details.                                    *
\*************************************************************************/

#include <iostream>
#include <cstring>
#include <cstdlib>

// ptr is a variable; the address it holds can change at runtime
char* ptr;

template<char* str>
void print_str()
{
    // In a valid template, str would be a constant address
    std::cout << str << "\n";
}

int main()
{
    // The address held by ptr is determined at runtime via malloc
    ptr = static_cast<char*>(std::malloc(32));
    if (ptr) {
        std::strcpy(ptr, "Hello World");
        
        // Compilation Error: 'ptr' is a variable, not a constant address
        // print_str<ptr>(); 
        
        std::free(ptr);
    }
    return 0;
}
