---
title: embed::can_network
summary: can_network is a canbus message receiver handler and  

---

**embed::can_network Class Reference**

[can_network]() is a canbus message receiver handler and 


`#include <can_network.hpp>`

Inherits from [embed::driver<>](classes/classembed_1_1driver/)

## Public Classes

|                | Name           |
| -------------- | -------------- |
| class | **[node_t](classes/classembed_1_1can__network_1_1node__t/)**  |

## Public Functions

|                | Name           |
| -------------- | -------------- |
| | **[can_network](classes/classembed_1_1can__network/#function-can-network)**([can](classes/classembed_1_1can/) & p_can, std::pmr::memory_resource & p_memory_resource) |
| virtual bool | **[driver_initialize](classes/classembed_1_1can__network/#function-driver-initialize)**() override |
| [node_t](classes/classembed_1_1can__network_1_1node__t/) * | **[register_message_id](classes/classembed_1_1can__network/#function-register-message-id)**([can::id_t](classes/classembed_1_1can/#using-id-t) id) |
| void | **[manually_call_receive_handler](classes/classembed_1_1can__network/#function-manually-call-receive-handler)**() |
| [can](classes/classembed_1_1can/) & | **[bus](classes/classembed_1_1can__network/#function-bus)**() |
| const auto & | **[GetInternalMap](classes/classembed_1_1can__network/#function-getinternalmap)**() |

## Additional inherited members

**Public Functions inherited from [embed::driver<>](classes/classembed_1_1driver/)**

|                | Name           |
| -------------- | -------------- |
| bool | **[initialize](classes/classembed_1_1driver/#function-initialize)**()<br>Initialize the driver, apply the setting as defined in the settings_t structure and enable it. Calling this function after it has already been initialized will return false. In order to run initialization again, [reset()]() must be called. After initialization, the settings are committed and saved into another settings structure. This settings can be looked up and inspected by the application.  |
| void | **[reset](classes/classembed_1_1driver/#function-reset)**()<br>Reset the driver in order to run initialize again. This is helpful if the application needs to change the settings of a driver after it is first initialized, like baud rate for serial or pull resistor for a pin.  |
| bool | **[is_initialized](classes/classembed_1_1driver/#function-is-initialized)**() const<br>Determine if the driver has been initialized.  |
| settings_t & | **[settings](classes/classembed_1_1driver/#function-settings)**()<br>Get access to uncommitted driver settings.  |
| const settings_t & | **[initialized_settings](classes/classembed_1_1driver/#function-initialized-settings)**() const<br>Get access to the settings that were used in the latest initialization. These settings only get updated when a successful [initialize()](classes/classembed_1_1driver/#function-initialize) has occurred.  |

**Protected Attributes inherited from [embed::driver<>](classes/classembed_1_1driver/)**

|                | Name           |
| -------------- | -------------- |
| settings_t | **[m_settings](classes/classembed_1_1driver/#variable-m-settings)**  |
| settings_t | **[m_initialized_settings](classes/classembed_1_1driver/#variable-m-initialized-settings)**  |
| bool | **[m_initialized](classes/classembed_1_1driver/#variable-m-initialized)**  |


## Public Functions Documentation

### function can_network

```cpp
inline can_network(
    can & p_can,
    std::pmr::memory_resource & p_memory_resource
)
```


**Parameters**: 

  * **can** - CAN peripheral to manage the network of. 
  * **memory_resource** - pointer to a memory resource. 


### function driver_initialize

```cpp
inline virtual bool driver_initialize() override
```


**Reimplements**: [embed::driver::driver_initialize](classes/classembed_1_1driver/#function-driver-initialize)


### function register_message_id

```cpp
inline node_t * register_message_id(
    can::id_t id
)
```


**Parameters**: 

  * **id** - Associated ID of messages to be stored. 


**Exceptions**: 

  * **std::bad_alloc** if this static storage allocated for this object is not enough to hold 


**Return**: node_t* - reference to the CANBUS network [node_t](classes/classembed_1_1can__network_1_1node__t/) which can be used at anytime to retreive the latest received message from the CANBUS that is associated with the set ID. 

In order for a CAN message with an associated ID to be stored in the [can_network](classes/classembed_1_1can__network/), it must be declared using this method. For example if you expect to get the following IDs 0x140, 0x7AA, and 0x561 from the CAN bus, then this method must be called as such:



```cpp
node_t * motor_node       = can_network.register_message_id(0x140);
node_t * encoder_node     = can_network.register_message_id(0x561);
node_t * temperature_node = can_network.register_message_id(0x7AA);
```


### function manually_call_receive_handler

```cpp
inline void manually_call_receive_handler()
```


Manually call the receive handler. This is useful for unit testing and for CANBUS peripherals that do NOT have a receive message interrupt routine. In the later case, a software (potentially a thread) can perform the receive call manually to extract messages from the CAN peripheral FIFO. This method cannot guarantee that data is not lost if the FIFO fills up. 


### function bus

```cpp
inline can & bus()
```


Return the CAN peripheral object which can be used to initialize, configure, and enable the peripheral as well as transmit messages. Access to this object, if a [can_network](classes/classembed_1_1can__network/)


### function GetInternalMap

```cpp
inline const auto & GetInternalMap()
```


Meant for testing purposes or when direct inspection of the map is useful in userspace. Should not be used in by libraries. 


-------------------------------

Updated on 2021-12-04 at 16:46:01 +0000