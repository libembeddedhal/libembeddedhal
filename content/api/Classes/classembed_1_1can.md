---
title: embed::can


---

**embed::can Class Reference**




`#include <can.hpp>`

Inherits from [embed::driver< can_settings >](classes/classembed_1_1driver/)

## Public Classes

|                | Name           |
| -------------- | -------------- |
| struct | **[message_t](classes/structembed_1_1can_1_1message__t/)**  |

## Public Types

|                | Name           |
| -------------- | -------------- |
| using uint32_t | **[id_t](classes/classembed_1_1can/#using-id-t)**  |

## Public Functions

|                | Name           |
| -------------- | -------------- |
| virtual void | **[send](classes/classembed_1_1can/#function-send)**(const [message_t](classes/structembed_1_1can_1_1message__t/) & p_message) =0 |
| virtual [message_t](classes/structembed_1_1can_1_1message__t/) | **[receive](classes/classembed_1_1can/#function-receive)**() =0 |
| virtual bool | **[has_data](classes/classembed_1_1can/#function-has-data)**() =0 |
| virtual void | **[attach_interrupt](classes/classembed_1_1can/#function-attach-interrupt)**(std::function< void([can](classes/classembed_1_1can/) &)> p_receive_handler) =0<br>Will attach an interrupt to this can driver such that, when a message is received, it will call the handler supplied.  |

## Additional inherited members

**Public Functions inherited from [embed::driver< can_settings >](classes/classembed_1_1driver/)**

|                | Name           |
| -------------- | -------------- |
| bool | **[initialize](classes/classembed_1_1driver/#function-initialize)**()<br>Initialize the driver, apply the setting as defined in the settings_t structure and enable it. Calling this function after it has already been initialized will return false. In order to run initialization again, [reset()]() must be called. After initialization, the settings are committed and saved into another settings structure. This settings can be looked up and inspected by the application.  |
| void | **[reset](classes/classembed_1_1driver/#function-reset)**()<br>Reset the driver in order to run initialize again. This is helpful if the application needs to change the settings of a driver after it is first initialized, like baud rate for serial or pull resistor for a pin.  |
| bool | **[is_initialized](classes/classembed_1_1driver/#function-is-initialized)**() const<br>Determine if the driver has been initialized.  |
| settings_t & | **[settings](classes/classembed_1_1driver/#function-settings)**()<br>Get access to uncommitted driver settings.  |
| const settings_t & | **[initialized_settings](classes/classembed_1_1driver/#function-initialized-settings)**() const<br>Get access to the settings that were used in the latest initialization. These settings only get updated when a successful [initialize()](classes/classembed_1_1driver/#function-initialize) has occurred.  |

**Protected Functions inherited from [embed::driver< can_settings >](classes/classembed_1_1driver/)**

|                | Name           |
| -------------- | -------------- |
| virtual bool | **[driver_initialize](classes/classembed_1_1driver/#function-driver-initialize)**() =0 |

**Protected Attributes inherited from [embed::driver< can_settings >](classes/classembed_1_1driver/)**

|                | Name           |
| -------------- | -------------- |
| settings_t | **[m_settings](classes/classembed_1_1driver/#variable-m-settings)**  |
| settings_t | **[m_initialized_settings](classes/classembed_1_1driver/#variable-m-initialized-settings)**  |
| bool | **[m_initialized](classes/classembed_1_1driver/#variable-m-initialized)**  |


## Public Types Documentation

### using id_t

```cpp
using embed::can::id_t =  uint32_t;
```


## Public Functions Documentation

### function send

```cpp
virtual void send(
    const message_t & p_message
) =0
```


### function receive

```cpp
virtual message_t receive() =0
```


### function has_data

```cpp
virtual bool has_data() =0
```


### function attach_interrupt

```cpp
virtual void attach_interrupt(
    std::function< void(can &)> p_receive_handler
) =0
```

Will attach an interrupt to this can driver such that, when a message is received, it will call the handler supplied. 

**Parameters**: 

  * **p_receive_handler** - Handler to be called when a message is received. If this is set to nullptr, then this function shall disable the can interrupt or replace the interrupt with a function that does nothing, but still clears the interrupt service routine. 


-------------------------------

Updated on 2021-12-04 at 16:46:01 +0000