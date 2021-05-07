#include "player.h"
#include <assert.h>
#include <DxLib.h>
#include "field.h"


Player::Player(SceneBase * scene):GameObject(scene)
{
	hModel = MV1LoadModel("data\\MMD�p�x��Lver1.02\\���u�`�˂�.pmx");
	assert(hModel > 0);
	int centor = MV1SearchFrame(hModel, "�S�Ă̐e");
	MV1SetFrameUserLocalMatrix(hModel, centor, MGetRotY(DX_PI_F));

	position = VGet(0, 60, 0);
	rotation = VGet(0, 0, 0);
}

Player::~Player()
{
	
}

void Player::Update()
{
	//�O
	if (CheckHitKey(KEY_INPUT_W))
	{

	}
	//���
	if (CheckHitKey(KEY_INPUT_S))
	{

	}
	//��
	if (CheckHitKey(KEY_INPUT_A))
	{

	}
	//�E
	if (CheckHitKey(KEY_INPUT_D))
	{

	}


	VECTOR upper = VAdd(position, VGet(0, 1000, 0));
	VECTOR lower = VAdd(position, VGet(0, -1000, 0));
	VECTOR hitposition;

	//�n�`�Ƃ̓����蔻��
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
