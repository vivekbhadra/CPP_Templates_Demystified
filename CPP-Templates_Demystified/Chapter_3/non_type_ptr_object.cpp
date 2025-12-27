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

// name represents a fixed memory location known at link time
char name[256];

template<char* str>
void print_str()
{
    // The compiler treats 'str' as a literal constant address
    std::cout << str << "\n";
}

int main()
{
    std::strcpy(name, "Hello World");
    
    // Valid: 'name' is a constant address known to the linker
    print_str<name>();
    
    return 0;
}
