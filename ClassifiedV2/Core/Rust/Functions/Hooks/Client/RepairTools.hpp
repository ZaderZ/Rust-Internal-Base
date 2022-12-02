
auto Hooks::TryRepair(std::uintptr_t sui) -> void
{

	//just ignore this, tried doing auto repair for jackhammer but realized this was only for repair bench :(

	Hooks::TryRepairhk.get_original< decltype(&TryRepair)>()(sui);
}