#pragma once

#include <cstdint>

#include "../error.hpp"
#include "../frequency.hpp"
#include "../percent.hpp"

namespace embed {
/**
 * @addtogroup pwm
 * Available pwm APIs
 * @{
 */
/**
 * @brief Pulse Width Modulation (PWM) channel hardware abstraction.
 *
 */
class pwm_interface
{
public:
  /// Generic settings for a hardware Pulse Width Modulation (PWM) generating
  /// devices devices.
  struct settings
  {
    /// The target channel PWM frequency.
    embed::frequency frequency = embed::frequency(1'000);

    /**
     * @brief Default operators for <, <=, >, >= and ==
     *
     * @return auto - result of the comparison
     */
    [[nodiscard]] constexpr auto operator<=>(const settings&) const noexcept =
      default;
  };

  /**
   * @brief Configure pwm to match the settings supplied
   *
   * @param p_settings - settings to apply to pwm driver
   * @return boost::leaf::result<void> - any error that occurred during this
   * operation. Will return embed::error::invalid_settings if the settings could
   * not be achieved.
   */
  [[nodiscard]] boost::leaf::result<void> configure(
    const settings& p_settings) noexcept
  {
    return driver_configure(p_settings);
  }

  /**
   * @brief Set the duty cycle percentage
   *
   * @param p_duty_cycle - set the duty cycle of the pwm.
   * @return boost::leaf::result<void> - any error that occurred during this
   * operation.
   */
  [[nodiscard]] boost::leaf::result<void> duty_cycle(
    percent p_duty_cycle) noexcept
  {
    return driver_duty_cycle(p_duty_cycle);
  }

private:
  virtual boost::leaf::result<void> driver_configure(
    const settings& p_settings) noexcept = 0;
  virtual boost::leaf::result<void> driver_duty_cycle(
    percent p_duty_cycle) noexcept = 0;
};

template<class T>
concept pwm = std::is_base_of_v<embed::pwm_interface, T>;

constexpr embed::pwm_interface& to_interface(embed::pwm auto& p_pwm)
{
  return p_pwm;
}

/** @} */
}  // namespace embed
