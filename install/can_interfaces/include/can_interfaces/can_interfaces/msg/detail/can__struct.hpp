// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from can_interfaces:msg/Can.idl
// generated code does not contain a copyright notice

#ifndef CAN_INTERFACES__MSG__DETAIL__CAN__STRUCT_HPP_
#define CAN_INTERFACES__MSG__DETAIL__CAN__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__can_interfaces__msg__Can __attribute__((deprecated))
#else
# define DEPRECATED__can_interfaces__msg__Can __declspec(deprecated)
#endif

namespace can_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Can_
{
  using Type = Can_<ContainerAllocator>;

  explicit Can_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      std::fill<typename std::array<float, 2>::iterator, float>(this->data.begin(), this->data.end(), 0.0f);
    }
  }

  explicit Can_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : data(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      std::fill<typename std::array<float, 2>::iterator, float>(this->data.begin(), this->data.end(), 0.0f);
    }
  }

  // field types and members
  using _data_type =
    std::array<float, 2>;
  _data_type data;

  // setters for named parameter idiom
  Type & set__data(
    const std::array<float, 2> & _arg)
  {
    this->data = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    can_interfaces::msg::Can_<ContainerAllocator> *;
  using ConstRawPtr =
    const can_interfaces::msg::Can_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<can_interfaces::msg::Can_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<can_interfaces::msg::Can_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      can_interfaces::msg::Can_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<can_interfaces::msg::Can_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      can_interfaces::msg::Can_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<can_interfaces::msg::Can_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<can_interfaces::msg::Can_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<can_interfaces::msg::Can_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__can_interfaces__msg__Can
    std::shared_ptr<can_interfaces::msg::Can_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__can_interfaces__msg__Can
    std::shared_ptr<can_interfaces::msg::Can_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Can_ & other) const
  {
    if (this->data != other.data) {
      return false;
    }
    return true;
  }
  bool operator!=(const Can_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Can_

// alias to use template instance with default allocator
using Can =
  can_interfaces::msg::Can_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace can_interfaces

#endif  // CAN_INTERFACES__MSG__DETAIL__CAN__STRUCT_HPP_
