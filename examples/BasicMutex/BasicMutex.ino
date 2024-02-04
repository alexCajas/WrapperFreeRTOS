/**
 * @file BasicMutex.ino
 * @author Alex Cajas (https://github.com/alexCajas/WrapperFreeRTOS)
 * @brief In this example, 
 * it is shown how to coordinate two threads using a mutex.
 * 
 * TaskHello prints the word "Hello", by Serial terminal.
 * TaskWorld, prints the word "World" by Serial terminal.
 * @version 0.1
 * 
 */

#include "TaskHello.h"
#include "TaskWorld.h"

TaskHello *taskHello;
TaskWorld *taskWorld;

SemaphoreHandle_t mutexHello;
SemaphoreHandle_t mutexWorld;

void setup(){
    Serial.begin(115200);
    mutexHello = xSemaphoreCreateMutex();  
    mutexWorld = xSemaphoreCreateMutex();

    if(mutexHello == NULL || mutexWorld == NULL ){
        Serial.println("Failed to create mutex");
        ESP.restart();
    }

    taskHello = new TaskHello(&mutexHello, &mutexWorld);
    taskWorld = new TaskWorld(&mutexHello, &mutexWorld);

    // set worldMutex to 0;
    xSemaphoreTake(mutexWorld,portMAX_DELAY);

    taskHello->start();
    taskWorld->start();
}

void loop(){
    // your code.
}