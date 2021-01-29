# imgui-app

Imgui-app is an amalgamation of two amazing projects [Dear Imgui](https://github.com/ocornut/imgui) and [Sokol libraries](https://github.com/floooh/sokol) into **two** files to make it very easy to start working with imgui. It might be useful when you need to do some UI quickly for a project but do not want to care that much how to get imgui up and running (imgui compilation, backend rendering, window handling, ...). 

![test.png](https://github.com/pplux/imgui-app/blob/main/example/test.png?raw=true)

# Howto

To start using imgui-app you need to add these two files to your project:
  * [imgui.h](https://github.com/pplux/imgui-app/blob/main/imgui.h)
  * [imgui_app.cpp](https://github.com/pplux/imgui-app/blob/main/imgui_app.cpp)
     
Once you are ready to display the UI, just call `imgui_app`, see the [example](https://github.com/pplux/imgui-app/blob/main/example/test.cpp). 

Finally, make sure to select the proper sokol render backend, by compiling your project with `-DSOKOL_GLCORE33` or any of the [available backends](https://github.com/floooh/sokol/blob/master/sokol_gfx.h#L18-L24).


# Notes:
  * Try not to modify the files `imgui.h` and `imgui_app.cpp` they are generated from the original sources by the `Makefile` of this project
  * We chose to use imgui.h for the headers to make the project compatible with other exisiting imgui code. 
  * imgui_app.cpp is **BIG**, it is the result of including in one file imgui, sokol, and all the dependencies. Try not to compile every time on your project :)
  * The *amalgamation* idea comes from [Sqlite amalgamation](https://www.sqlite.org/amalgamation.html)
         
