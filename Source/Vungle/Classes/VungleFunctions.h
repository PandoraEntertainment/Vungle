
#pragma once

#include "VungleFunctions.generated.h"



UCLASS(NotBlueprintable)
class UVungleFunctions : public UObject {
	GENERATED_BODY()
	
public:

#if PLATFORM_ANDROID
	static void InitJavaFunctions();
#endif
	

	// rewarded video

	/**Check if Vungle has a rewarded Video */
	UFUNCTION(BlueprintPure, meta = (Keywords = "vungle ad advertising video"), Category = "Vungle|Rewarded Video")
	static bool VungleHasRewardedVideo();

	/**Vungle show a rewarded Video */
	UFUNCTION(BlueprintCallable, meta = (Keywords = "vungle ad advertising video"), Category = "Vungle|Rewarded Video")
	static void VungleShowRewardedVideo();

};
