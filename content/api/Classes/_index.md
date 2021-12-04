---
title: Classes


---




* **namespace [embed](namespaces/namespaceembed/)** 
    * **class [adc](classes/classembed_1_1adc/)** <br>Analog to Digital Converter (ADC) hardware abstraction interface. Use this interface for devices and peripherals that can convert analog voltage signals into a digital number. 
    * **struct [bit_depth](classes/structembed_1_1bit__depth/)** 
    * **class [bit_limits](classes/classembed_1_1bit__limits/)** 
    * **class [can](classes/classembed_1_1can/)** 
        * **struct [message_t](classes/structembed_1_1can_1_1message__t/)** 
    * **class [can_network](classes/classembed_1_1can__network/)** <br>[can_network]() is a canbus message receiver handler and 
        * **class [node_t](classes/classembed_1_1can__network_1_1node__t/)** 
    * **struct [can_settings](classes/structembed_1_1can__settings/)** 
    * **class [counter](classes/classembed_1_1counter/)** <br>Counter hardware abstraction interface. Use this interface for devices and peripherals that have counting capabilities. Such devices can count up or down. Useful for keeping time. Expect counters to overflow when they reach the end of counting register's limits. 
    * **class [dac](classes/classembed_1_1dac/)** <br>Digital to Analog Converter (DAC) hardware abstraction interface. Use this interface for devices and peripherals that can create arbitrary analog voltages between a defined LOW and HIGH voltage. 
    * **class [driver](classes/classembed_1_1driver/)** <br>The basis class for all peripheral, device and system drivers in libembeddedhal. 
    * **class [full_scale](classes/classembed_1_1full__scale/)** 
    * **class [i2c](classes/classembed_1_1i2c/)** <br>Inter-integrated Circuit (I2C) or Two Wire Interface (TWI) communication protocol hardware abstract interface. 
    * **struct [i2c_settings](classes/structembed_1_1i2c__settings/)** <br>Generic settings for a standard I2C device. 
    * **class [input_pin](classes/classembed_1_1input__pin/)** <br>Digital input pin hardware abstraction. Use this to read a pin and determine if the voltage on it is HIGH or LOW. 
    * **struct [input_pin_settings](classes/structembed_1_1input__pin__settings/)** <br>Generic settings for input pins. 
    * **class [interrupt_pin](classes/classembed_1_1interrupt__pin/)** <br>Digital interrupt pin hardware abstraction. Use this to trigger an interrupt service routine (ISR) when a pin detects a falling edge (when the pin's voltage transitions from HIGH to LOW), a rising edge (when the pin's voltage transitions from LOW to HIGH), or any transition of state on the pin. 
    * **struct [interrupt_pin_settings](classes/structembed_1_1interrupt__pin__settings/)** <br>Generic settings for interrupt pins. 
    * **struct [invalid_option_t](classes/structembed_1_1invalid__option__t/)** <br>Used for defining static_asserts that should always fail, but only if the static_assert line is hit via `if constexpr` control block. Prefer to NOT use this directly but to use `invalid_option` instead. 
    * **struct [no_settings](classes/structembed_1_1no__settings/)** <br>An empty settings structure used to indicate that a driver or interface does not have generic settings. 
    * **class [output_pin](classes/classembed_1_1output__pin/)** <br>Digital output pin hardware abstraction. Use this to drive a pin HIGH or LOW in order to send a control signal or turn off or on an LED. 
    * **struct [output_pin_settings](classes/structembed_1_1output__pin__settings/)** <br>Generic settings for output pins. 
    * **class [pwm](classes/classembed_1_1pwm/)** <br>Pulse Width Modulation (PWM) channel hardware abstraction. 
    * **class [serial](classes/classembed_1_1serial/)** <br>Serial communication protocol hardware abstract interface. Use this interface for hardware that implements a serial protocol like UART, USART, RS232, RS485 and many others that use a similar communication protocol but may use different voltage schemes. 
    * **struct [serial_settings](classes/structembed_1_1serial__settings/)** <br>Generic settings for a standard serial device. 
    * **class [spi](classes/classembed_1_1spi/)** <br>Serial peripheral interface (SPI) communication protocol hardware abstract interface. 
    * **struct [spi_settings](classes/structembed_1_1spi__settings/)** <br>Generic settings for a standard SPI device. 
    * **class [static_callable](classes/classembed_1_1static__callable/)** <br>General class which will be used to allow for signature to be used and then split by the below class. 
    * **class [static_callable< owner_class, reference_designator, return_t(args_t...)>](classes/classembed_1_1static__callable_3_01owner__class_00_01reference__designator_00_01return__t_07args__t_8_8_8_08_4/)** <br>Specialization of [static_callable](classes/classembed_1_1static__callable/) with the return type and arguments split up. 
    * **class [static_memory_resource](classes/classembed_1_1static__memory__resource/)** <br>The [static_memory_resource]() is the polymorphic memory resource allocator that allows libembeddedhal's libraries to use a C++ standard container such as std::pmr::vector, std::pmr::string, std::pmr::unordered_map, and more without requiring dynamic memory allocation from the heap. It provides a simple way to create an allocator with built in storage, with its size indicated by a single template parameter. It also provides statistics regarding the amount of memory allocated such that developers can determine if they need to reduce or increase the size of the buffer. Memory statistics can also give programs the insight into how much memory space is available and make decisions based on that. In the event that the memory of the static allocator is exceeded, a std::bad_alloc excpetion is thrown. 
    * **namespace [this_thread](namespaces/namespaceembed_1_1this__thread/)** 
        * **struct [global_clocks](classes/structembed_1_1this__thread_1_1global__clocks/)** <br>internal clock 
    * **class [timer](classes/classembed_1_1timer/)** <br>Timer hardware abstraction interface. Use this interface for devices and peripherals that have timer like capabilities, such that, when a timer's time has expired, an event/interrupt/signal is generated. 



-------------------------------

Updated on 2021-12-04 at 16:46:01 +0000
