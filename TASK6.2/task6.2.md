# Code Documentation

## Overview

This code snippet is designed to read and filter encoder data from a rotary encoder using an Arduino or similar microcontroller. The encoder data is filtered using a low-pass filter, and the filtered value is printed to the serial monitor.

## Key Components

- Encoder Pins: `encoderPinA` and `encoderPinB` are used to connect the encoder channels A and B, respectively.
- Filter Parameters: `cutoffFrequency` and `samplingRate` are adjustable parameters for configuring the low-pass filter.
- Smoothing Factor: `alpha` is calculated based on the filter parameters to control the filtering effect.

## Setup

- Pin modes for `encoderPinA` and `encoderPinB` are set to `INPUT`.
- An interrupt is attached to `encoderPinA` to trigger the `updateEncoder` function when there's a change in its state.
- Serial communication is initialized for monitoring.

## Loop

- The filtered encoder value is read and stored in `currentValue`.
- `currentValue` is printed to the serial monitor.

## `updateEncoder` Function

- Reads the state of `encoderPinB` to determine the direction of rotation.
- Updates the `encoderValue` based on the state of `encoderPinB`.
- Applies a low-pass filter to update the `filteredValue` using the calculated `alpha` value.

This code can be used as a basis for projects involving rotary encoders and data filtering. Adjust the `cutoffFrequency` and `samplingRate` values to customize the filtering effect to your specific requirements.
