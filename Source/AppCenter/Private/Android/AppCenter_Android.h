// Copyright 2015-2020 Mail.Ru Group. All Rights Reserved.

#pragma once

#include "AppCenterProxy.h"

#include "AppCenter_Android.generated.h"

UCLASS()
class UAppCenter_Android : public UAppCenterProxy
{
	GENERATED_UCLASS_BODY()

#if PLATFORM_ANDROID

#if WITH_APPCENTER
	virtual void SetUserId(const FString& UserId) override;
	virtual void SetCustomPropertyAsString(const FString& Key, const FString& Value) override;
	virtual void SetCustomPropertyAsInt(const FString& Key, int32 Value) override;
	virtual void SetCustomPropertyAsFloat(const FString& Key, float Value) override;
	virtual void SetCustomPropertyAsBool(const FString& Key, bool Value) override;
	virtual void ClearCustomProperties(const TArray<FString>& Keys) override;
	virtual void ClearCustomProperty(const FString& Key) override;
#endif // WITH_APPCENTER

#if WITH_APPCENTER_ANALYTICS
	virtual void TrackEvent(const FString& EventName, const TMap<FString, FString>& Properties, EAppCenterEventPersistence EventPersistence = EAppCenterEventPersistence::PERSISTENCE_NORMAL) override;
#endif // WITH_APPCENTER_ANALYTICS

#if WITH_APPCENTER_CRASHES
	virtual void GenerateTestCrash() override;
	virtual void GenerateNativeCrash() override;
	virtual bool HasCrashedInLastSession() override;
#endif // WITH_APPCENTER_CRASHES

#endif
};
