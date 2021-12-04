---
title: embed


---

**embed Namespace Reference**

## Namespaces

| Name           |
| -------------- |
| **[embed::this_thread](namespaces/namespaceembed_1_1this__thread/)**  |

## Classes

|                | Name           |
| -------------- | -------------- |
| class | **[embed::adc](classes/classembed_1_1adc/)** <br>Analog to Digital Converter (ADC) hardware abstraction interface. Use this interface for devices and peripherals that can convert analog voltage signals into a digital number.  |
| struct | **[embed::can_settings](classes/structembed_1_1can__settings/)**  |
| class | **[embed::can](classes/classembed_1_1can/)**  |
| class | **[embed::can_network](classes/classembed_1_1can__network/)** <br>[can_network]() is a canbus message receiver handler and  |
| class | **[embed::counter](classes/classembed_1_1counter/)** <br>Counter hardware abstraction interface. Use this interface for devices and peripherals that have counting capabilities. Such devices can count up or down. Useful for keeping time. Expect counters to overflow when they reach the end of counting register's limits.  |
| class | **[embed::dac](classes/classembed_1_1dac/)** <br>Digital to Analog Converter (DAC) hardware abstraction interface. Use this interface for devices and peripherals that can create arbitrary analog voltages between a defined LOW and HIGH voltage.  |
| struct | **[embed::invalid_option_t](classes/structembed_1_1invalid__option__t/)** <br>Used for defining static_asserts that should always fail, but only if the static_assert line is hit via `if constexpr` control block. Prefer to NOT use this directly but to use `invalid_option` instead.  |
| struct | **[embed::no_settings](classes/structembed_1_1no__settings/)** <br>An empty settings structure used to indicate that a driver or interface does not have generic settings.  |
| class | **[embed::driver](classes/classembed_1_1driver/)** <br>The basis class for all peripheral, device and system drivers in libembeddedhal.  |
| class | **[embed::bit_limits](classes/classembed_1_1bit__limits/)**  |
| struct | **[embed::bit_depth](classes/structembed_1_1bit__depth/)**  |
| class | **[embed::full_scale](classes/classembed_1_1full__scale/)**  |
| struct | **[embed::input_pin_settings](classes/structembed_1_1input__pin__settings/)** <br>Generic settings for input pins.  |
| struct | **[embed::output_pin_settings](classes/structembed_1_1output__pin__settings/)** <br>Generic settings for output pins.  |
| struct | **[embed::interrupt_pin_settings](classes/structembed_1_1interrupt__pin__settings/)** <br>Generic settings for interrupt pins.  |
| class | **[embed::input_pin](classes/classembed_1_1input__pin/)** <br>Digital input pin hardware abstraction. Use this to read a pin and determine if the voltage on it is HIGH or LOW.  |
| class | **[embed::output_pin](classes/classembed_1_1output__pin/)** <br>Digital output pin hardware abstraction. Use this to drive a pin HIGH or LOW in order to send a control signal or turn off or on an LED.  |
| class | **[embed::interrupt_pin](classes/classembed_1_1interrupt__pin/)** <br>Digital interrupt pin hardware abstraction. Use this to trigger an interrupt service routine (ISR) when a pin detects a falling edge (when the pin's voltage transitions from HIGH to LOW), a rising edge (when the pin's voltage transitions from LOW to HIGH), or any transition of state on the pin.  |
| struct | **[embed::i2c_settings](classes/structembed_1_1i2c__settings/)** <br>Generic settings for a standard I2C device.  |
| class | **[embed::i2c](classes/classembed_1_1i2c/)** <br>Inter-integrated Circuit (I2C) or Two Wire Interface (TWI) communication protocol hardware abstract interface.  |
| class | **[embed::pwm](classes/classembed_1_1pwm/)** <br>Pulse Width Modulation (PWM) channel hardware abstraction.  |
| struct | **[embed::serial_settings](classes/structembed_1_1serial__settings/)** <br>Generic settings for a standard serial device.  |
| class | **[embed::serial](classes/classembed_1_1serial/)** <br>Serial communication protocol hardware abstract interface. Use this interface for hardware that implements a serial protocol like UART, USART, RS232, RS485 and many others that use a similar communication protocol but may use different voltage schemes.  |
| struct | **[embed::spi_settings](classes/structembed_1_1spi__settings/)** <br>Generic settings for a standard SPI device.  |
| class | **[embed::spi](classes/classembed_1_1spi/)** <br>Serial peripheral interface (SPI) communication protocol hardware abstract interface.  |
| class | **[embed::static_callable](classes/classembed_1_1static__callable/)** <br>General class which will be used to allow for signature to be used and then split by the below class.  |
| class | **[embed::static_callable< owner_class, reference_designator, return_t(args_t...)>](classes/classembed_1_1static__callable_3_01owner__class_00_01reference__designator_00_01return__t_07args__t_8_8_8_08_4/)** <br>Specialization of [static_callable](classes/classembed_1_1static__callable/) with the return type and arguments split up.  |
| class | **[embed::static_memory_resource](classes/classembed_1_1static__memory__resource/)** <br>The [static_memory_resource]() is the polymorphic memory resource allocator that allows libembeddedhal's libraries to use a C++ standard container such as std::pmr::vector, std::pmr::string, std::pmr::unordered_map, and more without requiring dynamic memory allocation from the heap. It provides a simple way to create an allocator with built in storage, with its size indicated by a single template parameter. It also provides statistics regarding the amount of memory allocated such that developers can determine if they need to reduce or increase the size of the buffer. Memory statistics can also give programs the insight into how much memory space is available and make decisions based on that. In the event that the memory of the static allocator is exceeded, a std::bad_alloc excpetion is thrown.  |
| class | **[embed::timer](classes/classembed_1_1timer/)** <br>Timer hardware abstraction interface. Use this interface for devices and peripherals that have timer like capabilities, such that, when a timer's time has expired, an event/interrupt/signal is generated.  |

