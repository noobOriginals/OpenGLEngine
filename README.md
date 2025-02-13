# **NOTE**

### To build this project, you currently need **[CMake](https://cmake.org/)**, **[GLFW](https://www.glfw.org/)** and **[GLAD](https://glad.dav1d.de/)**.  

## CMake

Go to the **[CMake website download page](https://cmake.org/download/)** and install the CMake GUI.  

## GLAD

Get the GLAD OpenGL loader for your requirements from **[GLAD's website](https://glad.dav1d.de/)**.  
Going to the website, you have to select some options to generate the right loader.  
Here are the options you should use:
1. **Language**: "C/C++".
2. **API**:
    - **gl**: "Version 3.3" or above.
    - **gles1/2/3**: "None".
3. **Specification**: "OpenGL".
4. **Profile**: "Core".
5. **Options**: tick only "Generate a loader".  

Now click "**GENERATE**" and then click on the "**glad.zip**" file to download it.  
Extract the files, and place the contents of the include folder (the "**glad**" and "**KHR**" folders) into a new folder that you name "**opengl**".  
Also place the "**glad.c**" file found in the src folder directly into your "**opengl**" folder.
In the same folder, creaet a new file named "**CMakeLists.txt**" that contains the following **CMake** script:  
```cmake
cmake_minimum_required(VERSION 3.26)

set (CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/Libs")

include_directories("${CMAKE_SOURCE_DIR}")

add_library(glad STATIC glad.c)
```
Now follow **[these steps](#building-with-the-cmake-gui)** to build your "**glad.lib**" static library.  
**Make sure to build it with the "Release" config.**  
After building, the "**build**" folder and "**CMakeLists.txt**" can be deleted, and the "**glad.lib**" file can be found in the "**Libs**" folder that was created by CMake when building the library.  
After placing the "**glad.lib**" file directly in your "**opengl**" folder, you can also delete the "**Libs**" folder.

## GLFW

Get the GLFW library from **[their website](https://www.glfw.org/)** or by **[cloning it on github](https://github.com/glfw/glfw)**.  
Then follow **[these steps](#building-with-the-cmake-gui)** to build the GLFW library with CMake. 
**Make sure to build it with the "Release" config.**     
In the build directory provided to CMake, after you build the files, you should have a folder named "**src**".
Navigate to "**src/Release**", and copy the "**glfw3.lib**" to your "**opengl**" folder.  
Then go back to your GLFW source folder and copy the contents of the "**include**" folder (the "**GLFW**" folder) to your "**opengl**" folder.

## Next

After completing **[theese three steps](#cmake)**, you should have a folder named "**opengl**" that has theese files: (this is if you installed all components of the VulkanSDK, and there's also **[Assimp](#assimp)**, **[stb_image](#stb_image)** and **[glm](#glm)** here as I have them already installed and placed in this folder. But don't worry about **[these](#aditional-libraries)** as I'll not be using them very soon) 
```bash
$ ls
KHR  assimp  assimp-vc143-mt.lib  glad  glad.lib  glfw  glfw3.lib  glm  stb_image 
```
You should be interested in having these specific files:  
```
./GLFW/
./glad/
./KHR/
./glm/
./glad.lib
./glfw3.lib
```
## OPENGL_PATH Env Variable

Now you have to create an **environment variable** with the name "**OPENGL_PATH**" and the value equal to the path to your "**opengl**" folder that you just created.    

On Windows, you edit the system env variables in the menu which you can search for in your taskbar (search for "**environment variable**").  
On Linux or Mac, you add that to your env paths in the bash or zsh config (Linux), or by command line, with  
```bash
$ OPENGL_PATH="path/to/opengl"
$ export $OPENGL_PATH
```

## Building with the CMake GUI
Open the CMake GUI, then select the source code directory.  
Now select a build directory (you have to create it yorself first).  
Now click "**Configure**", and choose your generator (I recommend **Ninja** for Mac and Linux, and **Visual Studio** for Windows). Then click "**Configure**" again to save the settings.  
Then click "**Generate**", to generate the build files.
Go to your build folder, and:  
- If you're on windows and you're using VS, open the generated "**.sln**" file and build the solution inside VS.
- If you're using Ninja, open the build folder in a terminal tab and run the `ninja` command in that folder.  

You can also use cmake to build you files, like this:  
```bash
$ cmake --build <build folder> --confing <configuration (usually 'Debug' or 'Release')> --target <if generator is Ninja: 'all'; if generator is VS: 'ALL_BUILD'>  
```

And CMake will also tell you which is the binary output directory. For example:  
```bash
$ cmake --build build --config Debug --target ALL_BUILD
MSBuild version 17.12.12+1cce77968 for .NET Framework

    Checking File Globs
    Copying resources into birnay output folder
    Engine-test.vcxproj -> .\bin\Debug\Engine-test.exe
```
  
Now you should see the binary files that were generated by building in the binary output folder.  

## Building the project
Follow **[these steps](#building-with-the-cmake-gui)** again, with the project folder as the source, and a build folder created inside the project folder as build.  
Then you can run the generated binary `/bin/<config>/Engine-test.exe` to see the result of this project.  

## Aditional Libraries

## Assimp

Clone the **[GitHub Repo](https://github.com/assimp/assimp)** and follow **[these steps](#building-with-the-cmake-gui)** to build the library.  
**Make sure to build it with the "Release" config.**  
Then: place the "**assimp-vc143-mtd.lib**" found in "**./lib/Release**" in your "**opengl**" folder.  
Then: place the contents of the "**./include**" folder in your "**opengl**" folder.

## stb_image

Download the raw file **[stb_image.h](https://github.com/nothings/stb/blob/master/stb_image.h)** and place it in you "**opengl**" folder in a folder named "**stb_image**".  
**Whenever you use it, include it like this:**
```cpp
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image/stb_image.h>
```

## GLM

Go to the official **[GitHub Page](https://github.com/g-truc/glm)** and download the code as zip or clone the repository.  
Then copy the "**glm**" folder directly into your "**opengl**" folder.