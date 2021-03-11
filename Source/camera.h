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
	
	float length= 500.0f;//‰~‰^“®‚Ì”¼Œa(’‹“_‚©‚ç‚Ì‹——£)
};