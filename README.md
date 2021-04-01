# TextEditor
A test example for WndDesign and BlockStore.



Open with Visual Studio 2019.

Below are all configurations modified from default:

	General
		Output Directory: $(SolutionDir)build\$(platform)\$(Configuration)\
		Intermidiate Directory: $(SolutionDir)temp\$(ProjectName)\$(Platform)\$(Configuration)\
		C++ Language Standard: ISO C++17 Standard
	
	C/C++
		General
			Additional Include Directories: (use your own directory)
				E:\source\WndDesign\code; 
				E:\source\BlockStore\code;
				%(AdditionalIncludeDirectories)
	
	Linker
		General
			Additional Libaray Directories: $(OutputPath)


And put these library files in *Additional Libaray Directories*, or $(OutputPath):

```
WndDesign.lib, WndDesignCore.lib, WndDesignCore.dll,
StaticStore.lib, StaticStore.dll	
```



Now you can build and run the program.