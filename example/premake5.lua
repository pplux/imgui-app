workspace "imgui-app"
   configurations { "Debug", "Release" }


function config(name, file)
   project(name)
      kind "ConsoleApp"
      language "c++"
      targetdir "bin/%{cfg.buildcfg}"
   
      files { file, "../imgui_app.cpp" }
      defines {"SOKOL_GLCORE33"}
   
      filter "configurations:Debug"
         defines { "_DEBUG" }
         symbols "On"
   
      filter "configurations:Release"
         optimize "On"
   
      configuration "linux"
         links {"GL","dl", "X11", "Xi", "Xcursor", "pthread"}
end


config("test", "test.cpp")
config("test_advanced", "test_advanced.cpp")
