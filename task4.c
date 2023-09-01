#include <stdio.h>
#include <math.h>

float mpu6050[10] = {0.0, 11.68, 18.95, 23.56, 25.72, 25.38, 22.65, 18.01, 10.14, -0.26};
float bno55[10] = {0.0, 9.49, 16.36, 21.2, 23.16, 22.8, 19.5, 14.85, 6.79, -2.69};

const float mpu6050_accuracy = 0.78;
const float bno55_accuracy = 0.92;

float weightedAverage(float val1, float val2, float acc1, float acc2) {
    float weight1 = 1.0 / (acc1 * acc1);
    float weight2 = 1.0 / (acc2 * acc2);
    return (weight1 * val1 + weight2 * val2) / (weight1 + weight2);
}

int main() {
    float fusedMeasurement[10];

    printf("Fused Measurement:\n");

    for (int i = 0; i < 10; ++i) {
        fusedMeasurement[i] = weightedAverage(mpu6050[i], bno55[i], mpu6050_accuracy, bno55_accuracy);

        printf("%f ", fusedMeasurement[i]);
    }
    printf("\n");

    return 0;
}