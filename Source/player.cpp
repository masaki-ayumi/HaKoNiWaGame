#include "player.h"
#include <assert.h>
#include <DxLib.h>


Player::Player(SceneBase * scene):GameObject(scene)
{
	hModel = MV1LoadModel("data\\MMD�p�x��Lver1.02\\���u�`�˂�.pmx");
	assert(hModel > 0);
	int centor = MV1SearchFrame(hModel, "�S�Ă̐e");
	MV1SetFrameUserLocalMatrix(hModel, centor, MGetRotY(DX_PI_F));

	position = VGet(0, 50, 0);
	rotation = VGet(0, 0, 0);
}

Player::~Player()
{
}

void Player::Update()
{
}

void Player::Draw()
{
	MV1SetPosition(hModel, position);
	MV1DrawModel(hModel);
}
