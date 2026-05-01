# OneBlink UE5 VR Project

A professional VR application template built with **Unreal Engine 5.2**, optimized for **Meta Quest 2/3** (Standalone) and **Windows Desktop** (VR/PCVR).

## 🚀 Key Features

*   **Stable VR Initialization:** Robust C++ system that enforces `Floor Level` tracking origin, ensuring the floor is always at your feet.
*   **Custom VRPlayerStart:** A specialized player start actor with a head-height visual reference (1.0m) and zero-collision footprint for perfect floor alignment.
*   **Advanced Hand Tracking:** Pre-configured support for Oculus XR Hand Tracking and OpenXR Hand Interaction.
*   **Hybrid Development:** Seamlessly integrates C++ core logic with Blueprint flexibility.
*   **Networking Ready:** Structure prepared for replicated actors and remote avatars.

## 🛠️ Technical Specifications

*   **Engine:** Unreal Engine 5.2
*   **Target Platforms:** Android (Quest 2/3), Windows (Win64)
*   **Rendering:** Mobile Forward Shading, Multi-View, MSAA 4x.
*   **Plugins:** OculusXR, OpenXRHandTracking, OpenXRMsftHandInteraction.

## 📦 Getting Started

### Prerequisites
*   Unreal Engine 5.2
*   Visual Studio 2022
*   Android Studio (for Quest builds)

### Setup
1.  Clone the repository.
2.  Right-click `oneblink_ue5.uproject` and select **Generate Visual Studio project files**.
3.  Open the `.sln` file and build the project.
4.  Open the project in Unreal Editor.
5.  In the `BP_VRGameMode`, ensure the Parent Class is set to `oneblink_ue5GameModeBase`.

## 🎮 VR Workflow

### Floor Height Alignment
The project uses a custom `AVRPlayerStart` to ensure correct height.
1.  Place an `AVRPlayerStart` actor in your level.
2.  Set its **Location Z to 0.0**.
3.  The visual bust icon (floating at 1m) serves as an editor-only reference for head height.

### Tracking Origin
The `Aoneblink_ue5GameModeBase` class automatically sets the tracking origin to **Floor Level** on startup. If the HMD is not detected immediately, it will retry every 0.5 seconds until success.

## 📜 Commands
*   **Package for Android:** `File > Package Project > Android > Android (ASTC)`
*   **VR Preview:** `Play > VR Preview` (Requires Quest Link or compatible HMD)
