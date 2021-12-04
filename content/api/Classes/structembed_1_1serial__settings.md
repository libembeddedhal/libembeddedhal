---
title: embed::serial_settings
summary: Generic settings for a standard serial device.  

---

**embed::serial_settings Struct Reference**

Generic settings for a standard serial device. 


`#include <serial.hpp>`

## Public Types

|                | Name           |
| -------------- | -------------- |
| enum class uint8_t | **[stop_bits](classes/structembed_1_1serial__settings/#enum-stop-bits)** { one = 0, two}<br>Set of available stop bits options.  |
| enum class uint8_t | **[parity](classes/structembed_1_1serial__settings/#enum-parity)** { none = 0, odd, even, forced1, forced0}<br>Set of parity bit options.  |

## Public Attributes

|                | Name           |
| -------------- | -------------- |
| uint32_t | **[baud_rate](classes/structembed_1_1serial__settings/#variable-baud-rate)** <br>The operating speed of the baud rate (in units of bits per second)  |
| [parity](classes/structembed_1_1serial__settings/#enum-parity) | **[parity](classes/structembed_1_1serial__settings/#variable-parity)** <br>Parity bit type for each frame.  |
| [stop_bits](classes/structembed_1_1serial__settings/#enum-stop-bits) | **[stop](classes/structembed_1_1serial__settings/#variable-stop)** <br>Number of stop bits for each frame.  |
| uint8_t | **[frame_size](classes/structembed_1_1serial__settings/#variable-frame-size)** <br>Number of bits in each frame. Typically between 5 to 9.  |

## Public Types Documentation

### enum stop_bits

| Enumerator | Value | Description |
| ---------- | ----- | ----------- |
| one | 0|   |
| two | |   |



Set of available stop bits options. 

### enum parity

| Enumerator | Value | Description |
| ---------- | ----- | ----------- |
| none | 0| Disable parity bit as part of the frame.   |
| odd | | Enable parity and set 1 (HIGH) when the number of bits is odd.   |
| even | | Enable parity and set 1 (HIGH) when the number of bits is even.   |
| forced1 | | Enable parity bit and always return 1 (HIGH) for ever frame.   |
| forced0 | | Enable parity bit and always return 0 (LOW) for ever frame.   |



Set of parity bit options. 

## Public Attributes Documentation

### variable baud_rate

```cpp
uint32_t baud_rate = 115200;
```

The operating speed of the baud rate (in units of bits per second) 

### variable parity

```cpp
parity parity = parity::none;
```

Parity bit type for each frame. 

### variable stop

```cpp
stop_bits stop = stop_bits::one;
```

Number of stop bits for each frame. 

### variable frame_size

```cpp
uint8_t frame_size = 8;
```

Number of bits in each frame. Typically between 5 to 9. 

-------------------------------

Updated on 2021-12-04 at 16:46:01 +0000