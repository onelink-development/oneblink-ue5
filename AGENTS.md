# AGENTS.md - oneblink_ue5

## Project Overview
- **Engine**: Unreal Engine 5.2
- **Type**: VR Application (Oculus Quest 2/3 + Windows Desktop)
- **Language**: C++ (minimal) + Blueprints

## Key Directories
- `Source/oneblink_ue5/` - C++ source code (default game module only)
- `Content/VR/` - VR Pawns, Maps, Hands, Avatar assets
- `Content/Networking/` - Replicated actors, PlayerState, RemoteAvatarManager
- `Config/` - Engine and input configuration

## Platforms
- **Win64**: Editor and packaged builds
- **Android**: Quest 2/3 (ARM64), pre-built APK at `Binaries/Android/`

## Critical Plugins
- OculusXR - Quest support
- OpenXRHandTracking - Hand tracking
- OpenXRMsftHandInteraction - Hand interactions

## Development Workflow
- Open `oneblink_ue5.uproject` in Unreal Editor 5.2
- C++ builds via Visual Studio or `UE5` build system
- Android builds require Android Studio SDK/NDK

## Build Commands (via Unreal Editor)
- **Package for Android**: File > Package Project > Android > Android (ASTC)
- **Cook Content**: Window > Cook Content > Android_ASTC

## VR Configuration
- Starts in VR automatically (`bStartInVR=True` in DefaultGame.ini)
- Hand tracking: Enabled (Low frequency, controllers+hands)
- Foveated rendering: Dynamic, fixed foveated
- Passthrough: Enabled for mixed reality

## Mobile Rendering (DefaultEngine.ini)
- Mobile HDR: Disabled
- Forward shading: Enabled
- Target hardware: Mobile/Scalable

## Important Settings
- Input system: Enhanced Input (`DefaultInput.ini:79-80`)
- Default map: `VR_TestMap` in `Content/VR/Maps/`
- Default game mode: `BP_VRGameMode`

## Testing
- VR preview in editor (Play > VR Preview)
- Standalone game with `-game` flag
- Deploy APK to Quest via Quest Link or SideQuest