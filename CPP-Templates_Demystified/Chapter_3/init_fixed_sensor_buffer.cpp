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
#include <array>

// HAL: Fixed-size sensor buffer (compile-time size)
template<size_t BufferSize, typename SensorData>
std::array<SensorData, BufferSize> init_fixed_sensor_buffer(SensorData initial_reading) {
    std::cout << "BufferSize = " << BufferSize << std::endl;
    return std::array<SensorData, BufferSize>{initial_reading};
}

int main() {
    constexpr size_t len = 10;
    auto temp_buffer = init_fixed_sensor_buffer<len>(25.0f);  // float, N=10
    for (auto val : temp_buffer) std::cout << val << " ";
    std::cout << "\n";

    auto pressure_buffer = init_fixed_sensor_buffer<50>(int16_t{1013});  // int16_t, N=50
    for (auto val : pressure_buffer) std::cout << val << " ";
    std::cout << "\n";

    constexpr size_t len3 = 8;
    auto status_buffer = init_fixed_sensor_buffer<len3>(false);  // bool, N=8
    for (auto val : status_buffer) std::cout << val << " ";
    std::cout << "\n";

    // No manual cleanup - std::array RAII
    return 0;
}
