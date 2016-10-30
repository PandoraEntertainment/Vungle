

#include "VunglePrivatePCH.h"

#if PLATFORM_ANDROID

#include "Android/AndroidJNI.h"
#include "AndroidApplication.h"

#define INIT_JAVA_METHOD(name, signature) \
if (JNIEnv* Env = FAndroidApplication::GetJavaEnv(true)) { \
	name = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, #name, signature, false); \
	check(name != NULL); \
} else { \
	check(0); \
}

#define DECLARE_JAVA_METHOD(name) \
static jmethodID name = NULL;


DECLARE_JAVA_METHOD(AndroidThunkJava_Vungle_HasRewardedVideo);
DECLARE_JAVA_METHOD(AndroidThunkJava_Vungle_ShowRewardedVideo);


void UVungleFunctions::InitJavaFunctions()
{
	
	INIT_JAVA_METHOD(AndroidThunkJava_Vungle_HasRewardedVideo, "()Z");
	INIT_JAVA_METHOD(AndroidThunkJava_Vungle_ShowRewardedVideo, "()V");
	
}
#undef DECLARE_JAVA_METHOD
#undef INIT_JAVA_METHOD


//This function is declared in the Java-defined class, GameActivity.java: "public native void nativeVungleonAdPlayableChanged(boolean isAdPlayable);"
extern "C" void Java_com_epicgames_ue4_GameActivity_nativeVungleonAdPlayableChanged(JNIEnv* jenv, jobject thiz, jboolean isAdPlayable)
{


	FSimpleDelegateGraphTask::CreateAndDispatchWhenReady(
		FSimpleDelegateGraphTask::FDelegate::CreateLambda([=]()
	{
		UVungleComponent::DidVungleAdPlayableChangedDelegate.Broadcast(isAdPlayable);
	}),
		TStatId(),
		nullptr,
		ENamedThreads::GameThread
		);
}


//This function is declared in the Java-defined class, GameActivity.java: "public native void nativeVungleonAdEnd(boolean wasSuccessfulView);"
extern "C" void Java_com_epicgames_ue4_GameActivity_nativeVungleonAdEnd(JNIEnv* jenv, jobject thiz, jboolean wasSuccessfulView)
{


	FSimpleDelegateGraphTask::CreateAndDispatchWhenReady(
		FSimpleDelegateGraphTask::FDelegate::CreateLambda([=]()
	{
		UVungleComponent::DidVungleCompleteRewardedVideoDelegate.Broadcast(wasSuccessfulView);
	}),
		TStatId(),
		nullptr,
		ENamedThreads::GameThread
		);
}



#endif


bool UVungleFunctions::VungleHasRewardedVideo() {

#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv(true))
	{


		bool ret = FJavaWrapper::CallBooleanMethod(Env, FJavaWrapper::GameActivityThis, AndroidThunkJava_Vungle_HasRewardedVideo);



		UE_LOG(LogAndroid, Warning, TEXT("I found the java method VungleShowRewardedVideo\n"));

		return ret;
	}
	else
	{
		UE_LOG(LogAndroid, Warning, TEXT("ERROR Could note get Java ENV\n"));
	}
#endif
	return false;

}



void UVungleFunctions::VungleShowRewardedVideo() {

#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv(true))
	{
		

		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, AndroidThunkJava_Vungle_ShowRewardedVideo);

		

		UE_LOG(LogAndroid, Warning, TEXT("I found the java method VungleShowRewardedVideo\n"));
	}
	else
	{
		UE_LOG(LogAndroid, Warning, TEXT("ERROR Could note get Java ENV\n"));
	}
#endif

}