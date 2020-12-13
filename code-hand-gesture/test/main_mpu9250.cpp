#include <MPU9250_asukiaaa.h>

#ifdef _ESP32_HAL_I2C_H_
#define SDA_PIN 21
#define SCL_PIN 22
#endif

MPU9250_asukiaaa mySensor;
float aX, aY, aZ, aSqrt, gX, gY, gZ;

void setup() {
    Serial.begin(115200);
    while (!Serial)
        ;
    Serial.println("started");

#ifdef _ESP32_HAL_I2C_H_ // For ESP32
    Wire.begin(SDA_PIN, SCL_PIN);
    mySensor.setWire(&Wire);
#endif

    mySensor.beginAccel();
    mySensor.beginGyro();
}

void loop() {
    uint8_t sensorId;
    if (mySensor.readId(&sensorId) == 0) {
        Serial.println("sensorId: " + String(sensorId));
    }
    else {
        Serial.println("Cannot read sensorId");
    }

    if (mySensor.accelUpdate() == 0) {
        aX = mySensor.accelX()*100;
        aY = mySensor.accelY()*100;
        aZ = mySensor.accelZ()*100;
        aSqrt = mySensor.accelSqrt();
        Serial.println("accelX: " + String(aX));
        Serial.println("accelY: " + String(aY));
        Serial.println("accelZ: " + String(aZ));
        Serial.println("accelSqrt: " + String(aSqrt));
    }
    else {
        Serial.println("Cannod read accel values");
    }

    if (mySensor.gyroUpdate() == 0) {
        gX = mySensor.gyroX();
        gY = mySensor.gyroY();
        gZ = mySensor.gyroZ();
        Serial.println("gyroX: " + String(gX));
        Serial.println("gyroY: " + String(gY));
        Serial.println("gyroZ: " + String(gZ));
    }
    else {
        Serial.println("Cannot read gyro values");
    }

    //Serial.println("at " + String(millis()) + "ms");
    Serial.println(""); // Add an empty line
    delay(300);
}