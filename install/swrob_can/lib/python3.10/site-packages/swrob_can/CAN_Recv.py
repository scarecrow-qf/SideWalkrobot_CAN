import asyncio
from typing import List

import can
from can.notifier import MessageRecipient

from .CAN_Send import*
from .Monitor import*
Motor1 = Motor_Monitor('left', 0x602, 'can0')
Receive_Package = {
    'CAN_ID': 0x00,
    'status': 0x00,
    'Index' : 0x00,
    'Index_Sub' : 0x00,
    'Recv_Data' : 0x00,
}
MotorState_dict = {
        0x2100:'Phase_Current',
        0x2101:'Output_PWM',
        0x2102:'Commutation_frequency',
        0x2105:'Count_positon',
        0x2106:'is_PositionControl_Finish',
        0x2109:'Count_Relative_Position',
        0x210A:'Motor_Speed',                            # unit: RPM
        0x210B:'LocationContorl_TimeRemaining',          # unit: ms
        0x210C:'Current',                                # unit: A
        0x210D:'Voltage',                                # unit: V
        0x2111:'is_block',
        0x2112:'Fault_Status'
}

def Receive(CAN_Channel):
    '''
    Author: Liu Yuxiang 
    Time: 2022.10.13
    Basic description
    : waiting for recevice CAN package.
    Parameter 
    : CAN_channel: which channel rev CAN packages. 
    '''
    # rev information
    canx = can.interface.Bus(channel = CAN_Channel, bustype = 'socketcan')

    '''    
    can_filter = [{"can_id": 0x582, "can_mask": 0xffffffff}]
    canx.set_filters(can_filter)
    '''

    '''
    loop the canx, recv the message like a listener
    '''

    for msg in canx:      
        print(msg)


def Unpack_Packages(msg) -> Receive_Package:
    # unpack rev packages
        Receive_Package['CAN_ID'] = hex(msg.arbitration_id)
        '''
        数据字节 0 状态码
        数据字节 1-2 对象字典索引号，低字节在前
        数据字节 3 对象字典子索引号
        数据字节 4-7 读取的数据或传送中止代码，低字节在前
        '''
        Receive_Package['status'] = hex(msg.data[0])
        Receive_Package['Index'] =  hex(msg.data[1] + ( msg.data[2] << 8))
        Receive_Package['Index_Sub'] = hex(msg.data[3])
        Receive_Package['Recv_Data'] = hex(msg.data[4] + (msg.data[5]<<8) + (msg.data[6]<<8) + (msg.data[7]<<8))
        print(Receive_Package)

        return Receive_Package


def Read_Data(CAN_ID, CAN_Channel, Index_num):
    # the data is invalid. Doesn't matter
    CAN_Send.Send_Package(CAN_ID, CAN_Channel, 5, Index_num, [0x00,0x00,0x00,0x00])


def Solve_Message(msg: can.Message) -> None:
    """Regular callback function. Can also be a coroutine."""
    global Motor1
    # You can add any id you want to recv and unpack
    if msg.arbitration_id == 0x582:
        Recv = Unpack_Packages(msg)
        Motor1.GetParameters(Recv,Recv['Index'])   

async def main() -> None:
    """The main function that runs in the loop."""

    with can.Bus(  # type: ignore
         channel="can0", bustype= 'socketcan'
    ) as bus:
        reader = can.AsyncBufferedReader()
        logger = can.Logger("logfile.asc") # Create log file to check the log information

        # 所有异步函数均需要放入到事件队列中
        listeners: List[MessageRecipient] = [
            Solve_Message,  # Callback function
            reader,  # AsyncBufferedReader() listener
            logger,  # Regular Listener object
        ]
   
        # Create Notifier with an explicit loop to use for scheduling of callbacks
        loop = asyncio.get_running_loop()
        # bus: which bus be listened
        # listeners: 每次收到消息将收到的消息传给listener
        # loop: – An asyncio event loop to schedule the listeners in. 
        notifier = can.Notifier(bus, listeners, loop=loop)

        # Start sending first message
        print("Getting messages...")
        for key, value in MotorState_dict.items():
            Read_Data(0x602, 'can0', key)
            # Wait for next message from AsyncBufferedReader
            msg = await reader.get_message()
            # Delay response
            await asyncio.sleep(0.5)

        # Wait for last message to arrive
        await reader.get_message()
        print("Done!")
        print(Motor1.__dict__)

        # Clean-up
        notifier.stop()


if __name__ == "__main__":
    asyncio.run(main())
    print("Finish!")
