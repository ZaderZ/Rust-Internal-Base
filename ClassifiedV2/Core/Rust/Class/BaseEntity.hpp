
class BaseEntity : public BaseNetworkable
{
public:
	CLASS("", "BaseEntity");

	MEMBER(PlayerModel*, model);
};