
auto Hooks::Enable() -> void
{
	const auto SwapChainFn = reinterpret_cast<IDXGISwapChain * (*)()>(pattern::find(L"UnityPlayer.dll", "48 83 ec 28 e8 ? ? ? ? 48 8b 80 a0 03 00 00"))();
	if (!SwapChainFn)
		return;
	static auto SwapChain = *reinterpret_cast<PVOID**> (SwapChainFn);
	static auto PresentAddr = reinterpret_cast<HRESULT(__fastcall*)(IDXGISwapChain*, UINT, UINT)>(SwapChain[8]);
	MH_CreateHook(PresentAddr, Present::PresentHk, &Present::o_present);
	MH_EnableHook(PresentAddr);

	Hooks::ClientInputhk.InitializeHook("", "BasePlayer", "ClientInput", &Hooks::ClientInput);
	//Hooks::TryRepairhk.InitializeHook("", "RepairBench", "TryRepair", &Hooks::TryRepair);
}

auto Hooks::Disable() -> void
{
	MH_DisableHook(MH_ALL_HOOKS);
}