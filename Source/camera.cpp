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
	float degRot = 1.0f;
	float radRot = degRot / 180.0f * DX_PI_F;

	//回転前後の座標（x,y,z）
	float posX, posY, posZ;     //変換前の座標
	float posX2, posY2, posZ2;  //変換後の座標

	posX = position.x;
	posY = position.y;
	posZ = position.z;

	//左回転
	if (CheckHitKey(KEY_INPUT_LEFT))
	{
		//回転行列
		posX2 = (posX * cos(radRot)) + (posZ * sin(radRot));
		posY2 = posY;
		posZ2 = (posZ * cos(radRot)) - (posX * sin(radRot));

		position.x = posX2;
		position.y = posY2;
		position.z = posZ2;
	}
	//右回転
	if (CheckHitKey(KEY_INPUT_RIGHT))
	{
		//回転行列
		posX2 = (posX * cos(-radRot)) + (posZ * sin(-radRot));
		posY2 = posY;
		posZ2 = (posZ * cos(-radRot)) - (posX * sin(-radRot));

		position.x = posX2;
		position.y = posY2;
		position.z = posZ2;
	}
	//下回転
	if (CheckHitKey(KEY_INPUT_DOWN))
	{
		//回転行列
		posX2 = (posX * cos(radRot)) - (posY * sin(radRot));
		posY2 = (posX * sin(radRot)) + (posY * cos(radRot));
		posZ2 = posZ;

		position.x = posX2;
		position.y = posY2;
		position.z = posZ2;
	}
	//上回転
	if (CheckHitKey(KEY_INPUT_UP))
	{
		//回転行列
		posX2 = (posX * cos(-radRot)) - (posY * sin(-radRot));
		posY2 = (posX * sin(-radRot)) + (posY * cos(-radRot));
		posZ2 = posZ;

		position.x = posX2;
		position.y = posY2;
		position.z = posZ2;
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