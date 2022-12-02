class BaseCombatEntity : public BaseEntity
{
public:
	CLASS("", "BaseCombatEntity");


	MEMBER(float, _health);
	MEMBER(float, _maxHealth);
};
