#include "VRPlayerStart.h"
#include "Components/CapsuleComponent.h"
#include "Components/ArrowComponent.h"
#include "Components/BillboardComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "Engine/Texture2D.h"

AVRPlayerStart::AVRPlayerStart(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	// Desactivar el ajuste automatico de altura al colocar en el editor
	bCollideWhenPlacing = false;

	// Forzar el spawn siempre independientemente de colisiones
	SpawnCollisionHandlingMethod = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	if (UCapsuleComponent* Capsule = GetCapsuleComponent())
	{
		Capsule->SetCapsuleHalfHeight(0.1f);
		Capsule->SetCapsuleRadius(0.1f);
		Capsule->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		Capsule->SetCollisionResponseToAllChannels(ECR_Ignore);
		Capsule->SetHiddenInGame(true);
		Capsule->SetVisibility(false);
	}
}

void AVRPlayerStart::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);

	// Asegurar que los valores se mantengan correctos al mover el actor en el editor
	if (UCapsuleComponent* Capsule = GetCapsuleComponent())
	{
		Capsule->SetCapsuleHalfHeight(0.1f);
		Capsule->SetCapsuleRadius(0.1f);
	}

#if WITH_EDITOR
	// Buscamos el BillboardComponent (el icono de la persona) para moverlo
	TArray<UBillboardComponent*> Billboards;
	GetComponents<UBillboardComponent>(Billboards);
	
	for (UBillboardComponent* SpriteComp : Billboards)
	{
		if (SpriteComp)
		{
			SpriteComp->SetRelativeLocation(FVector(0.0f, 0.0f, 100.0f));
			SpriteComp->SetRelativeScale3D(FVector(0.6f, 0.6f, 0.6f));
		}
	}

	// Flecha de direccion en el suelo
	if (UArrowComponent* Arrow = GetArrowComponent())
	{
		Arrow->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
	}
#endif
}