## Types

|                | Name           |
| -------------- | -------------- |
| enum class| **[pin_resistor](namespaces/namespaceembed/#enum-pin-resistor)** { none = 0, pull_down, pull_up}<br>Set of possible pin mode resistor settings. See each enumeration to get more details about when and how these should be used.  |

## Functions

|                | Name           |
| -------------- | -------------- |
| constexpr bool | **[is_platform](namespaces/namespaceembed/#function-is-platform)**(std::string_view p_platform)<br>Determines if the current application was built for a specific platform. For example:  |
| constexpr bool | **[is_a_test](namespaces/namespaceembed/#function-is-a-test)**()<br>Determines if the application is a test.  |
| template <typename enum_type \> <br>constexpr auto | **[value](namespaces/namespaceembed/#function-value)**(enum_type enum_value)<br>Helper function to convert an enum to its integral value.  |
| template <size_t bit_field_width\> <br>consteval uint32_t | **[generate_field_of_ones](namespaces/namespaceembed/#function-generate-field-of-ones)**()<br>Generate a mask of 1s at compiletime.  |
| template <typename T ,size_t source_width,typename U \> <br>constexpr static T | **[increase_bit_depth](namespaces/namespaceembed/#function-increase-bit-depth)**(U p_value) |
| template <std::unsigned_integral T,std::unsigned_integral U\> <br>auto | **[operator*](namespaces/namespaceembed/#function-operator*)**(U value, [full_scale](classes/classembed_1_1full__scale/)< T > scale) |

## Attributes

|                | Name           |
| -------------- | -------------- |
| constexpr const std::string_view | **[platform_string](namespaces/namespaceembed/#variable-platform-string)** <br>The platform string determines which platform this application was built for. Use this to determine at compile or runtime if the running application is a "test", an "lpc40" series mcu, and "stm" series mcu or a raspberry pi ("rpi").  |
| constexpr bool | **[invalid_option](namespaces/namespaceembed/#variable-invalid-option)** <br>Helper definition to simplify the usage of [invalid_option_t]().  |

## Types Documentation

### enum pin_resistor

| Enumerator | Value | Description |
| ---------- | ----- | ----------- |
| none | 0| No pull up. This will cause the pin to float. This may be desirable if the pin has an external resistor attached or if the signal is sensitive to external devices like resistors.   |
| pull_down | | Pull the pin down to devices GND. This will ensure that the voltage read by the pin when there is no signal on the pin is LOW (or false).   |
| pull_up | | See pull down explanation, but in this case the pin is pulled up to VCC, also called VDD on some systems.   |



Set of possible pin mode resistor settings. See each enumeration to get more details about when and how these should be used. 


## Functions Documentation

### function is_platform

```cpp
constexpr bool is_platform(
    std::string_view p_platform
)
```

Determines if the current application was built for a specific platform. For example: 

**Parameters**: 

  * **p_platform** platform string pattern to check against 


**Return**: 

  * true matches the platform string 
  * false does not matches the platform string 


[embed::is_platform](namespaces/namespaceembed/#function-is-platform)("lpc4078");

Will return true if the PLATFORM macro defined at compile time was equal to lpc4078. If the developer wants to be less specific, let say, to just determine if the platform is in the lpc40xx family then the following example will work.

[embed::is_platform](namespaces/namespaceembed/#function-is-platform)("lpc40");


### function is_a_test

```cpp
constexpr bool is_a_test()
```

Determines if the application is a test. 

**Return**: 

  * true this application is a test 
  * false this application is not a test 


### function value

```cpp
template <typename enum_type >
constexpr auto value(
    enum_type enum_value
)
```

Helper function to convert an enum to its integral value. 

**Parameters**: 

  * **enum_value** the enumeration you want to convert into an integral value 


**Template Parameters**: 

  * **enum_type** the underlying type of the enumeration. Do not supply this value, it is inferred by the enum_value passed to the function. 


**Return**: constexpr auto return the integral value of the enum. 

### function generate_field_of_ones

```cpp
template <size_t bit_field_width>
static consteval uint32_t generate_field_of_ones()
```

Generate a mask of 1s at compiletime. 

**Template Parameters**: 

  * **bit_field_width** number of 1s in the mask 


**Return**: consteval uint32_t mask with 1s at the LSB 

### function increase_bit_depth

```cpp
template <typename T ,
size_t source_width,
typename U >
static constexpr static T increase_bit_depth(
    U p_value
)
```


**Parameters**: 

  * **p_value** 


**Template Parameters**: 

  * **T** 
  * **source_width** 
  * **U** 


**Return**: constexpr T 

### function operator*

```cpp
template <std::unsigned_integral T,
std::unsigned_integral U>
auto operator*(
    U value,
    full_scale< T > scale
)
```


**Parameters**: 

  * **value** 
  * **scale** 


**Template Parameters**: 

  * **T** 
  * **U** 


**Return**: auto 


## Attributes Documentation

### variable platform_string

```cpp
constexpr const std::string_view platform_string = PLATFORM_STRING;
```

The platform string determines which platform this application was built for. Use this to determine at compile or runtime if the running application is a "test", an "lpc40" series mcu, and "stm" series mcu or a raspberry pi ("rpi"). 

### variable invalid_option

```cpp
constexpr bool invalid_option = invalid_option_t<options...>::value;
```

Helper definition to simplify the usage of [invalid_option_t](). 

**Template Parameters**: 

  * **options** ignored by the application but needed to create a non-trivial specialization of this class which allows its usage in static_assert. 





-------------------------------

Updated on 2021-12-04 at 16:46:01 +0000