// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from can_interfaces:msg/Can.idl
// generated code does not contain a copyright notice

#ifndef CAN_INTERFACES__MSG__DETAIL__CAN__STRUCT_H_
#define CAN_INTERFACES__MSG__DETAIL__CAN__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/Can in the package can_interfaces.
typedef struct can_interfaces__msg__Can
{
  float data[2];
} can_interfaces__msg__Can;

// Struct for a sequence of can_interfaces__msg__Can.
typedef struct can_interfaces__msg__Can__Sequence
{
  can_interfaces__msg__Can * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} can_interfaces__msg__Can__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CAN_INTERFACES__MSG__DETAIL__CAN__STRUCT_H_
