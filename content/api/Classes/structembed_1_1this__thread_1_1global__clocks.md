---
title: embed::this_thread::global_clocks
summary: internal clock  

---

**embed::this_thread::global_clocks Struct Reference**

internal clock 


`#include <clock.hpp>`

## Public Attributes

|                | Name           |
| -------------- | -------------- |
| auto | **[m_incremental_uptime](classes/structembed_1_1this__thread_1_1global__clocks/#variable-m-incremental-uptime)** <br>Default uptime timer that simply counts each time it is called. This should almost never be used.  |
| auto | **[m_loop_delay](classes/structembed_1_1this__thread_1_1global__clocks/#variable-m-loop-delay)** <br>Default sleep function that simply counts until it reaches a designated number.  |
| [sleep_function](namespaces/namespaceembed_1_1this__thread/#using-sleep-function) | **[m_global_sleep](classes/structembed_1_1this__thread_1_1global__clocks/#variable-m-global-sleep)** <br>Store the global sleep function.  |
| [uptime_function](namespaces/namespaceembed_1_1this__thread/#using-uptime-function) | **[m_global_uptime](classes/structembed_1_1this__thread_1_1global__clocks/#variable-m-global-uptime)** <br>Store the global uptime function.  |

## Public Attributes Documentation

### variable m_incremental_uptime

```cpp
static auto m_incremental_uptime = []() -> time_increment {
    using namespace std::chrono_literals;
    static time_increment count{ 0 };
    count += 100ns;
    return count;
  };
```

Default uptime timer that simply counts each time it is called. This should almost never be used. 

### variable m_loop_delay

```cpp
static auto m_loop_delay = [](time_increment loop_count) {
    time_increment count{ 0 };
    while (count < loop_count) {
      count += std::chrono::microseconds{ 100 };
    }
  };
```

Default sleep function that simply counts until it reaches a designated number. 

### variable m_global_sleep

```cpp
static sleep_function m_global_sleep = m_loop_delay;
```

Store the global sleep function. 

### variable m_global_uptime

```cpp
static uptime_function m_global_uptime = m_incremental_uptime;
```

Store the global uptime function. 

-------------------------------

Updated on 2021-12-04 at 16:46:01 +0000