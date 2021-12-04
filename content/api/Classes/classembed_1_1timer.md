---
title: embed::timer
summary: Timer hardware abstraction interface. Use this interface for devices and peripherals that have timer like capabilities, such that, when a timer's time has expired, an event/interrupt/signal is generated.  

---

**embed::timer Class Reference**

Timer hardware abstraction interface. Use this interface for devices and peripherals that have timer like capabilities, such that, when a timer's time has expired, an event/interrupt/signal is generated. 


`#include <timer.hpp>`

Inherits from [embed::driver<>](classes/classembed_1_1driver/)

## Public Types

|                | Name           |
| -------------- | -------------- |
| enum class| **[controls](classes/classembed_1_1timer/#enum-controls)** { start, stop, reset}<br>Set of controls for a timer.  |
| enum class| **[type](classes/classembed_1_1timer/#enum-type)** { oneshot, continuous}<br>Type of timer.  |

## Public Functions

|                | Name           |
| -------------- | -------------- |
| virtual bool | **[is_running](classes/classembed_1_1timer/#function-is-running)**() =0<br>Determine if the timer is currently running.  |
| virtual void | **[control](classes/classembed_1_1timer/#function-control)**([controls](classes/classembed_1_1timer/#enum-controls) p_control) =0<br>Control the state of the timer.  |
| virtual bool | **[attach_interrupt](classes/classembed_1_1timer/#function-attach-interrupt)**(std::function< void(void)> p_callback, std::chrono::nanoseconds interval, [type](classes/classembed_1_1timer/#enum-type) p_type =[type::continuous](classes/classembed_1_1timer/#enumvalue-continuous)) =0<br>Setup the timer and attach an interrupt to it.  |

## Additional inherited members

**Public Functions inherited from [embed::driver<>](classes/classembed_1_1driver/)**

|                | Name           |
| -------------- | -------------- |
| bool | **[initialize](classes/classembed_1_1driver/#function-initialize)**()<br>Initialize the driver, apply the setting as defined in the settings_t structure and enable it. Calling this function after it has already been initialized will return false. In order to run initialization again, [reset()]() must be called. After initialization, the settings are committed and saved into another settings structure. This settings can be looked up and inspected by the application.  |
| void | **[reset](classes/classembed_1_1driver/#function-reset)**()<br>Reset the driver in order to run initialize again. This is helpful if the application needs to change the settings of a driver after it is first initialized, like baud rate for serial or pull resistor for a pin.  |
| bool | **[is_initialized](classes/classembed_1_1driver/#function-is-initialized)**() const<br>Determine if the driver has been initialized.  |
| settings_t & | **[settings](classes/classembed_1_1driver/#function-settings)**()<br>Get access to uncommitted driver settings.  |
| const settings_t & | **[initialized_settings](classes/classembed_1_1driver/#function-initialized-settings)**() const<br>Get access to the settings that were used in the latest initialization. These settings only get updated when a successful [initialize()](classes/classembed_1_1driver/#function-initialize) has occurred.  |

**Protected Functions inherited from [embed::driver<>](classes/classembed_1_1driver/)**

|                | Name           |
| -------------- | -------------- |
| virtual bool | **[driver_initialize](classes/classembed_1_1driver/#function-driver-initialize)**() =0 |

**Protected Attributes inherited from [embed::driver<>](classes/classembed_1_1driver/)**

|                | Name           |
| -------------- | -------------- |
| settings_t | **[m_settings](classes/classembed_1_1driver/#variable-m-settings)**  |
| settings_t | **[m_initialized_settings](classes/classembed_1_1driver/#variable-m-initialized-settings)**  |
| bool | **[m_initialized](classes/classembed_1_1driver/#variable-m-initialized)**  |


## Public Types Documentation

### enum controls

| Enumerator | Value | Description |
| ---------- | ----- | ----------- |
| start | | Control value to start the timer.   |
| stop | | Control value to stop a timer.   |
| reset | | Control value to reset a timer. The timer shall remain in a running or stopped state after this call. So an ongoing timer will continue to count but will have its counter reset to zero if this control is used. If a timer is stopped, then it shall be reset to zero, and stay stopped.   |



Set of controls for a timer. 

### enum type

| Enumerator | Value | Description |
| ---------- | ----- | ----------- |
| oneshot | | Once the timer's time has been reached an interrupt will fire and the timer will be stopped.   |
| continuous | | Once the timer's time has been reached an interrupt will fire and the timer will be reset and will begin counting again.   |



Type of timer. 

## Public Functions Documentation

### function is_running

```cpp
virtual bool is_running() =0
```

Determine if the timer is currently running. 

**Return**: 

  * true timer is currently running 
  * false timer is currently stopped 


### function control

```cpp
virtual void control(
    controls p_control
) =0
```

Control the state of the timer. 

**Parameters**: 

  * **p_control** new state for the timer 


### function attach_interrupt

```cpp
virtual bool attach_interrupt(
    std::function< void(void)> p_callback,
    std::chrono::nanoseconds interval,
    type p_type =type::continuous
) =0
```

Setup the timer and attach an interrupt to it. 

**Parameters**: 

  * **p_callback** callback function to be called when the timer expires 
  * **interval** the amount of time before the timer expires 
  * **p_type** the type of timer this is 


**Return**: 

  * true successfully set all parameters 
  * false not all parameters could be met such as an interval smaller than is capable by hardware or an unsupported timer type. 


When called this will, stop and reset the timer. To start the timer, `control(controls::start)` must be called.


-------------------------------

Updated on 2021-12-04 at 16:46:01 +0000