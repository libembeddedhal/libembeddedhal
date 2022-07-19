#pragma once

#include "../counter/interface.hpp"
#include "../counter/util.hpp"
#include "../frequency.hpp"
#include "../input_pin/interface.hpp"
#include "../output_pin/interface.hpp"
#include "interface.hpp"

namespace embed {
/**
 * @brief SPI implementation using a generic output and input pin.
 *
 */
class bit_bang_spi : public embed::spi
{
public:
  bit_bang_spi(embed::counter& p_counter,
               embed::output_pin& p_data_out,
               embed::input_pin& p_data_in,
               embed::output_pin& p_clock)
    : m_counter(&p_counter)
    , m_data_out(&p_data_out)
    , m_data_in(&p_data_in)
    , m_clock(&p_clock)
  {
  }

private:
  boost::leaf::result<void> driver_configure(
    const settings& p_settings) noexcept override
  {
    using namespace embed::literals;
    auto uptime = BOOST_LEAF_CHECK(m_counter->uptime());
    if (p_settings.clock_rate > uptime.frequency &&
        p_settings.clock_rate > 1_MHz) {
      return boost::leaf::new_error(embed::error::invalid_settings{});
    }
    m_settings = p_settings;
    return {};
  }
  boost::leaf::result<void> driver_transfer(
    [[maybe_unused]] std::span<const std::byte> p_data_out,
    [[maybe_unused]] std::span<std::byte> p_data_in,
    [[maybe_unused]] std::byte p_filler) noexcept override
  {
    auto uptime = BOOST_LEAF_CHECK(m_counter->uptime());
    auto wavelength = uptime.frequency.wavelength();
    auto delay_time =
      std::chrono::duration_cast<embed::time_duration>(wavelength);
    BOOST_LEAF_CHECK(
      embed::delay(*m_counter, delay_time));  // DELAY LINE FOR MY REFERENCE
  }

  embed::counter* m_counter;
  embed::output_pin* m_data_out;
  embed::input_pin* m_data_in;
  embed::output_pin* m_clock;

  embed::spi::settings m_settings{};
};
}  // namespace embed
