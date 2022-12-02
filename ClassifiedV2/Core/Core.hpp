#include <Windows.h>
#include <iostream>
#include <cstdint>
#include <memory.h>
#include <map>
#include <mutex>
#include <vector>
#include <atomic>
#include <array>
#include <list>
#include <unordered_map>	

#include <d3d11.h>

#include "Dependencies/MinHook/include/minhook.h"

#include "Dependencies/ImGui/imgui.h"
#include "Dependencies/ImGui/imgui_internal.h"
#include "Dependencies/ImGui/imgui_impl_dx11.h"
#include "Dependencies/ImGui/imgui_impl_win32.h"

#include "Rust/Memory/Il2cpp/SDK.hpp"

#include "Dependencies/Vec/Vec3/Vec3.hpp"
#include "Dependencies/Vec/Vec2/Vec2.hpp"
#include "Dependencies/Vec/Matrix/Matrix.hpp"

#include "Rust/Class/Misc/ListDictionary.hpp"

#include "Rust/Memory/Pattern/Pattern.hpp"

#include "Rust/Memory/Enums/Enums.hpp"

class PlayerModel;
class Transform;
class Component;
class BaseNetworkable;
class BaseEntity;
class BaseCombatEntity;
class BasePlayer;
class LocalPlayer;
class Camera;

#include "Rust/Functions/Hooks/Present/PresentInit.hpp"

#include "Rust/Class/Misc/String.hpp"
#include "Rust/Class/Unity/Camera.hpp"
#include "Rust/Class/PlayerModel.hpp"
#include "Rust/Class/Transform.hpp"
#include "Rust/Class/Component.hpp"
#include "Rust/Class/BaseNetworkable.hpp"
#include "Rust/Class/BaseEntity.hpp"
#include "Rust/Class/BaseCombatEntity.hpp"
#include "Rust/Class/BasePlayer.hpp"
#include "Rust/Class/LocalPlayer.hpp"
#include "Rust/Class/BaseGameMode.hpp"

#include "Rust/Class/Misc/WorldToScreen.hpp"


#include "Rust/Hooking/Library/Library.hpp"

#include "Rust/Functions/Features/Drawing/Rendering/Rendering.hpp"
#include "Rust/Functions/Features/Drawing/Drawing.hpp"


#include "Rust/Hooking/Hooks.hpp"
#include "Rust/Hooking/LoadHooks.hpp"

#include "Rust/Functions/Hooks/Present/Present.hpp"

#include "Rust/Functions/Hooks/Client/ClientInput.hpp"
#include "Rust/Functions/Hooks/Client/RepairTools.hpp"