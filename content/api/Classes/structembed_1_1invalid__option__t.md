---
title: embed::invalid_option_t
summary: Used for defining static_asserts that should always fail, but only if the static_assert line is hit via if constexpr control block. Prefer to NOT use this directly but to use invalid_option instead.  

---

**embed::invalid_option_t Struct Reference**

Used for defining static_asserts that should always fail, but only if the static_assert line is hit via `if constexpr` control block. Prefer to NOT use this directly but to use `invalid_option` instead.  [More...](#detailed-description)


`#include <driver.hpp>`

Inherits from std::false_type

## Detailed Description

```cpp
template <auto... options>
struct embed::invalid_option_t;
```

Used for defining static_asserts that should always fail, but only if the static_assert line is hit via `if constexpr` control block. Prefer to NOT use this directly but to use `invalid_option` instead. 

**Template Parameters**: 

  * **options** ignored by the application but needed to create a non-trivial specialization of this class which allows its usage in static_assert. 

-------------------------------

Updated on 2021-12-04 at 16:46:01 +0000