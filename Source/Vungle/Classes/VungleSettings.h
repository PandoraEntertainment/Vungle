
#pragma once

#include "VungleSettings.generated.h"

UCLASS(config = Engine, defaultconfig)
class UVungleSettings : public UObject
{
	GENERATED_BODY()
	
public:
	UVungleSettings(const FObjectInitializer& ObjectInitializer);
	
	// SDK Ids

	UPROPERTY(Config, EditAnywhere, Category = App, meta = (DisplayName = "App Id"))
	FString AppId;

	UPROPERTY(Config, EditAnywhere, Category = App, meta = (DisplayName = "Zone Id"))
	FString ZoneId;

};
