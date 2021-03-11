#include "camera.h"
#include <DxLib.h>

Camera::Camera(SceneBase * scene)
{
	position = VGet(100.0f, 150.f, -1000.0f);
	target = VGet(0, 0, 0.0f);
}

Camera::~Camera()
{
}

void Camera::Update()
{
	if (CheckHitKey(KEY_INPUT_U))
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
	}
	if (CheckHitKey(KEY_INPUT_LEFT))
	{
		position.x -= 20.0f;
	}
}

void Camera::Draw()
{
	SetCameraPositionAndTarget_UpVecY(position, target);
}
