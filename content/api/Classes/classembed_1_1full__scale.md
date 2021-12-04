---
title: embed::full_scale


---

**embed::full_scale Class Reference**

 [More...](#detailed-description)


`#include <full_scale.hpp>`

## Public Functions

|                | Name           |
| -------------- | -------------- |
| constexpr | **[full_scale](classes/classembed_1_1full__scale/#function-full-scale)**() |
| template <typename U ,size_t bit_width\> <br>constexpr | **[full_scale](classes/classembed_1_1full__scale/#function-full-scale)**([bit_depth](classes/structembed_1_1bit__depth/)< U, [bit_width](classes/classembed_1_1full__scale/#variable-bit-width) > p_value) |
| template <typename U ,size_t bit_width\> <br>constexpr [full_scale](classes/classembed_1_1full__scale/)< T > & | **[operator=](classes/classembed_1_1full__scale/#function-operator=)**([bit_depth](classes/structembed_1_1bit__depth/)< U, [bit_width](classes/classembed_1_1full__scale/#variable-bit-width) > p_value) |
| T | **[value](classes/classembed_1_1full__scale/#function-value)**() |

## Public Attributes

|                | Name           |
| -------------- | -------------- |
| constexpr size_t | **[bit_width](classes/classembed_1_1full__scale/#variable-bit-width)** <br>Calculate the number.  |

## Detailed Description

```cpp
template <typename T >
class embed::full_scale;
```


**Template Parameters**: 

  * **T** 

## Public Functions Documentation

### function full_scale

```cpp
inline constexpr full_scale()
```


### function full_scale

```cpp
template <typename U ,
size_t bit_width>
inline constexpr full_scale(
    bit_depth< U, bit_width > p_value
)
```


### function operator=

```cpp
template <typename U ,
size_t bit_width>
inline constexpr full_scale< T > & operator=(
    bit_depth< U, bit_width > p_value
)
```


### function value

```cpp
inline T value()
```


## Public Attributes Documentation

### variable bit_width

```cpp
static constexpr size_t bit_width = sizeof(T) * CHAR_BIT;
```

Calculate the number. 

-------------------------------

Updated on 2021-12-04 at 16:46:01 +0000