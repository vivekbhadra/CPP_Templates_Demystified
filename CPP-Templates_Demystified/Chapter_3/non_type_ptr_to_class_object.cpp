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

class A {
public:
    void welcome() { std::cout << "Hello World\n"; }
};

// Global object has external linkage and a fixed identity
class A obj_A;

template<class A* ptr>
void execute_welcome()
{
    // Compiler treats 'ptr' as a constant memory address
    ptr->welcome();
}

int main()
{
    // Valid: The address of obj_A is a link time constant
    execute_welcome<&obj_A>();

    return 0;
}
