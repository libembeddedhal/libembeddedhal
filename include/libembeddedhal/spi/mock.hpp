
#pragma once
#include "../testing.hpp"
#include "interface.hpp"

namespace embed::mock {
/**
 * @addtogroup spi
 * @{
 */
/**
 * @brief Mock spi implementation for use in unit tests and simulations with a
 * spy functions for configure() and a record for the transfer() out data. The
 * record ignores the in buffer and just stores the data being sent so it can be
 * inspected later.
 */
struct write_only_spi : public embed::spi_interface
{
  /**
   * @brief Reset spy information for both configure() and transfer()
   *
   */
  void reset()
  {
    spy_configure.reset();
    write_record.clear();
  }

  /// Spy handler for embed::spi_interface::configure()
  spy_handler<settings> spy_configure;
  /// Record of the out data from embed::spi_interface::transfer()
  std::vector<std::vector<std::byte>> write_record;

private:
  boost::leaf::result<void> driver_configure(
    const settings& p_settings) noexcept override
  {
    return spy_configure.record(p_settings);
  };
  boost::leaf::result<void> driver_transfer(
    std::span<const std::byte> p_data_out,
    [[maybe_unused]] std::span<std::byte> p_data_in,
    [[maybe_unused]] std::byte p_filler) noexcept override
  {
    write_record.push_back({ p_data_out.begin(), p_data_out.end() });
    return {};
  };
};
/** @} */
}  // namespace embed::mock
