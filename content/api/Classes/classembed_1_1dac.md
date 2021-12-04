---
title: embed::dac
summary: Digital to Analog Converter (DAC) hardware abstraction interface. Use this interface for devices and peripherals that can create arbitrary analog voltages between a defined LOW and HIGH voltage.  

---

**embed::dac Class Reference**

Digital to Analog Converter (DAC) hardware abstraction interface. Use this interface for devices and peripherals that can create arbitrary analog voltages between a defined LOW and HIGH voltage. 


`#include <dac.hpp>`

Inherits from [embed::driver<>](classes/classembed_1_1driver/)

## Public Functions

|                | Name           |
| -------------- | -------------- |
| virtual void | **[write](classes/classembed_1_1dac/#function-write)**([full_scale](classes/classembed_1_1full__scale/)< uint32_t > value) =0<br>Generate a voltage between a defined LOW and HIGH voltage. The LOW and HIGH voltage are generally configured by a reference voltage (usually denoted Vref) connected to the device. Generally though, the low voltage is 0V and the high voltage reference is VCC.  |

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


## Public Functions Documentation

### function write

```cpp
virtual void write(
    full_scale< uint32_t > value
) =0
```

Generate a voltage between a defined LOW and HIGH voltage. The LOW and HIGH voltage are generally configured by a reference voltage (usually denoted Vref) connected to the device. Generally though, the low voltage is 0V and the high voltage reference is VCC. 

**Parameters**: 

  * **value** precentage scale from LOW to HIGH 


-------------------------------

Updated on 2021-12-04 at 16:46:01 +0000