---
title: embed::bit_limits


---

**embed::bit_limits Class Reference**

 [More...](#detailed-description)


`#include <full_scale.hpp>`

## Public Functions

|                | Name           |
| -------------- | -------------- |
| constexpr int_t | **[max](classes/classembed_1_1bit__limits/#function-max)**()<br>Get the maximum value available for an integer of `bit_width` size and that can be stored within `int_t`. The final value of the function depends also on the sign of the int type.  |
| constexpr int_t | **[min](classes/classembed_1_1bit__limits/#function-min)**()<br>Get the minimum value available for an integer of `bit_width` size and that can be stored within `int_t`. The final value of the function depends also on the sign of the int type. Unsigned ints simply return zero.  |

## Detailed Description

```cpp
template <uint8_t bit_width,
typename int_t >
class embed::bit_limits;
```


**Template Parameters**: 

  * **bit_width** 
  * **int_t** 

## Public Functions Documentation

### function max

```cpp
static inline constexpr int_t max()
```

Get the maximum value available for an integer of `bit_width` size and that can be stored within `int_t`. The final value of the function depends also on the sign of the int type. 

**Return**: 

  * constexpr int_t - returns the maximum value available for an integer of `bit_width` size and that can be stored within `int_t`. The final value of the function depends also on the sign of the int type.
  * constexpr int_t maximum value 


### function min

```cpp
static inline constexpr int_t min()
```

Get the minimum value available for an integer of `bit_width` size and that can be stored within `int_t`. The final value of the function depends also on the sign of the int type. Unsigned ints simply return zero. 

**Return**: constexpr int_t minimum value 

-------------------------------

Updated on 2021-12-04 at 16:46:01 +0000