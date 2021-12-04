---
title: embed::can::message_t


---

**embed::can::message_t Struct Reference**




`#include <can.hpp>`

## Public Attributes

|                | Name           |
| -------------- | -------------- |
| [id_t](classes/classembed_1_1can/#using-id-t) | **[id](classes/structembed_1_1can_1_1message__t/#variable-id)**  |
| uint8_t | **[length](classes/structembed_1_1can_1_1message__t/#variable-length)**  |
| std::array< uint8_t, 8 > | **[payload](classes/structembed_1_1can_1_1message__t/#variable-payload)**  |
| bool | **[is_remote_request](classes/structembed_1_1can_1_1message__t/#variable-is-remote-request)**  |

## Public Attributes Documentation

### variable id

```cpp
id_t id;
```


### variable length

```cpp
uint8_t length = 0;
```


### variable payload

```cpp
std::array< uint8_t, 8 > payload {0};
```


### variable is_remote_request

```cpp
bool is_remote_request = false;
```


-------------------------------

Updated on 2021-12-04 at 16:46:01 +0000