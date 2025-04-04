# Ben 10 Mixed Reality Project With HandTracking (Quest 3 – Unreal Engine 5.5.4)

This project is a mixed reality (MR) prototype for Meta Quest 3 inspired by **Ben 10**, allowing users to interact with an Omnitrix-style watch with their hands, chose and transform into aliens, and use gesture-based abilities in their real-world environment.

## Core Features

### 1. Omnitrix Watch System

- Built using **MetaXR Interaction SDK**.
- Functional watch with theree interactive buttons one for activation/deactivation, one for confirming alien to transform, one for turning back to human.
- Rotatable watch face to change alien selected.
- based on number of aliens in `UAliensDataAsset` it divides circumference of the omnitrix face circle equally.

### 2. Alien Selection System

- Data-driven using `UAliensDataAsset` (stores:
  - Alien names
  - Static meshes
  - Materials
  - Abilities)
- Delegates for interaction flow:
  - `OnAlienChanged`: Triggers UI/SFX feedback.
  - `OnAlienConfirmed`: Broadcasts final alien choice (e.g., smashing the watch).

### 3. Gameplay Ability System (GAS)

- Each alien has unique **gesture-triggered abilities** (e.g., `High5R` triggers `FireBeam`).
- Abilities linked via a `TMap<FString, TSubclassOf<UGameplayAbility>>` inside `FAliens`.
- On alien confirmation:
  - Abilities are granted to the pawn.
  - Activated using `TryActivateAbilityByClass()` by gesture recognition.

### 4. Gesture Recognition (OculusHandTools)

- Uses `FHandPose` struct (includes pose name, encoded data, confidence thresholds).
- Abilities mapped per alien via TMap in `AliensDataAsset`.
- Gesture detection runs on tick and triggers abilities dynamically.

### 5. Pawn & Abilities Integration

- Abilities are granted and removed using a custom `UBenAbilitySystemComponentBase`.
- Abilities update dynamically in Blueprint when `OnAlienConfirmed` is fired.

### 6. Mixed Reality Environment: Wall Destruction and Omnitrix Spaceship spawning

- Uses MRUK and passthrough-compatible **"Sky Dome"** setup.
- Custom version of `PokeAHole` material for realistic dome effect.
- Destructible walls added for interaction and Sky dome is showen after Breaking the walls.

---

## Plugins Used

- **Gameplay Abilities System (GAS)**
- **MetaXRInteraction v74.0.0**
- **UnrealMetaXRPlugin v74.0**
- **OculusHandTools**

---
## Credits & Contributions
Special thanks to the creators of the following 3D assets used in this project:

- [Main Omnitrix](https://sketchfab.com/3d-models/omnitrix-6eece96485f6433e9a8edf07da72ee90)  
- [Omnitrix Spaceship](https://sketchfab.com/3d-models/10-ben-10-all-omnitrix-a8d7182e738f4db69b0b359957a3cd70)  
- [Omnitrix Badge (used for human transformation)](https://sketchfab.com/3d-models/omnitrix-badge-a02e522eb9cb45bc89b616929b5f2edd)  
- [Omnitrix Cylinder Part](https://sketchfab.com/3d-models/omnitrix-1e51128e2f154badbd499ee48d23aa68)  
- [Diamondhead Crystal (used for projectile ability)](https://sketchfab.com/3d-models/large-crystal-237b07e70cf54c4c9f1f89519a7c077d)  

Huge thanks to the amazing artists who shared their work on Sketchfab!
