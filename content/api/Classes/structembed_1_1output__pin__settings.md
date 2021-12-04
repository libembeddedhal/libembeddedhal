---
title: embed::output_pin_settings
summary: Generic settings for output pins.  

---

**embed::output_pin_settings Struct Reference**

Generic settings for output pins. 


`#include <gpio.hpp>`

## Public Attributes

|                | Name           |
| -------------- | -------------- |
| bool | **[starting_level](classes/structembed_1_1output__pin__settings/#variable-starting-level)** <br>Set the starting level of the output pin on initialization. HIGH voltage defined as true and LOW voltage defined as false.  |
| bool | **[open_drain](classes/structembed_1_1output__pin__settings/#variable-open-drain)** <br>Starting level of the output pin. HIGH voltage defined as true and LOW voltage defined as false.  |
| [pin_resistor](namespaces/namespaceembed/#enum-pin-resistor) | **[resistor](classes/structembed_1_1output__pin__settings/#variable-resistor)** <br>Pull resistor for the pin. This generally only helpful when open drain is enabled.  |

## Public Attributes Documentation

### variable starting_level

```cpp
bool starting_level = true;
```

Set the starting level of the output pin on initialization. HIGH voltage defined as true and LOW voltage defined as false. 

### variable open_drain

```cpp
bool open_drain = false;
```

Starting level of the output pin. HIGH voltage defined as true and LOW voltage defined as false. 

### variable resistor

```cpp
pin_resistor resistor = pin_resistor::pull_up;
```

Pull resistor for the pin. This generally only helpful when open drain is enabled. 

-------------------------------

Updated on 2021-12-04 at 16:46:01 +0000