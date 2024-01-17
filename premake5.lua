-- premake5.lua
workspace "Application"
   architecture "x64"
   configurations { "Debug", "Release", "Dist" }
   startproject "Application"

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

include "External.lua"
include "Application"