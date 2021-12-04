---
title: embed::driver
summary: The basis class for all peripheral, device and system drivers in libembeddedhal.  

---

**embed::driver Class Reference**

The basis class for all peripheral, device and system drivers in libembeddedhal.  [More...](#detailed-description)


`#include <driver.hpp>`

Inherited by [embed::adc](classes/classembed_1_1adc/), [embed::can_network](classes/classembed_1_1can__network/), [embed::counter](classes/classembed_1_1counter/), [embed::dac](classes/classembed_1_1dac/), [embed::pwm](classes/classembed_1_1pwm/), [embed::timer](classes/classembed_1_1timer/)

## Public Functions

|                | Name           |
| -------------- | -------------- |
| bool | **[initialize](classes/classembed_1_1driver/#function-initialize)**()<br>Initialize the driver, apply the setting as defined in the settings_t structure and enable it. Calling this function after it has already been initialized will return false. In order to run initialization again, [reset()]() must be called. After initialization, the settings are committed and saved into another settings structure. This settings can be looked up and inspected by the application.  |
| void | **[reset](classes/classembed_1_1driver/#function-reset)**()<br>Reset the driver in order to run initialize again. This is helpful if the application needs to change the settings of a driver after it is first initialized, like baud rate for serial or pull resistor for a pin.  |
| bool | **[is_initialized](classes/classembed_1_1driver/#function-is-initialized)**() const<br>Determine if the driver has been initialized.  |
| settings_t & | **[settings](classes/classembed_1_1driver/#function-settings)**()<br>Get access to uncommitted driver settings.  |
| const settings_t & | **[initialized_settings](classes/classembed_1_1driver/#function-initialized-settings)**() const<br>Get access to the settings that were used in the latest initialization. These settings only get updated when a successful [initialize()](classes/classembed_1_1driver/#function-initialize) has occurred.  |

## Protected Functions

|                | Name           |
| -------------- | -------------- |
| virtual bool | **[driver_initialize](classes/classembed_1_1driver/#function-driver-initialize)**() =0 |

## Protected Attributes

|                | Name           |
| -------------- | -------------- |
| settings_t | **[m_settings](classes/classembed_1_1driver/#variable-m-settings)**  |
| settings_t | **[m_initialized_settings](classes/classembed_1_1driver/#variable-m-initialized-settings)**  |
| bool | **[m_initialized](classes/classembed_1_1driver/#variable-m-initialized)**  |

## Detailed Description

```cpp
template <class settings_t  =no_settings>
class embed::driver;
```

The basis class for all peripheral, device and system drivers in libembeddedhal. 

**Template Parameters**: 

  * **settings_t** generic settings for the driver. For example, generic settings for a uart driver would have baud rate, stop bits and parity. This is expected of all UART devices and as such is part of the systems API. 

## Public Functions Documentation

### function initialize

```cpp
inline bool initialize()
```

Initialize the driver, apply the setting as defined in the settings_t structure and enable it. Calling this function after it has already been initialized will return false. In order to run initialization again, [reset()]() must be called. After initialization, the settings are committed and saved into another settings structure. This settings can be looked up and inspected by the application. 

**Return**: 

  * true - initialization of the driver was successful 
  * false - initialization of the driver failed. See the error() function for details about exactly what failed. 


### function reset

```cpp
inline void reset()
```

Reset the driver in order to run initialize again. This is helpful if the application needs to change the settings of a driver after it is first initialized, like baud rate for serial or pull resistor for a pin. 

### function is_initialized

```cpp
inline bool is_initialized() const
```

Determine if the driver has been initialized. 

**Return**: 

  * true the driver is initialized 
  * false the driver has not been initialized or has been reset 


### function settings

```cpp
inline settings_t & settings()
```

Get access to uncommitted driver settings. 

**Return**: settings_t& reference to the uncommitted driver settings. When initialize runs successful, the uncommitted settings will be saved to the initialize_settings(). 

### function initialized_settings

```cpp
inline const settings_t & initialized_settings() const
```

Get access to the settings that were used in the latest initialization. These settings only get updated when a successful [initialize()](classes/classembed_1_1driver/#function-initialize) has occurred. 

**Return**: const settings_t& the current settings of the driver if it is initialized. If the driver is not initialized, then the contents of this structure should be ignored as they may not represent the current of the driver. 

## Protected Functions Documentation

### function driver_initialize

```cpp
virtual bool driver_initialize() =0
```


**Reimplemented by**: [embed::can_network::driver_initialize](classes/classembed_1_1can__network/#function-driver-initialize)


## Protected Attributes Documentation

### variable m_settings

```cpp
settings_t m_settings {};
```


### variable m_initialized_settings

```cpp
settings_t m_initialized_settings {};
```


### variable m_initialized

```cpp
bool m_initialized = false;
```


-------------------------------

Updated on 2021-12-04 at 16:46:01 +0000