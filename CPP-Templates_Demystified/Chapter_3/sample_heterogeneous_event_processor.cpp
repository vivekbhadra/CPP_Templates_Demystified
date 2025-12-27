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
#include <string>

/**
 * A generalized event processor handling two distinct types.
 * T1 and T2 are deduced independently, allowing the function to 
 * bridge different data domains without manual type conversion.
 */
template <typename T1, typename T2>
void process_system_event(const T1& descriptor, const T2& data)
{
    // The compiler ensures both types support the stream insertion operator.
    // Each unique combination of T1 and T2 results in a specialized instantiation.
    std::cout << "[EVENT: " << descriptor << "] Data: " << data << "\n";
}

int main()
{
    // Case 1: Mapping a string literal (const char*) to a numeric status code (int)
    process_system_event("SYS_INIT", 200);

    // Case 2: Mapping a numeric ID (int) to a floating point telemetry value (float)
    process_system_event(1042, 36.6f);

    // Case 3: Mapping a character code (char) to a string status message (const char*)
    process_system_event('W', "VOLTAGE_UNSTABLE");

    return 0;
}
