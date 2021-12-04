---
title: embed::output_pin
summary: Digital output pin hardware abstraction. Use this to drive a pin HIGH or LOW in order to send a control signal or turn off or on an LED.  

---

**embed::output_pin Class Reference**

Digital output pin hardware abstraction. Use this to drive a pin HIGH or LOW in order to send a control signal or turn off or on an LED. 


`#include <gpio.hpp>`

Inherits from [embed::driver< output_pin_settings >](classes/classembed_1_1driver/)

## Public Functions

|                | Name           |
| -------------- | -------------- |
| virtual void | **[level](classes/classembed_1_1output__pin/#function-level)**(bool p_high) =0<br>Set the state of the pin.  |
| virtual bool | **[level](classes/classembed_1_1output__pin/#function-level)**() const =0<br>Read the state of the input pin. Implementations must read the pin state from hardware and will not simply cache the results from running [level(bool)](classes/classembed_1_1output__pin/#function-level).  |

## Additional inherited members

**Public Functions inherited from [embed::driver< output_pin_settings >](classes/classembed_1_1driver/)**

|                | Name           |
| -------------- | -------------- |
| bool | **[initialize](classes/classembed_1_1driver/#function-initialize)**()<br>Initialize the driver, apply the setting as defined in the settings_t structure and enable it. Calling this function after it has already been initialized will return false. In order to run initialization again, [reset()]() must be called. After initialization, the settings are committed and saved into another settings structure. This settings can be looked up and inspected by the application.  |
| void | **[reset](classes/classembed_1_1driver/#function-reset)**()<br>Reset the driver in order to run initialize again. This is helpful if the application needs to change the settings of a driver after it is first initialized, like baud rate for serial or pull resistor for a pin.  |
| bool | **[is_initialized](classes/classembed_1_1driver/#function-is-initialized)**() const<br>Determine if the driver has been initialized.  |
| settings_t & | **[settings](classes/classembed_1_1driver/#function-settings)**()<br>Get access to uncommitted driver settings.  |
| const settings_t & | **[initialized_settings](classes/classembed_1_1driver/#function-initialized-settings)**() const<br>Get access to the settings that were used in the latest initialization. These settings only get updated when a successful [initialize()](classes/classembed_1_1driver/#function-initialize) has occurred.  |

**Protected Functions inherited from [embed::driver< output_pin_settings >](classes/classembed_1_1driver/)**

|                | Name           |
| -------------- | -------------- |
| virtual bool | **[driver_initialize](classes/classembed_1_1driver/#function-driver-initialize)**() =0 |

**Protected Attributes inherited from [embed::driver< output_pin_settings >](classes/classembed_1_1driver/)**

|                | Name           |
| -------------- | -------------- |
| settings_t | **[m_settings](classes/classembed_1_1driver/#variable-m-settings)**  |
| settings_t | **[m_initialized_settings](classes/classembed_1_1driver/#variable-m-initialized-settings)**  |
| bool | **[m_initialized](classes/classembed_1_1driver/#variable-m-initialized)**  |


## Public Functions Documentation

### function level

```cpp
virtual void level(
    bool p_high
) =0
```

Set the state of the pin. 

**Parameters**: 

  * **p_high** if true then the pin state is set to HIGH voltage. If false, the pin state is set to LOW voltage. 


### function level

```cpp
virtual bool level() const =0
```

Read the state of the input pin. Implementations must read the pin state from hardware and will not simply cache the results from running [level(bool)](classes/classembed_1_1output__pin/#function-level). 

**Return**: 

  * true indicates a HIGH voltage 
  * false indicates a LOW voltage 


-------------------------------

Updated on 2021-12-04 at 16:46:01 +0000