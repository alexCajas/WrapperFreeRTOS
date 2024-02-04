/**
 * @file BasicQeueue.ino
 * @author Alex Cajas (https://github.com/alexCajas/WrapperFreeRTOS)
 * @brief In this example, it is demonstrated how to 
 * coordinate two threads and exchange messages using a queue mutex. 
 * TaskHello, TaskHello receives a message from TaskWorldQueue and prints it on the Serial terminal.
 * TaskWorld receives a message from TaskHelloQueue and prints it on the Serial terminal.
 * @version 0.1
 * 
 */

#include "TaskHelloQ.h"
#include "TaskWorldQ.h"

TaskHelloQueue *taskHello;
TaskWorldQueue *taskWorld;

QueueHandle_t queueHello;
QueueHandle_t queueWorld;

void setup(){
    Serial.begin(115200);
    queueHello = xQueueCreate( 1, sizeof(String) );  
    queueWorld = xQueueCreate( 1, sizeof(String));

    if(queueHello == NULL || queueWorld == NULL ){
        Serial.println("Failed to create the queue");
        ESP.restart();
    }

    taskHello = new TaskHelloQueue(&queueHello, &queueWorld);
    taskWorld = new TaskWorldQueue(&queueHello, &queueWorld);

    taskHello->start();
    taskWorld->start();
}

void loop(){
    // your code
}