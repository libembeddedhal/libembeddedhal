#pragma once

#include <queue>
#include <stdexcept>

#include "../testing.hpp"
#include "interface.hpp"

namespace embed::mock {
/**
 * @addtogroup interrupt_pin Interrupt Pin
 * @{
 */
/**
 * @brief mock interrupt_pin implementation for use in unit tests and
 * simulations.
 *
 */
struct interrupt_pin : public embed::interrupt_pin_interface
{
  /**
   * @brief Reset spy information for configure(), attach_interrupt(), and
   * detach_interrupt()
   *
   */
  void reset()
  {
    spy_configure.reset();
    spy_attach_interrupt.reset();
    spy_detach_interrupt.reset();
  }
  /**
   * @brief Queues the active levels to be returned for level()
   *
   * @param p_levels - queue of actives levels
   */
  void set(std::queue<bool>& p_levels)
  {
    m_levels = p_levels;
  }

  /// Spy handler for embed::interrupt_pin_interface::configure()
  spy_handler<settings> spy_configure;
  /// Spy handler for embed::interrupt_pin_interface::attach_interrupt()
  spy_handler<std::function<void(void)>, trigger_edge> spy_attach_interrupt;
  /// Spy handler for embed::interrupt_pin_interface::detach_interrupt()
  spy_handler<bool> spy_detach_interrupt;

private:
  boost::leaf::result<void> driver_configure(
    const settings& p_settings) noexcept override
  {
    return spy_configure.record(p_settings);
  }
  boost::leaf::result<bool> driver_level() noexcept override
  {
    if (m_levels.size() == 0) {
      return boost::leaf::new_error(
        std::out_of_range("interrupt pin level queue is empty!"));
    }
    bool m_current_value = m_levels.front();
    m_levels.pop();
    return m_current_value;
  }
  boost::leaf::result<void> driver_attach_interrupt(
    std::function<void(void)> p_callback,
    trigger_edge p_trigger) noexcept override
  {
    return spy_attach_interrupt.record(p_callback, p_trigger);
  }
  boost::leaf::result<void> driver_detach_interrupt() noexcept override
  {
    return spy_detach_interrupt.record(true);
  }

  std::queue<bool> m_levels{};
};
/** @} */
}  // namespace embed::mock
