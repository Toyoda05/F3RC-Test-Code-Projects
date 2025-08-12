#include "mbed.h"
#include "BNO055/BNO055.hpp"

BNO055 bno(D14, D15);  // SDA, SCL

int main() {
    printf("Starting BNO055 test...\n");

    bno.reset();
    while (!bno.check()) {
        printf("Waiting for BNO055...\n");
        ThisThread::sleep_for(500ms);
    }
    printf("BNO055 detected!\n");

    bno.setmode(OPERATION_MODE_NDOF);

    while (true) {
        bno.get_angles();
        printf("Yaw: %.2f°, Pitch: %.2f°, Roll: %.2f°\n",
               bno.euler.yaw,
               bno.euler.pitch,
               bno.euler.roll);
        ThisThread::sleep_for(100ms);
    }
}
