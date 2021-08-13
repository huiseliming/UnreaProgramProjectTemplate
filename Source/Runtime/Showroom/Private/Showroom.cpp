// Copyright Epic Games, Inc. All Rights Reserved.

#include "Showroom.h"
#include "Modules/ModuleManager.h"

#define LOCTEXT_NAMESPACE "FShowroomModule"

void FShowroomModule::StartupModule()
{
	UE_LOG(LogShowroom, Log, TEXT("ShowroomModule Loaded"));
}

void FShowroomModule::ShutdownModule()
{
	UE_LOG(LogShowroom, Log, TEXT("ShowroomModule Unload"));
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_PRIMARY_GAME_MODULE( FShowroomModule, Showroom, "Showroom" );
DEFINE_LOG_CATEGORY(LogShowroom);
