import rclpy
from rclpy.node import Node
from std_msgs.msg import String

from .CAN_Recv import*
#from .CAN_Send import*

class CanBus(Node):
    def __init__(self,name):
        super().__init__(name)
        self.get_logger().info("test node:%s" % name)
        self.recv_data = self.create_publisher(String,"motor",10)
        self.time_period = 1
        self.timer = self.create_timer(self.time_period,self.timer_callback)

    def timer_callback(self):
        pass




def main(args=None):
    """
    建立CAN收发的node：canbus_node
    """
    rclpy.init(args=args)
    canbus_node = CanBus("can0")
    rclpy.spin(canbus_node)
    rclpy.shutdown()