workspace "imgui-app"
   configurations { "Debug", "Release" }

project "test"
   kind "ConsoleApp"
   language "c++"
   targetdir "bin/%{cfg.buildcfg}"

   files { "test.cpp", "../imgui_app.cpp" }
   defines {"SOKOL_GLCORE33"}

   filter "configurations:Debug"
      defines { "_DEBUG" }
      symbols "On"

   filter "configurations:Release"
      optimize "On"

   configuration "linux"
      links {"GL","dl", "X11", "Xi", "Xcursor", "pthread"}
