  // Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.


#include "ShowroomWorker.h"

#include "RequiredProgramMainCPPInclude.h"

#include "Misc/Paths.h"

DEFINE_LOG_CATEGORY_STATIC(LogShowroomWorker, Log, All);

IMPLEMENT_APPLICATION(BlankProgram, "MyBlankProgram");

INT32_MAIN_INT32_ARGC_TCHAR_ARGV()
{
#if defined(ParentProjectName)
	const FString ProjectDir = FString::Printf(TEXT("../../../%s/Programs/%s/"), ParentProjectName, FApp::GetProjectName());
	FPlatformMisc::SetOverrideProjectDir(ProjectDir);
#endif

	GEngineLoop.PreInit(ArgC, ArgV);
	
	check(GConfig && GConfig->IsReadyForUse());
#if PLATFORM_WINDOWS
	// hide the console window, if desired
	if (FParse::Param(FCommandLine::Get(), TEXT("HIDDEN")))
	{
		ShowWindow(GetConsoleWindow(), SW_HIDE);
	}
#endif
	
	double LastTime = FPlatformTime::Seconds();
	while (!IsEngineExitRequested())
	{
		FPlatformProcess::Sleep(1.0f);
		double Now = FPlatformTime::Seconds();
		float DeltaSeconds = LastTime - Now;
		GLog->FlushThreadedLogs();
		LastTime = Now;
	}
	
	return 0;
}