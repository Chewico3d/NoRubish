workspace "NoRubish"
	architecture "x64"

	configurations{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "NoRubish" 
	location "NoRubish"
	kind "SharedLib"
	language "c++"

	targetdir ("bin/" ..outputdir.. "%{prj.name}")
	objdir ("bin-int/" ..outputdir.. "%{prj.name}")

	files{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs{
		"%{prj.name}/submodule/logspd/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines{
			"NR_PLATFORM_WINDOWS",
			"NR_BUILD_DLL"
		}

		postbuildcommands{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "SandBox")
		}

	filter "configurations:Debug"
		defines "NR_DEBUG"
		symbols "On"
		
	filter "configurations:Release"
		defines "NR_Release"
		optimize "On"
		
	filter "configurations:Dist"
		defines "NR_Dist"
		optimize "On"

project "SandBox"
	location "SandBox"
	kind "ConsoleApp"

	language "C++"

	targetdir ("bin/" ..outputdir.. "%{prj.name}")
	objdir ("bin-int/" ..outputdir.. "%{prj.name}")

	files{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs{
		"%{prj.name}/submodule/logspd/include",
		"NoRubish/src"
	}

	links{
		"NoRubish"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines{
			"NR_PLATFORM_WINDOWS",
		}


	filter "configurations:Debug"
		defines "NR_DEBUG"
		symbols "On"
		
	filter "configurations:Release"
		defines "NR_Release"
		optimize "On"
		
	filter "configurations:Dist"
		defines "NR_Dist"
		optimize "On"