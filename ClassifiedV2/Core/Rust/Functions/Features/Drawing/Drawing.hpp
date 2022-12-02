namespace drawing
{
	ImDrawList* DrawList = nullptr;

	static auto player_cache() -> void
	{
		static auto visiblePlayerList = BasePlayer::playerList();

		if (!visiblePlayerList || visiblePlayerList->vals == nullptr || visiblePlayerList->vals->size == 0 || !world::main)
		{
			world::main = Camera::main(); //could be a better check to see if local is disconnected but this works well :)
		}
	}
	static auto player_loop() -> void
	{
		if (!LocalPlayer::Entity() || !LocalPlayer::Entity()->HasFlag(Enums::PlayerFlags::Connected) || !LocalPlayer::Entity()->PlayerValid())
			return;

		if (!DrawList)
			DrawList = ImGui::GetForegroundDrawList();

		if (!world::main)
			return;

		static auto visiblePlayerList = BasePlayer::playerList();

		if (!visiblePlayerList || visiblePlayerList->vals == nullptr || visiblePlayerList->vals->size == 0)
			return;

		const auto buffer = std::uintptr_t(visiblePlayerList->vals->buffer);

		if (!buffer)
			return;

		for (size_t i = 0; i < visiblePlayerList->vals->size; i++)
		{
			const auto& player = *reinterpret_cast<BasePlayer**>(buffer + 0x20 + (i * sizeof(void*)));

			if (!player || player == nullptr)
				continue;

			if (player->_health() < 0.05f)
				continue;

			if (!player->PlayerValid())
				continue;

			if (player->userID() == LocalPlayer::Entity()->userID())
				continue;

			if (player->playerModel()->PlayerNPC()) //optional check (remove / add a button if u dont want it to not draw on npc)
				continue;




			Vec2 footPos = {};
			const auto transformPos = world::screen_transform(player->transform()->position(), footPos);
			if (footPos.Zero())
				continue;


			if (true)
			{
				char buf[64] = { 0 }; sprintf_s(buf, "%ls", player->_displayName()->buffer);

				render::add_text(ImVec2(footPos.x, footPos.y), buf, ImColor(255, 255, 255));
			}
			if (true)
			{
				char buf[64] = { 0 }; sprintf_s(buf, "[%.f M]", player->transform()->position().Distance(LocalPlayer::Entity()->transform()->position()));

				footPos.y += 15;

				render::add_text(ImVec2(footPos.x, footPos.y), buf, ImColor(255, 255, 255));

			}
			if (true)
			{
				char buf[64] = { 0 }; sprintf_s(buf, "[%.f HP]", player->_health());

				footPos.y += 15;

				render::add_text(ImVec2(footPos.x, footPos.y), buf, ImColor(255, 255, 255));

			}

		}
	}	
}