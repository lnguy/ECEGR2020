##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=Lab_4
ConfigurationName      :=Debug
WorkspaceConfiguration := $(ConfigurationName)
WorkspacePath          :=C:/Users/Ly/ECEGR2020
ProjectPath            :=C:/Users/Ly/ECEGR2020/Lab_4
IntermediateDirectory  :=../build-$(ConfigurationName)/Lab_4
OutDir                 :=../build-$(ConfigurationName)/Lab_4
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Ly
Date                   :=28/02/2022
CodeLitePath           :="C:/Program Files/CodeLite"
LinkerName             :=C:/Tools/mingw64/bin/g++.exe
SharedObjectLinkerName :=C:/Tools/mingw64/bin/g++.exe -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=..\build-$(ConfigurationName)\bin\$(ProjectName).exe
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :=$(IntermediateDirectory)/ObjectsList.txt
PCHCompileFlags        :=
RcCmpOptions           := 
RcCompilerName         :=C:/Tools/mingw64/bin/windres.exe
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := C:/Tools/mingw64/bin/ar.exe rcu
CXX      := C:/Tools/mingw64/bin/g++.exe
CC       := C:/Tools/mingw64/bin/gcc.exe
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := C:/Tools/mingw64/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files\CodeLite
Objects0=../build-$(ConfigurationName)/Lab_4/QueueArrayOriginal.c$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: MakeIntermediateDirs $(OutputFile)

$(OutputFile): ../build-$(ConfigurationName)/Lab_4/.d $(Objects) 
	@if not exist "..\build-$(ConfigurationName)\Lab_4" mkdir "..\build-$(ConfigurationName)\Lab_4"
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@if not exist "..\build-$(ConfigurationName)\Lab_4" mkdir "..\build-$(ConfigurationName)\Lab_4"
	@if not exist ""..\build-$(ConfigurationName)\bin"" mkdir ""..\build-$(ConfigurationName)\bin""

../build-$(ConfigurationName)/Lab_4/.d:
	@if not exist "..\build-$(ConfigurationName)\Lab_4" mkdir "..\build-$(ConfigurationName)\Lab_4"

PreBuild:


##
## Objects
##
../build-$(ConfigurationName)/Lab_4/QueueArrayOriginal.c$(ObjectSuffix): QueueArrayOriginal.c ../build-$(ConfigurationName)/Lab_4/QueueArrayOriginal.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Users/Ly/ECEGR2020/Lab_4/QueueArrayOriginal.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/QueueArrayOriginal.c$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/Lab_4/QueueArrayOriginal.c$(DependSuffix): QueueArrayOriginal.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/Lab_4/QueueArrayOriginal.c$(ObjectSuffix) -MF../build-$(ConfigurationName)/Lab_4/QueueArrayOriginal.c$(DependSuffix) -MM QueueArrayOriginal.c

../build-$(ConfigurationName)/Lab_4/QueueArrayOriginal.c$(PreprocessSuffix): QueueArrayOriginal.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/Lab_4/QueueArrayOriginal.c$(PreprocessSuffix) QueueArrayOriginal.c


-include ../build-$(ConfigurationName)/Lab_4//*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r $(IntermediateDirectory)


