// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from can_interfaces:msg/Can.idl
// generated code does not contain a copyright notice

#ifndef CAN_INTERFACES__MSG__DETAIL__CAN__FUNCTIONS_H_
#define CAN_INTERFACES__MSG__DETAIL__CAN__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "can_interfaces/msg/rosidl_generator_c__visibility_control.h"

#include "can_interfaces/msg/detail/can__struct.h"

/// Initialize msg/Can message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * can_interfaces__msg__Can
 * )) before or use
 * can_interfaces__msg__Can__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_can_interfaces
bool
can_interfaces__msg__Can__init(can_interfaces__msg__Can * msg);

/// Finalize msg/Can message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_can_interfaces
void
can_interfaces__msg__Can__fini(can_interfaces__msg__Can * msg);

/// Create msg/Can message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * can_interfaces__msg__Can__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_can_interfaces
can_interfaces__msg__Can *
can_interfaces__msg__Can__create();

/// Destroy msg/Can message.
/**
 * It calls
 * can_interfaces__msg__Can__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_can_interfaces
void
can_interfaces__msg__Can__destroy(can_interfaces__msg__Can * msg);

/// Check for msg/Can message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_can_interfaces
bool
can_interfaces__msg__Can__are_equal(const can_interfaces__msg__Can * lhs, const can_interfaces__msg__Can * rhs);

/// Copy a msg/Can message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_can_interfaces
bool
can_interfaces__msg__Can__copy(
  const can_interfaces__msg__Can * input,
  can_interfaces__msg__Can * output);

/// Initialize array of msg/Can messages.
/**
 * It allocates the memory for the number of elements and calls
 * can_interfaces__msg__Can__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_can_interfaces
bool
can_interfaces__msg__Can__Sequence__init(can_interfaces__msg__Can__Sequence * array, size_t size);

/// Finalize array of msg/Can messages.
/**
 * It calls
 * can_interfaces__msg__Can__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_can_interfaces
void
can_interfaces__msg__Can__Sequence__fini(can_interfaces__msg__Can__Sequence * array);

/// Create array of msg/Can messages.
/**
 * It allocates the memory for the array and calls
 * can_interfaces__msg__Can__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_can_interfaces
can_interfaces__msg__Can__Sequence *
can_interfaces__msg__Can__Sequence__create(size_t size);

/// Destroy array of msg/Can messages.
/**
 * It calls
 * can_interfaces__msg__Can__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_can_interfaces
void
can_interfaces__msg__Can__Sequence__destroy(can_interfaces__msg__Can__Sequence * array);

/// Check for msg/Can message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_can_interfaces
bool
can_interfaces__msg__Can__Sequence__are_equal(const can_interfaces__msg__Can__Sequence * lhs, const can_interfaces__msg__Can__Sequence * rhs);

/// Copy an array of msg/Can messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_can_interfaces
bool
can_interfaces__msg__Can__Sequence__copy(
  const can_interfaces__msg__Can__Sequence * input,
  can_interfaces__msg__Can__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // CAN_INTERFACES__MSG__DETAIL__CAN__FUNCTIONS_H_
