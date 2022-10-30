# SideWalkrobot_CAN
Autor: 柳煜翔 

update time: 2022.10.19  14:55

description: 人行道机器人底层CAN通信接口

## 完成部分：

发包：目前阶段实现了除位置环外的所有发包函数，可以控制电机运动

收包：目前阶段实现了收包，但是还并没有完成解包的功能，对于监控台的编写还没写完

## 实现功能：

### CAN_Send.py

#### **发包底层接口函数**

`Send_Package(CAN_ID, CAN_channel, Write_Byte_Num, Index_num, data)`

| **CAN** **标识符** | **数据字节** **0** | **数据字节** **1-2** | **数据字节** **3** | **数据字节** **4-7** |
| :----------------: | :----------------: | :------------------: | :----------------: | :------------------: |
|   0x600+节点 ID    |        命令        |        索引号        |      子索引号      |         数据         |

**CAN** **标识符第** **0~6** **位：**节点 ID（0x01~0x7F），每一个 CAN 设备的节点 ID 应唯一

**数据字节** **0**：命令字节（写 1~4 字节数据的命令依次为 0x2F、0x2B、0x27、0x23，读数据命令为 0x40）

**数据字节** **1-2**：对象字典索引号，低字节在前

**数据字节** **3**：对象字典子索引号

**数据字节** **4-7**：要写入的数据，低字节在前，对于每个无效字节，可用 0x00 填充

**CAN_channel**：str类型，可以是can0，也可以是can1



#### 电机停止指令函数

`Motor_Stop_Control(CAN_ID, CAN_Channel, Stop_Mode)`

给电机发送停止运动指令，有三种停止模式，分别是正常停止、紧急停止和自由停止。正常停止就是按照自己设定的停止速度慢慢停止。紧急停止就是给一个刹车电流，然后让电机停止运动。自由停止就是断电，让电机自己慢慢的由于摩擦力停下来

- CAN_ID:是一个列表，里面是你所有需要发送电机的ID
- CAN_Channel:发送CAN包的channel
- Stop_Mode:停止方式——可以有三种参数：Normal, Emergency, Free.



#### **PWM占空比调速函数**

`PWM_Contorl(CAN_ID, CAN_channel, PWM_Duty_Cycle)`

利用PWM波占空比控制电机转动

- CAN_ID: PWM控制的电机ID
- CAN_channel:发送CAN包的channel
- PWM_Duty_Cycle: 占空比, 可以从-1000~1000

#### 速度环控制函数

`Speed_Contorl(CAN_ID, CAN_Channel, Speed)`

利用速度环控制电机转动

- CAN_ID: PWM控制的电机ID
- CAN_channel:发送CAN包的channel
- Speed: 电机转动的速度(单位/rpm)， -500~500 rpm

#### 力矩控制函数

`Torque_Contorl(CAN_ID, CAN_Channel, Current)`

利用力(固定电流)控制电机转动

- CAN_ID: PWM控制的电机ID
- CAN_channel:发送CAN包的channel
- Current: 固定电流，即加速度，实际电流为此参数*0.01

#### 位置环控制函数

`Position_Contorl(CAN_ID, CAN_Channel, Location_Type, Target_Location):`

位置环控制电机转动，暂时没用上

------------------------------------------------------------------------

待写

------------



### Monitor.py

电机控制台对象`Motor_Monitor`，包含以下属性

|             属性              |             名称              |
| :---------------------------: | :---------------------------: |
|         电机对象名字          |             name              |
|          电机CAN ID           |            CAN_ID             |
|        电机所用CAN通道        |          CAN_Channel          |
|          电机相电流           |         Phase_Current         |
|           输出 PWM            |          Output_PWM           |
|         电机换向频率          |     Commutation_frequency     |
|      电机转动位置计数值       |        Count_position         |
|     电机位置控制完成状态      |   is_PositionControl_Finish   |
|      相对转动位置计数值       |    Count_Relative_Position    |
|      电机转速(单位:RPM)       |          Motor_Speed          |
| 完成位置控制剩余时间(单位:ms) | LocationContorl_TimeRemaining |
|       母线电流(单位:A)        |            Current            |
|       电源电压(单位:V)        |            Voltage            |
|         电机堵转状态          |           is_block            |
|           故障状态            |         Fault_Status          |
|         (可随意添加)          |              ...              |

#### 获取电机属性函数

`GetParameters(self,Recv,Index)`:可以在后面继续添加所需要的参数和包，16进制要改为str类型，注意A~E要用小写

> 注意添加了新的属性之后，在`CAN_Recv.py`的`MotorState_dict`中需要增加相应的ID及其变量

### CAN_Recv.py

#### 收包函数

`Receive_Package(CAN_Channel)`

接收CAN包，这个是之前写的一个用遍历CAN_BUS总线循环来收包的一个函数，但是后续没用到

> 注意：这里的收包函数的本质是一个无限循环遍历CAN总线，等待接收CAN包，因此，这里需要单开一个线程来进行控制或者是单开一个节点

### 解包函数

`Unpack_Packages(msg) -> Receive_Package:`

解包的最底层函数，用来把字节放到正确的对应位置

### 读取数据函数

`Read_Data(CAN_ID, CAN_Channel, Index_num):`

发送读包指令

### 收包回调函数

`Solve_Message(msg: can.Message) -> None:`

由于后续使用了异步收包async库，因此每次收到msg后，会进入此回调函数，进行数据的处理和数据的解包操作。

在这里可以继续往后写需要解包的ID

### Event_Loop所在主函数

`async def main() -> None:`

收包主循环，所有的异步收包指令都在此完成
