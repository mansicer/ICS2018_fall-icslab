# ICS2018_fall-icslab
该项目的所有内容仅供参考，请遵守南京大学以及ICS课程的学术诚信要求，一切抄袭行为后果自负！

The lab assignments of Introduction of Computer System course of NJU.

Please work and run on a Linux system.


## Menu 目录

1. lab1 datalab 数据表示与操作
2. lab2 binary bomb 二进制炸弹
3. lab3 buffer overflow attacks 缓冲区溢出攻击
4. lab4 linklab ELF与链接



## Environment 运行环境

- OS Environment: Linux (Debian 9 I386 Architecture)
- Language: C
- Necessary Softwares: 
- - GCC (for all labs)
  - CMake (for lab 1)
  - Hexedit (or any other software which can change binary files)
  - GDB (for testing and debugging)

- Others: A Cool Brain

 

## Contents 内容

### LAB1 DATALAB 数据表示与操作

This lab can make you get better understand about the coding and operations of integers and floating-point numbers about your computer. During the lab, you need to finish a series of problems -- using operators with limited types and number to implement the described function.

本实验有助于更好地熟悉和掌握计算机中整数和浮点数的二进制编码表示及其操作。实验中，你需要完成
一系列编程“难题”——使用有限类型和数量的运算操作实现一组给定功能的函数。

Visit ICS2018_fall-icslab/lab1 for more detail.

访问ICS2018_fall-icslab/lab1以获取详细实验信息。



### LAB2 BINARY BOMB 二进制炸弹

During this lab, you are supposed to defuse a binary bomb with the knowledge got from our course, which can make you understand the knowledge about machine representation of programs, assembly language, debugger and reverse engineering. A binary bomb (We call it bomb above.) is a Linux executable program including 7 phases and a hidden phase. 

Every phase when the bomb runs need you to input a special string and the bomb get defused when your input is expected. Otherwise, the bomb booms with a hint output "BOOM!!!" and it turns to the next phase waiting for your input. The target of this lab is to defuse bombs as many as you can.  

在本实验中，你需要使用课程所学知识拆除一个二进制炸弹，从而加强对程序的机器级表示、汇编语言、调试器和逆向工程等方面知识的理解和掌握。一个二进制炸弹（下文将简称为炸弹）是一个Linux可执行程序，包含了7个阶段（或层次、关卡）以及1个隐藏阶段。
炸弹运行的每个阶段要求你输入一个特定字符串，你的输入符合程序预期的输入，该阶段的炸弹就被拆除引信即解除了，否则炸弹“爆炸”打印输出“BOOM!!!”并转到下一阶段等待你的输入。实验的目标是拆除尽可能多阶段的炸弹。

Visit ICS2018_fall-icslab/lab2 for more detail.

访问ICS2018_fall-icslab/lab2以获取详细实验信息。



### LAB3 BUFFER OVERFLOW ATTACKS 缓冲区溢出攻击

The target of this lab is to deepen your understanding about the function calling and the stack structure about IA-32 System. The main content of this lab is to implement a series of buffer overflow attacks to the executable program "buffbomb", which means you need to try to make buffer overflow attacks to change the memory map of this program, such as inserting a given string to a position where it shouldn't appear originally.

During the lab, you need to make 5 attacks with increasingly difficulties to the executable program "bufbomb". The 5 difficulties are named smoke (level 0), fizz (level 1), bang (level 2), boom (level 3) and kaboom(level 4). The level Smoke is easier while the level Kaboom is the most difficult.

本实验的目的在于加深对IA-32函数调用规则和栈结构的具体理解。实验的主要内容是对一个可执行程序 “bufbomb” 实施一系列缓冲区溢出攻击，也就是设法通过造成缓冲区溢出来改变该可执行程序的运行内存映像，例如将给定的字节序列插入到其本不应出现的内存位置。
实验中你需要对目标可执行程序bufbomb分别完成5个难度递增的缓冲区溢出攻击。5个难度级分别命名为smoke (level 0)、fizz (level 1)、bang (level 2)、boom (level 3)和kaboom (level 4)，其中smoke级最简单而kaboom级最困难。

Visit ICS2018_fall-icslab/lab3 for more detail.

访问ICS2018_fall-icslab/lab3以获取详细实验信息。



### LAB4 LINKLAB ELF与链接

The target of this lab is to deepen your understanding about the format of ELF file and the linking process during the generation and running of a program. The main content of this lab is to change a file composed by some C modules step by step to make it satisfy the given behavior requirements. You need to implement the change of corresponding binary relocatable file (.o file) specially including the change of data content, instructions, relocation records and so on.

本实验的目的在于加深对ELF文件的基本格式组成和程序生成与运行过程中链接的基本概念的理解。实验的
主要内容是逐步修改一个由多个C模块组成的程序（称为“linkbomb”），使其在运行时满足实验指定的行为
要求。你需要完成对二进制可重定位目标文件（.o文件）内容的特定修改，包括数据内容、机器指令、重定
位记录等。

Visit ICS2018_fall-icslab/lab4 for more detail.

访问ICS2018_fall-icslab/lab4以获取详细实验信息。
