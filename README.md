# Cheetah
2D game engine

Welcome to the Cheetah engine, this is manly personal hobby project in order to learn about game engine development, graphics programming and c++.

Currently the engine is at a very early stage but is able to be used for creating simple 2d games without audio. 
A sample game project is included to provide insight on possible ways to achieve this, this sample project is also used as test application for testing new features, improve API's and profiling.

Having remarks, comments or ideas? please let me know by filing in an issue!

## 1. Installation
1. clone this repository 
2. open folder in your IDE and generate the CMAKE cache (in Visual Studio select file->open->cmake and open cmakelists.txt file)
3. set Game.exe as startup project
4. run project

if any problems occur,
1. regenerate cache(in Visual Studio right click cmakelists.txt file and click generate cache)
2. rebuild solution

## 2. Available features
- 2d render engine using opengl
- mouse and keyboard handling
- window creation

## 3. Future features(in order of importance)
- 2d batch rendering / performance update
- sprite animations API
- particle API
- UI API
- audio
- development UI
- linux support
- vulkan support
- directX support
