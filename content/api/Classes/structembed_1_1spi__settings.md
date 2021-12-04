---
title: embed::spi_settings
summary: Generic settings for a standard SPI device.  

---

**embed::spi_settings Struct Reference**

Generic settings for a standard SPI device. 


`#include <spi.hpp>`

## Public Attributes

|                | Name           |
| -------------- | -------------- |
| uint32_t | **[clock_rate_hz](classes/structembed_1_1spi__settings/#variable-clock-rate-hz)** <br>Serial clock frequency.  |
| bool | **[clock_idles_high](classes/structembed_1_1spi__settings/#variable-clock-idles-high)** <br>The polarity of the pins when the signal is idle.  |
| bool | **[data_valid_on_trailing_edge](classes/structembed_1_1spi__settings/#variable-data-valid-on-trailing-edge)** <br>The phase of the clock signal when communicating.  |

## Public Attributes Documentation

### variable clock_rate_hz

```cpp
uint32_t clock_rate_hz = 100'000;
```

Serial clock frequency. 

### variable clock_idles_high

```cpp
bool clock_idles_high = false;
```

The polarity of the pins when the signal is idle. 

### variable data_valid_on_trailing_edge

```cpp
bool data_valid_on_trailing_edge = false;
```

The phase of the clock signal when communicating. 

-------------------------------

Updated on 2021-12-04 at 16:46:01 +0000