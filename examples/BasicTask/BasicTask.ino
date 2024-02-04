/**
 * @file BasicTask.ino
 * @author Alex Cajas (https://github.com/alexCajas/)
 * @brief Basic example of creating a basic Task class.
 * @version 0.1
 * 
 */

#include "BasicTask.hpp"


BasicTask task;

void setup(){

Serial.begin(115200);
task.start();

}

void loop(){

    // You can stop the Task
    // task.stop();

    // o or suspend the current execution
    // vTaskSuspend(task.getTaskHandle());
}

