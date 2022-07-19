#include <boost/ut.hpp>
#include <libembeddedhal/i2c/util.hpp>
#include <span>

namespace embed {
boost::ut::suite i2c_util_test = []() {
  using namespace boost::ut;

  static constexpr std::byte successful_address{ 0x15 };
  static constexpr std::byte failure_address{ 0x33 };
  static constexpr std::byte filler_byte{ 0xA5 };

  class dummy : public embed::i2c_interface
  {
  public:
    [[nodiscard]] boost::leaf::result<void> driver_configure(
      const settings&) noexcept override
    {
      return {};
    }
    [[nodiscard]] boost::leaf::result<void> driver_transaction(
      std::byte p_address,
      std::span<const std::byte> p_out,
      std::span<std::byte> p_in) noexcept override
    {
      m_address = p_address;
      m_out = p_out;
      m_in = p_in;

      std::fill(m_in.begin(), m_in.end(), filler_byte);

      if (m_address == failure_address) {
        return boost::leaf::new_error();
      }

      return {};
    }

    virtual ~dummy()
    {
    }

    std::byte m_address = std::byte{ 0 };
    std::span<const std::byte> m_out = std::span<const std::byte>{};
    std::span<std::byte> m_in = std::span<std::byte>{};
  };

  "[success] write"_test = []() {
    // Setup
    dummy i2c;
    const std::array<std::byte, 4> expected_payload{};

    // Exercise
    auto result = write(i2c, successful_address, expected_payload);
    bool successful = static_cast<bool>(result);

    // Verify
    expect(successful);
    expect(successful_address == i2c.m_address);
    expect(that % expected_payload.data() == i2c.m_out.data());
    expect(that % expected_payload.size() == i2c.m_out.size());
    expect(that % nullptr == i2c.m_in.data());
    expect(that % 0 == i2c.m_in.size());
  };

  "[failure] write"_test = []() {
    // Setup
    dummy i2c;
    const std::array<std::byte, 4> expected_payload{};

    // Exercise
    auto result = write(i2c, failure_address, expected_payload);
    bool successful = static_cast<bool>(result);

    // Verify
    expect(!successful);
    expect(failure_address == i2c.m_address);
    expect(that % expected_payload.data() == i2c.m_out.data());
    expect(that % expected_payload.size() == i2c.m_out.size());
    expect(that % nullptr == i2c.m_in.data());
    expect(that % 0 == i2c.m_in.size());
  };

  "[success] read"_test = []() {
    // Setup
    dummy i2c;
    std::array<std::byte, 4> expected_buffer;

    // Exercise
    auto result = read(i2c, successful_address, expected_buffer);
    bool successful = static_cast<bool>(result);

    // Verify
    expect(successful);
    expect(successful_address == i2c.m_address);
    expect(that % expected_buffer.data() == i2c.m_in.data());
    expect(that % expected_buffer.size() == i2c.m_in.size());
    expect(that % nullptr == i2c.m_out.data());
    expect(that % 0 == i2c.m_out.size());
  };

  "[failure] read"_test = []() {
    // Setup
    dummy i2c;
    std::array<std::byte, 4> expected_buffer;

    // Exercise
    auto result = read(i2c, failure_address, expected_buffer);
    bool successful = static_cast<bool>(result);

    // Verify
    expect(!successful);
    expect(failure_address == i2c.m_address);
    expect(that % expected_buffer.data() == i2c.m_in.data());
    expect(that % expected_buffer.size() == i2c.m_in.size());
    expect(that % nullptr == i2c.m_out.data());
    expect(that % 0 == i2c.m_out.size());
  };

  "[success] read<Length>"_test = []() {
    // Setup
    dummy i2c;
    std::array<std::byte, 5> expected_buffer;
    expected_buffer.fill(filler_byte);

    // Exercise
    auto result = read<expected_buffer.size()>(i2c, successful_address);
    bool successful = static_cast<bool>(result);

    // Verify
    expect(successful);
    expect(successful_address == i2c.m_address);
    expect(std::equal(
      expected_buffer.begin(), expected_buffer.end(), result.value().begin()));
    expect(that % nullptr == i2c.m_out.data());
    expect(that % 0 == i2c.m_out.size());
  };

  "[failure] read<Length>"_test = []() {
    // Setup
    dummy i2c;

    // Exercise
    auto result = read<5>(i2c, failure_address);
    bool successful = static_cast<bool>(result);

    // Verify
    expect(!successful);
    expect(failure_address == i2c.m_address);
    expect(that % nullptr == i2c.m_out.data());
    expect(that % 0 == i2c.m_out.size());
  };

  "[success] write_then_read"_test = []() {
    // Setup
    dummy i2c;
    const std::array<std::byte, 4> expected_payload{};
    std::array<std::byte, 4> expected_buffer;

    // Exercise
    auto result = write_then_read(
      i2c, successful_address, expected_payload, expected_buffer);
    bool successful = static_cast<bool>(result);

    // Verify
    expect(successful);
    expect(successful_address == i2c.m_address);
    expect(that % expected_payload.data() == i2c.m_out.data());
    expect(that % expected_payload.size() == i2c.m_out.size());
    expect(that % expected_buffer.data() == i2c.m_in.data());
    expect(that % expected_buffer.size() == i2c.m_in.size());
  };

  "[failure] write_then_read"_test = []() {
    // Setup
    dummy i2c;
    const std::array<std::byte, 4> expected_payload{};
    std::array<std::byte, 4> expected_buffer;
    expected_buffer.fill(filler_byte);

    // Exercise
    auto result =
      write_then_read(i2c, failure_address, expected_payload, expected_buffer);
    bool successful = static_cast<bool>(result);

    // Verify
    expect(!successful);
    expect(failure_address == i2c.m_address);
    expect(that % expected_payload.data() == i2c.m_out.data());
    expect(that % expected_payload.size() == i2c.m_out.size());
    expect(that % expected_buffer.data() == i2c.m_in.data());
    expect(that % expected_buffer.size() == i2c.m_in.size());
  };

  "[success] write_then_read<Length>"_test = []() {
    // Setup
    dummy i2c;
    const std::array<std::byte, 4> expected_payload{};
    std::array<std::byte, 4> expected_buffer{};
    expected_buffer.fill(filler_byte);

    // Exercise
    auto result = write_then_read<5>(i2c, successful_address, expected_payload);
    bool successful = static_cast<bool>(result);
    auto actual_array = result.value();

    // Verify
    expect(successful);
    expect(successful_address == i2c.m_address);
    expect(that % expected_payload.data() == i2c.m_out.data());
    expect(that % expected_payload.size() == i2c.m_out.size());
    expect(std::equal(
      expected_buffer.begin(), expected_buffer.end(), actual_array.begin()));
  };

  "[failure] write_then_read<Length>"_test = []() {
    // Setup
    dummy i2c;
    const std::array<std::byte, 4> expected_payload{};

    // Exercise
    auto result = write_then_read<5>(i2c, failure_address, expected_payload);
    bool successful = static_cast<bool>(result);

    // Verify
    expect(!successful);
    expect(failure_address == i2c.m_address);
    expect(that % expected_payload.data() == i2c.m_out.data());
    expect(that % expected_payload.size() == i2c.m_out.size());
  };
};
}  // namespace embed
