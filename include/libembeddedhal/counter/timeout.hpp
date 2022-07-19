#pragma once

#include "../frequency.hpp"
#include "interface.hpp"

namespace embed {
/**
 * @addtogroup counter
 * @{
 */
/**
 * @brief Timeout object based on embed::counter_interface
 *
 * Prefer to use `embed::create_timeout(embed::counter_interface&)` instead of
 * instantiating this class directly.
 *
 */
class counter_timeout
{
public:
  /**
   * @brief Construct a new counter timeout object
   *
   * @param p_counter - counter driver
   * @param p_cycles_until_timeout - number of cycles until timeout
   */
  counter_timeout(embed::counter_interface& p_counter,
                  std::int64_t p_cycles_until_timeout) noexcept
    : m_counter(&p_counter)
    , m_cycles_until_timeout(p_cycles_until_timeout)
  {
  }
  /**
   * @brief Construct a new counter timeout object
   *
   * @param p_timeout - other counter_timeout
   */
  counter_timeout(const counter_timeout& p_timeout) noexcept = default;
  /**
   * @brief Assign construct a new counter timeout object
   *
   * @param p_timeout - other counter_timeout
   * @return counter_timeout&
   */
  counter_timeout& operator=(const counter_timeout& p_timeout) noexcept =
    default;
  /**
   * @brief Construct a new counter timeout object
   *
   * @param p_timeout - other counter_timeout
   */
  counter_timeout(counter_timeout&& p_timeout) noexcept = default;
  /**
   * @brief Move assign construct a new counter timeout object
   *
   * @param p_timeout - other counter_timeout
   * @return counter_timeout&
   */
  counter_timeout& operator=(counter_timeout&& p_timeout) noexcept = default;

  /**
   * @brief Call this object to check if it has timed out.
   *
   * @return boost::leaf::result<void>
   * @throws embed::error::timeout - if the number of cycles until timeout has
   * been exceeded.
   */
  boost::leaf::result<void> operator()() noexcept
  {
    auto current_count = BOOST_LEAF_CHECK(m_counter->uptime()).count;
    std::uint32_t delta_count = current_count - m_previous_count;
    m_cycles_until_timeout -= delta_count;

    if (m_cycles_until_timeout <= 0) {
      return boost::leaf::new_error(embed::error::timeout{});
    }

    m_previous_count = current_count;

    return {};
  }

private:
  embed::counter_interface* m_counter;
  std::int64_t m_cycles_until_timeout = 0;
  std::uint32_t m_previous_count = 0;
};
/** @} */
}  // namespace embed
