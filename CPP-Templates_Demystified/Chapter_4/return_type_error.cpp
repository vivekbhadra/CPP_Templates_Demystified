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

template<typename T>
T largest_elem(const T data_set, size_t count)
{
    T max_value = data_set[0];
    for (size_t i = 0; i < count; ++i)
        if (data_set[i] > max_value)
            max_value = data_set[i];
    return max_value;
}

int main()
{
    double numbers[] = {
        20.1, 10.1, 30.1, 5.1, 40.1,
        200.1, 50.1, 1.1, 0.5, 100.5
    };

    double largest = largest_elem(numbers, 10);
    std::cout << "largest = " << largest << "\n";

    return 0;
}
