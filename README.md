# Ben 10 Mixed Reality Project With HandTracking (Quest 3 – Unreal Engine 5.5.4)

This project is a mixed reality (MR) prototype for Meta Quest 3 inspired by **Ben 10**, allowing users to interact with an Omnitrix-style watch with their hands, chose and transform into aliens, and use gesture-based abilities in their real-world environment.

## Core Features

### 1. Omnitrix Watch System

- Built using **MetaXR Interaction SDK**.
- Functional watch with two interactive buttons one for activation/deactivation and one for confirming alien to transform.
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
