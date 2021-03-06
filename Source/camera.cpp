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

	//t[1xñ]
	float degreeRotation = 1.0f;
	float radianRotation = degreeRotation / 180.0f * DX_PI_F;

	//ñ]OãÌÀWix,y,zj
	float positionX, positionY, positionZ;     //Ï·OÌÀW
	float positionX2, positionY2, positionZ2;  //Ï·ãÌÀW

	positionX = position.x;
	positionY = position.y;
	positionZ = position.z;

	//¶ñ]
	if (CheckHitKey(KEY_INPUT_LEFT))
	{
		//ñ]sñ
		positionX2 = (positionX * cos(radianRotation)) + (positionZ * sin(radianRotation));
		positionY2 = positionY;
		positionZ2 = (positionZ * cos(radianRotation)) - (positionX * sin(radianRotation));

		position.x = positionX2;
		position.y = positionY2;
		position.z = positionZ2;
	}
	//Eñ]
	if (CheckHitKey(KEY_INPUT_RIGHT))
	{
		//ñ]sñ
		positionX2 = (positionX * cos(-radianRotation)) + (positionZ * sin(-radianRotation));
		positionY2 = positionY;
		positionZ2 = (positionZ * cos(-radianRotation)) - (positionX * sin(-radianRotation));

		position.x = positionX2;
		position.y = positionY2;
		position.z = positionZ2;
	}
	//ºñ]
	if (CheckHitKey(KEY_INPUT_DOWN))
	{
		//ñ]sñ
		positionX2 = (positionX * cos(radianRotation)) - (positionY * sin(radianRotation));
		positionY2 = (positionX * sin(radianRotation)) + (positionY * cos(radianRotation));
		positionZ2 = positionZ;

		position.x = positionX2;
		position.y = positionY2;
		position.z = positionZ2;
	}
	//ãñ]
	if (CheckHitKey(KEY_INPUT_UP))
	{
		//ñ]sñ
		positionX2 = (positionX * cos(-radianRotation)) - (positionY * sin(-radianRotation));
		positionY2 = (positionX * sin(-radianRotation)) + (positionY * cos(-radianRotation));
		positionZ2 = positionZ;

		position.x = positionX2;
		position.y = positionY2;
		position.z = positionZ2;
	}



#if 0	//fobO\¦
	DebugSetColor(255, 255, 255);
	DebugPrintf(0, 100, "JÀWX:%f,Y:%f,Z:%f", position.x, position.y, position.z);
	DebugPrintf(0, 115, "JpxX:%f,Y:%f,Z:%f", rotation.x, rotation.y, rotation.z);
#endif // 0

}



void Camera::Draw()
{
	SetCameraPositionAndTarget_UpVecY(position, target);

}