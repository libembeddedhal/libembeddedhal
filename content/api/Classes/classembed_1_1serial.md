---
title: embed::serial
summary: Serial communication protocol hardware abstract interface. Use this interface for hardware that implements a serial protocol like UART, USART, RS232, RS485 and many others that use a similar communication protocol but may use different voltage schemes.  

---

**embed::serial Class Reference**

Serial communication protocol hardware abstract interface. Use this interface for hardware that implements a serial protocol like UART, USART, RS232, RS485 and many others that use a similar communication protocol but may use different voltage schemes.  [More...](#detailed-description)


`#include <serial.hpp>`

Inherits from [embed::driver< serial_settings >](classes/classembed_1_1driver/)

## Public Functions

|                | Name           |
| -------------- | -------------- |
| virtual void | **[write](classes/classembed_1_1serial/#function-write)**(std::span< const std::byte > p_data) =0<br>Write data on the transmitter line of the port. The exact implementation for this can be polling, interrupt driven or DMA driven. There is no guarantee on exactly how a write operation will operate, thus the [busy()]() function must polled called after this returns to determine if the write operation has finished. Attempting to call [write()]() when tranmission is busy is undefined behavior.  |
| virtual bool | **[busy](classes/classembed_1_1serial/#function-busy)**() =0<br>Determines if the write operation is currently on going.  |
| virtual size_t | **[bytes_available](classes/classembed_1_1serial/#function-bytes-available)**() =0<br>The number of bytes that have been buffered. For frames less than 8-bits, each byte holds a frame. For frames above 8-bits the number of bytes returned indicates the number of bytes a buffer needs to be to return all of the data held in the buffer.  |
| virtual std::span< const std::byte > | **[read](classes/classembed_1_1serial/#function-read)**(std::span< std::byte > p_data) =0<br>Read the bytes received over the ports receiver line and stored in the serial implementations buffer. The number of bytes read will subtract the number of bytes available until it reaches zero.  |
| virtual void | **[flush](classes/classembed_1_1serial/#function-flush)**() =0<br>Set [bytes_available()](classes/classembed_1_1serial/#function-bytes-available) to zero and clear any received data stored in hardware registers. This operation must be faster than simply running [read()](classes/classembed_1_1serial/#function-read) until [bytes_available()](classes/classembed_1_1serial/#function-bytes-available) is empty.  |

## Additional inherited members

**Public Functions inherited from [embed::driver< serial_settings >](classes/classembed_1_1driver/)**

|                | Name           |
| -------------- | -------------- |
| bool | **[initialize](classes/classembed_1_1driver/#function-initialize)**()<br>Initialize the driver, apply the setting as defined in the settings_t structure and enable it. Calling this function after it has already been initialized will return false. In order to run initialization again, [reset()]() must be called. After initialization, the settings are committed and saved into another settings structure. This settings can be looked up and inspected by the application.  |
| void | **[reset](classes/classembed_1_1driver/#function-reset)**()<br>Reset the driver in order to run initialize again. This is helpful if the application needs to change the settings of a driver after it is first initialized, like baud rate for serial or pull resistor for a pin.  |
| bool | **[is_initialized](classes/classembed_1_1driver/#function-is-initialized)**() const<br>Determine if the driver has been initialized.  |
| settings_t & | **[settings](classes/classembed_1_1driver/#function-settings)**()<br>Get access to uncommitted driver settings.  |
| const settings_t & | **[initialized_settings](classes/classembed_1_1driver/#function-initialized-settings)**() const<br>Get access to the settings that were used in the latest initialization. These settings only get updated when a successful [initialize()](classes/classembed_1_1driver/#function-initialize) has occurred.  |

**Protected Functions inherited from [embed::driver< serial_settings >](classes/classembed_1_1driver/)**

|                | Name           |
| -------------- | -------------- |
| virtual bool | **[driver_initialize](classes/classembed_1_1driver/#function-driver-initialize)**() =0 |

**Protected Attributes inherited from [embed::driver< serial_settings >](classes/classembed_1_1driver/)**

|                | Name           |
| -------------- | -------------- |
| settings_t | **[m_settings](classes/classembed_1_1driver/#variable-m-settings)**  |
| settings_t | **[m_initialized_settings](classes/classembed_1_1driver/#variable-m-initialized-settings)**  |
| bool | **[m_initialized](classes/classembed_1_1driver/#variable-m-initialized)**  |


## Detailed Description

```cpp
class embed::serial;
```

Serial communication protocol hardware abstract interface. Use this interface for hardware that implements a serial protocol like UART, USART, RS232, RS485 and many others that use a similar communication protocol but may use different voltage schemes. 

Due to the asynchronous nature of serial communication protocols, all implementations of serial devices MUST buffer received bytes using DMA or interrupts. A thread should not be used as this generally greatly increases the ROM and RAM cost of using library.

All implementations MUST allow the user to supply their own buffer of arbitrary size, such that the amount of buffered data can be tailored to the needs of the application. 

## Public Functions Documentation

### function write

```cpp
virtual void write(
    std::span< const std::byte > p_data
) =0
```

Write data on the transmitter line of the port. The exact implementation for this can be polling, interrupt driven or DMA driven. There is no guarantee on exactly how a write operation will operate, thus the [busy()]() function must polled called after this returns to determine if the write operation has finished. Attempting to call [write()]() when tranmission is busy is undefined behavior. 

**Parameters**: 

  * **p_data** data to be transmitted over the serial port transmitter line 


Data frames are not compact when frame size is less than 8 bits. Meaning that, if you want to send three 5-bit frames, then you will need to use a span of at least 3 bytes to hold each value.

When writing data with frame size greater than 8 is in little endian order. Meaning that the first byte in the sequence is the lower byte and the next is the greater byte. If you wanted to send a 9-bit frame with value 0x14A, the first byte must be 0x4A and the next 0x01.


### function busy

```cpp
virtual bool busy() =0
```

Determines if the write operation is currently on going. 

**Return**: 

  * true serial transmitter is currently writing data to the port 
  * false serial transmitter is idle and available to write data 


### function bytes_available

```cpp
virtual size_t bytes_available() =0
```

The number of bytes that have been buffered. For frames less than 8-bits, each byte holds a frame. For frames above 8-bits the number of bytes returned indicates the number of bytes a buffer needs to be to return all of the data held in the buffer. 

**Return**: size_t number of buffered by the serial driver and are available to be read by the [read()](classes/classembed_1_1serial/#function-read) function. 

### function read

```cpp
virtual std::span< const std::byte > read(
    std::span< std::byte > p_data
) =0
```

Read the bytes received over the ports receiver line and stored in the serial implementations buffer. The number of bytes read will subtract the number of bytes available until it reaches zero. 

**Parameters**: 

  * **p_data** Buffer to read bytes back from. If the length of this buffer is greater than the value returned by [bytes_available()](classes/classembed_1_1serial/#function-bytes-available) then buffer is filled up to the length returned by [bytes_available()](classes/classembed_1_1serial/#function-bytes-available). The rest of the buffer is left untouched. 


**Return**: std::span<const std::byte> provides a means to get the length of bytes read into the buffer p_data. The address will ALWAYS be the same as p_data and the length will be equal to the number of bytes read from the buffer. 

### function flush

```cpp
virtual void flush() =0
```

Set [bytes_available()](classes/classembed_1_1serial/#function-bytes-available) to zero and clear any received data stored in hardware registers. This operation must be faster than simply running [read()](classes/classembed_1_1serial/#function-read) until [bytes_available()](classes/classembed_1_1serial/#function-bytes-available) is empty. 

-------------------------------

Updated on 2021-12-04 at 16:46:01 +0000