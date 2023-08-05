workspace "FrameX"
	architecture "x64"
	
	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "FrameX"
	location "FrameX"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "FrameX/src/fxpch.h"
	pchsource "FrameX/src/fxpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"FX_PLATFORM_WINDOWS",
			";FX_BUILD_DLL;"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "FX_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "FX_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "FX_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"FrameX/vendor/spdlog/include",
		"FrameX/src"
	}

	links
	{
		"FrameX"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"FX_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "FX_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "FX_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "FX_DIST"
		optimize "On"