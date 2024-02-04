#ifndef TASKHELLO_H
#define TASKHELLO_H

#include "Task.h"

/**
 * @brief Prints the word "Hello", by Serial terminal.
 * 
 */
class TaskHello : public Task{
    private:
        
        SemaphoreHandle_t * helloMutex;
        SemaphoreHandle_t * worldMutex;
        

        void run (void * data){
            while(true){
                xSemaphoreTake((*helloMutex),portMAX_DELAY);
                Serial.print("Hello ");
                xSemaphoreGive((*worldMutex));
            }
        }
    public:
        TaskHello(SemaphoreHandle_t * helloMutex,SemaphoreHandle_t *worldMutex): Task("TaskHello",1024,TaskPrio_Low){
            this->helloMutex = helloMutex;
            this->worldMutex = worldMutex;
        }

        
};

#endif