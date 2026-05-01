#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerStart.h"
#include "VRPlayerStart.generated.h"

/**
 * VRPlayerStart con jerarquia original pero capsula plana para situar el pivote en el suelo.
 */
UCLASS()
class ONEBLINK_UE5_API AVRPlayerStart : public APlayerStart
{
	GENERATED_BODY()

public:
	AVRPlayerStart(const FObjectInitializer& ObjectInitializer);

	// Asegura la configuracion visual y de colision en el editor
	virtual void OnConstruction(const FTransform& Transform) override;
};
