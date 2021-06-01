#include "camera.h"
#include <DxLib.h>
#include "debugScreen.h"
#include <algorithm>
using namespace std;

Camera::Camera(SceneBase * scene):GameObject(scene)
{

	//position = VGet(700.0f, 400.f, -500.0f);
	position = VGet(-454.428131f, 78.392891f, 79.835190f);
	//position = VGet(0, 50, 400);
	target = VGet(0, 0, 0);
	rotation = VGet(0, 0, 0);
}

Camera::~Camera()
{
}

void Camera::Update()
{

	VECTOR add = VGet(0, 0, 0);//�J�����̒����_�ɑ������߂̕ϐ�

#if 0 //�J������]���������ׂăR�����g�A�E�g


#if 1//��]�s��
	//�E��]
	if (CheckHitKey(KEY_INPUT_RIGHT))
	{
		rotation.y += 1.0f*DX_PI_F / 180.0f;

		MATRIX rotY = MGetRotY(rotation.y);
		position = VTransform(position, rotY);

	}
	//����]
	if (CheckHitKey(KEY_INPUT_LEFT))
	{
		rotation.y -= 1.0f*DX_PI_F / 180.0f;

		MATRIX rotY = MGetRotY(rotation.y);
		position = VTransform(position, rotY);

	}
	if (CheckHitKey(KEY_INPUT_UP))
	{
		rotation.x += 1.0f*DX_PI_F / 180.0f;
		rotation.x = min(rotation.x, 1.5f);

		MATRIX rotX = MGetRotX(rotation.x);
		position = VTransform(position, rotX);

	}
	if (CheckHitKey(KEY_INPUT_DOWN))
	{
		rotation.x -= 1.0f*DX_PI_F / 180.0f;
		rotation.x = max(rotation.x, -1.5f);

		MATRIX rotX = MGetRotX(rotation.x);
		position = VTransform(position, rotX);

	}
#endif // 1
#if 0 //�O�p�֐����g������]
	//�E��]
	if (CheckHitKey(KEY_INPUT_RIGHT))
	{
		rotation.y += 3.0f*DX_PI_F / 180.0f;
#if 0
		add.x += cosf(rotation.z)*length;
		add.y += sinf(rotation.z)*length;
		add.x += cosf(rotation.y)*length;
		add.z += sinf(rotation.y)*length;
		add.y += sinf(rotation.x)*length;
		add.z += cosf(rotation.x)*length;
		//�����_�����߂�~�^�����J�������W�ɑ��
		position.x = target.x + add.x;
		position.y = target.y + add.y;
		position.z = target.z + add.z;
#endif // 0
		Yrot(add);
	}
	//����]
	if (CheckHitKey(KEY_INPUT_LEFT))
	{
		rotation.y -= 3.0f*DX_PI_F / 180.0f;
#if 0

		add.x += cosf(rotation.z)*length;
		add.y += sinf(rotation.z)*length;
		add.x += cosf(rotation.y)*length;
		add.z += sinf(rotation.y)*length;
		add.y += sinf(rotation.x)*length;
		add.z += cosf(rotation.x)*length;
		//�����_�����߂�~�^�����J�������W�ɑ��
		position.x = target.x + add.x;
		position.y = target.y + add.y;
		position.z = target.z + add.z;
#endif // 0
		Yrot(add);
	}
	//���]
	if (CheckHitKey(KEY_INPUT_UP))
	{
		rotation.z += 3.0f*DX_PI_F / 180.0f;
		rotation.z = min(rotation.z, 1.5f);
#if 0

		add.x += cosf(rotation.z)*length;
		add.y += sinf(rotation.z)*length;
		add.x += cosf(rotation.y)*length;
		add.z += sinf(rotation.y)*length;
		add.y += sinf(rotation.x)*length;
		add.z += cosf(rotation.x)*length;
		//�����_�����߂�~�^�����J�������W�ɑ��
		position.x = target.x + add.x;
		position.y = target.y + add.y;
		position.z = target.z + add.z;
#endif // 0
		Zrot(add);
	}
	//����]
	if (CheckHitKey(KEY_INPUT_DOWN))
	{
		rotation.z -= 3.0f*DX_PI_F / 180.0f;
		rotation.z = max(rotation.z, 0);

#if 0

		add.x += cosf(rotation.z)*length;
		add.y += sinf(rotation.z)*length;
		add.x += cosf(rotation.y)*length;
		add.z += sinf(rotation.y)*length;
		add.y += sinf(rotation.x)*length;
		add.z += cosf(rotation.x)*length;
		//�����_�����߂�~�^�����J�������W�ɑ��
		position.x = target.x + add.x;
		position.y = target.y + add.y;
		position.z = target.z + add.z;
#endif // 0
		Zrot(add);
	}
#endif // 1



#endif // 0

	//�搶�̂��
	 //���t���[��1�x��]
	float degRot = 1.0f;
	float radRot = degRot / 180.0f * 3.1415926f;
	//��]�O��̍��W�ix,y,z�j
	float posX, posY, posZ;     //�ϊ��O��vec
	float posX2, posY2, posZ2;  //�ϊ����vec
	posX = position.x;
	posY = position.y;
	posZ = position.z;
	//�E��]
	if (CheckHitKey(KEY_INPUT_RIGHT))
	{
		posX2 = (posX * cos(radRot)) + (posZ * sin(radRot));
		posY2 = posY;
		posZ2 = (posZ * cos(radRot)) - (posX * sin(radRot));
		position.x = posX2;
		position.y = posY2;
		position.z = posZ2;
	}
	//����]
	if (CheckHitKey(KEY_INPUT_LEFT))
	{
		posX2 = (posX * cos(-radRot)) + (posZ * sin(-radRot));
		posY2 = posY;
		posZ2 = (posZ * cos(-radRot)) - (posX * sin(-radRot));
		position.x = posX2;
		position.y = posY2;
		position.z = posZ2;
	}
	//���]
	if (CheckHitKey(KEY_INPUT_UP))
	{
		posX2 = (posX * cos(radRot)) - (posY * sin(radRot));
		posY2 = (posX * sin(radRot)) + (posY * cos(radRot));
		posZ2 = posZ;
		position.x = posX2;
		position.y = posY2;
		position.z = posZ2;
	}
	//����]
	if (CheckHitKey(KEY_INPUT_DOWN))
	{
		posX2 = (posX * cos(-radRot)) - (posY * sin(-radRot));
		posY2 = (posX * sin(-radRot)) + (posY * cos(-radRot));
		posZ2 = posZ;
		position.x = posX2;
		position.y = posY2;
		position.z = posZ2;
	}
	






	DebugSetColor(255, 255, 255);
	DebugPrintf(0, 100, "�J�������WX:%f,Y:%f,Z:%f", position.x, position.y, position.z);
	DebugPrintf(0, 115, "�J�����p�xX:%f,Y:%f,Z:%f", rotation.x, rotation.y, rotation.z);


	
}

void Camera::Draw()
{
	SetCameraPositionAndTarget_UpVecY(position, target);


#if 0
	
	SetCameraPositionAndTarget_UpVecY(VGet(-454.428131f, 78.392891f, 79.835190f), VGet(0.000000f, 0.000031f, 0.000000f));
	SetCameraNearFar(7.200000f, 1800.000000f);





#endif // 0

}

//Y����](�O�p�֐�)
void Camera::Yrot(VECTOR add)
{
	add.x += cosf(rotation.y)*length;
	add.z += sinf(rotation.y)*length;

	position.x = target.x + add.x;
	position.y = target.y + add.y;
	position.z = target.z + add.z;
}

//Z����](�O�p�֐�)
void Camera::Zrot(VECTOR add)
{
	add.x += cosf(rotation.z)*length;
	add.y += sinf(rotation.z)*length;

	position.x = target.x + add.x;
	position.y = target.y + add.y;
	position.z = target.z + add.z;
}
