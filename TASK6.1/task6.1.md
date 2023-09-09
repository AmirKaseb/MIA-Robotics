## Code Overview

The provided code is for interfacing with an MPU6050 gyroscope sensor using an Arduino or similar microcontroller. It reads gyroscope data from the sensor, calculates the yaw angle, and prints it to the serial monitor.

### MPU6050 Sensor

The MPU6050 is a popular gyroscope and accelerometer sensor that communicates via the I2C protocol. In this code, it's set up with the following key parameters:

- I2C Address: 0x68
- Gyroscope Configuration Register: 0x1B
- Gyroscope Z-Axis Data Registers: 0x47 (high byte) and 0x48 (low byte)
- Gyroscope Scale: +/- 500 degrees per second

## Code Logic

1. The code initializes communication with the MPU6050 sensor and configures the gyroscope's scale to +/- 500 degrees per second.

2. In the `loop()` function:
   - It reads the gyroscope's Z-axis data from the sensor.
   - Calculates the yaw angle using the gyroscope data and a time interval.
   - Prints the yaw angle to the serial monitor.
## Data Filtering 


**Q: If the Sensor is surrounded by a noisy environment, what type of filter could be used, and what is the recommended cutoff frequency depending on the sensor datasheet?**

In a noisy environment, it is recommended to use a digital low-pass filter (DLPF) to filter the gyroscope data from the MPU6050 sensor. The MPU6050 datasheet provides various DLPF settings that allow you to configure the cutoff frequency to suit your noise conditions and application requirements.

- **DLPF_CFG = 0**: Disables the DLPF, providing the highest bandwidth (8 kHz).
- **DLPF_CFG = 1 to 6**: Enables the DLPF with different cutoff frequencies. Higher values correspond to lower cutoff frequencies:
  - **DLPF_CFG = 1**: 184 Hz cutoff frequency
  - **DLPF_CFG = 2**: 94 Hz cutoff frequency
  - **DLPF_CFG = 3**: 44 Hz cutoff frequency
  - **DLPF_CFG = 4**: 21 Hz cutoff frequency
  - **DLPF_CFG = 5**: 10 Hz cutoff frequency
  - **DLPF_CFG = 6**: 5 Hz cutoff frequency