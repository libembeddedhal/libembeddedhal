#pragma once

#include "../testing.hpp"
#include "interface.hpp"

namespace hal::mock {
/**
 * @addtogroup pwm
 * @{
 */
/**
 * @brief Mock pwm implementation for use in unit tests and simulations with spy
 * functions for configure() and duty_cycle().
 *
 */
struct pwm : public hal::pwm
{
  /**
   * @brief Reset spy information for both configure() and duty_cycle()
   *
   */
  void reset()
  {
    spy_configure.reset();
    spy_duty_cycle.reset();
  }

  /// Spy handler for hal::pwm::configure()
  spy_handler<settings> spy_configure;
  /// Spy handler for hal::pwm::duty_cycle()
  spy_handler<percent> spy_duty_cycle;

private:
  status driver_configure(const settings& p_settings) noexcept override
  {
    return spy_configure.record(p_settings);
  };
  status driver_duty_cycle(percent p_duty_cycle) noexcept override
  {
    return spy_duty_cycle.record(p_duty_cycle);
  };
};
/** @} */
}  // namespace hal::mock
