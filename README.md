# Code vault for Tensile Testing Machine 
This repository contains all the Arduino (C++) code used in the calibration and running processes of the Tensile Testing Machine. 

`\calibrate` contains the code to calibrate the load cell 

`\motor` contains the code to run the step motor 

`\main` contains the code to read load cell results while running the machine

On GNU-Linux system, the entire programming process must be done in priviledged mode (root mode). To achieve this, either operate all commands in `su` or, prepend `sudo` to all commands.
