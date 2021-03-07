#include "camera.h"
#include <DxLib.h>

Camera::Camera(SceneBase * scene)
{
	position = VGet(100.0f, 150.f, -200.0f);
	target = VGet(0, 0, 10.0f);
}

Camera::~Camera()
{
}

void Camera::Update()
{
}

void Camera::Draw()
{
	SetCameraPositionAndTarget_UpVecY(position, target);
}
