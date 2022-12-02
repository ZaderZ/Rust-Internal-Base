auto Hooks::ClientInput(BasePlayer* player, std::uintptr_t state) -> void
{
	if (!player) return Hooks::ClientInputhk.get_original< decltype(&ClientInput)>()(player, state);


	Hooks::ClientInputhk.get_original< decltype(&ClientInput)>()(player, state);
}