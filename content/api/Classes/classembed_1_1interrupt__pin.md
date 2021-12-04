---
title: embed::interrupt_pin
summary: Digital interrupt pin hardware abstraction. Use this to trigger an interrupt service routine (ISR) when a pin detects a falling edge (when the pin's voltage transitions from HIGH to LOW), a rising edge (when the pin's voltage transitions from LOW to HIGH), or any transition of state on the pin.  

---

**embed::interrupt_pin Class Reference**

Digital interrupt pin hardware abstraction. Use this to trigger an interrupt service routine (ISR) when a pin detects a falling edge (when the pin's voltage transitions from HIGH to LOW), a rising edge (when the pin's voltage transitions from LOW to HIGH), or any transition of state on the pin. 


`#include <gpio.hpp>`

Inherits from [embed::driver< interrupt_pin_settings >](classes/classembed_1_1driver/)

## Public Types

|                | Name           |
| -------------- | -------------- |
| enum class| **[trigger_edge](classes/classembed_1_1interrupt__pin/#enum-trigger-edge)** { falling = 0, rising = 1, both = 2}<br>The condition in which an interrupt is triggered.  |

## Public Functions

|                | Name           |
| -------------- | -------------- |
| virtual bool | **[level](classes/classembed_1_1interrupt__pin/#function-level)**() const =0<br>Return the voltage level of the pin.  |
| virtual void | **[attach_interrupt](classes/classembed_1_1interrupt__pin/#function-attach-interrupt)**(std::function< void(void)> p_callback, [trigger_edge](classes/classembed_1_1interrupt__pin/#enum-trigger-edge) p_trigger) =0<br>Enable interrupts for this pin. Pass in the callback to be executed when the trigger condition is met. This function can be called multiple times if the callback or trigger conditions need to be changed. detach_interrupts() does not need to be called before re-running this function.  |
| virtual void | **[detach_interrupt](classes/classembed_1_1interrupt__pin/#function-detach-interrupt)**() =0<br>Disable interrupts for this pin.  |

## Additional inherited members

**Public Functions inherited from [embed::driver< interrupt_pin_settings >](classes/classembed_1_1driver/)**

|                | Name           |
| -------------- | -------------- |
| bool | **[initialize](classes/classembed_1_1driver/#function-initialize)**()<br>Initialize the driver, apply the setting as defined in the settings_t structure and enable it. Calling this function after it has already been initialized will return false. In order to run initialization again, [reset()]() must be called. After initialization, the settings are committed and saved into another settings structure. This settings can be looked up and inspected by the application.  |
| void | **[reset](classes/classembed_1_1driver/#function-reset)**()<br>Reset the driver in order to run initialize again. This is helpful if the application needs to change the settings of a driver after it is first initialized, like baud rate for serial or pull resistor for a pin.  |
| bool | **[is_initialized](classes/classembed_1_1driver/#function-is-initialized)**() const<br>Determine if the driver has been initialized.  |
| settings_t & | **[settings](classes/classembed_1_1driver/#function-settings)**()<br>Get access to uncommitted driver settings.  |
| const settings_t & | **[initialized_settings](classes/classembed_1_1driver/#function-initialized-settings)**() const<br>Get access to the settings that were used in the latest initialization. These settings only get updated when a successful [initialize()](classes/classembed_1_1driver/#function-initialize) has occurred.  |

**Protected Functions inherited from [embed::driver< interrupt_pin_settings >](classes/classembed_1_1driver/)**

|                | Name           |
| -------------- | -------------- |
| virtual bool | **[driver_initialize](classes/classembed_1_1driver/#function-driver-initialize)**() =0 |

**Protected Attributes inherited from [embed::driver< interrupt_pin_settings >](classes/classembed_1_1driver/)**

|                | Name           |
| -------------- | -------------- |
| settings_t | **[m_settings](classes/classembed_1_1driver/#variable-m-settings)**  |
| settings_t | **[m_initialized_settings](classes/classembed_1_1driver/#variable-m-initialized-settings)**  |
| bool | **[m_initialized](classes/classembed_1_1driver/#variable-m-initialized)**  |


## Public Types Documentation

### enum trigger_edge

| Enumerator | Value | Description |
| ---------- | ----- | ----------- |
| falling | 0| Trigger and interrupt when a pin transitions from HIGH voltage to LOW voltage.   |
| rising | 1| Trigger and interrupt when a pin transitions from LOW voltage to HIGH voltage.   |
| both | 2| Trigger and interrupt when a pin transitions it state.   |



The condition in which an interrupt is triggered. 

## Public Functions Documentation

### function level

```cpp
virtual bool level() const =0
```

Return the voltage level of the pin. 

**Return**: 

  * true HIGH voltage 
  * false LOW voltage 


### function attach_interrupt

```cpp
virtual void attach_interrupt(
    std::function< void(void)> p_callback,
    trigger_edge p_trigger
) =0
```

Enable interrupts for this pin. Pass in the callback to be executed when the trigger condition is met. This function can be called multiple times if the callback or trigger conditions need to be changed. detach_interrupts() does not need to be called before re-running this function. 

**Parameters**: 

  * **p_callback** function to execute when the trigger condition is met 
  * **p_trigger** the trigger condition that will signal the system to run the callback. 


### function detach_interrupt

```cpp
virtual void detach_interrupt() =0
```

Disable interrupts for this pin. 

-------------------------------

Updated on 2021-12-04 at 16:46:01 +0000