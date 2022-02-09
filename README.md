# SNAKE (unfinished)
Made with C++ with SDL library (In a Linux environnement)

# SDL2 library and gcc

Install SDL2 :
```bash
sudo apt install libsdl2-dev
```

Install G++ compiler and Make :
```bash
sudo apt install g++ make 
```

# Launching the snake

How to launch :

Use G++ compiler to make our game run : (Make sure to be in the right folder)
```
g++ Main.cpp snake.cpp MainWindowsSDL.cpp fruit.cpp playground.cpp  -l SDL2 -o snake
```
The controls :

```Up Key```: The snake will go up
```Left Key```: The snake will go left
```Right Key```: The snake will go right
```Down Key```: The snake will go down
