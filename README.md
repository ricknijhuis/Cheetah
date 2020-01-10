# Cheetah
2D game engine

Welcome to the Cheetah engine, this is manly personal hobby project in order to learn about game engine development, graphics programming and c++.

Currently the engine is at a very early stage but is able to be used for creating simple 2d games without audio. 
A sample game project is included to provide insight on possible ways to achieve this, this sample project is also used as test application for testing new features, improve API's and profiling.

Having remarks, comments or ideas? please let me know by filing in an issue!

## Contents
1. [Installation](#1-installation)                                                                                                       
2. [Available features](#2-available-features)
3. [Future features](#3-future-featuresin-order-of-importance)
4. [Basic setup](#4-basic-setup) 
5. [API](#5-api)\
    5.1 [Namespaces](#namespaces)\
        5.1.1. [Namespace cheetah](#namespace-cheetah)\                                                                 
            5.1.1.1. [Classes](#classes)\
            5.1.1.2. [Structs](#structs)\
            5.1.1.3. [Functions](#functions)\
            5.1.1.4. [Macros](#macros)

## 1. Installation
1. clone this repository 
2. open folder in your IDE and generate the CMAKE cache (in Visual Studio select file->open->cmake and open cmakelists.txt file)
3. set Game.exe as startup project
4. run project

if any problems occur,
1. regenerate cache(in Visual Studio right click cmakelists.txt file and click generate cache)
2. rebuild solution.

## 2. Available features
- 2d render engine using opengl
- mouse and keyboard handling
- window creation.

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

## 4. Basic Setup
this setup describes the basic steps needed in order to make your game with the engine, It presumes the installation was succesfull and you are now able to start coding.

## 5. API
All the exposed methods, classes and structs are described here.

## Namespaces
- cheetah
- input
- input -> keyCodes
- input -> mouseBtnCodes

## Namespace cheetah
master namespace contains all namespaces, classes, structs, methods and variables exposed to user.

#### classes
- Application
- Window
- Input
- Time
- Event
- EventDispatcher
- EventTypes
- CharInputEvent
- WindowCloseEvent
- WindowResizeEvent
- UpdateLayer
- UpdateLayerQueue
- ResourceLoader<T>
- Mat4x4<T>
- Quaternion
- Vector3<T>
- Vector4<T>
- Renderer2D
- OrthoGraphicCamera
- Texture
- Shader

#### structs
- TextureParams
- OrthoGraphicCameraParams
- DrawQuadParams
- DrawTexturedQuadParams

#### functions
- createApplication

#### macros
- CH_PLATFORM_WINDOWS
- CH_BUILD_DLL
- CH_API
- CH_ASSERT_ENABLED
- ASSERT
- STATIC_ASSERT
 
