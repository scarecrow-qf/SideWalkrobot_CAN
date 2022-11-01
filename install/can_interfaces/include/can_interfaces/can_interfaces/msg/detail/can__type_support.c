// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from can_interfaces:msg/Can.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "can_interfaces/msg/detail/can__rosidl_typesupport_introspection_c.h"
#include "can_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "can_interfaces/msg/detail/can__functions.h"
#include "can_interfaces/msg/detail/can__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void can_interfaces__msg__Can__rosidl_typesupport_introspection_c__Can_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  can_interfaces__msg__Can__init(message_memory);
}

void can_interfaces__msg__Can__rosidl_typesupport_introspection_c__Can_fini_function(void * message_memory)
{
  can_interfaces__msg__Can__fini(message_memory);
}

size_t can_interfaces__msg__Can__rosidl_typesupport_introspection_c__size_function__Can__data(
  const void * untyped_member)
{
  (void)untyped_member;
  return 2;
}

const void * can_interfaces__msg__Can__rosidl_typesupport_introspection_c__get_const_function__Can__data(
  const void * untyped_member, size_t index)
{
  const float * member =
    (const float *)(untyped_member);
  return &member[index];
}

void * can_interfaces__msg__Can__rosidl_typesupport_introspection_c__get_function__Can__data(
  void * untyped_member, size_t index)
{
  float * member =
    (float *)(untyped_member);
  return &member[index];
}

void can_interfaces__msg__Can__rosidl_typesupport_introspection_c__fetch_function__Can__data(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const float * item =
    ((const float *)
    can_interfaces__msg__Can__rosidl_typesupport_introspection_c__get_const_function__Can__data(untyped_member, index));
  float * value =
    (float *)(untyped_value);
  *value = *item;
}

void can_interfaces__msg__Can__rosidl_typesupport_introspection_c__assign_function__Can__data(
  void * untyped_member, size_t index, const void * untyped_value)
{
  float * item =
    ((float *)
    can_interfaces__msg__Can__rosidl_typesupport_introspection_c__get_function__Can__data(untyped_member, index));
  const float * value =
    (const float *)(untyped_value);
  *item = *value;
}

static rosidl_typesupport_introspection_c__MessageMember can_interfaces__msg__Can__rosidl_typesupport_introspection_c__Can_message_member_array[1] = {
  {
    "data",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    2,  // array size
    false,  // is upper bound
    offsetof(can_interfaces__msg__Can, data),  // bytes offset in struct
    NULL,  // default value
    can_interfaces__msg__Can__rosidl_typesupport_introspection_c__size_function__Can__data,  // size() function pointer
    can_interfaces__msg__Can__rosidl_typesupport_introspection_c__get_const_function__Can__data,  // get_const(index) function pointer
    can_interfaces__msg__Can__rosidl_typesupport_introspection_c__get_function__Can__data,  // get(index) function pointer
    can_interfaces__msg__Can__rosidl_typesupport_introspection_c__fetch_function__Can__data,  // fetch(index, &value) function pointer
    can_interfaces__msg__Can__rosidl_typesupport_introspection_c__assign_function__Can__data,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers can_interfaces__msg__Can__rosidl_typesupport_introspection_c__Can_message_members = {
  "can_interfaces__msg",  // message namespace
  "Can",  // message name
  1,  // number of fields
  sizeof(can_interfaces__msg__Can),
  can_interfaces__msg__Can__rosidl_typesupport_introspection_c__Can_message_member_array,  // message members
  can_interfaces__msg__Can__rosidl_typesupport_introspection_c__Can_init_function,  // function to initialize message memory (memory has to be allocated)
  can_interfaces__msg__Can__rosidl_typesupport_introspection_c__Can_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t can_interfaces__msg__Can__rosidl_typesupport_introspection_c__Can_message_type_support_handle = {
  0,
  &can_interfaces__msg__Can__rosidl_typesupport_introspection_c__Can_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_can_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, can_interfaces, msg, Can)() {
  if (!can_interfaces__msg__Can__rosidl_typesupport_introspection_c__Can_message_type_support_handle.typesupport_identifier) {
    can_interfaces__msg__Can__rosidl_typesupport_introspection_c__Can_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &can_interfaces__msg__Can__rosidl_typesupport_introspection_c__Can_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
