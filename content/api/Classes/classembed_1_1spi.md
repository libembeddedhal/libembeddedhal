---
title: embed::spi
summary: Serial peripheral interface (SPI) communication protocol hardware abstract interface.  

---

**embed::spi Class Reference**

Serial peripheral interface (SPI) communication protocol hardware abstract interface. 


`#include <spi.hpp>`

Inherits from [embed::driver< spi_settings >](classes/classembed_1_1driver/)

## Public Functions

|                | Name           |
| -------------- | -------------- |
| virtual bool | **[busy](classes/classembed_1_1spi/#function-busy)**() =0<br>Determines if a transfer is currently ongoing.  |
| virtual void | **[transfer](classes/classembed_1_1spi/#function-transfer)**(std::span< const std::byte > p_data_out, std::span< std::byte > p_data_in, std::byte p_write_value =std::byte{ 0xFF }) =0<br>Send and receieve bytes from the spi bus.  |

## Additional inherited members

**Public Functions inherited from [embed::driver< spi_settings >](classes/classembed_1_1driver/)**

|                | Name           |
| -------------- | -------------- |
| bool | **[initialize](classes/classembed_1_1driver/#function-initialize)**()<br>Initialize the driver, apply the setting as defined in the settings_t structure and enable it. Calling this function after it has already been initialized will return false. In order to run initialization again, [reset()]() must be called. After initialization, the settings are committed and saved into another settings structure. This settings can be looked up and inspected by the application.  |
| void | **[reset](classes/classembed_1_1driver/#function-reset)**()<br>Reset the driver in order to run initialize again. This is helpful if the application needs to change the settings of a driver after it is first initialized, like baud rate for serial or pull resistor for a pin.  |
| bool | **[is_initialized](classes/classembed_1_1driver/#function-is-initialized)**() const<br>Determine if the driver has been initialized.  |
| settings_t & | **[settings](classes/classembed_1_1driver/#function-settings)**()<br>Get access to uncommitted driver settings.  |
| const settings_t & | **[initialized_settings](classes/classembed_1_1driver/#function-initialized-settings)**() const<br>Get access to the settings that were used in the latest initialization. These settings only get updated when a successful [initialize()](classes/classembed_1_1driver/#function-initialize) has occurred.  |

**Protected Functions inherited from [embed::driver< spi_settings >](classes/classembed_1_1driver/)**

|                | Name           |
| -------------- | -------------- |
| virtual bool | **[driver_initialize](classes/classembed_1_1driver/#function-driver-initialize)**() =0 |

**Protected Attributes inherited from [embed::driver< spi_settings >](classes/classembed_1_1driver/)**

|                | Name           |
| -------------- | -------------- |
| settings_t | **[m_settings](classes/classembed_1_1driver/#variable-m-settings)**  |
| settings_t | **[m_initialized_settings](classes/classembed_1_1driver/#variable-m-initialized-settings)**  |
| bool | **[m_initialized](classes/classembed_1_1driver/#variable-m-initialized)**  |


## Public Functions Documentation

### function busy

```cpp
virtual bool busy() =0
```

Determines if a transfer is currently ongoing. 

**Return**: 

  * true transfer is currently ongoing 
  * false device is idle and available for a transaction 


### function transfer

```cpp
virtual void transfer(
    std::span< const std::byte > p_data_out,
    std::span< std::byte > p_data_in,
    std::byte p_write_value =std::byte{ 0xFF }
) =0
```

Send and receieve bytes from the spi bus. 

**Parameters**: 

  * **p_data_out** buffer to write data to the bus. If this is set to null/empty then writing is ignored and the p_write_value will be written to the bus. If the length is less than p_data_in, then p_write_value will be written to the bus after this buffer has been sent. 
  * **p_data_in** buffer to read the data off of the bus. If this is null/empty, then the transfer will be write only and the incoming data will be ignored. If the length of this buffer is less than p_data_out, once this buffer has been filled, the rest of the received bytes on the bus will be dropped. 
  * **p_write_value** filler data to be placed on the bus when the p_data_out buffer has been exhausted. 


-------------------------------

Updated on 2021-12-04 at 16:46:01 +0000