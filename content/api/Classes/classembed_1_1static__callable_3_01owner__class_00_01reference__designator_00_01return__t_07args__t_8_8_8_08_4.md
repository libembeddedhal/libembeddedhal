---
title: embed::static_callable< owner_class, reference_designator, return_t(args_t...)>
summary: Specialization of static_callable with the return type and arguments split up.  

---

**embed::static_callable< owner_class, reference_designator, return_t(args_t...)> Class Reference**

Specialization of [static_callable](classes/classembed_1_1static__callable/) with the return type and arguments split up.  [More...](#detailed-description)


`#include <static_callable.hpp>`

## Public Functions

|                | Name           |
| -------------- | -------------- |
| | **[static_callable](classes/classembed_1_1static__callable_3_01owner__class_00_01reference__designator_00_01return__t_07args__t_8_8_8_08_4/#function-static-callable)**(std::function< return_t(args_t...)> p_callback)<br>Construct a new static callable object.  |
| auto * | **[get_handler](classes/classembed_1_1static__callable_3_01owner__class_00_01reference__designator_00_01return__t_07args__t_8_8_8_08_4/#function-get-handler)**()<br>Get the handler object.  |

## Detailed Description

```cpp
template <class owner_class ,
int reference_designator,
typename return_t ,
typename... args_t>
class embed::static_callable< owner_class, reference_designator, return_t(args_t...)>;
```

Specialization of [static_callable](classes/classembed_1_1static__callable/) with the return type and arguments split up. 

**Template Parameters**: 

  * **owner_class** see [static_callable](classes/classembed_1_1static__callable/)
  * **reference_designator** see [static_callable](classes/classembed_1_1static__callable/)
  * **return_t** 
  * **args_t** 

## Public Functions Documentation

### function static_callable

```cpp
inline static_callable(
    std::function< return_t(args_t...)> p_callback
)
```

Construct a new static callable object. 

**Parameters**: 

  * **p_callback** 


### function get_handler

```cpp
inline auto * get_handler()
```

Get the handler object. 

**Return**: auto* 

-------------------------------

Updated on 2021-12-04 at 16:46:01 +0000