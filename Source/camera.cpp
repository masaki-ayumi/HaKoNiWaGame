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

	//毎フレーム1度回転
	float degreeRotation = 1.0f;
	float radianRotation = degreeRotation / 180.0f * DX_PI_F;

	//回転前後の座標（x,y,z）
	float positionX, positionY, positionZ;     //変換前の座標
	float positionX2, positionY2, positionZ2;  //変換後の座標

	positionX = position.x;
	positionY = position.y;
	positionZ = position.z;

	//左回転
	if (CheckHitKey(KEY_INPUT_LEFT))
	{
		//回転行列
		positionX2 = (positionX * cos(radianRotation)) + (positionZ * sin(radianRotation));
		positionY2 = positionY;
		positionZ2 = (positionZ * cos(radianRotation)) - (positionX * sin(radianRotation));

		position.x = positionX2;
		position.y = positionY2;
		position.z = positionZ2;
	}
	//右回転
	if (CheckHitKey(KEY_INPUT_RIGHT))
	{
		//回転行列
		positionX2 = (positionX * cos(-radianRotation)) + (positionZ * sin(-radianRotation));
		positionY2 = positionY;
		positionZ2 = (positionZ * cos(-radianRotation)) - (positionX * sin(-radianRotation));

		position.x = positionX2;
		position.y = positionY2;
		position.z = positionZ2;
	}
	//下回転
	if (CheckHitKey(KEY_INPUT_DOWN))
	{
		//回転行列
		positionX2 = (positionX * cos(radianRotation)) - (positionY * sin(radianRotation));
		positionY2 = (positionX * sin(radianRotation)) + (positionY * cos(radianRotation));
		positionZ2 = positionZ;

		position.x = positionX2;
		position.y = positionY2;
		position.z = positionZ2;
	}
	//上回転
	if (CheckHitKey(KEY_INPUT_UP))
	{
		//回転行列
		positionX2 = (positionX * cos(-radianRotation)) - (positionY * sin(-radianRotation));
		positionY2 = (positionX * sin(-radianRotation)) + (positionY * cos(-radianRotation));
		positionZ2 = positionZ;

		position.x = positionX2;
		position.y = positionY2;
		position.z = positionZ2;
	}



#if 0	//デバッグ表示
	DebugSetColor(255, 255, 255);
	DebugPrintf(0, 100, "カメラ座標X:%f,Y:%f,Z:%f", position.x, position.y, position.z);
	DebugPrintf(0, 115, "カメラ角度X:%f,Y:%f,Z:%f", rotation.x, rotation.y, rotation.z);
#endif // 0

}



void Camera::Draw()
{
	SetCameraPositionAndTarget_UpVecY(position, target);

}