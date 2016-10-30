
#include "VunglePrivatePCH.h"

void UVungleComponent::OnRegister()
{
	Super::OnRegister();
	
	UVungleComponent::DidVungleCompleteRewardedVideoDelegate.AddUObject(this, &UVungleComponent::DidVungleCompleteRewardedVideo_Handler);
	UVungleComponent::DidVungleAdPlayableChangedDelegate.AddUObject(this, &UVungleComponent::DidVungleAdPlayableChanged_Handler);

	

}

void UVungleComponent::OnUnregister()
{
	Super::OnUnregister();
	

	UVungleComponent::DidVungleCompleteRewardedVideoDelegate.RemoveAll(this);
	UVungleComponent::DidVungleAdPlayableChangedDelegate.RemoveAll(this);

	
}

UVungleComponent::FVungleDidCompleteRewardedVideoDelegate UVungleComponent::DidVungleCompleteRewardedVideoDelegate;
UVungleComponent::FVungleAdPlayableChangedDelegate UVungleComponent::DidVungleAdPlayableChangedDelegate;
