#include "camera.h"
#include <DxLib.h>

Camera::Camera(SceneBase * scene)
{
	position = VGet(100.0f, 150.f, 0);
	target = VGet(0, 0, 0.0f);
}

Camera::~Camera()
{
}

void Camera::Update()
{
#if 1
	if (CheckHitKey(KEY_INPUT_UP))
	{
		position.y += 20.0;
	}
	if (CheckHitKey(KEY_INPUT_DOWN))
	{
		position.y -= 20.0;
	}
	if (CheckHitKey(KEY_INPUT_RIGHT))
	{
		position.x += 20.0;
		position.z += 20.0;
	}
	if (CheckHitKey(KEY_INPUT_LEFT))
	{
		position.x -= 20.0;
		position.z -= 20.0;
	}
#endif // 0
#if 0

	VECTOR add = VGet(0, 0, 0);//カメラの注視点に足すための変数
	//右回転
	if (CheckHitKey(KEY_INPUT_RIGHT))
	{
		rotation.y += 3.0f*DX_PI_F / 180.0f;
	}
	//左回転
	if (CheckHitKey(KEY_INPUT_LEFT))
	{
		rotation.y -= 3.0f*DX_PI_F / 180.0f;
	}

	//円運動をする座標を求める
	add.x += cosf(rotation.y)*length;
	add.z += sinf(rotation.y)*length;

	//注視点を見つめる円運動をカメラ座標に代入
	position.z = target.z + add.z;
	position.x = target.x + add.x;
#endif // 1

}

void Camera::Draw()
{
	SetCameraPositionAndTarget_UpVecY(position, target);
}
