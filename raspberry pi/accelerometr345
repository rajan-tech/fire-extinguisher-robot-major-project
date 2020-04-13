#include <iostream>
#include <thread>
#include <chrono>
#include <wiringPiI2C.h>

#define DEVICE_ID 0x53
//sensor is on bus 1 at the address 0x53

#define REG_POWER_CTL   0x2D
#define REG_DATA_X_LOW  0x32
#define REG_DATA_X_HIGH 0x33
#define REG_DATA_Y_LOW  0x34
#define REG_DATA_Y_HIGH 0x35
#define REG_DATA_Z_LOW  0x36
#define REG_DATA_Z_HIGH 0x37

// registers assigned for power control and to store x,y and z axis inputs. The data format of the ADXL345 is 16 bits. Once acceleration data is acquired from data registers, the user must reconstruct the data.
//EX: DATAX0 is the low byte register for X-axis acceleration and DATAX1 is the high byte register.

int main (int argc, char **argv)
{
    // Setup I2C communication
    int fd = wiringPiI2CSetup(DEVICE_ID);
    if (fd == -1) {
        std::cout << "Failed to init I2C communication.\n";
        return -1;
    }
    std::cout << "I2C communication successfully setup.\n";

    // Switch device to measurement mode
    wiringPiI2CWriteReg8(fd, REG_POWER_CTL, 0b00001000);

// wiringPiI2CReadReg16() reads the data from two registers. The acceleration data we want is split into 2 bytes, and is available on 2 adjacent registers.

    while (1) {
        int dataX = wiringPiI2CReadReg16(fd, REG_DATA_X_LOW);
        dataX = -(~(int16_t)dataX + 1);
// Digital output data is formatted as 16-bit two's complement. So we have to transform it to get negative numbers.

        int dataY = wiringPiI2CReadReg16(fd, REG_DATA_Y_LOW);
        dataY = -(~(int16_t)dataY + 1);

        int dataZ = wiringPiI2CReadReg16(fd, REG_DATA_Z_LOW);
        dataZ = -(~(int16_t)dataZ + 1);

        std::cout << "x: " << dataX << ", y: " << dataY << ", z: " << dataZ << "\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(2000));
// Finally we print the result on the terminal, and we add a delay of 2000 ms between 2 reads, so we are basically reading the value from the sensor at around 10Hz.
    }

    return 0;
}
