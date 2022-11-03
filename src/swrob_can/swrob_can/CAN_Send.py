import os
import can
import sys

# The motor ID. 
CAN_ID = [0x602, 0x603]

def Send_Package(CAN_ID, CAN_Channel, Write_Byte_Num, Index_num, data):
    '''
    基本描述
    Author: Liu Yuxiang 
    Time: 2022.10.13
    description: Contracting bottom interface
    详细描述
    parameter
    :CAN_ID: 0X01-0X7F
    :Write_Byte_Num: from 1 to 5. info: 5 represent you need get data from register
    :Index_num: See the document 
    :data: the msg you need to send 
    '''
    Byte_num_dict = {
    1: 0x2F,
    2: 0x2B,
    3: 0x27,
    4: 0x23,
    5: 0x40, # represent reading data
    }
    if (Write_Byte_Num > 5) or  (Write_Byte_Num < 1):
        print("The Write_Byte_Num is not correct, plz choose 1 to 5./n")
        Write_Byte_Num = 1
    # Put lower byte in front
    Index_num_high =  Index_num & 0xFF
    Index_num_low =   (Index_num >> 8) & 0xFF
    # All data are combined to a list
    data = [Byte_num_dict.get(Write_Byte_Num)] + [Index_num_high,Index_num_low] + [0x00] + data
    msg = can.Message(is_extended_id=False, arbitration_id=CAN_ID, data=data)

    # send can data
    canx = can.interface.Bus(channel = CAN_Channel, bustype = 'socketcan')# socketcan_native
    canx.send(msg)
    print(msg)
    # Do not close CAN


def Motor_Stop_Control(CAN_Channel, Stop_Mode):
    '''
    Author: Liu Yuxiang 
    Time: 2022.10.14
    description: Stop motors

    parameter
    CAN_ID: you may have more than one motors, so the CAN_ID must be a list
    Stop_Mode: There are 3 Mode to stop motors
        Normal stop, Emergency stop and Free stop.
        1:Normal stop--stop by your own set parameters.
        2:Emergency stop--stop by your own set emergency parameters.
        3.Free stop--shut down the power and stop motors by resistance 
    '''
    for index,ID in enumerate(CAN_ID):
        if Stop_Mode == 1:
            Send_Package(CAN_Channel, 1, 0x2000, [0x10,0x00,0x00,0x00])
        elif Stop_Mode == 2:
            Send_Package(CAN_Channel, 1, 0x2000, [0x11,0x00,0x00,0x00])
        elif Stop_Mode == 3:
            Send_Package(CAN_Channel, 1, 0x2000, [0x12,0x00,0x00,0x00])

def PWM_Control(CAN_Channel, PWM_Duty_Cycle):
    '''
    Author: Liu Yuxiang 
    Time: 2022.10.13
    description: Control the motor by PWM
    详细描述
    parameter
    :CAN_ID: 0X01-0X7F
    :CAN_channel: (str)can0, can1
    :PWM_Duty_Cycle: -1000 ~ 1000
    '''
    # set mode as PWM control
    Send_Package(CAN_ID[0], CAN_Channel, 1, 0x2000, [0x00,0x00,0x00,0x00])
    Send_Package(CAN_ID[1], CAN_Channel, 1, 0x2000, [0x00,0x00,0x00,0x00])
    # set PWM_Duty_Cycle 
    data = [0x00,0x00,0x00,0x00]
    # Put lower byte in front
    for i in range(0,4):
        digit = i*8
        data[i] = (PWM_Duty_Cycle >> digit) & 0xFF
    # Send message
    Send_Package(CAN_ID[0], CAN_Channel, 4, 0x2001, data)
    Send_Package(CAN_ID[1], CAN_Channel, 4, 0x2001, data)



