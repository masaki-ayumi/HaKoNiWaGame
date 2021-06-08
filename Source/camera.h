#pragma once
#include "../Library/gameObject.h"

/// <summary>
/// カメラクラス
/// </summary>
class Camera :public GameObject
{
public:
	Camera(SceneBase* scene);
	~Camera();
	void Update();
	void Draw();
	
private:
	VECTOR position;
	VECTOR rotation;
	VECTOR target;	//カメラの注視点
	
};