
#pragma once

#include "VungleFunctions.h"
#include "VungleComponent.generated.h"

UCLASS(ClassGroup=Advertising, HideCategories=(Activation, "Components|Activation", Collision), meta=(BlueprintSpawnableComponent))
class UVungleComponent : public UActorComponent
{
	GENERATED_BODY()
	
public:
	
	DECLARE_MULTICAST_DELEGATE_OneParam(FVungleAdPlayableChangedDelegate, bool);

	static FVungleAdPlayableChangedDelegate DidVungleAdPlayableChangedDelegate;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FVungleAdPlayableChangedDynDelegate, bool, isAdPlayable);

	UPROPERTY(BlueprintAssignable)
	FVungleAdPlayableChangedDynDelegate DidVungleAdPlayableChanged;

	DECLARE_MULTICAST_DELEGATE_OneParam(FVungleDidCompleteRewardedVideoDelegate, bool);

	static FVungleDidCompleteRewardedVideoDelegate DidVungleCompleteRewardedVideoDelegate;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FVungleDidCompleteRewardedVideoDynDelegate, bool, wasSuccessfulView);

	UPROPERTY(BlueprintAssignable)
	FVungleDidCompleteRewardedVideoDynDelegate DidVungleCompleteRewardedVideo;
	

	
	void OnRegister() override;
	void OnUnregister() override;
	
private:	


	void DidVungleCompleteRewardedVideo_Handler(bool wasSuccessfulView) { DidVungleCompleteRewardedVideo.Broadcast(wasSuccessfulView); }

	void DidVungleAdPlayableChanged_Handler(bool isAdPlayable) { DidVungleAdPlayableChanged.Broadcast(isAdPlayable); }



	
};
