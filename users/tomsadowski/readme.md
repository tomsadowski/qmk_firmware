
## Release Gate

In the last section you may have noticed combos for Left Release Gate and Right Release Gate. This feature is used when you need to press multiple keys at the same time, but those keys are located on different layers from each other. While the Release Gate is held, the keyboard will not send key-release signals to the computer. Once you release a key without the Release Gate held, all previously withheld release signals will be sent. If you don't think you understand, try playing with the feature. It's pretty simple and you'll probably never need it.  

![release_gate_state_machine](https://github.com/tomsadowski/qmk_firmware/blob/master/users/tomsadowski/doc/release_gate_state_machine.jpg)  
