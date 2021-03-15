#include "camera.h"
#include <DxLib.h>
#include "debugScreen.h"
#include <algorithm>
using namespace std;

Camera::Camera(SceneBase * scene)
{
	position = VGet(100.0f, 150.f, 500.0f);
	target = VGet(0, 0, 0.0f);
	rotation = VGet(1, 1, 1);
}

Camera::~Camera()
{
}

void Camera::Update()
{
#if 0
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
#if 1
	VECTOR add = VGet(0, 0, 0);//カメラの注視点に足すための変数

	//右回転
	if (CheckHitKey(KEY_INPUT_RIGHT))
	{
		rotation.y += 3.0f*DX_PI_F / 180.0f;

		add.x += cosf(rotation.y)*length;
		add.z += sinf(rotation.y)*length;

		//add.x += cosf(rotation.z)*length;
		//add.y += sinf(rotation.z)*length;
		//Yrot(add);
		//注視点を見つめる円運動をカメラ座標に代入
		position.x = target.x + add.x;
		position.y = target.y + add.y;
		position.z = target.z + add.z;
	}
	//左回転
	if (CheckHitKey(KEY_INPUT_LEFT))
	{
		rotation.y -= 3.0f*DX_PI_F / 180.0f;

		add.x += cosf(rotation.y)*length;
		add.z += sinf(rotation.y)*length;

		//add.x += cosf(rotation.z)*length;
		//add.y += sinf(rotation.z)*length;
		//Yrot(add);
		//注視点を見つめる円運動をカメラ座標に代入
		position.x = target.x + add.x;
		position.y = target.y + add.y;
		position.z = target.z + add.z;
	}
	if (CheckHitKey(KEY_INPUT_UP))
	{
		rotation.z += 3.0f*DX_PI_F / 180.0f;
		rotation.z = min(rotation.z, 1.5f);

		//add.x += cosf(rotation.y)*length;
		//add.z += sinf(rotation.y)*length;

		add.x += cosf(rotation.z)*length;
		add.y += sinf(rotation.z)*length;
		//Zrot(add);
		//注視点を見つめる円運動をカメラ座標に代入
		position.x = target.x + add.x;
		position.y = target.y + add.y;
		position.z = target.z + add.z;
	}
	if (CheckHitKey(KEY_INPUT_DOWN))
	{
		rotation.z -= 3.0f*DX_PI_F / 180.0f;
		rotation.z = max(rotation.z, -1.5f);

		//add.x += cosf(rotation.y)*length;
		//add.z += sinf(rotation.y)*length;

		add.x += cosf(rotation.z)*length;
		add.y += sinf(rotation.z)*length;
		//Zrot(add);
		//注視点を見つめる円運動をカメラ座標に代入
		position.x = target.x + add.x;
		position.y = target.y + add.y;
		position.z = target.z + add.z;
	}

	//円運動をする座標を求める

	DebugSetColor(255, 255, 255);
	DebugPrintf(0, 100, "カメラ座標X:%f,Y:%f,Z:%f", position.x, position.y, position.z);
	DebugPrintf(0, 115, "カメラ角度X:%f,Y:%f,Z:%f", rotation.x, rotation.y, rotation.z);


	//注視点を見つめる円運動をカメラ座標に代入
	//position.x = target.x + add.x;
	//position.y = target.y + add.y;
	//position.z = target.z + add.z;
#endif // 1

}

void Camera::Draw()
{
	SetCameraPositionAndTarget_UpVecY(position, target);
}

void Camera::Yrot(VECTOR add)
{
	add.x += cosf(rotation.y)*length;
	add.z += sinf(rotation.y)*length;

	position.x = target.x + add.x;
	position.y = target.y + add.y;
	position.z = target.z + add.z;
	//return add;
}

void Camera::Zrot(VECTOR add)
{
	//VECTOR add = VGet(0, 0, 0);//カメラの注視点に足すための変数
	add.x += cosf(rotation.z)*length;
	add.y += sinf(rotation.z)*length;

	position.x = target.x + add.x;
	position.y = target.y + add.y;
	position.z = target.z + add.z;
	//return add;
}
