// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

// #ifdef UE_BUILD_DEBUG
// #define SHOWROOM_LOG(Verbosity, Format, ...) UE_LOG(LogShowroom, Verbosity, TEXT("[%s] ") Format, *UE__FUNC__LINE__, ##__VA_ARGS__ )
// #elif
#define SHOWROOM_LOG(Verbosity, Format, ...) UE_LOG(LogShowroom, Verbosity, Format, ##__VA_ARGS__ )
// #endif

class FShowroomModule : public FDefaultGameModuleImpl
{
public:
	
	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
	virtual bool IsGameModule() const override { return true; }
	
	static FShowroomModule& Get()
	{
		return FModuleManager::LoadModuleChecked<FShowroomModule>("Showroom");
	}

	static bool IsAvailable()
	{
		return FModuleManager::Get().IsModuleLoaded("Showroom");
	}
};

DECLARE_LOG_CATEGORY_EXTERN(LogShowroom, Log, All);
