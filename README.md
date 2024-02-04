<p align="center">

## [click para versión en español](https://github.com/alexCajas/WrapperFreeRTOS/blob/main/SpanishReadme.md)

</p>


[![Esp8266](https://img.shields.io/badge/soc-ESP8266-green)](https://www.espressif.com/en/products/socs/esp8266)
[![Esp32](https://img.shields.io/badge/soc-ESP32-orange)]()
[![Arduino](https://img.shields.io/badge/platform-Arduino-green)](https://www.arduino.cc/)
![C++](https://img.shields.io/badge/-C%2B%2B-red)
[![FreeRTOS](https://img.shields.io/badge/-FreeRTOS-blue)](https://github.com/espressif/ESP8266_RTOS_SDK)
[![RTOS](https://img.shields.io/badge/-RTOS-blue)](https://github.com/espressif/ESP8266_RTOS_SDK)
[![RTOSArduCore](https://img.shields.io/badge/-esp8266RTOSArduCore-blue)](https://github.com/alexCajas/esp8266RTOSArduCore)
[![Release](https://img.shields.io/github/v/release/alexCajas/WrapperFreeRTOS)](https://github.com/alexCajas/WrapperFreeRTOS/releases/latest)

# WrapperFreeRTOS

**FreeRTOS C++ Wrapper** for easy use of the main concurrency utilities from FreeRTOS in **OOP**,compatible with **Arduino core** and tested on an  **ESP32** and **ESP8266**. Note that you must to use [esp8266RTOSArdoArduCore](https://github.com/alexCajas/esp8266RTOSArduCore) to use this library with **esp8266**.

It is based on the wrappers by **Neil Kolban** [https://github.com/nkolban/esp32-snippets/blob/master/cpp_utils/Task.cpp], and **Richard Damon** [https://github.com/richard-damon/FreeRTOScpp/blob/master/TaskCPP.h] .

---

## Examples:

* **BasicTask:** Creation of a concurrent object.

* **BasicMutex:** Coordination between two concurrent objects using a mutex or binary semaphore.

* **BasicSemaphore:** Typical problem of a slow producer and several fast consumers, solved using a "counting semaphore."

* **BasicQueue:** Data transmission using QueueHandle_t between two concurrent objects.  

* **CrossedReferences:** Example of a possible solution to crossed object references in C++.

---

## Wrapper Adaptation

* The adaptation of the Task.h and Task.cpp wrapper (nKolban) involved replacing the std::string library with Arduino.h and redefining any variable and argument of type std::string or other std:: with its corresponding in Arduino.h. Note that it adapts according to the parameters passed to the functions for creating and manipulating TaskHandle_t.

* The stack size value is replaced from uint8 to uint32 since xcreateTask() receives a uint32.

* An enum (TaskPriority) is added that collects the numeric value of the different predefined priorities in the version of FreeRTOS used in your project (Richard Damon).

* The method xTaskHandle getTaskHandle() is added.

---

## Bibliography

* [https://github.com/nkolban/esp32-snippets/blob/master/cpp_utils/Task.cpp]

* [https://github.com/richard-damon/FreeRTOScpp/blob/master/TaskCPP.h]


---

## Licencia
* MIT License
