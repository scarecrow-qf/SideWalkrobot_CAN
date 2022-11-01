// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from can_interfaces:msg/Can.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "can_interfaces/msg/detail/can__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace can_interfaces
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void Can_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) can_interfaces::msg::Can(_init);
}

void Can_fini_function(void * message_memory)
{
  auto typed_message = static_cast<can_interfaces::msg::Can *>(message_memory);
  typed_message->~Can();
}

size_t size_function__Can__data(const void * untyped_member)
{
  (void)untyped_member;
  return 2;
}

const void * get_const_function__Can__data(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<float, 2> *>(untyped_member);
  return &member[index];
}

void * get_function__Can__data(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<float, 2> *>(untyped_member);
  return &member[index];
}

void fetch_function__Can__data(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const float *>(
    get_const_function__Can__data(untyped_member, index));
  auto & value = *reinterpret_cast<float *>(untyped_value);
  value = item;
}

void assign_function__Can__data(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<float *>(
    get_function__Can__data(untyped_member, index));
  const auto & value = *reinterpret_cast<const float *>(untyped_value);
  item = value;
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember Can_message_member_array[1] = {
  {
    "data",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    2,  // array size
    false,  // is upper bound
    offsetof(can_interfaces::msg::Can, data),  // bytes offset in struct
    nullptr,  // default value
    size_function__Can__data,  // size() function pointer
    get_const_function__Can__data,  // get_const(index) function pointer
    get_function__Can__data,  // get(index) function pointer
    fetch_function__Can__data,  // fetch(index, &value) function pointer
    assign_function__Can__data,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers Can_message_members = {
  "can_interfaces::msg",  // message namespace
  "Can",  // message name
  1,  // number of fields
  sizeof(can_interfaces::msg::Can),
  Can_message_member_array,  // message members
  Can_init_function,  // function to initialize message memory (memory has to be allocated)
  Can_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t Can_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &Can_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace can_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<can_interfaces::msg::Can>()
{
  return &::can_interfaces::msg::rosidl_typesupport_introspection_cpp::Can_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, can_interfaces, msg, Can)() {
  return &::can_interfaces::msg::rosidl_typesupport_introspection_cpp::Can_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
