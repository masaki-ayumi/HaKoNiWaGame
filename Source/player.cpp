#include "player.h"
#include <assert.h>
#include <DxLib.h>
#include "field.h"


Player::Player(SceneBase * scene):GameObject(scene)
{
	hModel = MV1LoadModel("data\\MMD用踊る猫ver1.02\\茶ブチねこ.pmx");
	assert(hModel > 0);
	int centor = MV1SearchFrame(hModel, "全ての親");
	MV1SetFrameUserLocalMatrix(hModel, centor, MGetRotY(DX_PI_F));

	position = VGet(0, 60, 0);
	rotation = VGet(0, 0, 0);
}

Player::~Player()
{
	
}

void Player::Update()
{
	VECTOR upper = VAdd(position, VGet(0, 1000, 0));
	VECTOR lower = VAdd(position, VGet(0, -1000, 0));
	VECTOR hitposition;

	//地形との当たり判定
	Field* pField = GetScene()->FindGameObject<Field>();
	if (pField->CollisoinLine(&hitposition, upper, lower))
	{
		position = hitposition;
	}
}

void Player::Draw()
{
	MV1SetPosition(hModel, position);
	MV1DrawModel(hModel);
}
