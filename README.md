# safety_device

This safety device can be used for any purpose. The objective is to send SMS using Python Twilio API if there is any unsafe condition. Here an implementation is presented where battery temperature is measured using Arduino, Arduino is connected with python and Ardunio sends signals to python code. If battery temperature is within desired range, it sends byte "1", but if battery temperature is out of limit, Arduino sends byte "0" to python code. Python code reads the bytes send by Arduino, and if it gets byte "0", python code will send SMS to the assigned recipient. It sends SMS after every two minutes until program is stopped manually. 

I used this small set up during my PhD for my experiments, which helped me a lot to manage experiments which have fire hazards. This set up is more general and can be used in differnt ways. 

# Core idea
* Read the target variable using some micro controller
* Communicate between micro controller and python codde
* Send alert to python code if the target variable out of range
* Python code will send alert using Twilio SMS API