def Speed_Control(CAN_Channel, Speed):
    '''
    Author: Liu Yuxiang 
    Time: 2022.10.14
    basic description
    : Control the motor by using speed loop
    parameter
    :Speed: -max speed ~ max speed(-500-500)
    '''
    # set mode as speed control mode
    Send_Package(CAN_ID[0], CAN_Channel, 1, 0x2000, [0x01,0x00,0x00,0x00])
    Send_Package(CAN_ID[1], CAN_Channel, 1, 0x2000, [0x01,0x00,0x00,0x00])
    # And the parameter can be set by GUI tool, So we do not need set.

    # Setting register 0x200A as 1 which change the motor mode to RPM control mode
    Send_Package(CAN_ID[0], CAN_Channel, 1, 0x200A, [0x01,0x00,0x00,0x00])
    Send_Package(CAN_ID[1], CAN_Channel, 1, 0x200A, [0x01,0x00,0x00,0x00])
    data = [0x00,0x00,0x00,0x00]
    # Put lower byte in front
    for i in range(0,4):
        digit = i*8
        data[i] = (Speed >> digit) & 0xFF
    # Send message
    Send_Package(CAN_ID[0], CAN_Channel, 4, 0x2001, data)
    Send_Package(CAN_ID[1], CAN_Channel, 4, 0x2001, data)


def Torque_Control(CAN_Channel, Current):
    '''
    Author: Liu Yuxiang 
    Time: 2022.10.14
    basic description
    :Using the Torque(force) to control motor
    parameter
    :Current: -max current ~ max current(set by youself)
    '''
    # set mode as torque control mode
    Send_Package(CAN_ID[0], CAN_Channel, 1, 0x2000, [0x02,0x00,0x00,0x00])
    Send_Package(CAN_ID[1], CAN_Channel, 1, 0x2000, [0x02,0x00,0x00,0x00])
    # The actual current is the send_data*0.01(A)
    data = [0x00,0x00,0x00,0x00]
    # Put lower byte in front
    for i in range(0,4):
        digit = i*8
        data[i] = (Current >> digit) & 0xFF
    # Send message
    Send_Package(CAN_ID[0], CAN_Channel, 4, 0x2001, data)
    Send_Package(CAN_ID[1], CAN_Channel, 4, 0x2001, data)

def Angle_continuity():
    angle = 0
    return angle
def Position_Contorl(CAN_Channel, Location_Type, Target_Location):
    '''
    Author: Liu Yuxiang 
    Time: 2022.10.14
    basic description
    :Using the position loop to control motor
    parameter
    :Location_Type: two typem, Absolute position and relative position
    :Target_Location: 这个地方文档没写清除，需要测试才知道是怎么样的,应该是根据电机的极来进行计数并控制
    这里需要考虑角度连续化、
    :Target_Location(unit: degree)
    '''
    # set mode as postion control mode
    Send_Package(CAN_Channel, 1, 0x2000, [0x03,0x00,0x00,0x00])
    # set location control type
    if Location_Type == 'Absolute':
        # set absolute type 
        Send_Package(CAN_Channel, 1, 0x2002, [0x00,0x00,0x00,0x00])

        '''
        角度连续化需要写的代码
        以及和监控台的代码相比较
        '''
        # set target location
        Send_Package(CAN_Channel, 1, 0x2003, [0x00,0x00,0x00,0x00])


    # if the type is relative
    else:
        # set absolute type control mode 
        Send_Package(CAN_Channel, 1, 0x2002, [0x01,0x00,0x00,0x00])

        '''
        角度连续化需要写的代码
        以及和监控台的代码相比较
        '''

        # The actual current is the send_data*0.01(A)
        data = [0x00,0x00,0x00,0x00]
        # Put lower byte in front
        for i in range(0,4):
            digit = i*8
            data[i] = (Target_Location >> digit) & 0xFF
        # Send message
        Send_Package(CAN_Channel, 4, 0x2001, data)



if __name__ == "__main__":
    '''
    tips
    These two line code should be put into Startup script
    os.system('sudo ip link set can0 up type can bitrate 500000')
    os.system('sudo ifconfig can0 txqueuelen 65536')
    '''

    '''debug'''
    #speed = sys.argv[1]
    #if_stop = sys.argv[2]
    
    while(1):
        print('------------------------------')
        #Send_Package(0x602, 'can0', 1, 0x2000, [0x01,0x00,0x00,0x00])
        #Recv = Receive_Package('can0')
