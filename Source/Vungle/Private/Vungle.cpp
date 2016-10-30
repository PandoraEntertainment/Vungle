
#include "VunglePrivatePCH.h"
#include "VungleSettings.h"
#include "ISettingsModule.h"

DEFINE_LOG_CATEGORY(LogVungle);

#define LOCTEXT_NAMESPACE "Vungle"

class FVungle : public IVungle
{
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};

IMPLEMENT_MODULE( FVungle, Vungle )

void FVungle::StartupModule()
{
	// register settings
	if (ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings"))
	{
		SettingsModule->RegisterSettings("Project", "Plugins", "Vungle",
										 LOCTEXT("RuntimeSettingsName", "Vungle"),
										 LOCTEXT("RuntimeSettingsDescription", "Configure the Vungle plugin"),
										 GetMutableDefault<UVungleSettings>()
										 );
	}

#if PLATFORM_ANDROID
	UVungleFunctions::InitJavaFunctions();
#endif
}


void FVungle::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

#undef LOCTEXT_NAMESPACE
