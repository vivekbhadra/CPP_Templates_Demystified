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
#include <string.h>
template<typename T>
T* dynamic_allocator(T val, const size_t N)
{
    T *mem = new T[N];
    for (size_t index = 0; index < N; ++index)
        mem[index] = val;

    return mem;
}

int main()
{
    size_t len = 0;
    len = 10;
    auto iptr = dynamic_allocator(5, len);
    for (size_t index = 0; index < len; ++index)
        std::cout << iptr[index] << " ";
    std::cout << "\n";
    
    len = 5;
    auto dptr = dynamic_allocator(20.7, len);    
    for (size_t index = 0; index < len; ++index)
        std::cout << dptr[index] << " ";
    std::cout << "\n";

    len = 3;
    auto cptr = dynamic_allocator('C', len);
    for (size_t index = 0; index < len; ++index)
        std::cout << cptr[index] << std::endl;

    delete [] iptr;
    delete [] dptr;
    delete [] cptr;

    return 0;
}
