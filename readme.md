## pearbear qmk firmware project directory

This is a fork of the qmk_firmware repo for hosting the pearbear keyboard. All other keyboards have been removed from this fork. If you would like to keep your qmk_firmware repo, simply add the keyboards/pearbear to your keyboards directory.

If you have a pearbear and need to flash it, start by referring to the official instructions for installing the qmk framework from the QMK website. Once QMK is installed, continue with the instructions below.

#### set your config as follows:
- $: qmk config compile.keyboard=pearbear
- $: qmk config compile.keymap=tomsadowski
- $: qmk config flash.keyboard=pearbear
- $: qmk config flash.keymap=tomsadowski

#### compile:   
- $: qmk compile

#### flash left: 
- plug USB into left half.
- $: qmk flash -bl uf2-split-left
- on the left half, press and hold the Boot Button on the KeyBoar circuit for 6 seconds while tapping the Reset Button 3 times. wait for indication in terminal that flashing is in progress before letting go.


#### flash right: 
- plug USB into right half.
- $: qmk flash -bl uf2-split-right
- on the right half, press and hold the Boot Button on the KeyBoar circuit for 6 seconds while tapping the Reset Button 3 times. wait for indication in terminal that flashing is in progress before letting go.
