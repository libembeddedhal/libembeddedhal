---
title: embed::counter
summary: Counter hardware abstraction interface. Use this interface for devices and peripherals that have counting capabilities. Such devices can count up or down. Useful for keeping time. Expect counters to overflow when they reach the end of counting register's limits.  

---

**embed::counter Class Reference**

Counter hardware abstraction interface. Use this interface for devices and peripherals that have counting capabilities. Such devices can count up or down. Useful for keeping time. Expect counters to overflow when they reach the end of counting register's limits. 


`#include <counter.hpp>`

Inherits from [embed::driver<>](classes/classembed_1_1driver/)

## Public Types

|                | Name           |
| -------------- | -------------- |
| enum class| **[controls](classes/classembed_1_1counter/#enum-controls)** { start, stop, reset}<br>Set of controls for a counter.  |

## Public Functions

|                | Name           |
| -------------- | -------------- |
| virtual bool | **[is_running](classes/classembed_1_1counter/#function-is-running)**() =0<br>Determine if the counter is currently running.  |
| virtual void | **[control](classes/classembed_1_1counter/#function-control)**([controls](classes/classembed_1_1counter/#enum-controls) p_control) =0<br>Control the state of the counter.  |
| virtual void | **[period](classes/classembed_1_1counter/#function-period)**(std::chrono::nanoseconds p_period) =0<br>Period for each count of the timer. For example a period of 1ms and a count of 500 would mean that 500ms has elapse since the counter has been started.  |
| virtual std::chrono::nanoseconds | **[period](classes/classembed_1_1counter/#function-period)**() =0<br>Get the current period for the counter.  |
| virtual uint64_t | **[count](classes/classembed_1_1counter/#function-count)**() =0<br>Get the count of the counter.  |

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
| start | | Control value to start the counter.   |
| stop | | Control value to stop a counter.   |
| reset | | Control value to reset a counter. The counter shall remain in a running or stopped state after this call. So an ongoing counter will continue to count but will have its counter reset to zero if this control is used. If a counter is stopped, then it shall be reset to zero, and stay stopped.   |



Set of controls for a counter. 

## Public Functions Documentation

### function is_running

```cpp
virtual bool is_running() =0
```

Determine if the counter is currently running. 

**Return**: 

  * true counter is currently running 
  * false counter is currently stopped 


### function control

```cpp
virtual void control(
    controls p_control
) =0
```

Control the state of the counter. 

**Parameters**: 

  * **p_control** new state for the counter 


### function period

```cpp
virtual void period(
    std::chrono::nanoseconds p_period
) =0
```

Period for each count of the timer. For example a period of 1ms and a count of 500 would mean that 500ms has elapse since the counter has been started. 

**Parameters**: 

  * **p_period** the amount of time each count should be. 


### function period

```cpp
virtual std::chrono::nanoseconds period() =0
```

Get the current period for the counter. 

**Return**: std::chrono::nanoseconds 

### function count

```cpp
virtual uint64_t count() =0
```

Get the count of the counter. 

**Return**: uint64_t current count 

-------------------------------

Updated on 2021-12-04 at 16:46:01 +0000