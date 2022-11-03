import CAN_Send
WheelRadius_r = 0.25   # unit m 
WheelSpacing_d = 0.6   # unit m
RotationRadius_R = 1   # unit m

def Move_Control(Line_Speed, Angular_Speed)-> None:
    '''
    Author: Liu Yuxiang 
    Time: 2022.10.21
    description: The motor control function by line spedd and angular speed of robot
    calculate the two rotation speed of motors and control it.

    parameter
    Line_Speed: the robot line speed 
    Positive number: Forward motion.        Negative number: backward movement
    Angular_Speed: the robot rotation speed 
    Positive number: clockwise movement.    Negative number: counterclockwise movement
    '''
    # The rotation speed of Left rear motor 
    w1 = (2*Line_Speed + Angular_Speed*WheelSpacing_d) / (2 * WheelRadius_r)
    # The rotation speed of right rear motor 
    w2 = -(2*Line_Speed - Angular_Speed*WheelSpacing_d) / (2 * WheelRadius_r)
    # Send speed to Electric regulation
    print('this is w1')
    print(int(w1))
    print('this is w2')
    print(int(w2))
    CAN_Send.Speed_Contorl(0x602, 'can0', int(w1))
    CAN_Send.Speed_Contorl(0x603, 'can0', int(w2))

# 位置环控制 暂时还没用上
def Rotation_Control(Rotation_Angle) -> None:
    '''
    Author: Liu Yuxiang 
    Time: 2022.10.21
    description: The motor control function by Rotation_Angle

    parameter
    Rotation_Angle: How many degrees does the robot need to rotate
    Positive number: clockwise movement.    Negative number: counterclockwise movement
    '''



if __name__ == "__main__":
    print('Start')
    Line_speed = CAN_Send.sys.argv[1]
    Angular_Speed = CAN_Send.sys.argv[2]
    Move_Control(float(Line_speed),float(Angular_Speed))
