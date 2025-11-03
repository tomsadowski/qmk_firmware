## pearbear qmk firmware project directory

put the contents of this directory in qmk_firmware/keyboards/pearbear

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
