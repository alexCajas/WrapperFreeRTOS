/**
 * @file CrossedReferences.ino
 * @author Alex Cajas (https://github.com/alexCajas/)
 * @brief Basic example to use crossed references in c++.
 * @version 0.1
 */

#include "Controlador.hpp"

Controlador controlador("Home controller");

void setup(){
    Serial.begin(115200);
    controlador.start();
}

void loop(){
    //your code.
}