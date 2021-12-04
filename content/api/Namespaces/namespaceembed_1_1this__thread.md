---
title: embed::this_thread


---

**embed::this_thread Namespace Reference**

## Classes

|                | Name           |
| -------------- | -------------- |
| struct | **[embed::this_thread::global_clocks](classes/structembed_1_1this__thread_1_1global__clocks/)** <br>internal clock  |

## Types

|                | Name           |
| -------------- | -------------- |
| using std::chrono::nanoseconds | **[time_increment](namespaces/namespaceembed_1_1this__thread/#using-time-increment)** <br>smallest increment of time for clocks  |
| using std::function< void(std::chrono::nanoseconds)> | **[sleep_function](namespaces/namespaceembed_1_1this__thread/#using-sleep-function)** <br>definition of a sleep function  |
| using std::function< std::chrono::nanoseconds(void)> | **[uptime_function](namespaces/namespaceembed_1_1this__thread/#using-uptime-function)** <br>definition of an uptime function  |

## Functions

|                | Name           |
| -------------- | -------------- |
| auto | **[sleep_for](namespaces/namespaceembed_1_1this__thread/#function-sleep-for)**([time_increment](namespaces/namespaceembed_1_1this__thread/#using-time-increment) delay)<br>Delay execution of the program by a predefined time.  |
| auto | **[uptime](namespaces/namespaceembed_1_1this__thread/#function-uptime)**()<br>Get the current system uptime.  |
| void | **[set_global_sleep](namespaces/namespaceembed_1_1this__thread/#function-set-global-sleep)**([sleep_function](namespaces/namespaceembed_1_1this__thread/#using-sleep-function) sleep_function)<br>Set the global sleep object.  |
| void | **[set_global_uptime](namespaces/namespaceembed_1_1this__thread/#function-set-global-uptime)**([uptime_function](namespaces/namespaceembed_1_1this__thread/#using-uptime-function) uptime_function)<br>Set the global uptime object.  |

## Types Documentation

### using time_increment

```cpp
using embed::this_thread::time_increment = typedef std::chrono::nanoseconds;
```

smallest increment of time for clocks 

### using sleep_function

```cpp
using embed::this_thread::sleep_function = typedef std::function<void(std::chrono::nanoseconds)>;
```

definition of a sleep function 

### using uptime_function

```cpp
using embed::this_thread::uptime_function = typedef std::function<std::chrono::nanoseconds(void)>;
```

definition of an uptime function 


## Functions Documentation

### function sleep_for

```cpp
static auto sleep_for(
    time_increment delay
)
```

Delay execution of the program by a predefined time. 

**Parameters**: 

  * **delay** the amount of time to delay execution by 


### function uptime

```cpp
static auto uptime()
```

Get the current system uptime. 

**Return**: auto the global uptime 

### function set_global_sleep

```cpp
static void set_global_sleep(
    sleep_function sleep_function
)
```

Set the global sleep object. 

**Parameters**: 

  * **sleep_function** the function to handle sleeping 


### function set_global_uptime

```cpp
static void set_global_uptime(
    uptime_function uptime_function
)
```

Set the global uptime object. 

**Parameters**: 

  * **uptime_function** the function to return the current system uptime 






-------------------------------

Updated on 2021-12-04 at 16:46:01 +0000