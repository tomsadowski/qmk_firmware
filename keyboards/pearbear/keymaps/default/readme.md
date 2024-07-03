# noonyworld 

There are 3 layers: Alpha Layer, Mouse Layer, and Number Layer. From any of those layers, the other two layers can be momentarily accessed by holding either of the space buttons. The visuals below should clarify this.   

---  

![alpha_layer_graph](doc/alpha_graph.jpg)  

---  

![mouse_layer_graph](doc/mouse_graph.jpg)  

Note: Since holding down the left-click button is a common use case, you must first access the Alpha Layer with the left thumb before accessing the Number Layer with the right thumb.  

---  

![number_layer_graph](doc/number_graph.jpg)  

## Combos  

The caps-lock combo only turns caps-lock on. Caps-lock is turned off when a modifier or mode-switching combo is pressed.   

![combos](doc/combos.jpg)  

## Release Gate

In the last section you may have noticed combos for Left Release Gate and Right Release Gate. This feature is used when you need to press multiple keys at the same time, but those keys are located on different layers from each other. While the Release Gate is held, the keyboard will not send key-release signals to the computer. Once you release a key without the Release Gate held, all previously withheld release signals will be sent. If you don't think you understand, try playing with the feature. It's pretty simple and you'll probably never need it. Also if you like confusing diagrams, one is provided here for your viewing ecstacy.    

![release_gate_state_machine](doc/release_gate_state_machine.jpg)  

## Bonus: Lefty Layers   

![lefty_layers](doc/lefty_layers.jpg)   

## Bonus: Game Layers   

![game_layers](doc/game_layers.jpg)  
