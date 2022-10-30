from glob import glob
from typing import Dict
#class member

class Motor_Monitor:
    def __init__(
        self,
        Name,
        CAN_ID,
        CAN_Channel,
    ):
        '''
        Monitor the motors' status
        
        Parameters
        : Name: Nameing the different motors and you can add any information in this parameters
        : CAN_ID: the motors' ID.
        '''
        self.name = Name
        self.CAN_ID = CAN_ID
        self.CAN_Channel = CAN_Channel
        self.Phase_Current = 0
        self.Output_PWM = 0
        self.Commutation_frequency = 0
        self.Count_position = 0
        self.is_PositionControl_Finish: bool = False
        self.Count_Relative_Position = 0
        self.Motor_Speed = 0                            # unit: RPM
        self.LocationContorl_TimeRemaining = 0          # unit: ms
        self.Current = 0                                # unit: A
        self.Voltage = 0                                # unit: V
        self.is_block = 0
        self.Fault_Status = 0

    def GetParameters(self,Recv,Index):
        # Get Phase_Current data
        if Index == '0x2100':
            self.Phase_Current = Recv['Recv_Data']
            print("get Phase_Current")
        if Index == '0x2101':
            self.Output_PWM = Recv['Recv_Data']
            print("get Output_PWM")
        if Index == '0x2102':
            self.Commutation_frequency = Recv['Recv_Data']
            print('get Commutation frequency')
        if Index == '0x2105':
            self.Count_position = Recv['Recv_Data']
            print('get Count position')
        if Index == '0x2106':
            self.is_PositionControl_Finish = Recv['Recv_Data']
            print('get whether position control is finished')
        if Index == '0x2109':
            self.Count_Relative_Position = Recv['Recv_Data']
            print("get the count of relative position")
        if Index == '0x210a':
            self.Motor_Speed = Recv['Recv_Data']
            print('get motor speed')
        if Index == '0x210b':
            self.LocationContorl_TimeRemaining = Recv['Recv_Data']
            print('get tune remaining')
        if Index == '0x210c':
            self.Current = Recv['Recv_Data']
            print('get current')
        if Index == '0x210d':
            self.Voltage = Recv['Recv_Data']
            print("get voltage")
            print(Recv['Recv_Data'])
        if Index == '0x2111':
            self.is_block = Recv['Recv_Data']
            print('get is block')
        if Index == '0x2112':
            self.Fault_Status = Recv['Recv_Data']
            print('Fault status')


if __name__ == "__main__":
    print()
