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

	VECTOR add = VGet(0, 0, 0);//カメラの注視点に足すための変数

#if 1 //カメラ回転処理をすべてコメントアウト


#if 0//回転行列
	//右回転
	if (CheckHitKey(KEY_INPUT_RIGHT))
	{
		rotation.y += 3.0f*DX_PI_F / 180.0f;

		MATRIX rotY = MGetRotY(rotation.y);
		position = VTransform(position, rotY);

	}
	//左回転
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
#if 1 //三角関数を使った回転
	//右回転
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
		//注視点を見つめる円運動をカメラ座標に代入
		position.x = target.x + add.x;
		position.y = target.y + add.y;
		position.z = target.z + add.z;
#endif // 0
		Yrot(add);
	}
	//左回転
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
		//注視点を見つめる円運動をカメラ座標に代入
		position.x = target.x + add.x;
		position.y = target.y + add.y;
		position.z = target.z + add.z;
#endif // 0
		Yrot(add);
	}
	//上回転
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
		//注視点を見つめる円運動をカメラ座標に代入
		position.x = target.x + add.x;
		position.y = target.y + add.y;
		position.z = target.z + add.z;
#endif // 0
		Zrot(add);
	}
	//下回転
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
		//注視点を見つめる円運動をカメラ座標に代入
		position.x = target.x + add.x;
		position.y = target.y + add.y;
		position.z = target.z + add.z;
#endif // 0
		Zrot(add);
	}
#endif // 1



#endif // 0


	DebugSetColor(255, 255, 255);
	DebugPrintf(0, 100, "カメラ座標X:%f,Y:%f,Z:%f", position.x, position.y, position.z);
	DebugPrintf(0, 115, "カメラ角度X:%f,Y:%f,Z:%f", rotation.x, rotation.y, rotation.z);


	
}

void Camera::Draw()
{
	//SetCameraPositionAndTarget_UpVecY(position, target);
	SetCameraPositionAndTarget_UpVecY(VGet(-230.462952f, 170.492661f, -11.206726f), VGet(217.512360f, 60.398552f, -153.989639f));
	//SetCameraNearFar(8.048284f, 2012.070923f);

}

//Y軸回転(三角関数)
void Camera::Yrot(VECTOR add)
{
	add.x += cosf(rotation.y)*length;
	add.z += sinf(rotation.y)*length;

	position.x = target.x + add.x;
	position.y = target.y + add.y;
	position.z = target.z + add.z;
}

//Z軸回転(三角関数)
void Camera::Zrot(VECTOR add)
{
	add.x += cosf(rotation.z)*length;
	add.y += sinf(rotation.z)*length;

	position.x = target.x + add.x;
	position.y = target.y + add.y;
	position.z = target.z + add.z;
}
