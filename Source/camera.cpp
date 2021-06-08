#include "camera.h"
#include <DxLib.h>
#include "debugScreen.h"
#include <algorithm>
using namespace std;

Camera::Camera(SceneBase * scene) :GameObject(scene)
{

	position = VGet(-454.428131f, 78.392891f, 79.835190f);
	target = VGet(0, 0, 0);
	rotation = VGet(0, 0, 0);
}

Camera::~Camera()
{
}

void Camera::Update()
{

	//���t���[��1�x��]
	float degRot = 1.0f;
	float radRot = degRot / 180.0f * DX_PI_F;

	//��]�O��̍��W�ix,y,z�j
	float posX, posY, posZ;     //�ϊ��O�̍��W
	float posX2, posY2, posZ2;  //�ϊ���̍��W

	posX = position.x;
	posY = position.y;
	posZ = position.z;

	//����]
	if (CheckHitKey(KEY_INPUT_LEFT))
	{
		//��]�s��
		posX2 = (posX * cos(radRot)) + (posZ * sin(radRot));
		posY2 = posY;
		posZ2 = (posZ * cos(radRot)) - (posX * sin(radRot));

		position.x = posX2;
		position.y = posY2;
		position.z = posZ2;
	}
	//�E��]
	if (CheckHitKey(KEY_INPUT_RIGHT))
	{
		//��]�s��
		posX2 = (posX * cos(-radRot)) + (posZ * sin(-radRot));
		posY2 = posY;
		posZ2 = (posZ * cos(-radRot)) - (posX * sin(-radRot));

		position.x = posX2;
		position.y = posY2;
		position.z = posZ2;
	}
	//����]
	if (CheckHitKey(KEY_INPUT_DOWN))
	{
		//��]�s��
		posX2 = (posX * cos(radRot)) - (posY * sin(radRot));
		posY2 = (posX * sin(radRot)) + (posY * cos(radRot));
		posZ2 = posZ;

		position.x = posX2;
		position.y = posY2;
		position.z = posZ2;
	}
	//���]
	if (CheckHitKey(KEY_INPUT_UP))
	{
		//��]�s��
		posX2 = (posX * cos(-radRot)) - (posY * sin(-radRot));
		posY2 = (posX * sin(-radRot)) + (posY * cos(-radRot));
		posZ2 = posZ;

		position.x = posX2;
		position.y = posY2;
		position.z = posZ2;
	}



#if 0	//�f�o�b�O�\��
	DebugSetColor(255, 255, 255);
	DebugPrintf(0, 100, "�J�������WX:%f,Y:%f,Z:%f", position.x, position.y, position.z);
	DebugPrintf(0, 115, "�J�����p�xX:%f,Y:%f,Z:%f", rotation.x, rotation.y, rotation.z);
#endif // 0

}



void Camera::Draw()
{
	SetCameraPositionAndTarget_UpVecY(position, target);

}