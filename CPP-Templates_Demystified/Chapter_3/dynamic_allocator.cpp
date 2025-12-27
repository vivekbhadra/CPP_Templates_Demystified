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
#include <vector>
#include <array>  // For NTTP version later

// HAL: Initialize sensor reading buffer (BAE/MBDA style)
template<typename SensorData>
std::vector<SensorData> init_sensor_buffer(SensorData initial_reading, size_t buffer_size) {
    return std::vector<SensorData>(buffer_size, initial_reading);
}

int main() {
    // Temperature sensor (float)
    auto temp_buffer = init_sensor_buffer(25.0f, 100);
    std::cout << "Temp buffer[0]: " << temp_buffer[0] << "\n";

    // Pressure sensor (int16_t)  
    auto pressure_buffer = init_sensor_buffer(int16_t{1013}, 50);
    std::cout << "Pressure buffer[0]: " << pressure_buffer[0] << "\n";

    // Status flags (bool)
    auto status_buffer = init_sensor_buffer(false, 8);
    std::cout << "Status buffer[0]: " << status_buffer[0] << "\n";

    return 0;  // Auto cleanup
}
