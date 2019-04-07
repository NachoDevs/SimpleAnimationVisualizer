# SimpleAnimationVisualizer

## Description
This is a simple tool for visualizing my animations from sprite sheets. It will work mainly for 16x16 up to 64x64 sprites since the render distance won't change (I didn't really needed that functionality)

## Technology
It is coded in c++.
SDL2 for time and window management.
SDL_image for the sprite rendering.

## Can I use it?
Sure, do whatever you desire.

## Usage Example
\> Create a spritesheet and copy it to the Animations folder (Release/Animations)

\> Run the application

\> Enter desired framerate (default 60): 
  60
  
\> Enter the directory where the file is stored in inside the 'Animations' folder (this file should only contain this animation, and the path should not contain spaces):
  sp_player_run.png
  
\> Enter the size of the sprite (default: 32):
  64
  
\> Enter the amount of frames in the animation:
  5
  
\> Enter the play speed(default: 400):
  300
  
\> Oops I forgot an eye in the third frame!
