---
title: embed::interrupt_pin_settings
summary: Generic settings for interrupt pins.  

---

**embed::interrupt_pin_settings Struct Reference**

Generic settings for interrupt pins. 


`#include <gpio.hpp>`

## Public Attributes

|                | Name           |
| -------------- | -------------- |
| [pin_resistor](namespaces/namespaceembed/#enum-pin-resistor) | **[resistor](classes/structembed_1_1interrupt__pin__settings/#variable-resistor)** <br>pull resistor for an interrupt pin. Generally advised to NOT use `[pin_resistor::none](namespaces/namespaceembed/#enumvalue-none)` and if it is used and external pull resistor should be placed on the pin to prevent random interrupt from firing.  |

## Public Attributes Documentation

### variable resistor

```cpp
pin_resistor resistor = pin_resistor::pull_up;
```

pull resistor for an interrupt pin. Generally advised to NOT use `[pin_resistor::none](namespaces/namespaceembed/#enumvalue-none)` and if it is used and external pull resistor should be placed on the pin to prevent random interrupt from firing. 

-------------------------------

Updated on 2021-12-04 at 16:46:01 +0000