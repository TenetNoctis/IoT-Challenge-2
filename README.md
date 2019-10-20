# IoT Challenge 2

Student Name: Abdulla Nibah
Student ID: S1800980

Introduction
============
This will demonstrate communication between 2 micro:bit with the use of 2 crocodile clips, one connected to pin 0 and one connected to ground. In this practical, morse code is sent from one micro:bit and translated on the other.

Compilation
===========
This program is compiled using os.mbed.com online compiler

Startup procedure
=================
1.	Connect P0 pin of both devices using a crocodile clip.
2.  Connect GND pin of both devices using a crocodile clip.
3.	Connect usb cables to both devices.
4.	Compile the sender program and copy the hex file to the micro:bit that will be the sender
5.  Compile the receiver program and copy the hex file to the micro:bit that will be the receiver
6.	On the sender, you can send messages using the A button
7.	After sending the message, press the A button on the receiver to translate

Send morse code
===============
Use a short click to send dot(.) to the other device. Press and hold button A to send dash(-).


Decrypt morse code on receiving end
===================================
Press A on the device to automatically translate

Limitations
==================
If you click too fast on the sender, the receiver is unable to process it fast enough so after each click, wait half a second before clicking again. Otherwise it will result in the receiver not giving the correct translation

