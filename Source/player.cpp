#include "player.h"
#include <assert.h>
#include <DxLib.h>
#include "field.h"
#include "debugScreen.h"


Player::Player(SceneBase * scene):GameObject(scene)
{
	hModel = MV1LoadModel("data\\MMD�p�x��Lver1.02\\���u�`�˂�.pmx");
	assert(hModel > 0);
	int centor = MV1SearchFrame(hModel, "�S�Ă̐e");
	MV1SetFrameUserLocalMatrix(hModel, centor, MGetRotY(DX_PI_F));

	position = VGet(0, 0, 0);
	rotation = VGet(0, 0, 0);
}

Player::~Player()
{
	
}

void Player::Update()
{
	//��]�s��
	MATRIX rotY = MGetRotY(rotation.y);


	//�O
	if (CheckHitKey(KEY_INPUT_W))
	{
		//��]�l�ɉ����ĉ�������l
		VECTOR velocity = VTransform(VGet(0.0, 0.0, 1.5), rotY);
		//���݂̍��W�ɉ��������l�����Z
		position = VAdd(position, velocity);
	}
	//���
	if (CheckHitKey(KEY_INPUT_S))
	{
		//��]�l�ɉ�����-��������l
		VECTOR velocity = VTransform(VGet(0.0, 0.0, -1.5), rotY);
		//���݂̍��W�ɉ��������l�����Z
		position = VAdd(position, velocity);
	}
	//��
	if (CheckHitKey(KEY_INPUT_A))
	{
		//�E����
		rotation.y -= 3.0*DX_PI_F / 180.0;
	}
	//�E
	if (CheckHitKey(KEY_INPUT_D))
	{
		//������
		rotation.y += 3.0*DX_PI_F / 180.0;
	}


	//VECTOR upper = VAdd(position, VGet(0, 1000, 0));
	VECTOR upper = VAdd(position, VGet(0, 10, 0));
	VECTOR lower = VAdd(position, VGet(0, -1000, 0));
	VECTOR hitposition;

	


	//�n�`�Ƃ̓����蔻��
	Field* pField = GetScene()->FindGameObject<Field>();
	if (pField->CollisoinLine(&hitposition, upper, lower))
	{
		position = hitposition;
	}

	//���̂��g�����ǂƂ̓����蔻��
	if (pField->CollisoinSphere(&hitposition,position))
	{
		position = hitposition;
	}

}

void Player::Draw()
{
	//�ړ��s��
	MATRIX mTranslate = MGetTranslate(position);
	//Y���̉�]�s��
	MATRIX mRotationY = MGetRotY(rotation.y);
	//��]���Ă���ړ�
	MATRIX matrix = MMult(mRotationY, mTranslate);
	//MV1SetPosition(hModel, position);
	MV1SetMatrix(hModel, matrix);
	MV1DrawModel(hModel);



#if 1	//�v���C���[�̃f�o�b�O�p
	DebugSetColor(255, 0, 255);
	DebugPrintf(0, 50, "���@�̍��W:X%d,Y%d,Z%d", mTranslate);
	DrawSphere3D(VAdd(position,VGet(0,10,0)), 10, 32, GetColor(255, 0, 0), GetColor(255, 255, 255), false);
	Player* pPlayer = GetScene()->FindGameObject<Player>();
	
	DrawLine3D(position, VAdd(position, VGet(0, 10, 0)), GetColor(255, 0, 0));
	DrawLine3D(position, VAdd(position, VGet(0, -1000, 0)), GetColor(0, 0, 255));
#endif // 0

}
