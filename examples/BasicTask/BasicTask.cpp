#include "BasicTask.hpp"

BasicTask::BasicTask(): Task("task",1024,TaskPrio_Low){

}

void BasicTask::run(void *data)
{
    while (true)
    {
        Serial.println(this->getName());
        vTaskDelay(1000);
    }
}