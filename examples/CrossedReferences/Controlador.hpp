#ifndef CONTROLADOR_HPP
#define CONTROLADOR_HPP

#include "Task.h"
/**
 * @brief  Example of a possible solution to crossed object references in C++.
 * 
 */

class ThreadTask;

/**
 * @brief Controlador Has a reference to ThreadTask.
 * 
 */
class Controlador {
    private:
        ThreadTask *thread;
        String nombre;
    public:
        Controlador(String nombre);
        
        /**
         * @brief use run to to start the thread.
         * 
         */
        void start();
        
        String getNombre(){
            return nombre;
        }
};

/**
 * @brief ThreadTask crosses its 
 * reference with Controller by having it as an attribute.
 * 
 */
class ThreadTask : public Task{

    private:
        Controlador *controlador;

        /**
         * @brief Override run function.
         * 
         * @param data 
         */
        void run(void *data);

    public:
        ThreadTask(Controlador* controlador);
    
};

#endif //CONTROLADOR_HPP