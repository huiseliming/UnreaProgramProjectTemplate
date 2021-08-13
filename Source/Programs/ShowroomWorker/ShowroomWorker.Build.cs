// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using Tools.DotNETCommon;
using System.Collections.Generic;

using System.IO;
public class ShowroomWorker: ModuleRules
{
	public ShowroomWorker(ReadOnlyTargetRules Target) : base(Target)
	{
	        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
            PublicIncludePaths.Add(Path.Combine(EngineDirectory, "Source/Runtime/Launch/Public"));
            PrivateIncludePaths.Add(Path.Combine(EngineDirectory, "Source/Runtime/Launch/Private"));
    
            PrivateDependencyModuleNames.Add("Core");
        	PrivateDependencyModuleNames.Add("Projects");

            DirectoryReference EngineSourceProgramsDirectory = new DirectoryReference(Path.Combine(EngineDirectory, "Source", "Programs"));
            FileReference CurrentModuleDirectory = new FileReference(ModuleDirectory);
            if (!CurrentModuleDirectory.IsUnderDirectory(EngineSourceProgramsDirectory))
            {
                string ProjectName = Target.ProjectFile.GetFileNameWithoutExtension();
                Log.TraceInformation("ShowroomWorkerProgram is outside engine source directory, parent project is: {0}", ProjectName);
    
                PrivateDefinitions.Add(string.Format("ParentProjectName=TEXT(\"{0}\")", ProjectName));
            }
	}
}
