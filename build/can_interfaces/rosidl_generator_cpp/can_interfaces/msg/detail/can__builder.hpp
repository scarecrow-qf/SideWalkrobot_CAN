// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from can_interfaces:msg/Can.idl
// generated code does not contain a copyright notice

#ifndef CAN_INTERFACES__MSG__DETAIL__CAN__BUILDER_HPP_
#define CAN_INTERFACES__MSG__DETAIL__CAN__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "can_interfaces/msg/detail/can__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace can_interfaces
{

namespace msg
{

namespace builder
{

class Init_Can_data
{
public:
  Init_Can_data()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::can_interfaces::msg::Can data(::can_interfaces::msg::Can::_data_type arg)
  {
    msg_.data = std::move(arg);
    return std::move(msg_);
  }

private:
  ::can_interfaces::msg::Can msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::can_interfaces::msg::Can>()
{
  return can_interfaces::msg::builder::Init_Can_data();
}

}  // namespace can_interfaces

#endif  // CAN_INTERFACES__MSG__DETAIL__CAN__BUILDER_HPP_
