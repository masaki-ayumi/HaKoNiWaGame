#pragma once
#include "../Library/gameObject.h"

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
	VECTOR target;
};