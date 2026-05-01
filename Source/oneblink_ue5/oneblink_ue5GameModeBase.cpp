// Copyright Epic Games, Inc. All Rights Reserved.


#include "oneblink_ue5GameModeBase.h"
#include "HeadMountedDisplayFunctionLibrary.h"
#include "TimerManager.h"

void Aoneblink_ue5GameModeBase::StartPlay()
{
    Super::StartPlay();

    ForceVRFloorLevel();
}

void Aoneblink_ue5GameModeBase::ForceVRFloorLevel()
{
    // Esperar un momento antes de configurar el tracking origin para asegurar que el HMD esté listo
    FTimerHandle TimerHandle;
    GetWorldTimerManager().SetTimer(TimerHandle, this, &Aoneblink_ue5GameModeBase::SetVRTrackingOrigin, 0.5f, false);
}

void Aoneblink_ue5GameModeBase::SetVRTrackingOrigin()
{
    if (UHeadMountedDisplayFunctionLibrary::IsHeadMountedDisplayEnabled())
    {
        UHeadMountedDisplayFunctionLibrary::SetTrackingOrigin(EHMDTrackingOrigin::Floor);
        UE_LOG(LogTemp, Warning, TEXT("VR: Tracking Origin configurado con exito a FLOOR LEVEL"));
    }
    else
    {
        // Si falla, reintentamos un poco mas tarde (util para algunos dispositivos lentos)
        FTimerHandle RetryHandle;
        GetWorldTimerManager().SetTimer(RetryHandle, this, &Aoneblink_ue5GameModeBase::SetVRTrackingOrigin, 0.5f, false);
        UE_LOG(LogTemp, Log, TEXT("VR: Reintentando configuracion de Floor Level..."));
    }
}

