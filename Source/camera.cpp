#include "camera.h"
#include <DxLib.h>
#include "debugScreen.h"
#include <algorithm>
using namespace std;

Camera::Camera(SceneBase * scene)
{

	//position = VGet(700.0f, 400.f, -500.0f);
	position = VGet(0.0f, 400.f, -400.0f);
	target = VGet(0, 0, 0.0f);
	rotation = VGet(0, 0, 0);
}

Camera::~Camera()
{
}

void Camera::Update()
{

	VECTOR add = VGet(0, 0, 0);//�J�����̒����_�ɑ������߂̕ϐ�

#if 1 //�J������]���������ׂăR�����g�A�E�g


#if 0//��]�s��
	//�E��]
	if (CheckHitKey(KEY_INPUT_RIGHT))
	{
		rotation.y += 3.0f*DX_PI_F / 180.0f;

		MATRIX rotY = MGetRotY(rotation.y);
		position = VTransform(position, rotY);

	}
	//����]
	if (CheckHitKey(KEY_INPUT_LEFT))
	{
		rotation.y -= 3.0f*DX_PI_F / 180.0f;

		MATRIX rotY = MGetRotY(rotation.y);
		position = VTransform(position, rotY);

	}
	if (CheckHitKey(KEY_INPUT_UP))
	{
		rotation.x += 3.0f*DX_PI_F / 180.0f;
		rotation.x = min(rotation.x, 1.5f);

		MATRIX rotX = MGetRotX(rotation.x);
		position = VTransform(position, rotX);

	}
	if (CheckHitKey(KEY_INPUT_DOWN))
	{
		rotation.x -= 3.0f*DX_PI_F / 180.0f;
		rotation.x = max(rotation.x, -1.5f);

		MATRIX rotX = MGetRotX(rotation.x);
		position = VTransform(position, rotX);

	}
#endif // 1
#if 1 //�O�p�֐����g������]
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


	DebugSetColor(255, 255, 255);
	DebugPrintf(0, 100, "�J�������WX:%f,Y:%f,Z:%f", position.x, position.y, position.z);
	DebugPrintf(0, 115, "�J�����p�xX:%f,Y:%f,Z:%f", rotation.x, rotation.y, rotation.z);


	
}

void Camera::Draw()
{
	//SetCameraPositionAndTarget_UpVecY(position, target);
	SetCameraPositionAndTarget_UpVecY(VGet(-230.462952f, 170.492661f, -11.206726f), VGet(217.512360f, 60.398552f, -153.989639f));
	//SetCameraNearFar(8.048284f, 2012.070923f);

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
