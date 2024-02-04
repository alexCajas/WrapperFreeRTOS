#ifndef BASICTASK_HPP
#define BASICTASK_HPP

#include "Task.h"
/**
 * @brief cpp

Object inheriting from Task must implement the run method. 
Additionally, note that the Task constructor takes an empty string ("") 
despite being defined to receive a const char* taskName. 
Passing a variable like const char* name = "name" to the constructor, 
as in the example:
 * SomeClass(const char* name):Task(name,...) 
results in a loadException error. 
 * The correct usage in the Task constructor is:
 * Task("name",...)
 */
class BasicTask : public Task{
    public:
        BasicTask();
        // override run function of Task interface. 
        void run (void *data);
};

#endif //BASICTASK_H