from dataclasses import dataclass
from socket import MsgFlag
from sqlite3 import DatabaseError
import rclpy
from rclpy.node import Node
from std_msgs.msg import String
from can_interfaces.msg import Can
from motordata_interfaces.msg import Motor
from .CAN_Recv import*
from .CAN_Send import*
from .Monitor import Motor_Monitor
from .CAN_Recv import Motor1


class CanBus(Node):
    """
    在canbus_node中建立发布者与订阅者
    发布者：pub_data 以1000帧率发布CAN_Recv中记录反馈数据的变量Motor1
    订阅者：订阅其他节点发布的控制电机运动的消息MotorControl，根据消息内容调用相应CAN发送函数
    """
    def __init__(self,name):
        super().__init__(name)
        self.get_logger().info("test node:%s" % name)
        self.pub_data = self.create_publisher(Motor,"motor",10)
        self.time_period = 0.001
        self.timer = self.create_timer(self.time_period,self.timer_callback)
        self.recv_data = self.create_subscription(Can,"motorcontrol",self.recvdata_callback,10)

    def timer_callback(self):
        msg = Motor()
        msg.can=Motor1.CAN_Channel
        msg.motor[0]=Motor1.Motor_Speed
        msg.motor[1]=Motor1.Current
        msg.motor[2]=Motor1.Voltage
        self.pub_data.publish(msg)


    def recvdata_callback(self,message):
         if message.data[0]==1:
             Motor_Stop_Control("can0", message.data[1])
         if message.data[0]==2:
             PWM_Control("can0", int(message.data[1]))
         if message.data[0]==3:
             Speed_Control("can0", message.data[1])
         if message.data[0]==4:
             Torque_Control("can0", message.data[1])
         self.get_logger().info('use fuction%d data%d' %(message.data[0],message.data[1]))

        





def main(args=None):
    """
    建立CAN收发的node：canbus_node
    """
    rclpy.init(args=args)
    canbus_node = CanBus("can0")
    rclpy.spin(canbus_node)
    rclpy.shutdown()




