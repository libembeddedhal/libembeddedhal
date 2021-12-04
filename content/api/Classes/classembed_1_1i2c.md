---
title: embed::i2c
summary: Inter-integrated Circuit (I2C) or Two Wire Interface (TWI) communication protocol hardware abstract interface.  

---

**embed::i2c Class Reference**

Inter-integrated Circuit (I2C) or Two Wire Interface (TWI) communication protocol hardware abstract interface. 


`#include <i2c.hpp>`

Inherits from [embed::driver< i2c_settings >](classes/classembed_1_1driver/)

## Public Functions

|                | Name           |
| -------------- | -------------- |
| virtual void | **[transaction](classes/classembed_1_1i2c/#function-transaction)**(std::byte p_address, std::span< const std::byte > p_data_out, std::span< std::byte > p_data_in) =0<br>perform an [i2c](classes/classembed_1_1i2c/) transaction with another device on the bus. The type of transaction depends on values of input parameters.  |
| virtual bool | **[busy](classes/classembed_1_1i2c/#function-busy)**() =0<br>Determines if the [i2c](classes/classembed_1_1i2c/) transaction is ongoing.  |

## Additional inherited members

**Public Functions inherited from [embed::driver< i2c_settings >](classes/classembed_1_1driver/)**

|                | Name           |
| -------------- | -------------- |
| bool | **[initialize](classes/classembed_1_1driver/#function-initialize)**()<br>Initialize the driver, apply the setting as defined in the settings_t structure and enable it. Calling this function after it has already been initialized will return false. In order to run initialization again, [reset()]() must be called. After initialization, the settings are committed and saved into another settings structure. This settings can be looked up and inspected by the application.  |
| void | **[reset](classes/classembed_1_1driver/#function-reset)**()<br>Reset the driver in order to run initialize again. This is helpful if the application needs to change the settings of a driver after it is first initialized, like baud rate for serial or pull resistor for a pin.  |
| bool | **[is_initialized](classes/classembed_1_1driver/#function-is-initialized)**() const<br>Determine if the driver has been initialized.  |
| settings_t & | **[settings](classes/classembed_1_1driver/#function-settings)**()<br>Get access to uncommitted driver settings.  |
| const settings_t & | **[initialized_settings](classes/classembed_1_1driver/#function-initialized-settings)**() const<br>Get access to the settings that were used in the latest initialization. These settings only get updated when a successful [initialize()](classes/classembed_1_1driver/#function-initialize) has occurred.  |

**Protected Functions inherited from [embed::driver< i2c_settings >](classes/classembed_1_1driver/)**

|                | Name           |
| -------------- | -------------- |
| virtual bool | **[driver_initialize](classes/classembed_1_1driver/#function-driver-initialize)**() =0 |

**Protected Attributes inherited from [embed::driver< i2c_settings >](classes/classembed_1_1driver/)**

|                | Name           |
| -------------- | -------------- |
| settings_t | **[m_settings](classes/classembed_1_1driver/#variable-m-settings)**  |
| settings_t | **[m_initialized_settings](classes/classembed_1_1driver/#variable-m-initialized-settings)**  |
| bool | **[m_initialized](classes/classembed_1_1driver/#variable-m-initialized)**  |


## Public Functions Documentation

### function transaction

```cpp
virtual void transaction(
    std::byte p_address,
    std::span< const std::byte > p_data_out,
    std::span< std::byte > p_data_in
) =0
```

perform an [i2c](classes/classembed_1_1i2c/) transaction with another device on the bus. The type of transaction depends on values of input parameters. 

**Parameters**: 

  * **p_address** 7-bit address of the device you want to communicate with. To perform a transaction with a 10-bit address, this parameter must be the address upper byte of the 10-bit address OR'd with 0b1111'0000 (the 10-bit address indicator). The lower byte of the address must be contained in the first byte of the p_data_out span. 
  * **p_data_out** data to be written to the addressed device. Set to nullptr with length zero in order to skip writting. 
  * **p_data_in** buffer to store read data from the addressed device. Set to nullptr with length 0 in order to skip reading. 


Performing Write, Read and Write-Then-Read transactions depends on which span for data_out and data_in are set to null.



* For write transactions, pass p_data_in as an empty span `std::span<std::byte>{}` and pass a buffer to p_data_out.
* For read transactions, pass p_data_out as an empty span `std::span<const std::byte>{}` and pass a buffer to p_data_in.
* For write-then-read transactions, pass a buffer for both p_data_in p_data_out.
Implementations of transaction can be synchronous, interrupt driven or DMA driven. Calling transaction while a current transaction is ongoing is undefined behavior. To prevent this, poll [busy()](classes/classembed_1_1i2c/#function-busy) until it returns false.


### function busy

```cpp
virtual bool busy() =0
```

Determines if the [i2c](classes/classembed_1_1i2c/) transaction is ongoing. 

**Return**: 

  * true transaction is currently ongoing 
  * false device is idle and available for a transaction 


-------------------------------

Updated on 2021-12-04 at 16:46:01 +0000