workspace "Turbo"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

	outputdir = "%{cfg.buildcfg}-%{cfg.system}-${cfg.architecture}"

	-- Includes directories relative to the solution directory
	IncludeDir = {}
	IncludeDir["GLFW"] = "Turbo/vendor/GLFW/include"

	include "Turbo/vendor/GLFW"

project "Turbo"
	location "Turbo"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "tbpch.h"
	pchsource "Turbo/src/tbpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}"
	}

	links{
		"GLFW",
		"opengl32.lib"
	}
	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"TB_PLATFORM_WINDOWS",
			"TB_BUILD_DLL"
		}


	postbuildcommands
	{
		("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
	}

	filter "configurations:Debug"
		defines "TB_DEBUG"
		optimize "On"

	filter "configurations:Release"
		defines "TB_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "TB_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir.. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Turbo/vendor/spdlog/include",
		"Turbo/src"
	}
	
	links
	{
		"Turbo"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

	defines
		{
			"TB_PLATFORM_WINDOWS",
		}


	filter "configurations:Debug"
		defines "TB_DEBUG"
		optimize "On"

	filter "configurations:Release"
		defines "TB_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "TB_DIST"
		optimize "On"